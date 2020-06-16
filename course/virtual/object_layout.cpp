#include<iostream>
#include<stdio.h>

using namespace std;

class A{

public:

	A(int a):_len(a){
		cout<<"constructor A"<<endl;
	}

	virtual void add(){
		cout<<"A add"<<endl;
	}

	void sub(){
		_len--;
		cout<<_len<<endl;
	}

	int _len;
	// int _a   // 16
	double _a; // 24
};

class B:public A{
	
public:

	B(int a):A(a){
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

	double _b;
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

	cout<<sizeof(A)<<endl; // 
	cout<<sizeof(B)<<endl; // 

	// B b(1);

	// printf("object addr:%p\n", &b);  // 2d10	
	// printf("object addr:%p\n", b);   // 2d10
	// printf("_len addr:%p\n", &b._len); // 2d18
	// printf("_b and _c addr:%p %p\n", &b._b, &b._c); // 2d1c, 2d20

	// not working
	// void* bb = (void*)*(unsigned long*)b;

	// Fun a = (Fun) bb;
	// a();
	// Fun A_add = getAddr(&b,0);
	// A_add();

	// B *a = new B(2); 
	// getAddr(a,0);
	
	return 0;
}
