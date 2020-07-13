#include<iostream>
#include<typeinfo>

// arg must be a rval
void func(int&& i){
	std::cout<<"rval: "<<i<<std::endl;
}


void show(int &t){
	std::cout<<"lvalue , ";
}

void show(int &&t){
	std::cout<<"rvalue , ";
}

template<typename T>
void Test(T &&t){
	// *** regardless of the origin tpye of arg,
	// in the function arg is treated as lvalue
	show(t);    // always lvalue
	// get the origin type by forward func
	show(std::forward<T>(t));  
}


int main(){

	

	int a = 2;
	std::cout<<"a: ";
	Test(a);    // lval, lval
	std::cout<<std::endl;
	
	std::cout<<"1: ";
    Test(1);   // lval, rval
	std::cout<<std::endl;

	std::cout<<"forward a: ";

	Test(std::forward<int>(a));   // lval, rval
	//it depends on the T, int is rval
	                            
	std::cout<<std::endl;

	return 0;
}
