#include<iostream>
using namespace std;

namespace my{
	const int num = 10;
	void print(){
		cout<<"my namespace"<<endl;
	}
}

int main(int argc, char** arg){

	int num = 5;
	cout<<my::num << " "<<num<<endl;
	my::print();

	return 0;
}

