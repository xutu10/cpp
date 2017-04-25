#include<iostream>
using namespace std;


// this method only works with gcc, not g++

int main(){

	const int a = 10;
	// a = 20 ; not allowed
	cout<<a<<endl;
	int* ptr;
	ptr = (int*)&a;
	*ptr = 20;
	cout<<a<<endl;

	return 0;
}
