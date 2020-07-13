#include<iostream>
#include<stdio.h>

using namespace std;

void Plus(int&& a, int&& b){

	cout<< a + b <<endl;
}

class T{
public:
	T(int a):m_data(a){
		cout<< "first is called"<<endl;
	}

	 T(const T& other){
		 cout<<"copy is called"<<endl;
		 *this = other;
	 }

	bool isSame( T& other){
		bool flag;

		flag = this == &other;
		// *this == other; doesn't work, syntax
		printf("addess of this %p, address of other %p \n", this, &other);
		printf("addess of *this %p, address of other %p \n", *this, other);

		//*this = other;

	   return flag;
	}
	
	int m_data;
	//	int m_a;
};

int main(){

	T t = 1;
	// syntax: t and &t are address
	printf("value of t %p, address of t %p \n", t, &t);

	// the type of t2 is reference which has no allocation
	//syntax: &t2 represents the address of t as well
	T& t2 = t;
	printf("value of t2 %p, address of t2 %p \n", t2, &t2);
	T t3 = t;
	printf("value of t3 %p, address of t3 %p \n", t3, &t3);
   

	cout<<"call isSame"<<endl;
	bool flag2 = t.isSame(t2);
	bool flag3 = t.isSame(t3);
    cout<< flag2<<","<<flag3<<endl;
	
	//Plus(1,2);

	int a = 3;

	//	Plus(move(a),3);
	
	return 0;
}
