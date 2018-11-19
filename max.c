max <- numero da input
while ci sono ancora numeri do
	x<- numeri da input 
	if x>max THEN max <- x
scrivi max

 R1 <- numero da input
%if numeri sono finiti THE salta alla fine
	R2 <- numero da input
	if R2<= R1 THEN salta a % 
	R1 <- R2
	salta %
fine: scrivi R1
////////////////////////////
		READ 1			//inizializzazione
%:		JBLANK fine
		READ 2
		LOAD 1
		SUB 2
		JGTZ %
		JZERO %
		LOAD 2
		STOR 1
		JUMP %
fine:	WRITE 1			//return
		HALT
		
[Tempo O(n)	]
[spazio O(1)]

//**********************************************

input n € N
output f(n) = n^n se n>= 1, 1 altrimenti

leggi n
risultato <- 1
for i <- n downto 1 do:
	risultato <- risultato*n
scrivi risultato

[n<->R1			]
[risultato <->R2]
[i<-> R3		]

R1 <- numero da input
R2 <- 1
R3 <- R1
while R3 > 0:
	R2 <- R2*R1
	R3 <- R3 -1
scrivi R2

/////////////////////////////
	
		READ 1
		LOAD = 1
		STORE 2
		LOAD 1
		STORE 3
inizio:	JZERO fine
		LOAD 2
		MULT 1
		STORE 2
		LOAD 3
		SUB = 1
		STORE 3
		JUMP inizio
		
fine:	WRITE 2
		HALT




		