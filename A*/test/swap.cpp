#include<iostream>
#include<utility>
using namespace std;

void reverse(int [],int);

int main(){

	int status[5] = {2,3,6,1,9};
	for(int i = 0;i<5;i++)
		cout<<status[i]<<endl;

	cout<<"-----------"<<endl;
	swap(status[1],status[4]);

	for(int i = 0;i<5;i++)
		cout<<status[i]<<endl;

	cout<<"-----------"<<endl;
	// reverse
	int array[5]={1,2,3,4,5};
	reverse(array,5);
	for(int i = 0;i<5;i++)
		cout<<array[i]<<endl;

	return 0;
}

void reverse(int arr[],int length){
	for(int i =0; i<length/2;i++)
		swap(arr[i],arr[length-1-i]);
}
