#include<fstream>
#include<cassert>
using namespace std;


// read(), write() just for binary stream

int main(int argc, char** arg){

	ifstream infile("test.txt",ifstream::binary);
	ofstream outfile("new.txt",ofstream::binary);

	assert(infile);
	assert(outfile);
	
	infile.seekg(0,infile.end);
	int size = infile.tellg();
	infile.seekg(0);

	char* buf = new char[size];
	infile.read(buf,size);

	outfile.write(buf,size);

	delete[] buf;

	infile.close();
	outfile.close();
	
	return 0;
}
