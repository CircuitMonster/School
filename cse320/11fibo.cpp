/* A Faster recursive Fibonaci function*/
/* Use a formula from Knuth Vol 1 page 80, section 1.2.8:
	   If F[n] is the n'th Fibonaci number then
		   F[n+m] = F[m]*F[n+1] + F[m-1]*F[n].
  First set m = n+1
   F[ 2*n+1 ] = F[n+1]**2 + F[n]*2.

  Then put m = n,
	   F[ 2*n ] = F[n]*F[n+1] + F[n-1]* F[n],
   and replace F[n+1] by F[n]+F[n-1],
	   F[ 2*n ] = F[n]*(F[n] + 2*F[n-1]).
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

/*GLOBAL*/  long fib_count;

long fibo(int n)
{
   cerr << "			fibo(" << n << ") called\n";
   fib_count = fib_count + 1; //count each call

   if(n==0){
	cerr << "                    fibo returned " << 0 << "\n" ;
	return 0;
   }
   else if( n <= 2 )
   {
	cerr << "                    fibo returned " << 1 << "\n" ;
 	return 1;
   }
   else if( n%2 == 0 ) // n is even
   {
      const int half = n/2;
      const long f1 = fibo(half);
      const long f2 = fibo(half-1);
	   cerr << "			fibo returned " << f1*(f1 + 2*f2) << "\n";
      return f1*(f1 + 2*f2);
   }
   else // n is odd
   {
      const int nearhalf = (n-1)/2;
      const long f1 = fibo(nearhalf+1);
      const long f2 = fibo(nearhalf);
	   cerr << "			fibo returned " << f1*f1 + f2*f2 << "\n";
      return f1*f1 + f2*f2;
   }
}//fibo

int main ( int argc, char* argv[] )
{
   int first, last;

   if( argc <= 1 )
   {  first= 0;
      last = 5;
   }
   else if ( argc <= 2 )
   {  first= 0;
      last = atoi(argv[1]); //ASCII to int conversion
   }
   else
   {  first= atoi(argv[1]);
      last = atoi(argv[2]);
   }

   for(int i=first; i<= last; i++)
   {
      fib_count = 0;
      cout << setw(4) <<setw(4) <<i <<", " 
	<< setw(10) << fibo(i) ;
      //Do not output fibo(i) and then fib_count in one cout.
      //C++ will print the fib_count BEFORE fibo(n) is executed
      cout 
	<< setw(10) << "  fib_count: "<< fib_count << endl;
   }


   return 0;
}

