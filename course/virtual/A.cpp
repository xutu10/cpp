#include<iostream>
#include<stdio.h>

using namespace std;

class A{

public:
	A(int a):_len(a){
		cout<<"constructor A"<<endl;
	}

	virtual void add(){
		_len++;
		cout<<_len<<endl;
	}

	void sub(){
		_len--;
		cout<<_len<<endl;
	}

	int _len;
	
};

class B:public A{
	
public:
	B(int b):A(b){
		cout<<"constructor B"<<endl;
	}

	// void add(){
	//     _len= _len+2;
	// 	cout<<_len<<endl;
	// }

	void multiple(){
		_len *= 2;
		cout<<_len<<endl;
	}

	int _b;
};

typedef void (*Fun)();
Fun getAddr(void* obj, int offset){
	
	cout<<"==========="<<endl;
	void* vptr_addr = (void*)*(unsigned long*)obj;
	printf("address:%p\n", vptr_addr);

	void* func_addr =(void*)*((unsigned long*)vptr_addr + offset);
	printf("func address:%p\n", func_addr);

	return (Fun)func_addr;
}


int main(){


	A *a = new B(1);
	// output: con A and con B
	//	a->add();
	// a-> multiple(); a doesn't have the member function

	B b(2);
	//  b. add();
	//  b.multiple();
	//  b.sub();
	//	b.A::add();
	
	printf("derived object address:%p\n", &b);
	printf("address b.A::_len :%p\n", &(b.A::_len));
	printf("address b._len:%p\n", &(b._len));
	printf("address b._b:%p\n", &(b._b));

	Fun base_add = getAddr(&b,0);
	base_add();
	//	printf("member varialbe:%d\n", *addr); not working
   
	// printf("base object address:%p/n", &(b.A)); not working
	return 0;
}
