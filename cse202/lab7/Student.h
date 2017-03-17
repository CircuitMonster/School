/*
Name: Brian Ackley
Date: 02-19-13
File: Student.h
Lab: #7
Description: The file contains the user interface for the Student Class
*/

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Person.h"
using namespace std;

class Student: public Person
{
public:
   Student(string fname, string lname, string addr, string tele, string mail, string stat);
   string getSStatus();	//freshman, sophomore, junior, or senior

private:
   string sstatus;
};
#endif
