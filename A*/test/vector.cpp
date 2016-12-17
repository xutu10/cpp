#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> v1 = {1,2,3};
	vector<int> v2 = {1,3,2};
	vector<vector<int> > v;
	v.push_back(v1);
	v.push_back(v2);

	for(vector<int> a : v){
		for(int i:a)
			cout<<i<<",";
		cout<<endl;
	}

	cout<<"----------"<<endl;
	if(v1 == v2)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	

	return 0;
}
