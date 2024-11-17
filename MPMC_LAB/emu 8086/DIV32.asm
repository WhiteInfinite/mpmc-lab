;=============================================================	(0)
;                    PROGRAM DESCRIPTION
;=============================================================
; CSL 331: SS&MP LAB		  	 CSE-BATCH1-CET-2024
;=============================================================
; EXP.No. 		: 05
; DATE			: 23-09-2024
; PROGRAM NAME		: DIVISION OF 32 BIT NUMBER BY 16 BIT NUMBERS
;=============================================================
; DESCRIPTION		: USING MEMORY MODEL
; AUTHOR      		: LIYAN C K M
; SEGMENT DEFINITION	: [IMPLICIT]   
;=============================================================	(1)

.MODEL SMALL       	; Use the SMALL memory model (separate code, data, stack)
.STACK 100H        	; Define a 256-byte stack segment    

;=============================================================	(2)

.DATA               	; Start of the data segment
 
 DIVIDENDLOW DW 1234H
 DIVIDENDHIGH DW 5678H  
 DIVISOR DW 9564H
 QUOTIENT DW 0
 REMAINDER DW 0

;=============================================================	(3)

.CODE               	; Start of the code segment

START:
MOV AX,@DATA
MOV DS,AX
MOV AX,DIVIDENDLOW
MOV DX,DIVIDENDHIGH  
MOV BX,DIVISOR
DIV BX
MOV QUOTIENT,AX
MOV REMAINDER,DX

MOV AH,4CH
INT 21H

END START                     


;=============================================================	(4)
