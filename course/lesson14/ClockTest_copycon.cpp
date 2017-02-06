#include"Clock_copycon.h"
#include<iostream>
using namespace std;

void ctest(const Clock c){
	
}


void ctest2(const Clock& c){
	
}

Clock ctest3(const Clock& c){
	return c;
}

const Clock& ctest4(const Clock& c){
	return c;
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
	ctest3(c1);
	// in blow two case, temporary object will be renamed c2 and exists still.
	Clock c2 = ctest3(c1);
	const Clock& c3 = ctest3(c1);
    // get back a reference from the function,  c4 will be init with the reference, must call copycon to create the space. 
	Clock c4 = ctest4(c1);
    return 0;
}
