#include"constructor.h"
#include<iostream>
using namespace std;

//global object, is invoked before main
constructor con4(6);

int main(int argc, char *argv[])
{
	// this two objects in stack, after the mainscope automatic invoke destructor
    constructor con1(88);
	con1.display();
	constructor con2;
	con2.display();
	// new not only allocate memory for this object but also invoke constructor
	// this object is in heap, destruct before the above ojects
	constructor* con3 = new constructor(68);
	con3->display();
	//effect of delete: release the allocated memory and invoke destructor
	delete con3;
	return 0;
}




