#include<iostream>
#include<fstream>
#include<sstream>
#include<cassert>
using namespace std;

string double_to_string(double val){

	ostringstream oss;
	oss<<val;
	return oss.str();
}

double string_to_double(const string& str){

	istringstream iss(str);
	double val;
	iss>>val;
	return val;
}

int main(int argc,char** arg){

	string line;
	string word;
	ifstream infile("string.txt");
	assert(infile);
	int counter = 0;
	while(getline(infile,line)){
		istringstream iss(line);
		while(iss>>word){         // according to blank space to split the stream into words
			cout<<word;
			counter++;
		}			
	}
	cout<<endl;
	cout<<counter<<endl;

	// test for  istringstream, ostringstream
	istringstream iss("192,168,0,100");
	int v1,v2,v3,v4;
	char chr;
	iss>>v1>>chr>>v2>>chr>>v3>>chr>>v4;

	chr = '.';
	ostringstream oss;
	oss<<v1<<chr<<v2<<chr<<v3<<chr<<v4;
	cout<<oss.str()<<endl;

	// test for stringstream
	stringstream ss("192,168,0,100");
	iss>>v1>>chr>>v2>>chr>>v3>>chr>>v4;

	chr = '.';
	stringstream ss1;
	ss1<<v1<<chr<<v2<<chr<<v3<<chr<<v4;
	cout<<ss1.str()<<endl;
	
	return 0;
}
