        PRESERVE8
		TTL TEXT
		GLOBAL main
		AREA MYCODE, CODE, READONLY

main
        MOV R2, #10      ; First number
        MOV R3, #15      ; Second number

        CMP R2, R3        
        BGT greater_R0    

        MOV R4, R3        ; Storing greater value in R4 (R3 is greater)
        B end    

greater_R0
        MOV R4, R2        ; Storing greater value in R2 (R2 is greater)

end
        ;end of the program 


