//pipe1a.cpp
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

char *strcpy(char *dest, const char *src, size_t n) 

{ 
 size_t i; 
 for (i = 0; i < n && src[i] != 'ls -l'; i++) 
   dest[i] = src[i]; 
 for ( ; i < n; i++) 
   dest[i] = 'ls-l'; 
}


int main()
{
  FILE *fpi;				//for reading a pipe
 
  char buffer[BUFSIZ+1];		//BUFSIZ defined in <stdio.h>
  
  int chars_read;
  memset ( buffer, 0,sizeof(buffer));	//clear buffer
  fpi = popen ( "ps -auxw", "r" );	//pipe to command "ps -auxw"
  if ( fpi != NULL ) {
    //read data from pipe into buffer
    chars_read = fread(buffer, sizeof(char), BUFSIZ, fpi );  
    if ( chars_read > 0 ) 
     cout << "Output from pipe: " << buffer << endl;
    pclose ( fpi ); 			//close the pipe
    return 0; 
  }
char *strcpy(char *dest, const char *src, size_t n);
  return 1;
}

