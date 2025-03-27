xref low2mid

low2mid:
	movem.l d3-d7/a2-a6,-(sp)

	move.w #19,d0
	move.w #199,d1

line:
word:
	move.w (a0)+,d2
	move.w (a0)+,d3

	move.w #15,d4
	clr.l d5
	clr.l d6
bits:
	btst.l d4,d2
	beq one1
	ori.b #%00,d5
	bra done1
one1:
	ori.b #%11,d5
done1:
	lsl.l #2,d5

	btst.l d4,d3
	beq one2
	ori.b #%00,d6
	bra done2
one2:
	ori.b #%11,d6
done2:
	lsl.l #2,d6
	dbra d4,bits
;** copy planes
	
	swap d5
	swap d6
	move.w d5,(a1)+
	move.w d6,(a1)+
	swap d5
	swap d6
	move.w d5,(a1)+
	move.w d6,(a1)+	

	dbra d0,word
	dbra d1,line
