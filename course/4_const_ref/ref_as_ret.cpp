#include<iostream>
using namespace std;

int a[] = {0,1,2,3};

int& index(int i){
	return a[i];
}

int add(int a, int b){
	int sum = a+b;
	return sum;
}

int main(int argc, char *argv[])
{
	index(3) = 100;
	cout<<a[3]<<endl;
	int ret = add(3,4);
	// int& ref = add(5,6);
	cout<<ret<<endl;  // ret is assigned to the return value
	//cout<<ref<<endl;  // not sure, ref has no own memory space
	                  // the return value is a reference which point to a local variable that doesn't exist no more.
    return 0;
}
