/*
Name: Brian Ackley
Date: 2-21-13
File: Mailbox.cpp
Exam 1 Extra Credit
Description: This File contains all the functions for the Mailbox Class
*/
#include "Mailbox.h"
#include <string>
using namespace std;

Mailbox::Mailbox()
{
}

void Mailbox::addmessage(Email newmessage)
{
   messages.push_back(newmessage);
}

Email Mailbox::getmessage(int i)
{
   return messages[i];
}
