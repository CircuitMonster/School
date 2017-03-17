/*
Name: Brian Ackley
Date: 02-04-13
File: assignment2.cpp
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
  string encode(vector<char> message);	 // encodes a message consisting of A-Z

private:

  vector<string> codewords; // this is a codeword vector parallel to A-Z
  vector<char>alpha; // this is the vector for A-Z

  vector<char>alphacode(); // function builds the vector alpha - A B C etc.
  vector<string>morsecode(); // function builds the vector codewords containing morse code

  char decode(string c); //returns the character for the codeword c.
  string encode(char x); //returns the codeword for the character x

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

string Code::encode(vector<char> message1)
{
   string encoded = "";
   for (int i = 0; i < message1.size(); i++)
   {
      encoded += encode(message1[i]);
   }
   return encoded;
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
   return ' ';
}

string Code::encode(char x)
{
   for (int i = 0; i < codewords.size(); i++)
   {
      if (x==alpha[i])
      {
         return codewords[i];
      }
   }
   return " ";
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
   vector<string> message;	//creates a vector for message in the main function for decode
   vector<char> message1;	//creates a vector for message1 in the main function for encode
   string input;
   Code c;			//calls the code function
   cout << "Enter your message(s): ";
   cin >> input;

   //set for decoding
   while (cin.good())
   {
      message.push_back(input);	//adding the input string to the end of message
      cin >> input;		//reads in the input string
   }
   cout << c.decode(message) << endl;


   //set for encodeding
   for (int i = 0; i < input.length(); i++)
   {
      message1.push_back(input[i]);
   }

   cout << c.encode(message1) << endl;

}
