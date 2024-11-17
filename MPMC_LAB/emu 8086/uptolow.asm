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
; AUTHOR      		: LIYAN C K M
; SEGMENT DEFINITION	: [IMPLICIT]   
;=============================================================	(1)

.MODEL SMALL       	; Use the SMALL memory model (separate code, data, stack)
.STACK 100H        	; Define a 256-byte stack segment    

;=============================================================	(2)

.DATA
inputString db 'HELLO WORLD$'  
outputString db 'Converted String: $'


;=============================================================	(3)


.CODE
START:
    mov ax, @data
    mov ds, ax

    mov ah, 09h                 
    lea dx, outputString        
    int 21h                     

    lea si, inputString        

convert_loop:
    mov al, [si]               
    cmp al, '$'                
    je done                    

    cmp al, 'A'                
    jb not_uppercase           
    cmp al, 'Z'                
    ja not_uppercase           

    add al, 32                 

not_uppercase:
    mov [si], al               
    inc si                     
    jmp convert_loop           

done:
    mov ah, 09h                
    lea dx, inputString        
    int 21h                    

    mov ah, 4Ch                
    int 21h                    
 END START
