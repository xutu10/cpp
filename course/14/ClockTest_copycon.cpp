#include"Clock_copycon.h"
#include<iostream>
#include<stdio.h>
using namespace std;

void ctest(const Clock c){
	
}


void ctest2(const Clock& c){
	
}

Clock ctest3(const Clock& c){
	Clock c1 = c;  // on stack, still the same address back to main
	return c1;
}

Clock& ctest4(const Clock& c){

	Clock *c1 = new Clock(c);  // on heap, 0x030, just local variable
	printf("pointer self: %p, pointer to:%p \n", &c1, c1);
	cout<<"back to main"<<endl;
	c1->update();
	//  a new stack object will be returned	
	return *c1;
}

int main(int argc, char *argv[])
{
    Clock c1(1,1,1);
	c1.display();
//	Clock c2(c1);
	// Clock c2 = c1; equal to above
	// when formal param(no space in memory) transfer to actual param(with space), call the copycon
//	ctest(c1);
	// when param is reference, no need to call copycon
	ctest2(c1);
	// when return value is the typ of Clock, will call copycon to
	// create a temporary object(with new space in memory) and will be destroyed immediately
	cout<<"test3: ";
	ctest3(c1);
	// in blow two case, temporary object will be renamed c2 and exists still.
	cout<<"test3 new object: ";
	Clock c2 = ctest3(c1);
	printf("address:%p \n", c2);
	
	cout<<"test3 new ref: ";
	// const object call non-const function
	const Clock& c3 = ctest3(c1);
	printf("address:%p \n", c3);
    // get back a reference from the function,  c4 will be init with the reference, must call copycon to create the space. 
	cout<<"test4: ";
	Clock c4 = ctest4(c1);
	printf("address:%p \n", c4);
	c4.update();
	
    return 0;
}
