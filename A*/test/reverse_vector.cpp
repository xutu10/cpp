#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

	vector<int> arr = {1,2,3,4};
	reverse(arr.begin(),arr.end());

	for(int i: arr)
		cout<<i<<",";
	cout<<endl;
	
	return 0;
}
