#include<iostream>
#include<memory>
#include<vector>
#include<typeinfo>

/**
   # compare vector and unique_ptr<T[]>
   # using replaces typedef, 	using v_int = std::vector<int>;
   # range based for loop just for container, so it's not suitable for pointer to an array, 
 */

int main(){

	// create a uni_ptr with a raw pointer, error double free
	// std::vector<int>* tmp_ptr = &a;
	// std::unique_ptr<std::vector<int>> a_ptr(tmp_ptr);

	using v_int = std::vector<int>;
	v_int* v_ptr = new v_int{1,2,3};

	
	// for not working for pointer, how to convert pointer to vector???
	// iterator
	for(auto it = v_ptr->begin(); it!= v_ptr->end(); it++)
		std::cout<<*it<<",";
	std::cout<<std::endl;

	// v_int& ref = *v_ptr;
	for(auto it : *v_ptr)
		std::cout<<it<<",";
	std::cout<<std::endl;

	// ################################
	// unique_ptr<int[]>
	std::unique_ptr<int[]> uni_ptr(new int[3]());
    auto arr_ptr = std::make_unique<int[]>(3);
	// std::unique_ptr<int[]> arr_ptr{9,8,7}; no working
	// std::unique_ptr<int[]> tmp_ptr(new int{9,8,7}); no working
	//	std::cout<<typeid(arr_ptr).name()<<","<<typeid(uni_ptr).name()<<std::endl;
	arr_ptr[0] = 9;
	arr_ptr[1] = 8;
	arr_ptr[2] = 7;

	auto raw = arr_ptr.get();
	std::cout<<typeid(raw).name()<<std::endl;

	// for(auto it : raw)
	// 	std::cout<<it<<",";
	// std::cout<<std::endl;
		
	
	delete v_ptr;
	
	return 0;
}
