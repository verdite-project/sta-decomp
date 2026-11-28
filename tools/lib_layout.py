#!/usr/bin/env python3
"""Place compiled library objects in the retail ELF, section by section.

    tools/lib_layout.py <objdir> [out.tsv]

<objdir> holds unlinked .o files (src/sce/ compiled with tools/compile_c.sh;
the path under <objdir> names the unit). For each object:

  .text      the whole section is searched for in the retail .text with the
             words that carry relocations masked out. A hit whose jal targets
             carry other names in symbol_addrs is rejected; of several hits,
             the one where the object's functions sit at their symbol_addrs
             addresses wins. A unique hit places it.
  data       A data-only game unit (src/game/data/) is placed by the
             addresses its D_XXXXXXXX globals name. Otherwise
             .data/.rodata/.sdata/.sbss/.bss are placed from the relocations
             that point into them: a %hi/%lo pair or a .word in the located
             .text/.data gives the absolute address, the object's in-place
             addend gives the offset, and their difference is the section
             base. All relocations must agree. Initialized sections are then
             compared byte for byte (relocated words masked). Sections nothing
             references fall back to a masked byte search: a unique hit (with
             named symbols at their addresses) places them, and failing that,
             the one hit between the same section of the objects before and
             after this one in .text order (all sections share one link order).

Prints one row per (object, section): unit, section, size, alignment, retail
address or '-', how it was placed, and whether the bytes match. Then lists,
per section, the placed units in address order with the gaps between them.
"""
import os
import re
import struct
import sys
from collections import defaultdict

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

R_32, R_26, R_HI16, R_LO16, R_GPREL16 = 2, 4, 5, 6, 7
GP = 0x00209B70
SECS = [".text", ".data", ".rodata", ".sdata", ".sbss", ".bss"]
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


# The retail ELF has no section table (mwldps2 wrote one PROGBITS blob), so
# its sections are the ranges config/sta.jp.yaml records. .data and .rodata
# share one range: mwldps2 put every .data, then every .rodata, in it.
REGIONS = {
    ".text":   (0x00100000, 0x001EDE80),
    ".data":   (0x001EDE80, 0x00201B80),
    ".rodata": (0x001EDE80, 0x00201B80),
    ".sdata":  (0x00201B80, 0x00201E80),
    ".sbss":   (0x00201E80, 0x00202480),
    ".bss":    (0x00202480, 0x004BE180),
}
ROM_END = 0x00201E80

# Where the game starts in each section: everything before is library code
# and data (crt0, the SDK, libc/libm/libgcc), everything from here on is the
# game's. Library and game code never reference each other's data across
# these lines (see docs/ROADMAP.md).
#   .text    0x128210  first CodeWarrior function (sq/lq saves), after
#                      __swsetup and its nop fill
#   .data    0x1F1AF0  after libc's malloc lock variables
#   .rodata  0x1FAAE8  "sta_abyss.ico", after vfprintf's table
#   .bss     0x209700  after the last library object (0x2096C0, 0x40 bytes)
GAME_START = {".text": 0x00128210, ".data": 0x001F1AF0,
              ".rodata": 0x001FAAE8, ".bss": 0x00209700}


def load_retail(path):
    """section -> (vma, bytes) for the ROM view of `path` (the retail ELF);
    the NOBITS ranges are zeros."""
    with open(path, "rb") as f:
        e = ELFFile(f)
        seg = next(s for s in e.iter_segments() if s["p_type"] == "PT_LOAD" and s["p_filesz"])
        base, rom = seg["p_vaddr"], seg.data()
    out = {}
    for name, (lo, hi) in REGIONS.items():
        if lo >= ROM_END:
            out[name] = (lo, b"\0" * (hi - lo))
        else:
            out[name] = (lo, rom[lo - base:hi - base])
    return out


def chunk_text(name):
    """(size, alignment) of the .text of the asm chunk whose first label is
    `name` (an INCLUDE_ASM marker's), from its built object."""
    import glob
    for src in glob.glob(os.path.join(ROOT, "asm", "**", "*.s"), recursive=True):
        if "/matchings/" in src or "/data/" in src:
            continue
        with open(src) as f:
            m = re.search(r"^\s*glabel (\w+)", f.read(), re.M)
        if m and m.group(1) == name:
            o = os.path.join(ROOT, "build", os.path.relpath(src, ROOT) + ".o")
            with open(o, "rb") as f:
                t = ELFFile(f).get_section_by_name(".text")
                return t["sh_size"], max(t["sh_addralign"], 1)
    raise SystemExit(f"INCLUDE_ASM({name}): no asm chunk starts with it")


class Obj:
    def __init__(self, path, unit):
        self.unit = unit
        with open(path, "rb") as f:
            e = ELFFile(f)
            # name -> (index of the first part, size, align, bytes). CodeWarrior can
            # write several sections of one name (one .text per function); ld joins
            # them in file order, each at its own alignment, and so does this.
            self.secs = {}
            self.part = {}      # section index -> (name, offset of that part in the joined section)
            idx = {}
            # an INCLUDE_ASM unit (tools/include_asm.py): its .text.iaN are
            # .text, and each marker stands for its asm chunk, bytes unknown
            # (self.gaps: (offset, size, marker name) in the joined .text, masked out)
            self.gaps = []
            marks = {sym["st_shndx"]: sym.name[len("__include_asm_"):]
                     for sym in e.get_section_by_name(".symtab").iter_symbols()
                     if sym.name.startswith("__include_asm_") and isinstance(sym["st_shndx"], int)}
            for i, s in enumerate(e.iter_sections()):
                name = ".text" if s.name.startswith(".text.ia") else s.name
                if name in SECS and s["sh_size"]:
                    data = s.data() if s["sh_type"] != "SHT_NOBITS" else b"\0" * s["sh_size"]
                    align = max(s["sh_addralign"], 1)
                    if s.name == ".text.iastub":
                        size_, align = chunk_text(marks[i])
                        data = b"\0" * size_
                    first, size, salign, joined = self.secs.get(name, (i, 0, 1, b""))
                    off = -(-size // align) * align
                    joined = joined + b"\0" * (off - size) + data
                    self.secs[name] = (first, off + len(data), max(salign, align), joined)
                    if s.name == ".text.iastub":
                        self.gaps.append((off, len(data), marks[i]))
                        continue        # the marker's own relocations and symbol are not the chunk's
                    self.part[i] = (name, off)
                    idx[i] = name
            symtab = e.get_section_by_name(".symtab")
            syms = list(symtab.iter_symbols())
            # relocations: section name -> list of (offset, type, target section or None,
            # symbol value, symbol name)
            self.relocs = defaultdict(list)
            for s in e.iter_sections():
                if not isinstance(s, RelocationSection):
                    continue
                if s["sh_info"] not in self.part:
                    continue
                tgt, base = self.part[s["sh_info"]]
                for r in s.iter_relocations():
                    sym = syms[r["r_info_sym"]]
                    shndx = sym["st_shndx"]
                    tsec = idx.get(shndx) if isinstance(shndx, int) else None
                    self.relocs[tgt].append((base + r["r_offset"], r["r_info_type"], tsec,
                                             self.offset_of(sym), sym.name))
            # globals in the data sections: (section, offset, name)
            self.datasyms = [(idx[s["st_shndx"]], self.offset_of(s), s.name) for s in syms
                             if s["st_info"]["bind"] == "STB_GLOBAL" and isinstance(s["st_shndx"], int)
                             and idx.get(s["st_shndx"]) in (".data", ".rodata", ".sdata")]
            # every global in a data section, .bss included: (section, offset, name)
            self.allsyms = [(idx[s["st_shndx"]], self.offset_of(s), s.name) for s in syms
                            if s["st_info"]["bind"] == "STB_GLOBAL" and isinstance(s["st_shndx"], int)
                            and idx.get(s["st_shndx"]) in SECS[1:]]
            self.funcs = sorted((self.offset_of(sym), sym.name) for sym in syms
                                if sym["st_info"]["type"] == "STT_FUNC" and
                                idx.get(sym["st_shndx"] if isinstance(sym["st_shndx"], int) else -1) == ".text")

    def offset_of(self, sym):
        """A symbol's value as an offset in its joined section."""
        shndx = sym["st_shndx"]
        part = self.part.get(shndx) if isinstance(shndx, int) else None
        return sym["st_value"] + (part[1] if part else 0)

    def mask(self, sec):
        """Per-word masks for `sec`: bits that the linker leaves alone."""
        _, size, _, _ = self.secs[sec]
        m = [0xFFFFFFFF] * (size // 4)
        if sec == ".text":
            for off, n, _ in self.gaps:
                m[off // 4:(off + n) // 4] = [0] * (n // 4)
        for off, typ, *_ in self.relocs[sec]:
            if off // 4 < len(m):
                m[off // 4] &= {R_26: 0xFC000000, R_HI16: 0xFFFF0000,
                                R_LO16: 0xFFFF0000, R_GPREL16: 0xFFFF0000}.get(typ, 0)
        return m


def load_symbols(generated=True):
    """symbol_addrs.txt (and, with `generated`, tools/carve.py's
    symbol_addrs.carve.txt) as (name -> addr, addr -> name)."""
    n2a, a2n = {}, {}
    files = ["config/symbol_addrs.txt"] + (["config/symbol_addrs.carve.txt"] if generated else [])
    lines = []
    for fn in files:
        if os.path.exists(os.path.join(ROOT, fn)):
            lines += open(os.path.join(ROOT, fn)).readlines()
    for line in lines:
        note = line.split("//", 1)[1] if "//" in line else ""
        line = line.split("//", 1)[0].strip().rstrip(";")
        if "=" in line:
            name, addr = (x.strip() for x in line.split("=", 1))
            if "ignore:True" in note:
                continue
            # a repeated static name has no single address: it names no call.
            # symbol_addrs.txt is read first; a static that shares its name
            # does not take the name from it
            if "allow_duplicated:True" not in note:
                n2a.setdefault(name, int(addr, 0))
            a2n[int(addr, 0)] = name
    return n2a, a2n


def calls_agree(obj, base, rtext, rbase, syms):
    """Do the object's jal targets agree with the retail ones at `base`?

    Calls inside the object must land on the same offsets; calls out of it
    must not land on an address symbol_addrs.txt gives another name (masked
    search alone cannot tell wf_acos from wf_asin)."""
    n2a, a2n = syms
    data = obj.secs[".text"][3]
    for off, typ, tsec, sval, sname in obj.relocs[".text"]:
        if typ != R_26:
            continue
        ow = struct.unpack_from("<I", data, off)[0]
        rw = struct.unpack_from("<I", rtext, base - rbase + off)[0]
        target = ((rw & 0x3FFFFFF) << 2) | ((base + off) & 0xF0000000)
        if tsec == ".text":
            if target != base + sval + ((ow & 0x3FFFFFF) << 2):
                return False
        elif sname:
            if sname in n2a and n2a[sname] != target:
                return False
            if a2n.get(target, sname) != sname:
                return False
    return True


def words(b):
    return struct.unpack("<%dI" % (len(b) // 4), b[: len(b) // 4 * 4])


def search(hay_words, needle_words, mask):
    """Positions (word index) where needle matches hay under mask."""
    if not needle_words:
        return []
    # anchor on the first fully unmasked word
    anchor = next((i for i, m in enumerate(mask) if m == 0xFFFFFFFF), None)
    hits = []
    if anchor is None:
        return hits
    aw = needle_words[anchor]
    n = len(needle_words)
    start = 0
    while True:
        try:
            p = hay_words.index(aw, start)
        except ValueError:
            break
        start = p + 1
        base = p - anchor
        if base < 0 or base + n > len(hay_words):
            continue
        if all((hay_words[base + i] ^ needle_words[i]) & mask[i] == 0 for i in range(n)):
            hits.append(base)
    return hits


def sext16(v):
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def bases_from(obj, sec, sec_addr, retail):
    """Section bases implied by relocations in `sec` (placed at sec_addr)."""
    _, size, _, data = obj.secs[sec]
    rbase, rdata = retail[sec]
    out = defaultdict(set)    # target section -> {base}
    pending_hi = []
    for off, typ, tsec, sval, sname in sorted(obj.relocs[sec], key=lambda r: r[0]):
        if typ not in (R_32, R_HI16, R_LO16):
            continue
        ow = struct.unpack_from("<I", data, off)[0]
        roff = sec_addr - rbase + off
        rw = struct.unpack_from("<I", rdata, roff)[0]
        if typ == R_32 and tsec:
            out[tsec].add(rw - (ow + sval))
        elif typ == R_HI16:
            pending_hi.append((off, tsec, sval))
        elif typ == R_LO16:
            # pair with the pending HI16 of the same target whose lui wrote the
            # register this lo16 instruction reads: gcc hoists several luis
            # of section-relative symbols (all with value 0) into saved
            # registers, and pairing across them gives false bases. Failing
            # that, with every pending HI16 of the same target (gcc may emit
            # several).
            same = [h for h in pending_hi if h[1] == tsec and h[2] == sval]
            byreg = [h for h in same
                     if (struct.unpack_from("<I", data, h[0])[0] >> 16) & 31 == (ow >> 21) & 31]
            for hoff, htsec, hval in (byreg[-1:] or same):
                how = struct.unpack_from("<I", data, hoff)[0]
                hrw = struct.unpack_from("<I", rdata, sec_addr - rbase + hoff)[0]
                addend = ((how & 0xFFFF) << 16) + sext16(ow)
                absolute = ((hrw & 0xFFFF) << 16) + sext16(rw)
                if tsec:
                    out[tsec].add(absolute - (addend + sval))
            # a register-paired lui may serve later lo16s too; keep it
            if not byreg:
                pending_hi = [h for h in pending_hi if not (h[1] == tsec and h[2] == sval)]
    return out


def layout(objdir):
    """Rows of (unit, section, size, align, addr or None, how, bytes_match)."""
    retail = load_retail(os.path.join(ROOT, "baserom/jp/SLPS_252.17"))
    rwords = {s: words(d) for s, (a, d) in retail.items()}
    objs = []
    for root, _, files in os.walk(objdir):
        for fn in sorted(files):
            if fn.endswith(".o"):
                p = os.path.join(root, fn)
                objs.append(Obj(p, os.path.relpath(p, objdir)[:-2]))
    objs.sort(key=lambda o: o.unit)

    syms = load_symbols()
    place = {}   # (unit, sec) -> (addr, how)
    tbase, tdata = retail[".text"]
    for o in objs:
        if ".text" not in o.secs:
            continue
        _, size, _, data = o.secs[".text"]
        # a game unit is one function named after its address: identical code
        # repeats in the game (four copies of the VU0 distance routine), so the
        # name places it, and the byte check below confirms it
        m = re.fullmatch(r"src/game/(?:.*/)?((?:func|[A-Za-z]\w*?_[0-5])_([0-9A-F]{8}))\.[cs]", o.unit)
        if m:
            # the named function's offset in the joined .text (not 0 when the
            # unit starts with an INCLUDE_ASM'd chunk)
            fn = m.group(1)
            off = next((v for v, n in o.funcs if n == fn), 0)
            place[(o.unit, ".text")] = (int(m.group(2), 16) - off, "by-name")
            continue
        hits = search(rwords[".text"], words(data), o.mask(".text"))
        hits = [h for h in hits if calls_agree(o, tbase + h * 4, tdata, tbase, syms)]
        # identical code in two members (sceGsSetHalfOffset/2): the names in
        # symbol_addrs.txt say which copy is which
        named = [(v, n) for v, n in o.funcs if n in syms[0]]
        if len(hits) > 1 and named:
            hits = [h for h in hits
                    if all(syms[0][n] == tbase + h * 4 + v for v, n in named)]
        if len(hits) == 1:
            place[(o.unit, ".text")] = (retail[".text"][0] + hits[0] * 4, "text-search")
        elif hits:
            place[(o.unit, ".text")] = (None, f"ambiguous x{len(hits)}")
    def reloc_pass():
        for o in objs:
            for sec in list(o.secs):
                got = place.get((o.unit, sec))
                if not got or got[0] is None or sec in (".sbss", ".bss"):
                    continue
                for tsec, bases in bases_from(o, sec, got[0], retail).items():
                    if tsec == ".text" or tsec not in o.secs:
                        continue
                    key = (o.unit, tsec)
                    old = place.get(key)
                    if len(bases) == 1:
                        b = next(iter(bases))
                        if old and old[0] is not None and old[0] != b:
                            place[key] = (None, f"conflict {old[0]:#x}/{b:#x}")
                        elif not old or old[0] is None and not old[1].startswith("conflict"):
                            place[key] = (b, f"reloc<-{sec}")
                    else:
                        place[key] = (None, "conflict " + "/".join(f"{b:#x}" for b in sorted(bases)))

    def data_hits(o, sec):
        """Retail addresses where the section's bytes are (relocated words
        masked), aligned as the section is and agreeing with symbol names."""
        _, size, align, data = o.secs[sec]
        rbase, rdata = retail[sec]
        m = o.mask(sec)
        hits, start = [], 0
        probe = data[:4] if m and m[0] == 0xFFFFFFFF else None
        while True:
            if probe is not None:
                i = rdata.find(probe, start)
            else:
                i = start if start + size <= len(rdata) else -1
            if i < 0 or i + size > len(rdata):
                break
            start = i + 1
            if (rbase + i) % max(align, 1):
                continue
            seg = rdata[i:i + size]
            ok = all((struct.unpack_from("<I", seg, k * 4)[0] ^ struct.unpack_from("<I", data, k * 4)[0])
                     & m[k] == 0 for k in range(size // 4))
            if ok and seg[size // 4 * 4:] == data[size // 4 * 4:]:
                hits.append(rbase + i)
        named = [(v, n) for s, v, n in o.datasyms if s == sec and n in syms[0]]
        if named:
            hits = [h for h in hits if all(syms[0][n] == h + v for v, n in named)]
        return hits

    def search_pass():
        """Unreferenced initialized sections: a unique byte match places them."""
        for o in objs:
            for sec in o.secs:
                if sec in (".text", ".sbss", ".bss"):
                    continue
                got = place.get((o.unit, sec))
                if got and (got[0] is not None or got[1].startswith("conflict")):
                    continue
                hits = data_hits(o, sec)
                if len(hits) == 1:
                    place[(o.unit, sec)] = (hits[0], "data-search")
                elif hits:
                    place[(o.unit, sec)] = (None, f"ambiguous x{len(hits)}")

    def order_pass():
        """Still ambiguous or unplaced: the unit's section must lie between those
        of its neighbours in .text order (one link order for all sections)."""
        taddr = {o.unit: place[(o.unit, ".text")][0] for o in objs
                 if place.get((o.unit, ".text"), (None,))[0] is not None}
        for o in objs:
            if o.unit not in taddr:
                continue
            for sec in o.secs:
                got = place.get((o.unit, sec))
                if sec in (".text", ".sbss", ".bss") or (got and got[0] is not None):
                    continue
                if got and got[1].startswith("conflict"):
                    continue
                lo, hi = 0, 1 << 32
                for p in objs:
                    pa = place.get((p.unit, sec), (None,))[0]
                    if p.unit not in taddr or pa is None or p is o:
                        continue
                    if taddr[p.unit] < taddr[o.unit]:
                        lo = max(lo, pa + p.secs[sec][1])
                    else:
                        hi = min(hi, pa)
                size = o.secs[sec][1]
                hits = [h for h in data_hits(o, sec) if lo <= h and h + size <= hi]
                if len(hits) == 1:
                    place[(o.unit, sec)] = (hits[0], "order-search")

    def bss_order_pass():
        """A .bss no relocation reaches (an unused static): it follows the
        .bss of the unit before it in .text order, at its own alignment, and
        must then end within the alignment fill before the next unit's."""
        taddr = {o.unit: place[(o.unit, ".text")][0] for o in objs
                 if place.get((o.unit, ".text"), (None,))[0] is not None}
        for o in objs:
            if o.unit not in taddr or ".bss" not in o.secs:
                continue
            if place.get((o.unit, ".bss"), (None,))[0] is not None:
                continue
            prev, nxt = None, None
            for p in objs:
                pa = place.get((p.unit, ".bss"), (None,))[0]
                if p.unit not in taddr or pa is None or p is o:
                    continue
                if taddr[p.unit] < taddr[o.unit]:
                    if prev is None or taddr[p.unit] > taddr[prev.unit]:
                        prev = p
                elif nxt is None or taddr[p.unit] < taddr[nxt.unit]:
                    nxt = p
            if prev is None or nxt is None:
                continue
            _, size, align, _ = o.secs[".bss"]
            a = place[(prev.unit, ".bss")][0] + prev.secs[".bss"][1]
            a = (a + max(align, 1) - 1) & -max(align, 1)
            hi = place[(nxt.unit, ".bss")][0]
            if a + size <= hi and hi - (a + size) < max(nxt.secs[".bss"][2], 1):
                place[(o.unit, ".bss")] = (a, "bss-order")

    def name_pass():
        """A data-only game unit (src/game/data/): its globals are named by
        address (D_XXXXXXXX, or a name symbol_addrs.txt gives), which places
        each section, zero-filled ones included; the bytes are checked below."""
        for o in objs:
            if not o.unit.startswith("src/game/data/"):
                continue
            for sec in o.secs:
                bases = set()
                for s, off, n in o.allsyms:
                    if s != sec:
                        continue
                    m = re.fullmatch(r"(?:D|g[A-Z][A-Za-z0-9]*)_([0-9A-F]{8})", n)
                    a = syms[0].get(n, int(m.group(1), 16) if m else None)
                    if a is not None:
                        bases.add(a - off)
                if len(bases) == 1:
                    place[(o.unit, sec)] = (bases.pop(), "by-name")
                elif bases:
                    place[(o.unit, sec)] = (None, "conflict " + "/".join(f"{b:#x}" for b in sorted(bases)))

    name_pass()
    for _ in range(3):
        reloc_pass()
        search_pass()
    order_pass()
    reloc_pass()
    bss_order_pass()

    rows = []
    for o in objs:
        for sec in SECS:
            if sec not in o.secs:
                continue
            _, size, align, data = o.secs[sec]
            addr, how = place.get((o.unit, sec), (None, "unplaced"))
            ok = "-"
            if addr is not None and sec not in (".sbss", ".bss"):
                rbase, rdata = retail[sec]
                seg = rdata[addr - rbase: addr - rbase + size]
                m = o.mask(sec)
                ok = "yes"
                for i in range(size // 4):
                    a = struct.unpack_from("<I", seg, i * 4)[0]
                    b = struct.unpack_from("<I", data, i * 4)[0]
                    if (a ^ b) & m[i]:
                        ok = "NO"
                        break
                if ok == "yes" and size % 4 and seg[size // 4 * 4:] != data[size // 4 * 4:]:
                    ok = "NO"
            rows.append((o.unit, sec, size, align, addr, how, ok))
    return rows


def main():
    objdir = sys.argv[1]
    out_tsv = sys.argv[2] if len(sys.argv) > 2 else None
    rows = layout(objdir)
    lines = ["unit\tsection\tsize\talign\taddr\thow\tbytes_match"]
    for u, s, size, al, addr, how, ok in rows:
        lines.append(f"{u}\t{s}\t{size:#x}\t{al}\t{addr:#010x}\t{how}\t{ok}" if addr is not None
                     else f"{u}\t{s}\t{size:#x}\t{al}\t-\t{how}\t{ok}")
    text = "\n".join(lines) + "\n"
    if out_tsv:
        open(out_tsv, "w").write(text)
    else:
        sys.stdout.write(text)

    # per-section layout with gaps
    for sec in SECS:
        placed = sorted((addr, size, u) for u, s, size, al, addr, how, ok in rows
                        if s == sec and addr is not None)
        if not placed:
            continue
        print(f"\n## {sec}: {len(placed)} placed", file=sys.stderr)
        prev_end = None
        for addr, size, u in placed:
            if prev_end is not None and addr != prev_end:
                print(f"   gap {prev_end:#010x}..{addr:#010x} ({addr - prev_end:#x})", file=sys.stderr)
            print(f"  {addr:#010x} {size:#8x} {u}", file=sys.stderr)
            prev_end = addr + size


if __name__ == "__main__":
    main()
