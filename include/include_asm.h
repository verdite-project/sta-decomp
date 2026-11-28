#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

/* INCLUDE_ASM(func_X); puts splat's retail asm of func_X (the asm/ chunk
 * whose first label it is) at this point of the unit's .text, for a
 * translation unit whose other functions are C.
 *
 * Game code is plain C (tools/compile_c.sh refuses inline asm), so this is
 * no asm block: it defines an empty marker function. CodeWarrior gives
 * every function a .text section of its own, in source order;
 * tools/include_asm.py (run by compile_c.sh) renames the marker's section
 * .text.iastub (discarded) and the sections after the Nth marker .text.iaN,
 * and tools/gen_ninja.py links unit(.text), chunk(.text), unit(.text.ia1),
 * ... The unit's data stays one object, so its data order is the retail
 * one; the asm function stays its own objdiff unit, unmatched. */
#ifdef __MWERKS__
#define INCLUDE_ASM(name) void __include_asm_##name(void) {}
#else
/* ee-gcc puts a unit's functions in one .text that cannot be split, so
 * there a marker must be the whole unit (tools/gen_ninja.py links the chunk
 * after its empty .text) and emits nothing. */
#define INCLUDE_ASM(name) extern int __include_asm_##name
#endif

#endif
