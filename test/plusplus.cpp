#include<iostream>
using namespace std;

int main(int argc, char** arg){


	int list[5] = {0};
	int counter =0;

	// 0 1 1
	list[counter++] = 1;
	cout<<list[counter]<<" "<<counter<<" "<<list[0]<<endl;

	// 2 2
	list[++counter] = 2;
	cout<<list[counter]<<" "<<counter<<endl;
	
	return 0;
}
