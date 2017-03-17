/*
Name: Brian Ackley
Date: 02-19-13
File: Employee.h
Lab: #7
Description: File contains the interfeace for the Employee Class
*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "Person.h"
using namespace std;

class Employee: public Person
{
public:
   Employee(string fname, string lname, string addr, string tele, string mail, string offc, string slry, string hdate);
   string getOffice();
   string getSalary();
   string getHiredate();

private:
   string office;
   string salary;
   string hire_date;
};
#endif