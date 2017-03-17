/*
Name: Brian Ackley
Date: 2-21-13
File: Mailbox.h
Exam 1 Extra Credit
Description: This file contains the interface for the Mailbox Class
*/
#ifndef MAILBOX_H
#define MAILBOX_H
#include <string>
#include <vector>
#include "Email.h"
using namespace std;

class Mailbox
{
public:
   Mailbox();
   void addmessage(Email newmessage);
   Email getmessage(int i);
private:
   vector<Email> messages;
};
#endif
