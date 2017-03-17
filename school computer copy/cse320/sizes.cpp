/*** size of some C++ data types ***/

/*** WARNING: this program has one statement that must be removed ***/

/* kelly and pohl 2nd ed. pg. 98 modified by karant, from K&R C by dick */
/* Apr 19th 2004 modified to C++ by dick*/
/* Jan 31st 2007 Updated to ANSI C++ by dick*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

main()
{
  // some fundamental types
	cout <<"Fundamental Types\n";
	cout <<"    Type  " << "Size \n";
	cout <<"    char: " << sizeof(char) << " bytes.\n";
	cout <<"   short: " << sizeof(short) << " bytes.\n";
	cout <<"     int: " << sizeof(int) << " bytes.\n";
	cout <<"    long: " << sizeof(long) << " bytes.\n";
	cout <<"unsigned: " << sizeof(unsigned) << " bytes.\n";
	cout <<"   float: " << sizeof(float) << " bytes.\n";
	cout <<"  double: " << sizeof(double) << " bytes.\n";
	cout <<"l double: " << sizeof(long double) << " bytes.\n";
	cout <<"    bool: " << sizeof(bool) << " bytes.\n";
	//cout <<"    void: " << sizeof(void) << " bytes.\n";
  //pointer types
	cout <<"Pointers\n";
	cout <<"   char*: " << sizeof(char*) << " bytes.\n";
	cout <<"   long*: " << sizeof(long*) << " bytes.\n";
	cout <<"   void*: " << sizeof(void*) << " bytes.\n";
  // strings
	cout <<"strings?\n";
	cout <<"   \"123\": " << sizeof("123") << " bytes.\n";
	cout <<"     \"1\": " << sizeof("1") << " bytes.\n";
	string s; s="123";
	cout <<" s=\"123\": " << sizeof(s) << " bytes.\n";
	s="1";
	cout <<"   s=\"1\": " << sizeof(s) << " bytes.\n";
  // array types
	cout <<"arrays\n";
	char a[10];
	cout <<"   a(10): " << sizeof(a) << " bytes.\n";
	char a2[100];
	cout <<" a2(100): " << sizeof(a2) << " bytes.\n";
  // STL vectors
	cout <<"STL vectors\n";
	vector<char> v(10);
	cout <<"   v(10): " << sizeof(v) << " bytes.\n";
	vector<char> v2(100);
	cout <<" v2(100): " << sizeof(v2) << " bytes.\n";
}

