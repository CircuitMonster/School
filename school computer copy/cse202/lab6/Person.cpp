/*
Name: Brian Ackley
Date: 2-14-13
File: Person.cpp
Lab # 6
Description: This file contains the function for the Person class.
*/

#include "Person.h"
#include <string>
using namespace std;

Person::Person()
{
   firstname = "";
   lastname = "";
   company = "";
}

Person::Person(string fname, string lname, string cname)
{
   firstname = fname;
   lastname = lname;
   company = cname;
}

string Person::getFirstName()
{
   return firstname;
}

string Person::getName()
{
   return firstname + " " + lastname;
}

string Person::getLastName()
{
   return lastname;
}

string Person::getCompany()
{
   return company;
}
