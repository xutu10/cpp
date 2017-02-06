#include<stdio.h>
#include<iostream>
using namespace std;

class Parent{
public:
	virtual void fun1(){
		cout<<"Base:fun1..."<<endl;
	}
	virtual void fun2(){
		cout<<"Base:fun2..."<<endl;
	}

	void fun3(){
		cout<<"Base:fun3..."<<endl;
	}
	virtual ~Parent(){
		cout<<"~Parent"<<endl;
	}
	
	int data1_;
};

class Child: public Parent{
public:
	void fun1(){// default virtual func
		cout<<"child fun1"<<endl;
	}
	void fun2(){//default virtual func
		cout<<"child fun2"<<endl;
	}
	void fun3(){
		cout<<"child fun3"<<endl;
	}
	~Child(){
		cout<<"~Child"<<endl;
	}
	
	int data2_;

};


int main(int argc, char *argv[])
{
    // Parent* p;
	// Child c;
	// p = &c;
	// p->fun1();
	// p->fun2();
	// p->fun3();

	Parent*	p;
	Child c;
	p =&c;
	printf("%d %d",&c.data2_,&c.data1_);
//	printf("%d %d %d",p,&p->data1_,&p->data2_); no member of data2_???
	
	delete p;            // if desconstructor without virtual
	                     // just call the desconstructor of Parent
	                     // then lead to memory leak of Child
	
    return 0;
}
