#include<iostream>
#include<vector>
using namespace std;

int main(){

	vector<int> v1 = {
		1,2,3,4	};
	vector<int> v2 = {
		1,3,2,4	};
	if(v1 ==v2 )
		cout<<"same"<<endl;
	else
		cout<<"not same"<<endl;

	return 0;
}
