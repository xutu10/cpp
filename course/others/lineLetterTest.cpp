#include<iostream>
#include<fstream>
#include<cassert>

using namespace std;

void copyText(ifstream&, ofstream&, char&, int[]);
void count(char, int[]);
void printout(ofstream&,int, int[]);

int main(){

	int counter[26] = {	0};
	int line = 0;
	char chr;
	ifstream infile("input");
	ofstream outfile("output");
	assert(infile);
	assert(outfile);

	infile.get(chr);
	while(infile){
		copyText(infile,outfile,chr,counter);
		line++;
		infile.get(chr);
	}

	printout(outfile,line,counter);

	infile.close();
	outfile.close();
	
	return 0;
}

void copyText(ifstream& in, ofstream& out, char& chr, int counter[]){

	while(chr != '\n'){
		out<<chr;
		count(chr,counter);
		in.get(chr);
	}
	out<<chr;

}
void count(char chr, int counter[]){

	chr = toupper(chr);
	int index = static_cast<int>(chr) - static_cast<int>('A');
	if(0 <= index && index < 26)
		counter[index]++;
}
void printout(ofstream& out, int line, int counter[]){

	out<<"below is counter information"<<endl<<endl;
	out<<"number of lines is "<<line<<endl;
	for(int i = 0; i < 26 ; i++)
		out<<static_cast<char> (i + static_cast<int>('A'))<< " is "<<counter[i]<<endl;
	
}
