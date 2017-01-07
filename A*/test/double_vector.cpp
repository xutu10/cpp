#include<iostream>
#include<vector>
using namespace std;

int main(){

	vector<vector<int> > doub;
	vector<int> v1 = {1,2,3,4};
	vector<int> v2 = {4,3,2,1};

	doub.push_back(v1);
	doub.push_back(v2);

	for(vector<int> v : doub){
		for(int i : v)
			cout<<i<<" ";
		cout<<endl;
	}
	vector<int> input = {2,3,4};
	//	vector<vector<int> > :: iterator it;
	int i = 0;
    for(i = 0;input != doub[i]&& i < doub.size();i++ );
	if(i == doub.size())
		cout<< "new status";
	else
		cout<< "already exists";
	
	return 0;
}
