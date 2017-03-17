/*
Name: Brian Ackley
CSE 330
Lab 6
*/

#include "Stack.h"
#include <iostream>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <string>

using namespace std;

bool is_palindrome(string);
int digit_to_int(char);
int do_op(char, int, int);
int postfix_calc(string);

int main()
{
   string palind;
   cout << endl;
   cout << "Enter string for palindrome test: ";
   cin >> palind;
   cout << endl;

   if (is_palindrome(palind))
      cout << palind << " is a palindrome" << endl << endl;
   else
      cout << palind << " is not a palindrome" << endl << endl;

  return 0;
}

bool is_palindrome(string pal)
{
   Stack<char> thestack;
   int len = pal.length();
   int k = 1;
   while (k <= len/2)
   {
      thestack.push(pal[k-1]);
      k++;
   }
   if (len%2 != 0)
      k++;

   char next;
   while (k <= len)
   {
      next = thestack.top();
      thestack.pop();

      if (next != pal[k-1])
         return false;
      k++;
   }
   return true;
}

int postfix_calc(string post)
{
  Stack<int> thestack;
  int operand1, operand2;

  for (int i = 0; i < post.length(); i++)
    {
      if (isdigit(post[i]))
	  thestack.push(digit_to_int(post[i]));		//having an error with this line!!!! =[
      else
	{
	  char op = post[i];
	  assert(op == '+' or op == '-' or op == '*' or op == '/');
	  operand2 = thestack.top();
	  thestack.pop();
//lab exercise 2: 
	  operand1 = thestack.top();
	  thestack.pop(); 
	  int res = do_op(post[i], operand1, operand2);
	  thestack.push(res);
	}
    }
  // find the final result on stack;
  // if all went well, this is the only item left on stack;
  // return the final result;

   
}

// converts digit '0' to '9' to integers 0 to 9
// this is the primitive way ... but it works;
int digit_to_int(char dig)
{
int num;
  if (dig == '0')
    { 
      num = 0;
    }
 else if (dig == '1')
    {
       num = 1;
    }
  else if (dig == '2')
    {
       num = 2;
    }
  else if (dig == '3')
    {
       num = 3;
    }
  else if (dig == '4')
    {
       num = 4;
    }
  else if (dig == '5')
    {
       num = 5;
    }
  else if (dig == '6')
    {
       num = 6;
    }
  else if (dig == '7')
    {
       num = 7;
    }
  else if (dig == '8')
    {
       num = 8;
    }
  else if (dig == '9')
    {
       num = 9;
    }

return num;
}

int do_op(char op, int x, int y)
{
  assert (op == '+' or op == '_' or op == '*' or op == '/');

  if (op == '+')
    return x + y;
  else if (op == '-')
    return x - y;
  else if (op == '*')
    return x * y;
  else if (op == '/')
    return x / y;
}
