/*
Name: Brian Ackley
Date: 02-19-13
File: Student.cpp
Lab: #7
Description: The file contains the functions for the Student Class
*/

#include "Student.h"
#include <string>
using namespace std;

Student::Student(string fname, string lname, string addr, string tele, string mail, string stat): Person(fname, lname, addr, tele, mail)
{
   sstatus = stat;
}

string Student::getSStatus()
{
   return sstatus;
}
