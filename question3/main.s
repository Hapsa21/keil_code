        PRESERVE8
        TTL TEXT
        GLOBAL main
        AREA MYDATA, DATA, READWRITE
        ALIGN

ARRAY   DCD 10, 15, 21, 33, 40   

        AREA MYCODE, CODE, READONLY
       
main
        LDR R2, =ARRAY      ; Load base address of the array
        MOV R3, #5          
        MOV R4, #7          
        MOV R5, #0          
        MOV R8, #0          ; Store the number divisible by 7 (0 means not found)

loop
        CMP R5, R3          ; If index >= size, exit
        BGE end            

        LDR R6, [R2, R5, LSL #2]  ; Load ARRAY[i] into R6

        SDIV R7, R6, R4      
        MLS  R7, R7, R4, R6  
        CMP R7, #0           
        BEQ found            ; If divisible, store the number and exit

        ADD R5, R5, #1       
        B loop               

found
        MOV R8, R6           ; Store the number that is divisible by 7

end
        BX LR                ; Return

        END


