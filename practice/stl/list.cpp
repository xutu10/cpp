#include<iostream>
#include<list>
#include<stdio.h>
#include<string>

using namespace std;

template<typename T> 
void show(const list<T>& a){
	for(auto const_it = a.cbegin();const_it!=a.cend();const_it++)
		cout<<*const_it<<"\t";
	// *const_it = 10; not allowed
	cout<<endl;
}

//template<>, no matched template
void show(const list<pair<int, string> > a){
	for(auto const_it = a.cbegin();const_it!=a.cend();const_it++)
		cout<<const_it->first<<","<<const_it->second<<endl;
}

template<typename T>
void increment(list<T>& v){
	for(auto it = v.begin(); it != v.end(); it++)
		(*it)++; 
}

int main(){

	list<int> li = { 1,2,3	};
	show(li);
	increment(li);
	show(li);

	int add = 10;
	// val is copied
	li.push_front(add);
	show(li);
	
	auto it = li.cbegin();
	// cout<<&add<<","<< it <<endl;
	printf("add: %d, list: %d \n", add, *it);
	printf("add: %p, list: %p \n", &add, it);

	li.push_back(10);
	// address of each element
	// for(it;it!= li.cend(); it++)
	//    	printf("list element:%d %p \n", *it, it);

	li.remove(3);
	show(li);
	// just remove one duplicate element by calling unique
	li.push_front(10);
	cout<<"after adding 10: ";
	show(li);
	// 10 10 2 4 10
	li.unique();
	cout<<"after unique: ";
	show(li);
	// 10 2 4 10
	
	li.sort();
	show(li);

	list<string> ls = {"aaa","bbb","ccc"};
	show(ls);

	// wrong syntax
	// list<int, string> lis;
	// lis.push_back(1,"sss");

	
	return 0;
}
