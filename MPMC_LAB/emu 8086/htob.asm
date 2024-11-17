;=============================================================	(0)
;                    PROGRAM DESCRIPTION
;=============================================================
; CSL 331: SS&MP LAB		  	 CSE-BATCH1-CET-2024
;=============================================================
; EXP.No. 		: 05
; DATE			: 27-09-2024
; PROGRAM NAME		: HEXADECIMAL TO BCD
;=============================================================
; DESCRIPTION		: USING MEMORY MODEL
; AUTHOR      		: ANANTHAKRISHNAN K
; SEGMENT DEFINITION	: [IMPLICIT]   
;=============================================================	(1)

.MODEL SMALL       	; Use the SMALL memory model (separate code, data, stack)
.STACK 100H        	; Define a 256-byte stack segment    

;=============================================================	(2)

.DATA               	; Start of the data segment

HEX DB 19H
TENS DB ?
ONES DB ?
     
;=============================================================	(3)


.CODE

START:MOV AX,@DATA
      MOV DS,AX
      MOV AL,HEX
      MOV AH,00H
      MOV BL,0AH
      DIV BL
      MOV ONES,AH
      MOV TENS,AL
      JMP done
done:MOV AX,4C00H
     INT 21H
END START


;=============================================================	(4)

