/*
Name: Brian Ackley
Date: 02-19-13
File: Staff.cpp
Lab: #7
Description: File contains the functions for the Staff Class
*/

#include "Staff.h"
#include <string>
using namespace std;

Staff::Staff(string fname, string lname, string addr, string tele, string mail, string offc, string slry, string hdate, string title): 
	Employee(fname, lname, addr, tele, mail, offc, slry, hdate)
{
   jobtitle = title;
}

string Staff::getJobtitle()
{
   return jobtitle;
}
