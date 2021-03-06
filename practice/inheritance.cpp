#include<iostream>
using namespace std;

class Base{

public:
	Base(int a):a_(a){
		cout<<"constructor base"<<endl;
	}
	~Base(){
		cout<<"destructor base"<<endl;
	}
	virtual void increment(){
		a_++;
		
	}
	void show(){
		cout<<"show in base: "<<a_<<endl;
	}
	
	int a_;
	
};

class Derived : public Base{
public:
	Derived(int b, int c, int a):b_(b), c_(c), Base(a){
		cout<<"constructor Derived"<<endl;		
	}
	~Derived(){
		cout<<"destructor Derived"<<endl;
	}
	void increment(){
		a_ = a_+ b_+c_;
	}

	void display(){
		cout<<a_<<","<<b_<<","<<c_<<endl;
	}
int b_,c_;	
	
};

int main(){

	//1. an object of Base will be created in the Derived object
	// show() is inherited from Base
	Derived d(1,2,3);
	d.increment();
	d.show();
	d.display();

	// 2. layout and size
	Base b(8);
	b.increment();
	b.show();
	// 4+8+alignment = 16, 4+8+4+4+alignment = 24
	cout<<sizeof(Base)<<","<<sizeof(Derived)<<endl;
	// memory layout
	cout<<&d<<"\n"<<&d.a_<<"\n"<<&d.b_<<"\n"<<&d.c_<<"\n"<<&d.Base::a_<<endl;

	// 3. Polymorphism
	Derived dd(4,5,6);
	Base *bb = &dd;
	cout<<"--------------"<<endl;
	cout<<"size of bb: "<<sizeof(*bb)<<endl;;
	bb->increment();  // from Derived
	bb->show();
	// bb->display();  Base doesn't have the member func
	cout<<&dd<<","<<&dd.a_<<","<<&dd.b_<<","<<&dd.c_<<","<<&dd.Base::a_<<endl;
	// Base doesn't have b_ and c_
	// &(bb->b_)<<"\n"<<&(bb->c_)
	cout<<bb<<","<<&(bb->a_)<<","<<&bb->Base::a_<<endl;
	
	
	return 0;
}
