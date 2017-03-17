/*
Name: Brian Ackley
Date: 2-21-13
File: Email.h
Exam 1 Extra Credit
Description: This file contains the interface for the Email Class
*/

#ifndef EMAIL_H
#define EMAIL_H
#include <string>
using namespace std;

class Email
{
public:
   Email();
   Email(string s, string r, string j, string t);
   void addText(string newtext);
   string getSender();
   string getRecipient();
   string getSubject();
   string getText();

private:
   string sender;
   string recipient;
   string subject;
   string text;
};
#endif
