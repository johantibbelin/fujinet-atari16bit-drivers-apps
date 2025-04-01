*
*
* IMGRWABS.S - Routine for reading/writing sectors
*			   to disk image. Adds itself to TOS vector.
*
* Written by: Johan Tibbelin (sjfroos)
*
*			  For the Fujinet project.
*
* 	   Started: 2025-03-31
*
* Last changed: 2025-04-01
*
*

;** Labels to export
XDEF imgrwabs, setup_imgrwabs, remove_imgrwabs

;*** EQUs
hdv_bpb     = $472
hdv_rw      = $476
hdv_boot    = $47a
hdv_mediach = $47e
drvbits     = $4c2

imgrwabs:
	move.w  4(sp),d0
	cmp.w #1,d0
	beq cont
	jmp (old_rw)
cont:
	movem.l d3-d7/a2-a6,-(sp)
	
	movem.l (sp)+,d3-d7/a2-a6
	rts 

setup_imgrwabs:
	move.l a0,-(sp)
	move.l #0,-(sp)
	move.w #32,-(sp)
	trap #1
	addq.l #6,sp
	move.l d0,s_sp

	move.l hdv_bpb,old_bpb
	move.l hdv_rw, old_rw
	move.l hdv_mediach, old_mediach

	lea imgrwabs(pc),a0
	move.l a0,hdv_rw
	lea imgmediach(pc), a0
	move.l a0,hdv_mediach
	lea imgbpb(pc),a0
	move.l a0,hdv_bpb

	move.l s_sp,-(sp)
	move.w #32,-(sp)
	trap #1
	addq.l #6,sp

	move.l (sp)+,a0
	rts
remove_imgrwaps:
	move.l #0,-(sp)
	move.w #32,-(sp)
	trap #1
	addq.l #6,sp
	move.l d0,s_sp

	move.l old_rw, hdv_rw
	move.l old_bpb,hdv_bpb
	move.l old_mediach,hdv_mediach

	move.l s_sp,-(sp)
	move.w #32,-(sp)
	trap #1
	addq.l #6,sp
	rts

imgmediach:
	rts

imgbpb:
	rts

;*** Storage area

s_sp:	ds.l 1
old_rw:	ds.l 1
old_bpb:
		ds.l 1
old_boot:
		ds.l 1
old_mediach:
		ds.l 1

