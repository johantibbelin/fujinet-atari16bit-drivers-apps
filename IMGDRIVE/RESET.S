*
*
* reset.s - resets computer

XREF reset

reset:
	pea reset_st
	move.w #$26,-(sp) ;Gemdos - Superexec
	trap #14
reset_st:
	move.l 4.w,-(sp) ; OS start to stack
	rts
