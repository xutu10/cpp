#include<iostream>

int main(){

	int a = 2;
	int* a_ptr = &a;

	std::cout<<*a_ptr<<std::endl;

	int arr[]{1,2,3};
	int* arr_ptr = arr;
	std::cout<<arr_ptr[0]<<std::endl;
	

	return 0;
}
