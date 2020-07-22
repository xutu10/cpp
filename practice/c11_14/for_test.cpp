#include<iostream>
#include<vector>
#include<cstring>
#include<map>

/**
   # test for range-based for loop since c++11
   # references an array, int (&ref_a)[4] = a;
 */

//	for(auto em : *a_ptr)
//for(auto em : a)

int main(){

	int a[] = { 2,4,6,8};
	int* a_ptr = a;
	
	// pointer to int, not array
	// int (&ref_a)[4] = *a_ptr;

	int (&ref_a)[4] = a;
	for(auto em : ref_a)
		std::cout<<em<<",";
	std::cout<<std::endl;

	
	// std::vector<std::string> slist = {"aaa", "bbb","ccc"};

	// for(auto s : slist){
	// 	std::cout<<s<<","<<std::endl;
	// }


	// std::map<std::string, int> mlist;
	// mlist["c"] = 10;
	// mlist["b"] = 20;
	// mlist["a"] = 30;

	// for(auto m : mlist)
	// 	std::cout<<m.first<<","<<m.second<<std::endl;
	

	return 0;
}
