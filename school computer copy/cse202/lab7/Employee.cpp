/*
Name: Brian Ackley
Date: 02-19-13
File: Employee.cpp
Lab: #7
Description: File contains the functions for the Employee Class
*/

#include "Employee.h"
#include <string>
using namespace std;

Employee::Employee(string fname, string lname, string addr, string tele, string mail, string offc, string slry, string hdate): Person(fname, lname, addr, tele, mail)
{
   office = offc;
   salary = slry;
   hire_date = hdate;
}

string Employee::getOffice()
{
   return office;
}

string Employee::getSalary()
{
   return salary;
}

string Employee::getHiredate()
{
   return hire_date;
}
