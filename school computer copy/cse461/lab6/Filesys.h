/*
Brian Ackley
CSE461
Spring 2015
Lab Filesys
*/

#ifndef FILESYS_H
#define FILESYS_H
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
	Filesys(string diskname, int numberofblocks, int blocksize);
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
	vector<string> ls();
private:
	int rootsize;           	// maximum number of entries in ROOT
	int fatsize;            	// number of blocks occupied by FAT
	vector<string> filenames;   // filenames in ROOT
	vector<int> firstblock; 	// firstblocks in ROOT
	vector<int> fat;            // FAT
	bool checkblock(string file, int blocknumber);
};

Filesys::Filesys(string diskname, int numberofblocks, int blocksize) : Sdisk(diskname, numberofblocks, blocksize)
{
	rootsize = (getblocksize() / 12); 
	fatsize = (getnumberofblocks() * 8 / getblocksize()) + 1; 
	string buffer;
	getblock(1, buffer);
	if (buffer[0] == '#')
	{
		//build root
		for (int i = 0; i < rootsize; i++)
		{
			filenames.push_back("XXXXXX");
			firstblock.push_back(0);
		}

		//build fat
		fat.push_back(2 + fatsize);
		for (int i = 0; i < fatsize; i++)
		{
			fat.push_back(1);
		}
		for (int i = fatsize + 2; i < getnumberofblocks(); i++)
		{
			fat.push_back(i + 1);
		}
		fat[fat.size() - 1] = 0;
	}
	else
	{
		//read in exsisting filesystem...

		string rootbuffer;
		getblock(1, rootbuffer);
		istringstream rootstream;
		rootstream.str(rootbuffer);
		for (int i = 0; i < rootsize; i++)
		{
			string t1;
			int t2;
			rootstream >> t1 >> t2;
			filenames.push_back(t1);
			firstblock.push_back(t2);
		}

		string fatbuffer;
		for (int i = 0; i < fatsize; i++)
		{
			string t;
			getblock(2 + i, t);
			fatbuffer += t;
		}
		istringstream fatstream;
		fatstream.str(fatbuffer);

		for (int i = 0; i < getnumberofblocks(); i++)
		{
			int x;
			fatstream >> x;
			fat.push_back(x);
		} 
	}
}

int Filesys::fsclose()
{
	fssynch();
	return 0;
}

int Filesys::fssynch()
{
    //write updated root to disk
    ostringstream rootstream;
    
    for(int i = 0; i < rootsize; ++i){
        rootstream << filenames[i] << " " << firstblock[i] << " ";  
    }
    string root = rootstream.str();
    for(long j = root.size(); j < getblocksize(); j++){
        root += "#";
    }
    putblock(1, root);
    
    //write the FAT onto the disk
    
    ostringstream fatstream;
    
    for(int i = 0; i < getnumberofblocks(); i++){
        fatstream << fat[i] << " ";
    }
    string fatstring = fatstream.str();
    vector<string> blocks=block(fatstring,getblocksize());
    
    //writing the substring of the FAT
    for(int i = 0; i < blocks.size(); i++)
       {
        putblock(i+2, blocks[i]);
       }
    return 1; //successful!
/*
	ostringstream fatstream;
	string fatbuffer;
	fatbuffer = fatstream.str();
	for(int i = 0; i < getnumberofblocks(); i++)
	{
		fatstream << fat[i]<<" ";
	}
	putblock(1, fatbuffer);

	ostringstream outstream;
	string buffer;

	for( int i = 0; i < rootsize; i++ )
	{
		outstream << filenames[i] << " " << firstblock[i] << " ";
		buffer = outstream.str();
	}
	putblock(0, buffer);
	return 1;
*/
}

int Filesys::newfile(string file)
{

	for (int i = 0; i < filenames.size(); i++)
	{
		if (filenames[i] == file)
		{
			cout << "file already exsists" << endl;
			return 1;
		}
	}

	for (int i = 0; i < filenames.size(); i++ ) 
	{
		if( filenames[i] == "XXXXXX" )
		{
			filenames[i] = file;
			firstblock[i] = 0;	
fssynch();
		}
	}

	return 1;
}

int Filesys::rmfile(string file)
{
	for( int i = 0; i < filenames.size(); i++)
	{
		if(filenames[i] == file)
		{
			if(firstblock[i] == 0)
			{
				filenames[i] = "XXXXXX";
				firstblock[i] = 0;
			}	
		}
	}
	fssynch();
	return 1;
}

int Filesys::getfirstblock(string file)
{
	int blockfirst = 0;
	for(int i = 0; i < filenames.size(); i++)
	{
		if(filenames[i] == file)
		{
			blockfirst = firstblock[i];
		}
	}
	fssynch();
	return blockfirst;
}

int Filesys::addblock(string file, string block)
{
	int blockid = getfirstblock(file);
	int allocate = fat[0];

	if (allocate == 0)
	{
		cout << "no space left" << endl;
		return -1;
	}

	if (blockid == 0)
	{
		for (int i = 0; i < filenames.size(); i++)
		{
			if (filenames[i] == file)
			{
				firstblock[i] = allocate;
				fat[0] = fat[allocate];
				fat[allocate] = 0;
			}
		}
	}
	else
	{
		int nextblock = blockid;
		while (fat[allocate] != 0)
		{
			nextblock = fat[nextblock];
			fat[nextblock] = allocate;
			fat[0] = fat[allocate];
			fat[allocate] = 0;
		}

	}
	putblock(allocate, block);
	fssynch();
	return allocate;
}

int Filesys::delblock(string file, int blocknumber)
{
	if (checkblock(file, blocknumber))
	{
		if (blocknumber == getfirstblock(file))
		{
			for (int i = 0; i < filenames.size(); i++)
			{
				if (filenames[i] == file)
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
		int blockid = getfirstblock(file);
		while(blockid != blocknumber)
		{
			blockid = fat[blockid];
		}
		return fat[blockid];
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
		blocks[lastblock] += "#";
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

vector<string> Filesys::ls()
{
	vector<string> flist;
	for (int i = 0; i < filenames.size(); i++)
	{
		if (filenames[i] != "XXXXXX")
		{
			flist.push_back(filenames[i]);
		}
	}
	return flist;
}

#endif
/*
int main()
{
	Sdisk disk1("disk1",256,128);
	Filesys fsys("disk1",256,128);
	fsys.newfile("file1");
	fsys.newfile("file2");

	string bfile1;
	string bfile2;

	for (int i=1; i<=1024; i++)
	{
		bfile1+="1";
	}

	vector<string> blocks=fsys.block(bfile1,128); 

	int blocknumber=0;

	for (int i=0; i< blocks.size(); i++)
	{
		blocknumber=fsys.addblock("file1",blocks[i]);
	}

	fsys.delblock("file1",fsys.getfirstblock("file1"));

	for (int i=1; i<=2048; i++)
	{
		bfile2+="2";
	}

	blocks=fsys.block(bfile2,128); 

	for (int i=0; i< blocks.size(); i++)
	{
	blocknumber=fsys.addblock("file2",blocks[i]);
	}

	fsys.delblock("file2",blocknumber);
}
*/
