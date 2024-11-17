;=============================================================	(0)
;                    PROGRAM DESCRIPTION
;=============================================================
; CSL 331: SS&MP LAB		  	 CSE-BATCH1-CET-2024
;=============================================================
; EXP.No. 		: 07
; DATE			: 27-09-2024
; PROGRAM NAME		:  COMPARISON OF TWO STRINGS
;=============================================================
; DESCRIPTION		: USING MEMORY MODEL
; AUTHOR      		: LIYAN C K M
; SEGMENT DEFINITION	: [IMPLICIT]   
;=============================================================	(1)

.MODEL SMALL       	; Use the SMALL memory model (separate code, data, stack)
.STACK 100H        	; Define a 256-byte stack segment    

;=============================================================	(2)
.DATA               	; Start of the data segment

 STR1 DB 'HELLO',0
 STR2 DB 'WORLD',0
 EQUALMSG DB 'STRINGS ARE EQUAL$'
 NOTEQUALMSG DB 'STRINGS ARE NOT EQUAL$'

     
;=============================================================	(3)


.CODE               	; Start of the code segment

  START:
  MOV AX,@DATA
  MOV DS,AX
  LEA SI,STR1
  LEA DI,STR2
  COMPARE_LOOP:
  LODSB
  CMP AL,[DI]
  JNE NOTEQUAL
  CMP AL,0
  JE EQUAL
  INC DI
  JMP COMPARE_LOOP
  EQUAL:
  MOV DX,OFFSET EQUALMSG
  MOV AH,09H
  INT 21H
  JMP EXIT
  NOTEQUAL:
  MOV DX,OFFSET NOTEQUALMSG
  MOV AH,09H
  INT 21H
  EXIT:
  MOV AX,4C00H
  INT 21H
  END START


;=============================================================	(4)

