/*
Name: Brian Ackley
Assignment 3
File: Employee.cpp
Description: Functions for employee class
*/
#include "Employee.h"
#include <string>
using namespace std;

Employee::Employee()
{
   office = "";
   salary = "";
   hire_date = "";
}

Employee::Employee(string n, string addr, string tele, string mail, string offc, string slry, string hdate): Person(n, addr, tele, mail)
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

string Employee::whatami()
{
   return "Employee";
}
