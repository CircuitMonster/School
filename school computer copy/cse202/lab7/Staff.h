/*
Name: Brian Ackley
Date: 02-19-13
File: Staff.h
Lab: #7
Description: The file contains the user interface for the Staff class
*/

#ifndef STAFF_H
#define STAFF_H
#include <string>
#include "Employee.h"
using namespace std;

class Staff: public Employee
{
public: 
   Staff(string fname, string lname, string addr, string tele, string mail, string offc, string slry, string hdate, string title);
   string getJobtitle();

private:
   string jobtitle;
};
#endif
