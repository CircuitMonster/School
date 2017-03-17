/*
Name: Brian Ackley
Date: 2-21-13
File: Email.cpp
Exam 1 Extra Credit
Description: This file contains all the functions for the Email Class
*/
#include "Email.h"
#include <string>
using namespace std;

Email::Email()
{
   sender = "";
   recipient = "";
   subject = "";
   text = "";
}

Email::Email(string s, string r, string j, string t)
{
   sender = s;
   recipient = r;
   subject = j;
   text = t;
}

void Email::addText(string newtext)
{
   text += newtext;
}

string Email::getSender()
{
   return sender;
}

string Email::getRecipient()
{
   return recipient;
}

string Email::getSubject()
{
   return subject;
}

string Email::getText()
{
   return text;
}
