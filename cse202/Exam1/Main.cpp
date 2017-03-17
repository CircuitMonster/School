/*
Name: Brian Ackley
Date: 2-21-13
File: Main.cpp
Exam 1 Extra Credit
Description: Main program takes in the user input and then stores it into the mailbox inbox
*/
#include "Email.h"
#include "Mailbox.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
   string sender;
   string recipient;
   string subject;
   string message;

   cout << "Sender: ";
   cin >> sender;
   cout << "Recipient: ";
   cin >> recipient;
   cout << "Subject: ";
   cin >> subject;
   cout << "Message: ";
   cin >> message;

   Email letter(sender, recipient, subject, message);

   Mailbox inbox;

   inbox.addmessage(letter);

   if(inbox.getmessage(0).getText() == letter.getText())
   {
      cout << "Program test works" << endl;
   }
}
