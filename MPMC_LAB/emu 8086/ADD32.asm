;=============================================================	(0)
;                    PROGRAM DESCRIPTION
;=============================================================
; CSL 331: SS&MP LAB		  	 CSE-BATCH1-CET-2024
;=============================================================
; EXP.No. 		: 02 
; DATE			: 23-09-2024
; PROGRAM NAME		: ADDITION OF TWO 32 BIT NUMBERS
;=============================================================
; DESCRIPTION		: USING MEMORY MODEL
; AUTHOR      		: LIYAN C K M
; SEGMENT DEFINITION	: [IMPLICIT]   
;=============================================================	(1)

.MODEL SMALL       	; Use the SMALL memory model (separate code, data, stack)
.STACK 100H        	; Define a 256-byte stack segment    

;=============================================================	(2)

.DATA               	; Start of the data segment
 
 NUM1 DD 12345678H
 NUM2 DD 9ABCDEF0H
 RESULT DD ?
 CARRYFLAG DD 0

;=============================================================	(3)

.CODE               	; Start of the code segment

START:
MOV AX,@DATA
MOV DS,AX
MOV AX,WORD PTR NUM1
ADD AX,WORD PTR NUM2
MOV WORD PTR RESULT,AX 
MOV AX,WORD PTR NUM1+2
ADC AX,WORD PTR NUM2+2
MOV WORD PTR RESULT+2,AX
JC CARRY_OCCURED
MOV CARRYFLAG,0
JMP DONE

CARRY_OCCURED:
MOV CARRYFLAG,1
DONE:
MOV AH,4CH
INT 21H

END START                     


;=============================================================	(4)
