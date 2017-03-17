#include "passwordfile.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void PasswordFile::Synch()
{
   ofstream out;
   out.open(filename.c_str());
   for (int i = 0; i < entry.size(); i++)
   {
      out << entry[i].getUser() << " " << entry[i].getPassword() << endl;
      //or construct and use: out << entry[i].get_format_user();
   }
   out.close();
}

PasswordFile::PasswordFile(string filename)
{
   this->filename = filename;
   ifstream password;
   string u, p;
   password.open(filename.c_str());
   if (password.is_open())
   {
      password >> u >> p;
      while(password.good())
      {
         entry.push_back(UserPW(u, p));
         password >> u >> p;
      }
      password.close();
   }
//   else
//      cout << "file not found" << endl;
}

vector<UserPW> PasswordFile::getFile()
{
   return entry;
}

void PasswordFile::addPW(UserPW newentry)
{
   entry.push_back(newentry);
   Synch();
}

bool PasswordFile::checkPW(string user, string passwd)
{
   for (int i = 0; i < entry.size(); i++)
      if (entry[i].CheckPW(user, passwd))
         return true;
   return false;
}
