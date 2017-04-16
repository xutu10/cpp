#include"constructor.h"
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    constructor con[2] = {66,88};
	// con1[] in heap must self invoke the destructor
	constructor* con1 = new constructor[2];
	delete[] con1;
    return 0;
}


















