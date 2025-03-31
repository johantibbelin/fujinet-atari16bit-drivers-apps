xref low2mid

low2mid:
	movem.l d2-d7/a2-a6,-(sp)

	move.w #19,d0
	move.w #199,d1

line:
word:
	move.w (a0)+,d2
	move.w (a0)+,d3
	add.l #4,a0
	move.w #15,d4
	clr.l d5
	clr.l d6
bits:
	lsl.l #2,d5
	btst.l d4,d2
	bne one1
	ori.b #%00,d5
	bra done1
one1:
	ori.b #%11,d5
done1:
	
	lsl.l #2,d6
	btst.l d4,d3
	bne one2
	ori.b #%00,d6
	bra done2
one2:
	ori.b #%11,d6
done2:
	
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
	move.w #19,d0
	dbra d1,line

	movem.l (sp)+,d2-d7/a2-a6
	rts