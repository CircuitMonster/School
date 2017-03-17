/*
Name: Brian Ackley
Assignment 3
File: Staff.cpp
Description: functions for the Staff class
*/

#include "Staff.h"
#include <string>
using namespace std;

Staff::Staff()
{
   jobtitle = "";
}

Staff::Staff(string n, string addr, string tele, string mail, string offc, string slry, string hdate, string title)
: Person(n, addr, tele, mail), Employee(n, addr, tele, mail, offc, slry, hdate)
{
   jobtitle = title;
}

string Staff::getJobtitle()
{
   return jobtitle;
}

string Staff::whatami()
{
   return "Staff";
}