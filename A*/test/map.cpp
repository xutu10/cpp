#include <iostream>
#include <map>
using namespace std;

int main(){
	map<int,int> cost;

	cost[5] = 10;
	cost[2] = 6;
	cost[4] = 12;
	// default sorted ascend by key
	map<int,int>::iterator itr;
	for(itr = cost.begin();itr!=cost.end();itr++)
		cout<<itr->first<<","<<itr->second<<endl;
	cout<<"------------"<<endl;
	// insert new element
	cost.insert(pair<int,int>(1,19));
	for(itr = cost.begin();itr!=cost.end();itr++)
		cout<<itr->first<<","<<itr->second<<endl;	

	return 0;
}
