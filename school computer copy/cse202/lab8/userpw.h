#ifndef USERPW_H
#define USERPW_H
#include <string>
using namespace std;

class UserPW
{
public:
   UserPW(string user, string password);
   string getUser();
   string getPassword();
   bool CheckPW(string user, string passwd);

private:
   string user;
   string password;
};
#endif
