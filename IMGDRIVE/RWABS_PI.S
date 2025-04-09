*
*
* rwabs_pi.s - position independent rwabs to put in HI-ram
*
* written by: Johan Tibbelin (sjfroos)
*
* started: 2025-04-09 last changed:2025-04-09
*
*
XDEF rwabs, enabled, drive

rwabs:	jmp rw1
enabled:
		ds.w $0000
drive:	dc.w $0000
changed:dc.w $0001

rw1:	lea enabled(pc),a0
		cmp #0,(a0)
		
		beq not_enabled
		move.w 14(sp),d0
		lea drive(pc),a0
		; Our drive?
		cmp.w d0,(a0)
		bne not_enabled ;No - call system rwabs
		bra rwabs1

not_enabled:
		lea sys_rwabs(pc),a0
		jmp (a0)

rwabs1:	
		move.w 12(sp),d0
		ext.l d0
		lsl.l #8,d0
		lsl.l #1,d0 ;Multiply by 512

		move.l 6(sp),a0
		move.w 10(sp),d1
		subq #1,d1
		lea rwabs(pc),a1
		add.l #$20000,a1 ;IMG location
		add.l d0,a1

		move.w 4(sp),d0 ; read-flag
		btst #0,d0 ;read?
		beq rloop0
		exg a0,a1 ; exange dest. and source

rloop0:
		move.l #511,d0
rloop:	move.b (a1)+,(a0)+
		dbra d0,rloop
		dbra d1,rloop0
		clr.l d0
		rts

;*** Media change

media:	move.w drive(pc),d0
		cmp.w d0,4(sp)
		beq media1 ;If our drive
		; if not jump to OS routine
		lea os_media(pc),a0
		jmp (a0)

media1:	lea changed(pc),a0
		move.w (a0),d0
		clr.w (a0)
		rts
	
sys_rwabs:
		ds.l 1