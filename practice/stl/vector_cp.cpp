#include<iostream>
#include<vector>
#include<memory>  
#include<stdio.h>

/**
   copy vector with std::copy
   compared with raw and unique ptr
 */

int main(){

	using v_int = std::vector<int>;
	
	v_int data{1,2,3};
   
	//	ptr = &data; wrong

	// raw pointers
	v_int* raw_ptr = &data;
	v_int* raw_cp_ptr = new v_int(3);
   
	// copy by raw pointer
	std::cout<<"copy by raw pointer"<<std::endl;
	std::copy(raw_ptr->begin(), raw_ptr->end(), raw_cp_ptr->begin());

	for(auto i : *raw_cp_ptr)
		std::cout<<i<<",";
	std::cout<<"\n";

	// ########################################## 
	// iterate unique ptr by for,
	// was not working, segment fault => didn't allocate for dest 
	std::cout<<"copy by unique ptr"<<std::endl;
	auto ptr = std::make_unique<v_int>(data);
    auto cp_ptr = std::make_unique<v_int>(3);

	std::copy(ptr->begin(), ptr->end(), cp_ptr->begin());
	
	for(auto i : *cp_ptr)
		std::cout<<i<<",";
	std::cout<<"\n";
	
	delete raw_cp_ptr;

	return 0;
}
