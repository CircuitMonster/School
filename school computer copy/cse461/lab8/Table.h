#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Sdisk.h"
#include "Filesys.h"
#include "Shell.h"

using namespace std;

class Table: public Filesys
{
public:
	Table(string diskname, int blocksize, int numberofblocks, string flatfile, string indexfile);
	int Build_Table(string input_file);
	void Search(string value);
private:
	string flatfile;
	string indexfile;
	int numberofrecords;
	int IndexSearch(string value);
};

Table::Table(string diskname, int blocksize, int numberofblocks, string flatfile, string indexfile) : Filesys(diskname, numberofblocks, blocksize)
{
	this -> indexfile = indexfile;
	this -> flatfile = flatfile;
	newfile(flatfile);
	newfile(indexfile);
}

int Table::Build_Table(string input_file)
{
	ifstream infile;
	infile.open(input_file.c_str());
	vector<string> ikey;
	vector<int> iblock;				//was <string> but changed to <int>
	string rec;
	getline(infile, rec);
	int inum = 0;
	while (infile.good())
	{
		string primkey = rec.substr(0, 5);
		vector<string> blocks = block(rec, getblocksize());
		int blockid = addblock(flatfile, blocks[0]);
		ikey.push_back(primkey);
		iblock.push_back(blockid);
		getline(infile, rec);
		if (infile.bad() and ikey.size() > 0)
		{
			ostringstream ibuffer;
			ibuffer << ikey.size() << " ";
			for (int i = 0; i < ikey.size(); i++)
			{
				ibuffer << ikey[i] << " " << iblock[i] << " ";
			}

			//below should be in if or out of if???
			string buffer = ibuffer.str();
			vector<string> blocks2 = block(buffer, getblocksize());
			int error = addblock(indexfile, blocks2[0]);
			ikey.clear();
			iblock.clear();
		}
	}
}

void Table::Search(string value)
{
	int block = IndexSearch(value);
	if(block == 0)
	{
		cout << "Record not found!";
	}
	else
	{
		string buffer;
		readblock(flatfile, block, buffer);
		cout << buffer << endl;
	}
}

int Table::IndexSearch(string key)
{
	int block = getfirstblock(indexfile);
	while (block != 0)
	{
		string buffer;
		readblock(indexfile, block, buffer);
		istringstream istream;
		istream.str(buffer);
		int num = 0;
		istream >> num;
		for (int i = 0; i < num; i++)
		{
			string s;
			int b;
			istream >> s >> b;
			if (key == s)
			{
				return b;
			}
		}
		block = nextblock(indexfile, block);
	}
}
#endif
