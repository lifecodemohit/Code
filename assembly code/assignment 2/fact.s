fact:
SUB sp, sp, 8 @ adjust stack for 2 items
STR lr, [sp, #4] @ save return address
STR r0, [sp, #0] @ save argument
CMP r0, 1 @ test for n < 1
BGE L1
MOV r0, #1 @ if so, result is 1
ADD sp, sp, 8 @ pop 2 items from stack
MOV pc, lr @ and return
L1: SUB r0, r0, #1 @ else decrement n
BL fact @ recursive call
MOV r12, r0 @ save the return register
LDR r0, [sp, #0] @ restore original n
LDR lr, [sp, #4] @ and return address
ADD sp, sp, 8 @ pop 2 items from stack
MUL r0, r0, r12 @ multiply to get result
MOV pc, lr @ and return