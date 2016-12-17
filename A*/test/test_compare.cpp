#include<iostream>
using namespace std;


bool is_goal(int arr1[],int arr2[]){
	bool flag = true;

	for(int i =0;i<9;i++){
		if(arr1[i] != arr2[i]){
			flag = false;
			break;
		}
	}

	return flag;
}

int main(){

	int arr1[] = {1,2,3,4,5,6,7,8,9};
	int arr2[] = {1,2,3,4,5,6,7,8,9};

	cout<<is_goal(arr1,arr2)<<endl;
	cout<<"---------------"<<endl;
	int options[9][4] = {{2,4},    // current position 1     
					{1,3,5},  // 2
					{2,6},    // 3
					{1,5,7},  // 4
					{2,4,6,8}, // 5
					{3,5,9},  //6 
					{4,8},    //7
					{5,7,9},  //8
					{6,8}	}; 

	int option[4];

	
	return 0;
}
