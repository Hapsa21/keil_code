        PRESERVE8
        TTL TEXT
        GLOBAL main
        AREA MYDATA, DATA, READWRITE
        ALIGN
            
ARRAY   DCD 45, 12, 89, 2, 34  

        AREA MYCODE, CODE, READONLY

main
        LDR R2, =ARRAY      
        MOV R3, #5          ; size of array
        LDR R4, [R2]        
        MOV R5, #1          

loop
        CMP R5, R3          ; Check if i < array size
        BGE end             ; If i >= size exit

        LDR R6, [R2, R5, LSL #2]  ; Load ARRAY[i] into R6
        CMP R6, R4                ; Compare with current minimum
        BLT update_min             ; If ARRAY[i] < min, update it

        B next_element

update_min
        MOV R4, R6          ; storing the minimum value in R4

next_element
        ADD R5, R5, #1      ; index++
        B loop             

end
        BX LR               

        END




