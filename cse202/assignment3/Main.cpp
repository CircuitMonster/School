/*
Name: Brian Ackley
Assignment 3
File: Main.cpp
Description: Main program, takes in the information for a person, adds them to a vector and then displays the information and of which class they are.
*/

#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "Faculty.h"
#include "Staff.h"
#include "StaffST.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Classify(Person* p)
{
   return p->whatami();
}

int main()
{

   vector<Person*> v;
   v.push_back(new Person("John Adams","Boston","617-555-0000","john@adams.com"));
   v.push_back(new Student("John Quincy Adams","Boston","617-555-0000","johnq@adams.com","senior"));
   v.push_back(new Staff("Samuel Adams","Boston","617-555-BEER","sam@adams.com","brewhouse 1","1000","9-15-1764","Brewer"));
   v.push_back(new StaffST("Samuel Smith","Boston","617-555-BEER","samsmith@adams.com","brewhouse 5","100","9-15-1774","Taster","junior", 500));

   v.push_back(new Faculty("John Smith", "Boston", "617-000-5555","johnsmith@adams.com", "brewhouse 7", "700", "12-12-1812", "Inspector", "Full-Time"));

   for (int i=0; i<v.size(); i++)
     {
       cout << v[i]->getName() << "  " << Classify(v[i]) << endl;
     }

   return 1;
}
