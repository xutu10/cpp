#include<iostream>
using namespace std;

class Parent{
public:
	Parent(int a,int b,int c):val_(a),count_(b),y_(c){
		
	}
	void show(){
		cout<<val_<<endl;
	}
	int val_;
	int count_;
	int y_;
};

class Child : public Parent{
public:
	Child(int a, int b,int c,int d):val_(a),Parent(b,c,d){
		
	}
	void show(int a){
		cout<<val_+a<<endl;
	}
	int val_;
};

int main(int argc, char *argv[])
{
    Child c(2,4,6,8);
	cout<<c.val_<<" "<<c.Parent::val_<<endl;
	cout<<&c<<" "<<&c.val_ <<" "<<&c.Parent::val_<<" "<<&c.Parent::count_<<" "<<&c.count_<<" "<<&c.y_<<endl;
//0x7ffc86584850 0x7ffc86584858 0x7ffc86584850 0x7ffc86584854 0x7ffc86584854

	c.show(1);
	c.Parent::show();
//	cout<<&Child::show<<" "<<&Parent::show<<endl; 1 1
//	cout<<&c.Parent<<endl; doesn't work
    return 0;
}
