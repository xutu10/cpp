#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){


	vector<int> intList(5);
	vector<string> stringList;
	vector<char> vecList;
	vector<char> newList(vecList);
	vector<int> list2(0,5);
	for(int i = 0; i < 5; i++){
		intList[i] = i * 5;
		cout<<intList[i]<<" ";
	}
	cout<<endl;
	// cout<< intList.at(3) <<endl;
	// cout<< intList[3] <<endl;
	// cout<< intList.front() <<endl;
	// cout<< intList.back() <<endl;
	// cout<< intList.capacity() <<endl;
	// cout<< intList.empty() <<endl;
	intList.resize(6,4);
	for(int i = 0; i < intList.size(); i++){
		cout<<intList[i]<<" ";
	}
	cout<<endl;

	vector<int>::iterator iter;
	iter = intList.begin();
	for(iter = intList.begin(); iter != intList.end();++iter)
		cout<< *iter << " ";

	cout<<endl;
   
	return 0;
}
