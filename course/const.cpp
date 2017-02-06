#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    //const int a = 10;
//  a = 10; Error
	int b =8;
	int c = 10;
	int& a = b;
	cout<<a<<endl;
	a = c;
//	int& a = 8; error
	cout<<a<<endl;
    return 0;
}
