#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

// vector c11
// 2. iterator
template<typename T> 
void show(const vector<T>& a){
	for(auto const_it = a.cbegin();const_it!=a.cend();const_it++)
		cout<<*const_it<<"\t";
	// *const_it = 10; not allowed
	cout<<endl;
}


template<typename T>
void increment(vector<T>& v){
	for(auto it = v.begin(); it != v.end(); it++)
		(*it)++; 
}

int main(){
	// c11
	//1. Constructor
	vector<int> b = {1,4,8,9};
	show(b);

	
	// vector<int> c(5,6); 

	//	int ints[] = {4,5,6,7};
	//  vector<int> a(ints, ints+sizeof(ints)/sizeof(ints[0]));

	// // c11, const_iterator
	increment(b);
	show(b);
	cout<<b.size()<<","<<b.capacity()<<endl;
	// // 3. other funcs
	b.push_back(2);
	show(b);
	cout<<b.size()<<","<<b.capacity()<<endl;
	int add[]= {100,100	};
	auto it = b.begin();
	b.insert(it+1,add,add+2);
	show(b);
	cout<<b.size()<<","<<b.capacity()<<endl;
		
	b.pop_back();
	show(b);

	cout<<b[3]<<endl;  // 4
	b.erase(it+1, it+3); // delete 100,100
	show(b);

	// string
	vector<string> s = {"aaa", "bbb","ccc"};	
	// for(auto const_it = s.cbegin();const_it != s.cend();const_it++)
	// 	cout<<*const_it<<",";
	// cout<<endl;
	show(s);
    // not allowed?
	// vector<pair<int,char>> p;
	
	
	return 0;
}
