#include<iostream>
#include<cassert>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char** arg){

	// test for instream of file 
	string line;
	ifstream fin("test.txt");

	assert(fin);
	while(getline(fin,line))  // comparing with fin.getline()
		cout<<line<<endl;

	fin.close();

	// test for outstream of file
	// ofstream fout;
	// fout.open("test.txt");
	ofstream fout("test.txt");
	// to check if open normally
	// fout.is_open();
	// fout.good();
	// if(fout);
	assert(fout);

	fout<< "first line.\n";
	fout<< "second line.\n";
	
	fout.close();

	// test for file position

	streampos begin, end;
	ifstream infile("test.txt");
	assert(infile);
	begin = infile.tellg();
	cout<<begin<<endl;
	infile.seekg(0,ios::end);
	end = infile.tellg();
	cout<<end<<endl;

	// test for other funcs
	infile.seekg(2);            // the current pointer move to second positon
	char chr;
	infile.get(chr);
	infile.seekg(-1,ios::end); // one position before the end of file
	
	infile.close();

   


	return 0;
}
