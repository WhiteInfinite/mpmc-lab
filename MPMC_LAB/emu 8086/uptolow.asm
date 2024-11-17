;=============================================================	(0)
;                    PROGRAM DESCRIPTION
;=============================================================
; CSL 331: SS&MP LAB		  	 CSE-BATCH1-CET-2024
;=============================================================
; EXP.No. 		: 05
; DATE			: 27-09-2024
; PROGRAM NAME		: UPPER TO LOWER
;=============================================================
; DESCRIPTION		: USING MEMORY MODEL
; AUTHOR      		: ANANTHAKRISHNAN K
; SEGMENT DEFINITION	: [IMPLICIT]   
;=============================================================	(1)

.MODEL SMALL       	; Use the SMALL memory model (separate code, data, stack)
.STACK 100H        	; Define a 256-byte stack segment    

;=============================================================	(2)

.DATA               	; Start of the data segment

INPUT DB 'HELLO WORLD$','$'
VOWEL DB 'AEIOUaeiou$','$'
VOWEL_COUNT DW 0
     
;=============================================================	(3)


.CODE

START:

    MOV AX, @DATA       ; Initialize the data segment

    MOV DS, AX

    MOV ES, AX

    

    LEA SI, INPUT       ; Load the address of the INPUT string into SI

    MOV CX, 0           ; Initialize the vowel counter to 0


NEXT_CHAR:

    LODSB               ; Load the next character from INPUT (DS:SI) into AL

    CMP AL, '$'         ; Check if end of string

    JE END_PROGRAM      ; If end of string, exit


    PUSH AX             ; Save the current character (AL) on the stack

    LEA DI, VOWEL      ; Load the address of the VOWELS string into DI


CHECK_VOWEL:

    LODSB               ; Load the next vowel from VOWELS (DS:DI) into AL

    CMP AL, '$'         ; Check if end of the vowels list

    JE NOT_VOWEL        ; If no match, exit vowel check


    POP BX              ; Restore the saved character into BX

    CMP BL, AL          ; Compare the character from INPUT with the current vowel

    JE IS_VOWEL         ; If they are equal, it's a vowel


    PUSH BX             ; Save the input character again for the next vowel check

    JMP CHECK_VOWEL     ; Continue checking the next vowel


IS_VOWEL:

    INC CX              ; Increment vowel count

    JMP NEXT_ITERATION  ; Go to the next character in INPUT


NOT_VOWEL:

    POP BX              ; Remove the input character from the stack


NEXT_ITERATION:

    JMP NEXT_CHAR       ; Continue with the next character in INPUT


END_PROGRAM:

    MOV VOWEL_COUNT, CX ; Store the final vowel count


    MOV AH, 4CH         ; Terminate the program

    INT 21H


END START
;=============================================================	(4)

