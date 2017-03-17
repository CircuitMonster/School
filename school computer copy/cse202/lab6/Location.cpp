/*
Name: Brian Ackley
Date: 2-14-13
File: Location.cpp
Lab # 6
Description: This file contains the functions for the Location class.
*/

#include "Location.h"
#include <string>
using namespace std;

Location::Location()
{
   address = "";
   building = "";
   room = "";
}

Location::Location(string addr, string bldg, string rm)
{
   address = addr;
   building = bldg;
   room = rm;
}

string Location::getLocationAddress()
{
   return address;
}

string Location::getLocationBuilding()
{
   return building;
}

string Location::getLocationRoom()
{
   return room;
}
