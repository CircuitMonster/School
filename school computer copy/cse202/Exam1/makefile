#Name: Brian Ackley
#Date: 2-21-13
#File: makefile
#Exam 1 Extra Credit
#Description: This file contaions all the other files and compiles them within the file.(makefile)

Main: Email.o Mailbox.o Main.o
	g++ Main.o Email.o Mailbox.o -o Main
Main.o: Main.cpp
	g++ -c Main.cpp
Email.o: Email.cpp
	g++ -c Email.cpp
Mailbox.o: Mailbox.cpp
	g++ -c Mailbox.cpp

clean:
	rm *.o        
	rm Main
	rm *.~
