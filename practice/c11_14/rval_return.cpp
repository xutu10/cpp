#include<iostream>

class X{
public:
	X(int a):m_data(a){
		std::cout<<"constructor"<<std::endl;
	}

	X(const X& other)

	~X(){
		
	}
	

private:
	int m_data;
	
};
