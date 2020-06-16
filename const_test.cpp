#include<iostream>
using namespace std;

int main(){

	int a = 10;
	const int& b = 6;
	cout<< b<<endl;
	int& c = a;  // int& c = 6 error
	// b = 9;
	cout<< a<<","<<c<<endl;
	c = 8;
	cout<< a<<","<<c<<endl;

	 return 0;
}
