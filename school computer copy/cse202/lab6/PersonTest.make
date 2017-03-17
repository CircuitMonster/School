#name: Brian Ackley
#Date: 2-14-13
#Lab 6
#File Name: PersonTest.make

PersonTest: PersonTest.o Person.o Location.o
	g++ PersonTest.o Person.o Location.o -o PersonTest

Person.o: Person.cpp
	g++ -c Person.cpp

PersonTest.o: PersonTest.cpp
	g++ -c PersonTest.cpp

Location.o: Location.cpp
	g++ -c Location.cpp
