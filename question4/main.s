        PRESERVE8
        TTL TEXT
        GLOBAL main
        AREA MYDATA, DATA, READWRITE
        ALIGN

STRING  DCB "Rohan Lambture", 0   

        AREA MYCODE, CODE, READONLY

main
        LDR R2, =STRING 
        MOV R3, R2       

find_length
        LDRB R4, [R3], #1  
        CMP R4, #0         
        BNE find_length    

        SUB R4, R3, R2     
        SUB R4, R4, #1     

        MOV R3, #0         
        SUB R5, R4, #1     
        MOV R8, #1         

loop
        CMP R3, R5         ; If left index >= right index, exit
        BGE end

        LDRB R6, [R2, R3]  ; Load character from left
        LDRB R7, [R2, R5]  ; Load character from right

        CMP R6, R7         ; Compare characters
        BNE not_palindrome ; If not equal, set flag to 0

        ADD R3, R3, #1     
        SUB R5, R5, #1     
        B loop             

not_palindrome
        MOV R8, #0         ; Not a palindrome

end
        BX LR              
        END

