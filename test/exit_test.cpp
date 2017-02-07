#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

int add(int a){
	if(1 == a)
		return EXIT_SUCCESS;
	else
		return EXIT_FAILURE;
}

int main(){

	int a = 1;
	assert(add(a) == EXIT_SUCCESS);
	cout<<"finish"<<endl;

	return 0;
}

