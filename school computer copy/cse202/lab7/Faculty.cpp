/*
Name: Brian Ackley
Date: 02-19-13
File: Faculty.cpp
Lab: #7
Description: File contains the functions for the Faculty Class
*/

#include "Faculty.h"
#include <string>
using namespace std;

Faculty::Faculty(string fname, string lname, string addr, string tele, string mail, string offc, string slry, string hdate, string rank, string stat): 
	Employee(fname, lname, addr, tele, mail, offc, slry, hdate)
{
   frank = rank;
   fstatus = stat;
}

string Faculty::getRank()
{
   return frank;
}

string Faculty::getFStatus()
{
   return fstatus;
}