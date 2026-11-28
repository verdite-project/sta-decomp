#!/usr/bin/env bash
# Compile one source to an object with the period toolchain.
#
#   tools/compile_c.sh src/<path>.c build/src/<path>.c.o
#   tools/compile_c.sh src/<path>.s build/src/<path>.s.o   (hand-written asm)
#
# The compiler follows where the code came from:
#   src/sce/libc|libm|libgcc   ee-gcc 2.96-ee-001003-1 -O2 -G 0 -fno-builtin,
#                              SCE ee-as 2.10 (find_lib_matches: 69 of ICO's
#                              91 libc functions match under 2.96, 12 under 2.9)
#   src/sce/*                  Sony SDK 2.5 archives: ee-gcc 2.9-ee-991111-01
#                              -O2 -G 0, SCE ee-as 2.10 (286 of 301 libkernl
#                              functions match under 2.9, 168 under 2.96)
#   src/game/ee/*              the game's three ee-gcc modules (0x1D3A90-0x1D7EC0,
#                              0x1DC328-0x1DC900, 0x1E1E08-0x1E5E80): ee-gcc 2.96 -O2 -G 8
#                              -fno-strict-aliasing, SCE ee-as 2.10
#   everything else (the game) Metrowerks CodeWarrior mwccps2 3.0 beta -O4,p,
#                              run under wibo
#
# CDEFS (tools/gen_ninja.py: -DNONMATCHING unless --matching) goes to every
# C compile.
#
# tools/probe_compiler.py settles the game's compilers: its probes match
# under mwccps2 3.0b38, 3.0b50 and 3.0b52 at -O4,p only (b50 and b52 emit
# identical code on everything tried), and the gcc modules under ee-gcc 2.96
# with -fno-strict-aliasing only. b52 is the default. b38 emits a trapping
# addi for a switch range check with a nonzero lowest case (b50/b52: addiu)
# and reverses some 4-float struct copies; the units showing that addi are
# marked "mwcc=mwcps2-3.0b38-030307" in config/game_cflags.txt. MWCC
# overrides the CodeWarrior build (a directory under tools/cc/) for every
# unit, GAME_CFLAGS the flags.
set -eu
[ $# -eq 2 ] || { echo "usage: $0 <src.c|src.s> <out.o>" >&2; exit 2; }
SRC="$1"; OUT="$2"
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
CC9="${ROOT}/tools/cc/ee-gcc2.9-991111-01"
CC96="${ROOT}/tools/cc/ee-gcc2.96"
AS_SDK="${CC96}/bin/as"
MWCC_DIR="${ROOT}/tools/cc/${MWCC:-mwcps2-3.0b52-030722}"
WIBO="${ROOT}/tools/cc/wibo"

INCS="-I${ROOT}/include"
for d in "${ROOT}"/src/sce/*/; do [ -d "$d" ] && INCS="${INCS} -I${d%/}"; done

# Game code is matched from plain C: inline asm would only re-type the
# retail instructions, so it is refused.
case "${SRC}" in
    src/game/*.c)
        if grep -nE '\b(__asm__|asm)\b' "${SRC}" >&2; then
            echo "compile_c.sh: ${SRC}: inline asm is not allowed in game code" >&2
            exit 1
        fi ;;
esac

mkdir -p "$(dirname "${OUT}")"
case "${SRC}" in
    src/sce/libc/*|src/sce/libm/*|src/sce/libgcc/*)
        GCC="${CC96}/bin/gcc -B ${CC96}/gcc-lib/ee/2.96-ee-001003-1/"; FLAGS="-G 0 -fno-builtin" ;;
    src/sce/*)
        GCC="${CC9}/ee-gcc -B ${CC9}/gcc-lib/ee/2.9-ee-991111-01/"; FLAGS="-G 0" ;;
    src/game/ee/*.c)
        GCC="${CC96}/bin/gcc -B ${CC96}/gcc-lib/ee/2.96-ee-001003-1/"; FLAGS="-G 8 -fno-strict-aliasing"
        INCS="${INCS} -I${ROOT}/src/game" ;;
    *.s)
        exec "${ROOT}/tools/period_env.sh" "${AS_SDK}" -EL -mcpu=5900 -mabi=eabi -G 8 -Iinclude -o "${OUT}" "${SRC}" ;;
    *)
        # mwccps2 writes the object itself; it reads its system include path
        # from MWCIncludes and warns when that is unset.
        INCS="${INCS} -I${ROOT}/src/game"
        # config/game_cflags.txt lists the units built with other flags
        UNIT_CFLAGS="$(awk -v s="${SRC#"${ROOT}"/}" '$1 == s { $1 = ""; print substr($0, 2) }' \
            "${ROOT}/config/game_cflags.txt")"
        # data-only units (tools/data_to_c.py): small objects stay in .data/.bss
        # (the .sdata and .sbss units: every object stays small data)
        case "${SRC#"${ROOT}"/}" in
            src/game/data/sdata.c|src/game/data/sbss.c) UNIT_CFLAGS="${UNIT_CFLAGS:--O4,p} -sdatathreshold 32767" ;;
            src/game/data/*) UNIT_CFLAGS="${UNIT_CFLAGS:--O4,p} -sdatathreshold 0" ;;
        esac
        # a "mwcc=<tools/cc dir>" token picks another CodeWarrior build for the unit
        case " ${UNIT_CFLAGS} " in *" mwcc="*)
            B="${UNIT_CFLAGS##*mwcc=}"; B="${B%% *}"
            [ -n "${MWCC:-}" ] || MWCC_DIR="${ROOT}/tools/cc/${B}"
            UNIT_CFLAGS="$(echo "${UNIT_CFLAGS}" | sed 's/ *mwcc=[^ ]*//')" ;;
        esac
        # tools/mwfix.py retypes the .mwcats section, which ld 2.10 cannot read
        MWCIncludes="${ROOT}/include" "${WIBO}" "${MWCC_DIR}/mwccps2.exe" -c -nostdinc \
            ${GAME_CFLAGS:-${UNIT_CFLAGS:--O4,p}} ${CDEFS:-} ${INCS} -o "${OUT}" "${SRC}"
        python3 "${ROOT}/tools/mwfix.py" "${OUT}"
        # INCLUDE_ASM markers (include/include_asm.h): split the unit's .text
        if grep -q '^[[:space:]]*INCLUDE_ASM(' "${SRC}"; then
            exec "${ROOT}/.venv/bin/python" "${ROOT}/tools/include_asm.py" "${OUT}"
        fi
        exit 0 ;;
esac

GNUM=0
case "${SRC}" in src/game/*) GNUM=8 ;; esac
case "${SRC}" in
    *.s) exec "${ROOT}/tools/period_env.sh" "${AS_SDK}" -EL -mcpu=5900 -mabi=eabi -G "${GNUM}" -o "${OUT}" "${SRC}" ;;
esac
S="${OUT%.o}.s"
# ee-gcc records the path it is given in __FILE__ strings, so compile from the
# source's directory with its bare name.
SRC_DIR="$(cd "$(dirname "${SRC}")" && pwd)"
( cd "${SRC_DIR}" && "${ROOT}/tools/period_env.sh" ${GCC} \
    -S -O2 -mips3 -EL -nostdinc ${FLAGS} ${CDEFS:-} ${INCS} -o "${ROOT}/${S}" "$(basename "${SRC}")" )
# The newlib libraries were assembled by an older gas, which never put a
# macro (`move`, `ld`, `sd`, ...) in a delay slot; tools/oldmove.py stops ours
# from doing so.
case "${SRC}" in
    src/sce/libc/*|src/sce/libm/*|src/sce/libgcc/*) python3 "${ROOT}/tools/oldmove.py" "${S}" "${S}" ;;
esac
"${ROOT}/tools/period_env.sh" "${AS_SDK}" -EL -mcpu=5900 -mabi=eabi -G "${GNUM}" -o "${OUT}" "${S}"
