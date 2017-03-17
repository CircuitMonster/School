/*
Brian Ackley
CSE461
Spring 2015
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Sdisk.h"

using namespace std;

class Filesys: public Sdisk
{
public:
	Filesys(string filename);
	int fsclose();
	int fssynch();
	int newfile(string file);
	int rmfile(string file);
	int getfirstblock(string file);
	int addblock(string file, string block);
	int delblock(string file, int blocknumber);
	int readblock(string file, int blocknumber, string& buffer);
	int writeblock(string file, int blocknumber, string buffer);
	int nextblock(string file, int blocknumber);
	vector<string> block(string buffer, int b);
private:
	int rootsize;           	// maximum number of entries in ROOT
	int fatsize;            	// number of blocks occupied by FAT
	vector<string> filename;   // filenames in ROOT
	vector<int> firstblock; 	// firstblocks in ROOT
	vector<int> fat;            // FAT
	bool checkblock(string file, int blocknumber);
};

Filesys::Filesys(string filename) : Sdisk(filename, getnumberofblocks(), getblocksize())
{
	int rootsize = (getblocksize() / 12); 
	int fatsize = (getnumberofblocks() * 5) / (getblocksize() + 1);
	string buffer;
	getblock(1, buffer);
	if (buffer[1] == '#')
	{
		//build root
		ostringstream ostreamroot;
		for (int i = 0; i < rootsize; i++)
		{
			ostreamroot << "XXXXXX" << " " << 0 << " ";
		//	filename.push_back("XXXXXX");
		//	firstblock.push_back(0);
		}
		string rootbuffer = ostreamroot.str();

		//build fat
		fat[0] = fatsize + 2;
		fat[1] = 0;
		for (int i = 0; i < fatsize; i++)
		{
			fat[2 + i] = 0;
		}
		for (int i = fatsize + 2; i < getnumberofblocks(); i++)
		{
			fat[i] = i + 1;
		}
		fat[getnumberofblocks() - 1] = 0;

		ostringstream ostreamfat;
		for (int i = 0; i < getnumberofblocks(); i++)
		{
			ostreamfat << fat[i] << " ";
		}
		string fatbuffer = ostreamfat.str();

/*		for (int i = 0; i < rootsize; i++)
		{
			filename.push_back("XXXXXX");
			firstblock.push_back(0);
		}*/
		//fatbuffer.length();
	}
	else
	{
		//read in exsisting filesystem...

		string buffer1;
		getblock(1, buffer1);
		istringstream istream;
		istream.str(buffer1);
		for (int i = 0; i < rootsize; i++)
		{
			string t1, t2;
			istream >> t1 >> t2;
			//filename.push_back(t1);
			//getfirstblock.push_back(t2);
		}

		string buffer2;
		for (int i = 0; i < fatsize; i++)
		{
			string t;
			getblock(2 + i, t);
			buffer2 += t;
		}
		istringstream istream2;
		istream2.str(buffer2);

		for (int i =0; i < filename.size(); i++)
		{
			int x;
			istream2 >> x;
			fat.push_back(x);
		} 
	}
}

int Filesys::fsclose()
{
	fssynch();
}

int Filesys::fssynch()
{
	vector<string>  tempblocks;
	string fatbuffer, rootbuffer;
	ostringstream fatstream, rootstream;
	for(int i = 0 ; i < fat.size();i++)
	{
		fatstream << fat[i]<<" ";
	}	
	fatbuffer = fatstream.str();
	tempblocks = block(fatbuffer, getblocksize());

	for(int i = 0; i < tempblocks.size();i++)
	{
		putblock(i + 10, tempblocks[i]);
	}

	for( int i = 0; i < filename.size(); i++)
	{
		rootstream << filename[i] << " " << firstblock[i] << " ";
	}

	rootbuffer = rootstream.str();
	int pad = getblocksize() - rootbuffer.length();
	if(pad > 0)
	{
		for(int i = 0; i < pad; i++)
		{
			rootbuffer += '~';
		}
	}
	vector<string> temproot = block(rootbuffer, getblocksize());		
	for(int i = 1; i < (getblocksize() / 16) ; i++)
	{
		putblock(i, temproot[i - 1]);
	}
	return 1;
}

int Filesys::newfile(string file)
{
	for (int i = 0; i < filename.size(); i++)
	{
		if (filename[i] == file)
		{
			cout << "file exsists" << endl;
			return 0;
		}
	}

	for (int i = 0; i < filename.size(); i++)
	{
		if (filename[i] == "XXXXXX")
		{
			filename[i] = file;
			return 1;
		}
	}
	return 0;
}

int Filesys::rmfile(string file)
{
	for( int i = 0; i < filename.size(); i++)
	{
		if(filename[i] == file)
		{
			if(firstblock[i] == 0)
			{
				filename[i] = "XXXXXX";
				fssynch();
				return 1;		
			}	
		}
	}
	return 0;
}

int Filesys::getfirstblock(string file)
{
	for (int i =0; i < filename.size(); i++)
	{
		if (filename[i] == file)
		{
			return firstblock[i];
		}
		cout << "file does not exsits" << endl;
	}
}

int Filesys::addblock(string file, string block)
{
	int id = getfirstblock(file);
	if (id == -1)
	{
		cout << "no such file";
		return -1;
	}

	int allocate = fat[0];
	if (allocate == 0)
	{
		cout << "no space left";
		return -1;
	}

	if (id == 0)
	{
		for (int i = 0; i < filename.size(); i++)
		{
			if (filename[i] == file)
			{
				firstblock[i] == allocate;
			}
		}
	}
	else
	{
		int nextblock;
		nextblock = id;
		while (fat [nextblock] != 0)
		{
			nextblock = fat[nextblock];
		}
		fat[nextblock] = allocate;
	}

	fat[0] = fat[fat[0]];
	fat[allocate] = 0;
	fssynch();
	putblock(allocate, block);
}

int Filesys::delblock(string file, int blocknumber)
{
	if (checkblock(file, blocknumber))
	{
		if (blocknumber == getfirstblock(file))
		{
			for (int i = 0; i < filename.size(); i++)
			{
				if (filename[i] == file)
				{
					firstblock[i] == fat[blocknumber];
				}
			}
		}
		else
		{
			int blockid = getfirstblock(file);
			while (fat[blockid] != blocknumber)
			{
				blockid = fat[blockid];
			}
			fat[blockid] = fat[blocknumber];
		}
		fat[blocknumber] = fat[0];
		fat[0] = blocknumber;
	}
}

int Filesys::readblock(string file, int blocknumber, string& buffer)
{
	if (checkblock(file, blocknumber))
	{
		getblock(blocknumber, buffer);
		return 1;
	}
	else
	{
		return -1;
	}
}

int Filesys::writeblock(string file, int blocknumber, string buffer)
{
	if(checkblock(file, blocknumber))
	{
		putblock(blocknumber, buffer);
		return 1;
	}
	else
	{
		return -1;
	}
}

int Filesys::nextblock(string file, int blocknumber)
{
	if (checkblock(file, blocknumber))
	{
		return fat[blocknumber];
	}
	else
	{
		return -1;
	}
}

vector<string> Filesys::block(string buffer, int b)
{
// blocks the buffer into a list of blocks of size b

	vector<string> blocks;
	int numberofblocks = 0;

	if (buffer.length() % b == 0) 
	{
		numberofblocks = buffer.length() / b;
	}
	else 
	{
		numberofblocks = buffer.length() / b + 1;
	}

	string tempblock;
	for (int i = 0; i < numberofblocks; i++)
	{
		tempblock=buffer.substr(b * i, b);
		blocks.push_back(tempblock);
	}

	int lastblock = blocks.size() - 1;

	for (int i = blocks[lastblock].length(); i < b; i++)
	{
		blocks[lastblock]+="#";
	}

	return blocks;
}

bool Filesys::checkblock(string file, int blocknumber)
{
	int blockid = getfirstblock(file);
	if (blockid == -1)
	{
		cout << "file doesnt exsits";
		return false;
	}

	while (blockid != 0)
	{
		if (blockid == blocknumber)
		{
			return true;
		}
		blockid = fat[blockid];
	}
	return false;
}


int main()
{
	Sdisk disk1("disk1",256,128);
	Filesys fsys("disk1",256,128);
	fsys.newfile("file1");
	fsys.newfile("file2"};

	string bfile1;
	string bfile2;

	for (int i=1; i<=1024; i++)
	{
		bfile1+="1";
	}

	vector<string> blocks=block(bfile1,128); 

	int blocknumber=0

	for (int i=0; i< blocks.size(); i++)
	{
		blocknumber=fsys.addblock("file1",blocks[i]);
	}

	fsys.delblock("file1",fsys.getfirstblock("file1"));

	for (int i=1; i<=2048; i++)
	{
		bfile2+="2";
	}

	blocks=block(bfile2,128); 

	for (int i=0; i< blocks.size(); i++)
	{
	blocknumber=fsys.addblock("file2",blocks[i]);
	}

	fsys.delblock("file2",blocknumber);
}
