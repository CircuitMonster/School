;Class: CSE313
;Instructor: Taline Georgiou
;Spring 2013
;Brian Ackley
;Lab #5: SUBROUTINES: MULTIPLICATION, DIVISION, MODULUS 
;Description:


	.ORIG x3000

	AND R0, R0, x0 	; X
	AND R1, R0, x0 	; Y
	AND R2, R0, x0 	; Z

	LDI R0, X 	;loads value of X into R0
	LDI R1, Y 	;loads value of Y into R1

JSR	MULT        	; jump to the multiplication subroutine
STI 	R2, MULT_XY 	; product XY is in R2

JSR 	DIV		; jump to the division and mod subroutine
	STI R0, DIV_XY
	STI R1, MOD_XY

HALT

X 	.FILL x3100 	;fills value of X into this address
Y 	.FILL x3101 	;fills value of Y into this address

MULT_XY .FILL x3102 	;fills product of X*Y into this address
DIV_XY 	.FILL x3103 	;fills quotient of X/Y into this address
MOD_XY 	.FILL x3104 	;fills mod X (mod Y) in this address


R0_SAVE .FILL x3105 	;fill value of R0_SAVE into this address
R1_SAVE .FILL x3106 	;fill value of R1_SAVE into this address
R2_SAVE .FILL x3107 	;fill value of R2_SAVE into this address
R3_SAVE .FILL x3108 	;fill value of R3_SAVE into this address
R4_SAVE .FILL x3109 	;fill value of R4_SAVE into this address

; R2 = R0 * R1
MULT
	; save registers
	STI R0, R0_SAVE ;store R0 into R0_SAVE
	STI R1, R1_SAVE ;store R1 into R1_SAVE
	STI R3, R3_SAVE ;store R3 into R3_SAVE

	AND R2, R2, x0 ; product = 0
	AND R3, R3, x0 ; clear sign
	ADD R3, R3, #1 ; sign = 1

	
	AND R0, R0, xFFFF ; if (x < 0)
	BRzp MULT_XPOS    
	
	NOT R0, R0     	; x = -x
	ADD R0, R0, #1 

	
	NOT R3, R3     	;sign = -sign
	ADD R3, R3, #1 
MULT_XPOS

	
	AND R1, R1, xFFFF ;		; if (y < 0)
	BRzp MULT_START_LOOP
	
	NOT R1, R1     			; y = -y
	ADD R1, R1, #1 

	
	NOT R3, R3     			;sign = -sign
	ADD R3, R3, #1 


MULT_START_LOOP
	AND R1, R1, xFFFF
	BRz MULT_END_LOOP
	ADD R2, R2, R0   		; product += x
	ADD R1, R1, #-1 		 ; y -= 1
	BR MULT_START_LOOP
MULT_END_LOOP

	AND R3, R3, xFFFF		; if ( sign < 0 )
	BRzp MULT_SAVE_END
	
	NOT R2, R2			; product = -product
	ADD R2, R2, #1
MULT_SAVE_END

	
	LDI R0, R0_SAVE 		; cleanup
	LDI R1, R1_SAVE 
	LDI R3, R3_SAVE 
RET


; R1 = R0/R1; R2 = valid (boolean)
DIV
	STI R3, R3_SAVE 
	STI R4, R4_SAVE 


	AND R3, R0, xFFFF 	; initial
	AND R4, R1, xFFFF 	; temp2 = y

	AND R0, R0, x0 		; quotient  = 0
	AND R1, R1, x0 		; remainder = 0
	AND R2, R2, x0 		; status    = 0

	
	AND R3, R3, xFFFF 	; if ( x != 0 )
	BRz DIV_END

	
	AND R4, R4, xFFFF 	; if ( y != 0 )
	BRz DIV_END			
	ADD R1, R3, #0 		; remainder starts as x

DIV_START_LOOP

			
	; To decrease register usage and mem lookup, status register 
	; used here as temporary.
	; if ( remainder >= Y )
 
	NOT R2, R4     
	ADD R2, R2, #1 
	ADD R2, R2, R1 		; remainder - y
	BRn DIV_END
	ADD R1, R2, x0 		; move quotient
	ADD R0, R0, #1 		; increment
	BR DIV_START_LOOP
	
DIV_END

	ADD R2, R2, #1 		; status = 1

	LDI R3, R3_SAVE
	LDI R4, R4_SAVE
RET


.END
