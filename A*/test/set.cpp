#include<iostream>
#include<set>
#include<utility>    //pair, make_pair
using namespace std;

/**
 *  implementation of A* search for puzzle 
 *  use set instead of map, because want to sort collection by value
 *  in set can take cost as key and number as value, double keys are
 *  allowed while map aren't
*/
int main(){
	// typedef pair<int, int> pairs;
	// set<pairs > cost;
	// set<pairs> :: iterator it;

	set<pair<int,int> > cost;
	set<pair<int,int> > :: iterator it;
	int size = 3;
	pair<int,int> p[size];

	//	pairs p[size];
	p[0] = make_pair(2,1);
	p[1] = make_pair(4,5);
	p[2] = make_pair(2,9);
	
	for(int i = 0; i<size;i++)
		cost.insert(p[i]);

	for(it = cost.begin();it!=cost.end();it++)
		cout<<it->first<<","<<it->second<<endl;

	cout<<"------------"<<endl;

	cost.insert(make_pair(1,6));
	for(it = cost.begin();it!=cost.end();it++)
		cout<<it->first<<","<<it->second<<endl;

	for(it = cost.begin();it!=cost.end();it++)
		cout<< it->second<<",";
	cout<<endl;
	
	return 0;
}
