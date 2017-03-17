/*
Name: Brian Ackley
Date: 02-19-13
File: Main.cpp
Lab: #7
Description: File contains the main program, which list a person and then gives there information determined on whether they are a student, employee, faculty, or staff.
*/

#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "Faculty.h"
#include "Staff.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
   Student a("Brian", "Ackley", "123 Fake St.", "909-777-5577", "B_Ackley@Email.com", "Junior");
   Employee b("Candace", "Lucas", "123 Fake St.", "909-555-7755", "C_Lucas@Email.com", "Jack Brown 387", "$56,000/yr", "August 27th, 2010");
   Faculty c("Josh", "Kulic", "123 Mockingbird Ln.", "909-749-4949", "J_Kulic@Email.com", "Jack Brown 377", "$43,000/yr", "July 25th, 2008", "Professor",
		 "Tenured");
   Staff d("Doug", "Funny", "666 Nick St.", "909-777-6666", "D_Funny@Email.com", "University Hall 104", "$12,000/yr", "April 19th, 2010", 
		"Administrative Assistant");

   //Student test person (person a)
   cout << a.getName() << endl;
   cout << a.getAddress() << endl;
   cout << a.getTelephone() << endl;
   cout << a.getEmail() << endl;
   cout << a.getSStatus() << endl << endl;

  //Employee test person (person b)
   cout << b.getName() << endl;
   cout << b.getAddress() << endl;
   cout << b.getTelephone() << endl;
   cout << b.getEmail() << endl;
   cout << b.getOffice() << endl;
   cout << b.getSalary() << endl;
   cout << b.getHiredate() << endl << endl;

   //Faculty test person (person c)
   cout << c.getName() << endl;
   cout << c.getAddress() << endl;
   cout << c.getTelephone() << endl;
   cout << c.getEmail() << endl;
   cout << b.getOffice() << endl;
   cout << b.getSalary() << endl;
   cout << b.getHiredate() << endl;
   cout << c.getRank() << endl;
   cout << c.getFStatus() << endl << endl;

   //Staff test person (person d)
   cout << d.getName() << endl;
   cout << d.getAddress() << endl;
   cout << d.getTelephone() << endl;
   cout << d.getEmail() << endl;
   cout << b.getOffice() << endl;
   cout << b.getSalary() << endl;
   cout << b.getHiredate() << endl;
   cout << d.getJobtitle() <<endl << endl;
}
