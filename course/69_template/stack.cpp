#include<iostream>
//#include"stack.h"
#include "stack2.h"
using namespace std;

int main(int argc,char** arc){

	// class template just can be instantiated explicitly
	// not like function template can be inducted by complier

	//	Stack<int> s(2);

	Stack2<int ,2> s;
	s.push(1);
	s.push(2);

	while(!s.isEmpty()){
		cout<<s.top()<<endl;
		s.pop();
	}
	
	return 0;
}
