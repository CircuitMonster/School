/*
Name: Brian Ackley
Assignment 3
File: Person.cpp
Description: Functions for the Person class
*/

#include "Person.h"
#include <string>
using namespace std;

Person::Person()
{
   name = "N/A";
   address = "N/A";
   telephone = "N/A";
   email = "N/A";
}

Person::Person(string n, string addr, string tele, string mail)
{
   name = n;
   address = addr;
   telephone = tele;
   email = mail;
}

string Person::getName()
{
   return name;
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

string Person::whatami()
{
   return "Person";
}
