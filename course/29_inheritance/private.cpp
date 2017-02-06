#include<iostream>
using namespace std;

class Parent{
public:
	Parent(int a):val_(a){
		
	}
	void show(){
		cout<<val_<<endl;
	}
	int val_;
};

class Child : public Parent{
public:
	Child(int a, int b):count_(a),Parent(b){
		
	}
	void show(int a){
		cout<<val_+a<<endl;
	}
	int count_;
};

int main(int argc, char *argv[])
{
    Child c(2,4);
	Parent* p;
	p = &c;
//	int a = 4;
//	c.show(a);
	cout<<c.val_<<endl;
	cout<<c.count_<<endl;
	cout<<p->val_<<endl;
	cout<<p->count_<<endl;

    return 0;
}
