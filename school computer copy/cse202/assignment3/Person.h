/*
Name: Brian Ackley
Assignment 3
File: Person.h
Description: the interface for the Person class
*/

#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
public:
   Person();
   Person(string n, string addr, string tele, string mail);
   string getName();
   string getAddress();
   string getTelephone();
   string getEmail();
   virtual string whatami();

private:
   string name;
   string address;
   string telephone;
   string email;
};
#endif
