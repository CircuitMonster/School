#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Sdisk.h"
#include "Filesys.h"

using namespace std;

class Shell: public Filesys
{
public:
	Shell(string filename, int numberofblocks, int blocksize);
	int dir();
	int add(string file);
	int del(string file);
	int type(string file);
	int copy(string file1, string file2);
};

Shell::Shell(string diskname, int numberofblocks, int blocksize) : Filesys(diskname, numberofblocks, blocksize)
{

}

int Shell::dir()
{
	vector<string> flist = ls();
	for (int i = 0; i < flist.size(); i++)
	{
		cout << flist[i] << endl;
	}
}

int Shell::add(string file)
{
	newfile(file);
	string buffer;
	for (int i = 0; i < getblocksize(); i++)
	{
		buffer += "R";
	}
	vector<string> blocks=block(buffer, getblocksize());

	for (int i = 0; i < getblocksize(); i++)
	{
		addblock(file, blocks[i]);
	}
}

int Shell::del(string file)
{
	int block = getfirstblock(file);
	while (block > 0)
	{
		delblock(file, block);
		block = getfirstblock(file);
	}

	rmfile(file);
}

int Shell::type(string file)
{
	int block = getfirstblock(file);
	string buffer;
	while (block > 0)
	{
		string t;
		int error = readblock(file, block, t);
		buffer += t;
		block = nextblock(file, block);
	}
	cout << buffer;
}

int Shell::copy(string file1, string file2)
{
	int block = getfirstblock(file1);
	int code = newfile(file2);
	while (block > 0)
	{
		string buffer;
		code = readblock(file1, block, buffer);
		code = addblock(file2, buffer);
		block = nextblock(file1, block);
	}
}

int main()
{
	Shell sh("disk1", 256, 128);
	string s;
	string command = "go";
	string op1, op2;

	while (command != "quit")
	{
		command.clear();
		op1.clear();
		op2.clear();
		cout << "$";
		getline(cin,s);
		int firstblank = s.find(' ');
		if (firstblank < s.length()) s[firstblank] = '#';
		int secondblank = s.find(' ');
		command = s.substr(0, firstblank);
		if (firstblank < s.length())
			op1 = s.substr(firstblank + 1,secondblank - firstblank - 1);

		if (secondblank < s.length())
			op2 = s.substr(secondblank + 1);

		if (command == "dir")
		{
            // use the ls function
			sh.dir();
		}

		if (command == "add")
		{
            // The variable op1 is the new file
			sh.add(op1);
		}

		if (command == "del")
		{
            // The variable op1 is the file
			sh.del(op1);
		}

		if (command == "type")
		{
            // The variable op1 is the file
			sh.type(op1);
		}

		if (command == "copy")
		{
            // The variable op1 is the source file and the variable op2 is the destination file.
			sh.copy(op1, op2);
		}
       
      }

 return 0;
}
