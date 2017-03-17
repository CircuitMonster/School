#include "userpw.h"
#include <string>
using namespace std;

UserPW::UserPW(string user, string password)
{
   this->user = user;
   this->password = password;
}

string UserPW::getUser()
{
   return user;
}

string UserPW::getPassword()
{
   return password;
}

bool UserPW::CheckPW(string user, string passwd)
{
   if (user == this->user && passwd == password)
      return true;
   return false;
}
