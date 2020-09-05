#include<iostream>
#include<memory>  // unique_ptr, c11
                  // make_unique, c14
using namespace std;

/*
  check overwrite func between base and derived class
 */

class Base{
public:

	Base(int num) : data_(num){
		
	}

	void display(int add){
		cout<<"base: "<<data_+add<<endl;
	}
	
	~Base()	{
		
	}
protected:
	int data_;
};


class Derived:public Base{
public:
	
	Derived(int n): Base(n){
		
	}

	void display(char c){
		Base::display(5);
		cout<<"child: "<<c<<endl;
	}

	void display(int add){
		// if data_ is public or protected in base, here it can be accessed
		cout<<"child: "<<Base::data_+add<<endl;
	}
	
};

int main(){

	Base b(10);
	b.display(1);

	cout<<"Child start"<<endl;
	Derived d(5);
	d.display('a');
	d.display(2);

	// polymorphism
	unique_ptr<Base> b_ptr = make_unique<Derived>(6);
	b_ptr->display(2);  // display of base will be called
	
	return 0;
}
