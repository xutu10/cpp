#include"operator.h"
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Complex c1(3,5);
	Complex c2(4,6);
	c1.add(c2);
	cout<<c1.real_<<"+"<<c1.imag_<<"i"<<endl;

	Complex c3 = c1 + c2;    //c1.operator(c2); invoke the func
	// Complex c3 = c1.operator +(c2);
    return 0;
}
