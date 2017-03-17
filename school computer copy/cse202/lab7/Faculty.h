/*
Name: Brian Ackley
Date: 02-19-13
File: Faculty.h
Lab: #7
Description: File contains the interface for the Faculty Class
*/

#ifndef FACULTY_H
#define FACULTY_H
#include <string>
#include "Employee.h"
using namespace std;

class Faculty: public Employee
{
public: 
   Faculty(string fname, string lname, string addr, string tele, string mail, string offc, string slry, string hdate, string rank, string stat);
   string getRank();	//professor, associate, assistant, lecturer
   string getFStatus();	//tenured, tenure-track, visiting, non-tenure-track

private:
   string frank;
   string fstatus;
};
#endif
