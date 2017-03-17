/*
Name: Brian Ackley
Date: 02-12-13
File: lab5.cpp
Lab # 5
Description: This is the fixed version of the previous program which changes all of the character arrays to string arrays. The new string
	      arrays prevents buffer overflow and people from hacking into the system.
*/
#include <cassert>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

void get(string askfor, int numchars, string& input);	//the input gets the string& because its being used from user input.
void get_password(string name, string &pwd);	//pwd gets the string& because its dependent on the users input based on the name assigned to it.

int main()
{
    //  Change these character arrays to strings.

	string name; 
	string pwd; 
	string passwd; 
	cout << "Address of name =" <<  &name <<"\n";
	cout << "Address of pwd =" <<  &pwd <<"\n";
	cout << "Address of passwd =" <<  &passwd <<"\n";

	bool authenticated=false;
	while(! authenticated)
	{

                // input the name here 
		get("Name", 7, name);
                // get the password pwd for the name
		get_password(name, pwd);
               // input a password passwd
		get("Password", 7, passwd);
	 	// cout <<pwd<<" vs " <<passwd<<endl;
                // compare the two passwords
		authenticated = (pwd == passwd);

		if(!authenticated)
			cout << "Please try again\n";
	}
	cout << "Welcome "<<name<<"\n";

	//...
	return 0;
}
void get(string askfor, int numchars, string& input)
{
   // this inputs a chracter array from input ... change it to input a string
	cout << askfor<<"("<<numchars<<" characters): ";
	cin>>input;
	return;
}
void get_password(string name, string &pwd)
{
        // Yuch! This returns pwd depending on the variable name
        // Rewrite so it accepts a string name and returns a string

	if(name == "botting")
	{
	   pwd = "123456";
	}
        else if(name == "ernesto")
	{	
	   pwd = "765432";
        }
	else if(name == "tong")
	{
	   pwd = "234567";
	}
	else
	   pwd != "qwerty";	//changed the pwd = qwerty to "!=" so no outside user can get in without the right username and pwd.
	return;
}

