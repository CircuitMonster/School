/*
Name: Brian Ackley
Assignment 3
File: Employee.h
Description: interface for the employee class
*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "Person.h"
using namespace std;

class Employee: public virtual Person
{
public:
   Employee();
   Employee(string n, string addr, string tele, string mail, string offc, string slry, string hdate);
   string getOffice();
   string getSalary();
   string getHiredate();
   virtual string whatami();

private:
   string office;
   string salary;
   string hire_date;
};
#endif
