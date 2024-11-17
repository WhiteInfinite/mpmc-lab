;=============================================================	(0)
;                    PROGRAM DESCRIPTION
;=============================================================
; CSL 331: SS&MP LAB		  	 CSE-BATCH1-CET-2024
;=============================================================
; EXP.No. 		: 05
; DATE			: 23-09-2024
; PROGRAM NAME		: CONVERSION OF BCD NUMBER TO ITS HEXADECIMAL EQUIVALENT
;=============================================================
; DESCRIPTION		: USING MEMORY MODEL
; AUTHOR      		: LIYAN C K M
; SEGMENT DEFINITION	: [IMPLICIT]   
;=============================================================	(1)

.MODEL SMALL       	; Use the SMALL memory model (separate code, data, stack)
.STACK 100H        	; Define a 256-byte stack segment    

;=============================================================	(2)

.DATA               	; Start of the data segment

BCD_NUM DB 25H  ; number to be coverted 
HEX_NUM DB 0            ;result

;=============================================================	(3)

.CODE               	; Start of the code segment

START:	MOV AX, @DATA   ; Load the data segment address into AX
	MOV DS, AX      ; Initialize DS with the data segment address

	MOV AL, BCD_NUM     ; LOAD OP
	MOV DL,AL
	AND DL,0FH
	AND AL,0F0H
	MOV CL,4H
	ROR AL,CL
	MOV DH,0AH
	MUL DH
	ADD AL,DL
	MOV [HEX_NUM],AL 

	MOV AX, 4C00H   ; Terminate the program
	INT 21H         ; DOS interrupt to terminate the program

END START		; End of the program, specify the entry point

;=============================================================	(4)
