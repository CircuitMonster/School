#include <signal.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void func ( int sig )
{
  cout << "Alarm has gone off " << sig << endl;
}

int main()
{
  (void) signal ( SIGKILL, func );	//catch terminal interrupts

  while (1) {
    cout << "Waiting for alarm to go off!" << endl;
    sleep (1); 
  }
  return 0;
}
