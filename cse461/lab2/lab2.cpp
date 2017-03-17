/*
Brian Ackley
CSE461
Spring 2015
Lab 2/ HW 1
*/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
class Sdisk {
public: 	
	Sdisk(string diskname, int numberofblocks, int blocksize);
	string getblock(int blocknumber, string& buffer);
	int putblock(int blocknumber, string buffer);
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

int main()
{
  Sdisk disk1("test1",16,32);
  string block1, block2, block3, block4;
  for (int i = 1; i <= 32; i++) block1 = block1 + "1";
  for (int i = 1; i <= 32; i++) block2 = block2 + "2";
  disk1.putblock(4,block1);
  disk1.getblock(4,block3);
  cout << "Should be 32 1s : ";
  cout << block3 << endl;
  disk1.putblock(8,block2);
  disk1.getblock(8,block4);
  cout << "Should be 32 2s : ";
  cout << block4 << endl;;
}
