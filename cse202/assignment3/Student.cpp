/*
Name: Brian Ackley
Assignment 3
File: Student.cpp
Description: Functions for the Student class
*/

#include "Student.h"
#include <string>
using namespace std;

Student::Student()
{
   sstatus = "";
}

Student::Student(string n, string addr, string tele, string mail, string stat): Person(n, addr, tele, mail)
{
   sstatus = stat;
}

string Student::getSStatus()
{
   return sstatus;
}

string Student::whatami()
{
   return "Student";
}
