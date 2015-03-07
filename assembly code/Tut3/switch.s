.equ print, 0x6b
.equ prchr, 0x0
.equ exit, 0x11
mov r0,#1
mov r1,#0
mov r2,#0 @a
mov r3,#0 @x
mov r4,#0 @y
mov r5,#'u' @operations
mov r6,#'+' @operations
mov r7,#'-' @operations
mov r8,#'&' @operations
mov r9,#'*' @operations
cmp r5,r6


