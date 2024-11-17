;=============================================================	(0)
;                    PROGRAM DESCRIPTION
;=============================================================
; CSL 331: SS&MP LAB		  	 CSE-BATCH1-CET-2024
;=============================================================
; EXP.No. 		: 01 
; DATE			: 23-09-2024
; PROGRAM NAME		: ADDITION OF TWO 16 BIT NUMBERS
;=============================================================
; DESCRIPTION		: USING MEMORY MODEL
; AUTHOR      		: ANANTHAKRISHNAN K
; SEGMENT DEFINITION	: [IMPLICIT]   
;=============================================================	(1)

.MODEL SMALL       	; Use the SMALL memory model (separate code, data, stack)
.STACK 100H        	; Define a 256-byte stack segment    

;=============================================================	(2)

.DATA               	; Start of the data segment
 
 NUM1 DW 1234H
 NUM2 DW 5678H
 RESULT DW ?
 CARRYFLAG DW 0

;=============================================================	(3)

.CODE               	; Start of the code segment

START:
MOV AX,@DATA
MOV DS,AX
MOV AX,NUM1
ADD AX,NUM2
MOV RESULT,AX
JC CARRY_OCCURED
MOV CARRYFLAG,0
JMP DONE

CARRY_OCCURED:
MOV CARRYFLAG,1
DONE:
MOV RESULT,AX 

MOV AH,4CH
INT 21H

END START                     


;=============================================================	(4)