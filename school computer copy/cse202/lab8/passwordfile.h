#ifndef PASSWORDFILE_H
#define PASSWORDFILE_H
#include <string>
#include <vector>
#include "userpw.h"
using namespace std;

class PasswordFile
{
public:
   PasswordFile(string filename);
   vector<UserPW> getFile();
   void addPW(UserPW newentry);
   bool checkPW(string user, string passwd);

private:
   string filename;
   vector<UserPW> entry;
   void Synch();
};
#endif
