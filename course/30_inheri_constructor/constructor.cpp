#include<iostream>
using namespace std;

class Parent{
public:
	Parent(int a): a_(a){
		cout<<"parent"<<endl;
	}
	~Parent(){
		cout<<"deconstructor parent"<<endl;
	}
	int a_;
};

class Child : public Parent{
public:
	Child(int a, int b): b_(b), Parent(a){
		cout<<"child"<<endl;
	}
	~Child(){
		cout<<"deconstructor child"<<endl;
	}
	int b_;
};

int main(int argc, char *argv[])
{
//	Parent p;
	Child c(6,10);
	cout<<c.Parent::a_<<" "<<c.b_<<endl;
	return 0;
}
