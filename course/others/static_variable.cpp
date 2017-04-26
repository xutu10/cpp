#include<iostream>
using namespace std;

void function1();
void function2(int);
// void function2(int&); in c symbol & here is not allowed


int main(){

	static int z = 0;
	for(int count = 0; count<5;count++){
		//		function1();
  		function2(z);
	}
	cout<<z<<endl;
	return 0;
}

void function1(){
	static int x = 0;
	x += 1;
	cout<<x<<endl;
}

void function2(int z){
	z += 1;
}
