#include<iostream>
using namespace std;

class Parent{
public:
	void show(){
		val_ = 2;
		cout<<val_<<endl;
	}
	int val_;
};

class Child : public Parent{
public:
	void show(int a){
		val_ = 2;
		cout<<val_+a<<endl;
	}
    int count_;
	int value_;
};

int main(int argc, char *argv[])
{
    Child c;
	c.show(4);
	c.Parent::show();
	cout<<sizeof(Child)<<" "<<sizeof(Parent)<<endl;
	cout<<&show
    return 0;
}
