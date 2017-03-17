;Description: Perform eight different logic operations given a specific input. Including addition, AND logic, OR logic, and NOT.


	
	
	.ORIG x3000
	
	LEA R2, xFF    ;R2 = x3100
	LDR R1, R2, x0 ;R1 = M[x3100]
	LDR R3, R2, x1 ;R3 = M[x3100+1]
 

	;X+Y
 
	ADD R4, R1, R3 ;R4 = R1 + R3
	STR R4, R2, x2 ;x3102 = R4

	;X AND Y
 
	AND R4, R1, R3 ; R4 = R1 AND R3
	STR R4, R2, x3 ; X3103 = R4

	;X OR Y
 
	NOT R5, R1 ; R5 = NOT X
	NOT R6, R3 ; R6 = NOT Y
	AND R4, R5, R6 ; R4 = (X.Y)
	NOT R4, R4     ; R4 = (X.Y) = X+Y
	STR R4, R2, x4 ; x3104 = X OR Y

	;NOT X

	NOT R4, R1 ; R4 = NOT(X)
	STR R4, R2, x5 ; x3105 = NOT(X)

	;NOT Y

	NOT R4, R3 ; R4 = NOT(Y)
	STR R4, R2, x6; x3106 = NOT(Y)

	;X+3
	
	ADD R4, R1, x3 ;R4 = X+3
	STR R4, R2, x7 ;x3107 = X+3

	;Y-3

	ADD R4, R3, X-3 ;R4 = Y-3
	STR R4, R2, x8  ;x3108 = Y-3

	; X EVEN or ODD
	
	AND R4, R1, x0001  ;R4 = X 
	STR R4, R2, x9     ;x3109

	HALT

	.END