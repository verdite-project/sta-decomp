#!/bin/bash
# commit.sh "message" : carve, rebuild, near-duplicates, progress, commit, notify
set -e
cd /home/fatalis/code/sta
.venv/bin/python tools/carve.py --check 2>&1 | grep -v "^  \.\|placed" || true
.venv/bin/python tools/carve.py >/dev/null
rm -rf /home/fatalis/code/sta/asm
./build.sh 2>&1 | tail -1 | grep -q "OK (matches retail)" || { echo BUILD FAILED; exit 1; }
if .venv/bin/python tools/dupes.py 2>&1 | grep "^MATCH"; then
  .venv/bin/python tools/carve.py >/dev/null
  rm -rf /home/fatalis/code/sta/asm
  ./build.sh 2>&1 | tail -1 | grep -q "OK (matches retail)" || { echo BUILD FAILED; exit 1; }
fi
before=$(git show HEAD:docs/progress/summary.json | python3 -c 'import json,sys; d=json.load(sys.stdin); print([c for c in d["categories"] if c["id"]=="game"][0]["measures"]["matched_functions"])' 2>/dev/null || echo '?')
G=$(ninja progress 2>&1 | grep '^game' | awk '{print $6}')
.venv/bin/python tools/progress.py --write >/dev/null
git add -A
big=$(git diff --cached --name-only --diff-filter=A -- 'src/game/*.c' 'src/game/ee/*.c' | xargs -r -n1 basename | sed 's/\.c$//' | .venv/bin/python -c '
import sys
from elftools.elf.elffile import ELFFile
want = set(sys.stdin.read().split())
sizes = {s.name: s["st_size"] for s in ELFFile(open("build/sta.elf", "rb")).get_section_by_name(".symtab").iter_symbols() if s.name in want}
if sizes:
    n = max(sizes, key=sizes.get)
    print(f"{n} ({sizes[n]} bytes)")
' 2>/dev/null)
table=$(.venv/bin/python tools/hand/rules_table.py --staged)
git commit -q -m "$1

Game functions: $G.${table:+

Differing words against retail of the m2c output, the m2c + rules starting
point, and the final C:

$table}

Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>"
now=${G%%/*}
delta=$((now - before))
echo "committed: game $G (+$delta)${big:+, largest: $big}"
notify-send "sta decomp" "+$delta game functions matched (now $G)${big:+, largest: $big}"
[ -n "$table" ] && echo "$table"
