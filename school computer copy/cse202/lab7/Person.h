/*
Name: Brian Ackley
Date: 02-19-13
File: Person.h
Lab: #7
Description: File contains the interface for the Person Class
*/

#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
public:
   Person();
   Person(string fname, string lname, string addr, string tele, string mail);
   string getFirstName();
   string getName();
   string getLastName();
   string getAddress();
   string getTelephone();
   string getEmail();

private:
   string firstname;
   string lastname;
   string address;
   string telephone;
   string email;
};
#endif
