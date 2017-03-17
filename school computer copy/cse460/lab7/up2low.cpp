//up2low.cpp
//convert from upper case to lower case
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main()
{

  string s;

  cout << "\nWaiting for input:";

  getline ( cin, s );
  char low[100];
  int len = s.length();
  for ( int i = 0; i < len; ++i )
    low[i] = tolower( s[i] );
  low[len] = 0;
  cout << "Lower case output: " << low << endl;
  return 0;
}

