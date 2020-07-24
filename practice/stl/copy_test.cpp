#include<iostream>
#include<memory>
#include<typeinfo>

/**
   copy function for int[]

   + can not be init by make_shared for array, only by make_unique
   + ptr init semantic for array
   + copy only to raw pointer, because copy constructor of unique_ptr isnot allowed
   + no operator * and [] for unique_ptr
 */


int main(){

	// int[]
	int a[]{5,6,7};

	//    auto s_ptr = std::make_shared<int[]>(3); wrong	
	// std::unique_ptr<int[]> s_ptr(new int[3]); init OK
	auto s_ptr = std::make_unique<int[]>(3);  
	auto raw_ptr = s_ptr.get();  // raw_ptr is pointer of int
	// std::copy(a, a+3, s_ptr);  // copy constructor isnot allowed for unique

	// invalid use of array with unspecified bounds
	std::copy(a, a+3, raw_ptr);
	for(auto i = 0; i < 3; i++ )
		std::cout<<raw_ptr[i]<<","; 
	std::cout<<"\n";

	return 0;
}
