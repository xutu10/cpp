#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<typeinfo>

/**
   1. ref to array
   int (&b)[3] = a;
 */

// template<typename T>
// void for_each_ptr(T* arr){

// 	std::cout<<"template call with ptr"<<std::endl;
// 	std::for_each(std::begin(*arr), std::end(*arr), [](int n){
// 		std::cout<<n<<std::endl;
// 	});
// }

// a-> pointer, arr is int*
// &a -> int(&)[3], arr is int(*&)[3]
void for_each_ptr(int* arr){

	std::cout<<"call with ptr"<<std::endl;
	std::for_each(std::begin(arr), std::end(arr), [](int n){
		std::cout<<n<<std::endl;
	});
}


int main(){

	// std::vector<char> v_char{'a','b','c'};
	// std::cout<<typeid(v_char).name()<<std::endl;
	
	int a[]{1,2,3};
	printf("a:%p, &a:%p \n", a, &a);
	
	int* ptr_arr = a;  
	int (&b)[3] = a;  // ref to array with number

	std::cout<<"call with ref"<<std::endl;
	std::for_each(std::begin(b), std::end(b), [](int n){
		std::cout<<n<<std::endl;
	});

	std::cout<<"call with array"<<std::endl;
	std::for_each(std::begin(a), std::end(a), [](int n){
		std::cout<<n<<std::endl;
	});

	// T is int, arr=int*&, *arr = int&
	// pointer cannot be converted to a container, arg of begin should be container&
	//	for_each_ptr(a);
	
	// T is int[3],  arr = (*&)[], *arr = &[]
	for_each_ptr(&a);
	

	return 0;
}
