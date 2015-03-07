.equ print, 0x6b
.equ prchr, 0x0
.equ exit, 0x11

mov r0,#1 @init
mov r1,#1 
mov r2,#0 @counter
mov r3,#20 @limit
mov r4,#1 @one
mov r5,#1 @temp
mov r6,#0 @a
loop:
	cmp r2, r3
	beq case1
	and r5, r4,r2
	cmp r5,r4
	beq case21
	cmp r2,#10
	bgt case21
	blt case22
	add r6,r6, r6
	mov r1,r6
	swi print
	swi prchr
	add r2,r2,#1
b loop
case1:
	swi exit
case21:
	add r6,r6,r2
	add r2,r2,#1
	mov r1,r6
	swi print
	swi prchr
	b loop