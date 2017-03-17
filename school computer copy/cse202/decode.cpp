/*
Name: Brian Ackley
Date: 02-04-13
File: decode.cpp
Lab: #4
Description: Program takes in a string (morsecode) and then decodes the message into a character string  			(alpha)/alphabet. Program does this by going through the parelle vectors and 			then comparing the index's of them. 
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Code
{
public:
  
  Code();  // Default constructor - loads and uses morse code

  string decode(vector<string> message);  // decodes a message 

private:

  vector<string> codewords; // this is a codeword vector parallel to A-Z
  vector<char>alpha; // this is the vector for A-Z

  vector<char>alphacode(); // function builds the vector alpha - A B C etc.

  vector<string>morsecode(); // function builds the vector codewords containing morse code

  char decode(string c); //returns the character for the codeword c.

};

Code::Code()
{
   alpha=alphacode();
   codewords=morsecode();
}

string Code::decode(vector<string> message)
{
   string decoded = "";
   for (int i = 0; i < message.size(); i++)
   {
      decoded += decode(message[i]);	//decoded string is the decode of the message index
   }
   return decoded;
}

char Code::decode(string c)
{
   for (int i = 0; i < alpha.size(); i++)
   {
      if (c==codewords[i])	//compares string c with the index of codewords
      {
         return alpha[i];	//returns the corresponding alpha index
      }
   }
   return 0;
}

vector<string> Code::morsecode()	// This function returns a vector containing the morse code
{
   vector<string> temp(28);
   temp[0] =".-";
   temp[1] ="-...";
   temp[2] ="-.-.";
   temp[3] ="-..";
   temp[4] =".";
   temp[5] ="..-.";
   temp[6] ="--.";
   temp[7] ="....";
   temp[8] ="..";
   temp[9] =".---";
   temp[10] ="-.-";
   temp[11] =".-..";
   temp[12] ="--";
   temp[13] ="-.";
   temp[14] ="---";
   temp[15] =".--.";
   temp[16] ="--.--";
   temp[17] =".-.";
   temp[18] ="...";
   temp[19] ="-";
   temp[20] ="..-";
   temp[21] ="...-";
   temp[22] =".--";
   temp[23] ="-..-";
   temp[24] ="-.--";
   temp[25] ="--..";
   temp[26] =".......";
   temp[27] ="x";
   return temp;
}

vector<char> Code::alphacode()		// This returns a vector containing the alphabet a-z and " "
{
   vector<char> temp;
   for (char c='A'; c<='Z'; c++)
   temp.push_back(c);
   temp.push_back(' ');
   temp.push_back('.');
   return temp;
}


int main()
{
   vector<string> message;	//creates a vector for message in the main function
   string input;
   Code c;			//calls the code function
   cout << "Enter your message(s): ";
   cin >> input;

   while (cin.good())
   {
      message.push_back(input);	//adding the input string to the end of message
      cin >> input;		//reads in the input string
   }
   cout << c.decode(message) << endl;
}

