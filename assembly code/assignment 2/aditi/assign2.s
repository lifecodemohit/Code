.equ SWI_PrInt, 0x6b
.equ SWI_Exit, 0x11
.equ SWI_PrChr, 0x0

Main:
mov r2,#0
mov r3,#1
mov r1,r2
mov r0, #1
swi SWI_PrInt
mov r0, #'\n'
mov r1,r3
mov r0, #1
swi SWI_PrInt
mov r0, #'\n'
BL Fibo
mov r0, #1
swi SWI_PrInt
mov r0, #'\n'

Fibo:
mov r4,#1
SUB sp, sp, #12
STR r2,[sp,#8]
STR r3,[sp,#4]
STR r4,[sp,#0]
CMP r4,#20
BNE ELSE
mov r0, #1
swi SWI_PrInt
mov r0, #'\n'
ELSE:
ADD r4,r2,r3
mov r2,r3
mov r3,r4
mov r1,r4
mov r0, #1
swi SWI_PrInt
mov r0, #'\n'
swi SWI_PrChr
ADD r4,r4,#1
BL Fibo
MOV r12,r2
LDR r4,[sp,#0]
LDR r3,[sp,#4]
LDR r2,[sp,#8]
ADD sp,sp,#12
MOV pc,lr
swi SWI_Exit

