#include<iostream>
using namespace std;

class Parent{
public:
	int x_;
protected:
	int y_;
private:
	int z_;	
};

class Child: public Parent{
public:
	void init(){
		x_ = 6;
		y_ = 8;
		//z_ = 10;   // not accessible
	}
	void show(){
		cout<<x_<<endl;
	}
private:
	int a_;    // class member redefine
	int x_;
};

int main(int argc, char *argv[])
{
	Parent p;
    Child c;
//	c.x_ = 10; private
	c.init();
	c.show();
	c.Parent::x_; //visit the member or function of Parent
	p.x_ = 8;
//	p.y_ = 11; not accessible here
	
     
    return 0;
}
