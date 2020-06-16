#include<iostream>
using namespace std;


int main(){

	int arrSize = 5;
	int arr1[5];
	int arr2[5] = {1,2,3,4,5};
	
	for(int i=0; i<arrSize; i++){
		cout<<"i,"<<arr1[i]<<endl;
	}

	// array can't be assigned
	//	arr1 = arr2;

	for(int i=0; i<arrSize; i++){
		cout<<"i,"<<arr1[i]<<endl;
	}
	



	return 0;
}
