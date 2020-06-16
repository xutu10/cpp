#include<iostream>
#include<stdio.h>

using namespace std;


typedef void (*Fun)();

class Base{
public:
	Base(){}
	virtual void fun1(){
		cout<<"base:fun1"<<endl;
	}
	virtual void fun2(){
		cout<<"base:fun2"<<endl;
	}
	~Base()	{}
	
};

class Derived:public Base{
public:
	Derived(){}
	void fun1(){
		cout<<"Derived:fun1"<<endl;
	}

	void fun2(){
		cout<<"Derived:fun2"<<endl;
	}
	~Derived(){	}
};


Fun getAddr(void* obj, int offset){
	
	cout<<"==========="<<endl;
	void* vptr_addr = (void*)*(unsigned long*)obj;
	printf("address:%p\n", vptr_addr);

	void* func_addr =(void*)*((unsigned long*)vptr_addr + offset);
	printf("func address:%p\n", func_addr);

	return (Fun)func_addr;
}


int main(){

	Base b;
	Derived d;
	Base *ptr = new Derived();
	Derived *dptr = new Derived();
	Base &bref = d;
	Base &bbref = *ptr;
	Base &bbbref = *dptr;

	d.fun1();
	bbref.fun1();
	bbbref.fun1();

	Fun df1 = getAddr(&b,0);
	df1();
	Fun df2 = getAddr(ptr,1);
	df2();
	
	Fun bf1 = getAddr(&bref,0);
	df1();
	Fun bf2 = getAddr(&bbref,1);
	df2();

	delete ptr;
	delete dptr;

	return 0;
}

