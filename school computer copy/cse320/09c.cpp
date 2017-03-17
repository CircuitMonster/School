#include <iostream>
using namespace std;
int main()
{
 int i,j;
 cout <<"Enter value i="; cin >> i;
 cout <<"Enter value j="; cin >> j;
 cout << "(i>j ? i : j)" << " = " << (i>j ? i : j) << endl; 
 cout << "(i>j ? j : i)" << " = " << (i>j ? j : i) << endl; 
 return 0;
}

