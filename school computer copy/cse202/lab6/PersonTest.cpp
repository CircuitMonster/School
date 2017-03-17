/*
Name: Brian Ackley
Date: 2-14-13
File: PersonTest.cpp
Lab # 6
Description: This file combines the Person and Location class libraries and uses them to get the person's first name, last name, company name, location address, location building, and location room #.
*/

#include "Person.h"
#include "Location.h"
#include <iostream>
#include <string>
using namespace std;
    
int main()
{
   Person t("Bill", "Gates", "Microsoft");
   Location r("123 Fake st.", "Building #50", "Room 501");
    
   cout << t.getName() << endl;
   cout << t.getCompany() << endl;

   cout << r.getLocationAddress() << endl;
   cout << r.getLocationBuilding() << endl;
   cout << r.getLocationRoom() << endl;
}
