#include<iostream>
using namespace std;

int main(){

	int length = 3;
	int array[length] = {0};  // array is a pointer and constant variable,which stores the addrese of the first element of array, it cann't be changed
	//int* ptr = new int[length];

	array[0] = 1;
	array[1] = 2;

	cout<<array[0]<<array[1]<<endl;

	return 0;
}
