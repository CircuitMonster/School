#include "passwordfile.h"
#include "userpw.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
 PasswordFile passfile("password.txt");
 passfile.addPW(UserPW("dbotting","123qwe"));
 passfile.addPW(UserPW("egomez","qwerty"));
 passfile.addPW(UserPW("tongyu","liberty"));
 // write some lines to see if passwords match users
 passfile.checkPW("dbotting","123qwe");
 passfile.checkPW("egomez","qwerty");
 passfile.checkPW("tongyu","liberty");
}

