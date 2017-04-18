#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
using namespace std;

struct Student{
	int age;
	string name;
};

int main(int argc, char** arg){

	struct Student s;
	s.age = 10;
	s.name = "xutu";

	ofstream outfile("student.txt");
	assert(outfile);
	//	** string is just a pointer with size of 32 bits
	// in this way just the pointer is stored in the file not the content of the string
	// outfile.write((char*)&s, sizeof(Student));
	outfile.write((char*)&s.age, sizeof(int) );
	int len = s.name.length();
	outfile.write(s.name.data(),len);
	outfile.close();

	ifstream infile("student.txt");
	assert(infile);
	struct Student s1;
	// 	infile.read((char*)&s1, sizeof(Student));
	infile.read((char*)&s1.age,sizeof(int) );
	s1.name.resize(len);
	// infile.read(&s1.name[0],len );
	cout<<s1.age<<" "<<s1.name<<endl;

	infile.close();

	// cout<<sizeof(string)<<" "<<sizeof(int)<<endl;

	return 0;
	
}
