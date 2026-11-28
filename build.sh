#!/usr/bin/env bash
# One command from a fresh checkout to a verified build:
#   tools/setup.sh        when the venv or toolchain is missing
#   tools/extract_elf.py  when baserom/jp/ is missing (disc at baserom/sta_jp.iso)
#   tools/split.py        when asm/ is missing
#   tools/gen_ninja.py + ninja
#
# The default build is NONMATCHING: functions with best-effort C under
# #ifdef NONMATCHING build from it, and the image (build/sta.elf) is not
# retail's. `./build.sh --matching` builds their asm instead and checks the
# ROM SHA-1.
set -euo pipefail
cd "$(dirname "$0")"
MODE=()
ARGS=()
for a in "$@"; do
    if [[ $a == --matching ]]; then MODE=(--matching); else ARGS+=("$a"); fi
done
set -- "${ARGS[@]+"${ARGS[@]}"}"
[[ -x .venv/bin/python && -x tools/cc/binutils-2.10-ee/bin/ld ]] || tools/setup.sh
[[ -f baserom/jp/sta.rom ]] || .venv/bin/python tools/extract_elf.py "$@"
[[ -d asm ]] || .venv/bin/python tools/split.py
.venv/bin/python tools/gen_ninja.py "${MODE[@]+"${MODE[@]}"}"
exec .venv/bin/ninja
