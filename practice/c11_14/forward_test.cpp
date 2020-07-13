#include<iostream>
#include<typeinfo>

using namespace std;

template<typename T, typename U>
decltype(auto) Plus(T&& t, U&& u){
	//	return forward<T>(t) + forward<U>(u);
	return t + u;
}

class X{

	friend X operator+(const X& x1, const X& x2){
		return X(x1.m_data + x2.m_data);
	}
public:
	explicit X(int a):m_data(a){
		cout<<"constructor"<<endl;
	}

	void display() const{
		cout<< this->m_data<<endl;
	}

	~X(){
		
	}
	
private:
	int m_data;
};


int main(){

	int a = 10;
	int b = 20;

	cout<< Plus(a,b)<<endl;

	float f = 10.5;
	cout<<Plus(f, 9.8)<<endl;

	string h = "hello,";
	cout<<Plus(h, "world")<<endl;

	auto m = Plus(f, a);
	cout<<typeid(m).name()<<endl;

	X x1(9);
	X x2(8);
	X x3 = Plus(x1, x2);
   	x3.display();
	
	// X x4 = Plus(x1, 6);
	// x4.display();
	
	return 0;
}
