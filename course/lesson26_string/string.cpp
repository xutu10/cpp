#include<iostream>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
    string s;
	string s1("asdfgh");
	cout<<s1<<endl;

	string s2("asdfgh",2);
	cout<<s2<<endl;

	string s3(s1,1,3); // string, from_index, offset
	cout<<s3<<endl;    //sdf

	string::iterator first = s1.begin() + 1;
	string::iterator last = s1.end();
	string s4(first,last);
	cout<<s4<<endl;
	return 0;
}
