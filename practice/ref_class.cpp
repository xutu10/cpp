#include<iostream>
#include<stdio.h>
using namespace std;

class T{

public:
	T(int a):m_a(a){
		
	}


	~T(){
		
	}

	T& get_a(){
		printf("address of this: %p\n", this);

		return *this;
	}

	void display(){
		cout<<this->m_a<<endl;
	}
	
	
private:
	int m_a;
	
};


int main(){

	T t1(5);
	T t2(4);
	t2.display();

	T& t3 = t2.get_a();
	t3.display();
	printf("address of t3: %p\n", t3);
	   
	
	t2 = t1.get_a(); // not the same address
	printf("addr of t1: %p, addr of t2: %p\n", t1, t2);
	t2.display();

   
	return 0;
}
