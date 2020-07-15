#include<iostream>
#include<vector>
#include<cstring>
#include<map>

/**
   test for range-based for loop since c++11
 */

int main(){

	std::vector<std::string> slist = {"aaa", "bbb","ccc"};

	for(auto s : slist){
		std::cout<<s<<","<<std::endl;
	}


	std::map<std::string, int> mlist;
	mlist["c"] = 10;
	mlist["b"] = 20;
	mlist["a"] = 30;

	for(auto m : mlist)
		std::cout<<m.first<<","<<m.second<<std::endl;
	

	return 0;
}
