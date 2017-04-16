#include"plusplus.h"
#include<iostream>
using namespace std;

int add(int a, int b){
	return a+b;
}

int main(int argc, char *argv[])
{
    Integer n(6);
	n.display();
	Integer n2 = ++n;
	n.display();
	n2.display();

	int num = add(n,2);
	cout<<num<<endl;
	
    return 0;
}
