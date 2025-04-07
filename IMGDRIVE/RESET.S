*
*
* reset.s - resets computer

XREF reset

reset:
	move.l #0,-(sp)
	move.w #32,-(sp)
	trap #1

	move.l #$4f2,a0
	jmp (a0)
	rts