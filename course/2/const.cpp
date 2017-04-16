#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int a = 100;
	const int* p = &a;
//	a = 150;  no error ??? it should be
//	thar the value of the address cann't be changed
//	*p= 10000;     error, *p read-only
	cout<<*p<<endl;
	int b = 200;
	p = &b;
	cout<<*p<<endl;

	int c = 300;
	int d = 400;
	int* const p1 = &c;
	cout<<*p1<<endl;
//	p1 = &d; read-only
	*p1 = 350;
	cout<<*p1<<" "<<c<<endl;  // c == 350;
    return 0;
}
