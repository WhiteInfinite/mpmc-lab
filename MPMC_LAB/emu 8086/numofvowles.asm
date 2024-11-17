;=============================================================	(0)
;                    PROGRAM DESCRIPTION
;=============================================================
; CSL 331: SS&MP LAB		  	 CSE-BATCH1-CET-2024
;=============================================================
; EXP.No. 		: 05
; DATE			: 27-09-2024
; PROGRAM NAME		: COUNT THE NUMBER OF VOWELS
;=============================================================
; DESCRIPTION		: USING MEMORY MODEL
; AUTHOR      		: LIYAN C K M
; SEGMENT DEFINITION	: [IMPLICIT]   
;=============================================================	(1)

.MODEL SMALL       	; Use the SMALL memory model (separate code, data, stack)
.STACK 100H        	; Define a 256-byte stack segment    

;=============================================================	(2)

.DATA               	; Start of the data segment

 STR1 DB 'HELLO WORLD$'
 N DB 00
 CNT DB 0BH
     
;=============================================================	(3)


.CODE

   
START:
    MOV AX,DATA
    MOV DS,AX
   
    MOV CL,CNT
   
    LEA SI,STR1
   
UP: MOV AL,[SI]
   
    CMP AL,'A'
    JZ COUNT
   
    CMP AL,'E'
    JZ COUNT
   
    CMP AL,'I'
    JZ COUNT
   
    CMP AL,'O'
    JZ COUNT
   
    CMP AL,'U'
    JZ COUNT
               
    INC SI
    DEC CL
    JNZ UP
    JMP DISPLAY
   
COUNT:
    INC N
    INC SI
    DEC CL
    JNZ UP
    JMP DISPLAY
   
DISPLAY:
    MOV AH,4CH
    INT 21H

CODE ENDS
END START
;=============================================================	(4)
