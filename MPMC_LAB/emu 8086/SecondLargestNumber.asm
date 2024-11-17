;=============================================================	(0)
;                    PROGRAM DESCRIPTION
;=============================================================
; CSL 331: SS&MP LAB		  	 CSE-BATCH1-CET-2024
;=============================================================
; EXP.No. 		: 05
; DATE			: 1-10-2024
; PROGRAM NAME		: Second laegest Number
;=============================================================
; DESCRIPTION		: USING MEMORY MODEL
; AUTHOR      		: ANANTHAKRISHNAN K
; SEGMENT DEFINITION	: [IMPLICIT]   
;=============================================================	(1)

.MODEL SMALL       	; Use the SMALL memory model (separate code, data, stack)
.STACK 100H        	; Define a 256-byte stack segment    

;=============================================================	(2)

.DATA               	; Start of the data segment

STR1 DB 10H, 05H, 01H, 0AH, 04H  
NUM1 DB ?
SEC_LAR DB ?                        
CNT  DB 05 
     
;=============================================================	(3)


.CODE

START:
    MOV AX, DATA        
    MOV DS, AX          

    MOV CL, CNT        
OUTER_LOOP:
    DEC CL              ; Decrement CL for the outer loop counter
    LEA SI, STR1        ; Load the address of STR1 into SI

    ; If CL becomes 0, sorting is done
    JCXZ END_SORT       ; Jump to end if CL = 0 (array sorted)

    MOV CH, CL          ; Use CH as the inner loop counter (CH = CL)

INNER_LOOP:
    MOV AL, [SI]        ; Load current element into AL
    CMP AL, [SI+1]      ; Compare with the next element
    JBE NO_SWAP         ; If current element <= next element, no swap

    ; Perform swap
    MOV NUM1, AL        ; Store the value in NUM1 (temporary storage)
    MOV AL, [SI+1]      ; Move the value at [SI+1] into AL
    MOV [SI], AL        ; Move the value from AL to [SI]
    MOV AL, NUM1        ; Move the stored value from NUM1 to AL
    MOV [SI+1], AL      ; Move the value from AL to [SI+1]
   
NO_SWAP:
    INC SI              ; Move to the next pair of elements
    DEC CH              ; Decrement inner loop counter
    JNZ INNER_LOOP      ; Repeat inner loop until CH = 0

    ; After completing one outer loop iteration, CL is already decremented
    JMP OUTER_LOOP      ; Repeat outer loop until CL = 0

END_SORT:
    LEA SI,STR1
    MOV AL,[SI+3]
    MOV SEC_LAR,AL

    MOV AH, 4CH         ; DOS interrupt to terminate the program
    INT 21H

CODE ENDS
END START

 
	
