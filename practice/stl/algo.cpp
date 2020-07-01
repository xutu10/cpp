#include<iostream>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

// template<typename T>  can't deduce tmplt param
void show(int i){

	cout<<i<<",";
}

void show_map(pair<char, int> e){
	cout<<e.first<<","<<e.second<<endl;
}

int main(){

	int myset[] = {1,2,2,4,6,6,9};

	multiset<int> multi_int(myset, myset + (sizeof(myset)/sizeof(int)));
	// for_each with func
	for_each(multi_int.begin(), multi_int.end(),show);
	cout<<endl;

	// find in multiset
	cout<<"find in multiset"<<endl;
	auto it = find(multi_int.begin(), multi_int.end(), 2);
	if (it != multi_int.end())
		cout<<"found it"<<endl;
	
	
	multimap<char, int> multi;
	multi.insert(pair<char,int>('a',10));
	multi.insert(pair<char,int>('b',20));
	multi.insert(pair<char,int>('a',30));
	multi.insert(pair<char,int>('c',10));
	for_each(multi.cbegin(), multi.cend(),show_map);
	

	return 0;
}
