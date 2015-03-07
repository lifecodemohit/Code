.equ print, 0x6b
.equ prchr, 0x00
.equ exit, 0x11
mov r1,#10
mov r4,#1
loop:
mov r0,#1
mov r1,r4
swi print
mov r0,#'\n'
swi prchr
add r4,r4,#1
cmp r4,#11
beq lal
b loop

lal:
swi exit 