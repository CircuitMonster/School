#ifndef SDISK_H
#define SDISK_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Sdisk
{
public:
	Sdisk(string diskname, int numberofblocks, int blocksize);
	string getblock(int blocknumber, string& buffer);
	int putblock(int blocknumber, string buffer);
	int getblocksize()const;
	int getnumberofblocks()const;
private:
	string diskname; 		
	int numberofblocks;		
	int blocksize;			
};

Sdisk::Sdisk(string diskname, int numberofblock, int blocksize)
{
	string temp = diskname + ".dat";
	fstream checkfile;
	checkfile.open(temp.c_str(), ios::in | ios::out);
	char s; 
	s = checkfile.get();

	if(s =='#')
	{
		cout << diskname << " already exists" << endl;
		this->diskname = diskname;
		this->numberofblocks = numberofblock;
		this->blocksize = blocksize;
	}
	else
	{
		this->diskname = diskname;
		this->numberofblocks = numberofblock;
		this->blocksize = blocksize;
		string tempSpc = diskname + ".spc";
		string tempDat = diskname + ".dat";	
		ofstream out;
		out.open( tempSpc.c_str());
		out << numberofblocks << " " << blocksize;
		out.close();

		out.open(tempDat.c_str());
		cout << "Create disk "<< diskname << endl;

		for(int i = 0; i < numberofblocks ; i++)
		{
			for(int j = 0; j < blocksize; j++)
			{				
				out.put('#');
			}
			out.put('\n');
		}
		out.close();
	}
}

string Sdisk::getblock(int blocknumber, string& buffer)
{
	ifstream open1;	
	string tempDat = diskname + ".dat";	
	open1.open(tempDat.c_str());	
	open1.seekg((blocksize * blocknumber) + blocknumber, ios::beg);
	for(int i = 0 ; i < blocksize; i++)
	{
		char x = open1.get();
		buffer += x ; 
	}
	open1.close();
	return buffer;
}

int Sdisk::putblock(int blocknumber, string buffer)
{
	ofstream open2;	
	string tempDat = diskname + ".dat" ; 
	open2.open(tempDat.c_str(), ios::in | ios::out) ;
	open2.seekp((blocksize * blocknumber) + blocknumber, ios::beg);
	for(int i = 0 ; i < blocksize ; i++)
	{
		open2.put(buffer[i]);	
	}
	open2.put('\n');
	open2.close();
	return 1;	
}

int Sdisk::getblocksize()const 
{
    return blocksize;
}

int Sdisk::getnumberofblocks()const 
{
    return numberofblocks;
}
#endif
