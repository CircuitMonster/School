;Class: CSE313
;Instructor: Taline Georgiou
;Spring 2013
;Brian Ackley
;Lab #7: COMPUTE DAY OF THE WEEK 
;Description:

	.ORIG x3000

	;loops for displaying day

	RESTART	LEA R0, PROMPT 	; loads the prompt stated below
	PUTS		; outputs promt statement
	GETC		; gets input, places ASCII value into R0
	ADD R3, R0, x0	 ; copies R0 into R3
	ADD R3, R3, #-16 ; subtract 48 from the ASCII vaue of 0
	ADD R3, R3, #-16
	ADD R3, R3, #-16 ; R3 now contains the actual value

	ADD R4, R3, #-6
	BRp invalid
	
	LEA R0, DAYS	 ; Loads address of Sunday R0
	
LOOP 	BRz DISPLAY	 
	ADD R0 , R0 , #10 ; go to next day
	ADD R3 , R3 , #-1 ; decrement by 1 until zero
	BR LOOP
DISPLAY	PUTS		  ; outputs day
	BR RESTART	  ;goes to line tagged with RESTART to restart the program
invalid	HALT


DAYS	.STRINGZ "Sunday   "
	.STRINGZ "Monday   "
	.STRINGZ "Tuesday  "
	.STRINGZ "Wednesday"
	.STRINGZ "Thursday "
	.STRINGZ "Friday   "
	.STRINGZ "Saturday "


MULT

	
	RET


DIV



	RET
	.END