.equ print, 0x6b
.equ prchr, 0x0
.equ exit, 0x11
mov r0, #1
mov r4, #0
mov r2, #20
mov r3, #0

loop:
cmp r2,r0
beq lalala
mov r1, r3
swi print
add r3, r3, r0
swi prchr
add r0, r0, #1
b loop

lalala:
swi exit
