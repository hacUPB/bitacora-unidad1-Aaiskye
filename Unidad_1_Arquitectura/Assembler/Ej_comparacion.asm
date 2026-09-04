// Comparar RAM[5] con 10

@5
D=M         

@10
D=D-A        

@MENOR
D;JLT        

// Caso: RAM[5] >= 10
@7
M=0          

@FIN
0;JMP       

// Caso: RAM[5] < 10
(MENOR)
@7
M=1         

(FIN)
@FIN
0;JMP