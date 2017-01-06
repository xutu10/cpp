#include<iostream>
#include<vector>
using namespace std;

int main(){

	vector<int> origin = {1,2,3,4};
	vector<int> arr = origin;

	for(int i : arr)
		cout<<i<<",";
	cout<<endl;

	
	return 0;
}
