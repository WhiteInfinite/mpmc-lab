;=============================================================	(0)
;                    PROGRAM DESCRIPTION
;=============================================================
; CSL 331: SS&MP LAB		  	 CSE-BATCH1-CET-2024
;=============================================================
; EXP.No. 		: 05
; DATE			: 1-10-2024
; PROGRAM NAME		:  CHECK WHETHER A SUBSTRING IS PRESENT IN A GIVEN STRING
;=============================================================
; DESCRIPTION		: USING MEMORY MODEL
; AUTHOR      		: LIYAN C K M
; SEGMENT DEFINITION	: [IMPLICIT]   
;=============================================================	(1)

.MODEL SMALL       	; Use the SMALL memory model (separate code, data, stack)
.STACK 100H        	; Define a 256-byte stack segment    

;=============================================================	(2)

.DATA               	; Start of the data segment

MSG DB 'HELLOWORLD$',0
SUBSTRING DB 'ZEZ$',0
STRING_FOUND DB 'STRING FOUND$',0
NOT_FOUND DB 'STRING NOT FOUND$',0
     
;=============================================================	(3)


.CODE

   
START:
    MOV AX,@DATA
    MOV DS,AX
    MOV ES,AX
    LEA SI,MSG
    LEA DI,SUBSTRING
   
SEARCH: PUSH SI
        PUSH DI   
        
COMPARE: MOV AL,[SI]
         MOV BL,[DI]
         CMP BL,'$'
         JE FOUND
         CMP AL,BL
         JNE NOMATCH
         INC SI
         INC DI
         JMP COMPARE
      
NOMATCH: POP DI
         POP SI
         INC SI
         CMP BYTE PTR[SI],'$'
         JE NOTFOUND
         JMP SEARCH
         
FOUND:  MOV AH,09H
        MOV DX,OFFSET STRING_FOUND
        INT 21H
        JMP EXIT
        
NOTFOUND: LEA DX,NOT_FOUND
          MOV AH,09H
          INT 21H
          JMP EXIT
          
EXIT:   MOV AH,4CH
        INT 21H
                                                   
END START
;=============================================================	(4)
