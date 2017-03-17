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
//	Sdisk(string diskname);
	string getblock(int blocknumber, string& buffer);
	int putblock(int blocknumber, string buffer);
	int getblocksize()const;
	int getnumberofblocks()const;
	friend class Filesys;
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
/*
Sdisk::Sdisk(string name)
{
	string temp =  diskname + ".dat";
	fstream iofile;
	iofile.open(temp.c_str(), ios::in | ios::out);
	char x;
	x = iofile.get();
	if( x =='#')
	{
		cout << "Disk " << name << " already exists" << endl;
		diskname = name;
		numberofblocks = 1024;
		blocksize = 128;
	}	
	else
	{
		cout << "Create disk " << name << endl;
		diskname = name;
		numberofblocks = 800;
		blocksize = 100;
	
		string tempSpc = diskname + ".spc";
		string tempDat = diskname + ".dat";	
		ofstream out;
		out.open(tempSpc.c_str() );
		out << numberofblocks << " " << blocksize;
		out.close();
		out.open(tempDat.c_str() ) ;
		for(int i = 0; i < numberofblocks; i++)
		{
			for(int j = 0; j < blocksize; j++)
			{				
				out.put('#');
			}
			out.put('\n');
		}
		out.close();				
	}
	iofile.close();
}
*/

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
