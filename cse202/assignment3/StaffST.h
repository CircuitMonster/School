/*
Name: Brian Ackley
Assignment 3
File: StaffST.h
Description: interface for the StaffSt class
*/

#ifndef STAFFST_H
#define STAFFST_H
#include <string>
#include "Staff.h"
#include "Student.h"
using namespace std;

class StaffST: public virtual Student, public virtual Staff
{
public: 
   StaffST();
   StaffST(string n, string addr, string tele, string mail, string offc, string slry, string hdate, string title, string stat, int chours);
   int getCredithours();
   virtual string whatami();

private:
   int credithours;
};
#endif
