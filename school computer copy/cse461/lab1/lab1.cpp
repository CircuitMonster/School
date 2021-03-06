/*
Brian Ackley
CSE 461
Spring 2015
Lab 1
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class PasswordFile
{
public:
	PasswordFile(string filename); // opens the file and reads the names/passwords in the vectors user and password.
	void addpw(string newuser, string newpassword); //this adds a new user/password to the vectors and writes the vectors to the file filename
	bool checkpw(string usr, string passwd); // returns true if user exists and password matches
private:
	string filename; // the file that contains password information
	vector<string> user; // the list of usernames
	vector<string> password; // the list of passwords
	void synch(); //writes the user/password vectors to the password file
	void checkuser(string check);
};

void PasswordFile::synch()
{
	ofstream out;
	out.open(filename.c_str());
	for (int i = 0; i < user.size(); i++)
	{
		out << user[i] << " " << password[i] << endl;
	}
	out.close();
}

PasswordFile::PasswordFile(string filename)
{
	this->filename = filename;
	ifstream infile;
	string u, p;
	infile.open(filename.c_str());
	if (infile.is_open())
	{
		infile >> u >> p;
		while (infile.good())
		{
			user.push_back(u);
			password.push_back(p);
			infile >> u >> p;
		}
		infile.close();
	}
}

void PasswordFile::addpw(string newuser, string newpassword)
{
	checkuser(newuser);
	user.push_back(newuser);
	password.push_back(newpassword);
	synch();
}

bool PasswordFile::checkpw(string usr, string passwd)
{
	for (int i = 0; i < password.size(); i++)
	{
		if ((user[i] == usr) and (password[i] == passwd))
		{
			return true;
		}
	}
}

void PasswordFile::checkuser(string check)
{
	for (int i = 0; i < user.size(); i++)
	{
		if (check == user[i])
		{
			cout << "User name exsits, please choose another name" << endl;
			return;
		}
	}
}

int main()
{
	PasswordFile passfile("password.txt");
	passfile.addpw("dbotting","123qwe");
	passfile.addpw("egomez","qwerty");
	passfile.addpw("tongyu","liberty");

// write some lines to see if passwords match users

	if (passfile.checkpw("dbotting","123qwe") == true)
	{
		cout << "correct name and password" << endl;
	}
	else
	{
		cout << "incorrect name and password" << endl;
	}

	if (passfile.checkpw("egomez","qwerty") == true)
	{
		cout << "correct name and password" << endl;
	}
	else
	{
		cout << "incorrect name and password" << endl;
	}
	if (passfile.checkpw("whatttt","noooooo") == true)
	{
		cout << "correct name and password" << endl;
	}
	else
	{
		cout << "incorrect name and password" << endl;
	}

}
