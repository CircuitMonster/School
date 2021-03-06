/*
Name: Brian Ackley
Date: 02-19-13
File: Person.cpp
Lab: #7
Description: File contains the functions for the Person Class
*/

#include "Person.h"
#include <string>
using namespace std;

Person::Person()
{
   firstname = "";
   lastname = "";
   address = "";
   telephone = "";
   email = "";
}

Person::Person(string fname, string lname, string addr, string tele, string mail)
{
   firstname = fname;
   lastname = lname;
   address = addr;
   telephone = tele;
   email = mail;
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

string Person::getAddress()
{
   return address;
}

string Person::getTelephone()
{
   return telephone;
}

string Person::getEmail()
{
   return email;
}
