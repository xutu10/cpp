#include<iostream>
#include<utility>
using namespace std;

int main(){

	int status[5] = {2,3,6,1,9};
	for(int i = 0;i<5;i++)
		cout<<status[i]<<endl;

	cout<<"-----------"<<endl;
	swap(status[1],status[4]);

	for(int i = 0;i<5;i++)
		cout<<status[i]<<endl;
	

	return 0;
}
