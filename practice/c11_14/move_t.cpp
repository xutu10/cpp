#include<iostream>

class A{

	friend A getA();

public:
	A(){
		
	}

	A(int size): m_size(size){
		m_data = new int[m_size];
		std::cout<<"constructor"<<std::endl;
	}

	A(const A& other){
		m_size = other.m_size;
		m_data = new int[m_size];
		// shallow or deepy
		std::cout<<"copy constructor"<<std::endl;
	}

	A(const A&& other){
		m_size = other.m_size;
		std::cout<<"moved"<<std::endl;
	}

	void show(){
		
		std::cout<<"show it"<<std::endl;
	}

	~A(){
		if(m_data != nullptr)
			delete[] m_data;
		std::cout<<"destructor"<<std::endl;
	}
	

private:
	int *m_data;
	int m_size;
};

A getA(){
	A temp_a(1);
	std::cout<<temp_a.m_size<<std::endl;

	return temp_a;
}

A&& geta(){

	A temp_a(1);
	std::cout<<"not friend func"<<std::endl;
	return std::move(temp_a);
	
}

int main(){

	A a(3);  // contructor
	A b(b);  // copy
	A c(std::move(b));  // move

	std::cout<<"############"<<std::endl;
	// check return value
	//	A d = getA();   // return local var, segment fault
	//A e = geta();     // return local var, segment fault

	A&& e = geta();  // ok
	e.show();

	
	return 0;
}
