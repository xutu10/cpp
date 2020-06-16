#include<iostream>
#include<cstring>
#include"max.h"

using namespace std;


class Test{
public:
	// ??? without friend only one parameter is not allowed
	friend bool operator<(const Test& t1,const Test& other){
		cout<<"friend function"<<endl;
		return true;
	}
	
};

int main(int argc, char** arg){
	// templ 1
	cout<< ::max(5.5, 6.6)<<endl;  // ambiguous, std::max()
	Test t1,t2;	
	// templ 1, friend function
	:: max(t1,t2);
	// Test can be passed to template
	// because Test doesn't support symbol '<'

	// in this way the address of pointer will be compared, rather than the content
	const char* str1 = "ccc";
	const char* str2 = "bbb";
	// temeplate specialization
	cout<<::max(str1,str2)<<endl;
	// cout<<::max("aaaa","bbbb")<<endl; type of parameter doesn't match

	// test for overload
	cout<<::max(1,4,3)<<endl;

	// template int
	cout<<::max('a',100)<<endl;  // works only by non-template function
	                           // 'a' is implicitly cast to int

	cout<<::max(97,100)<<endl; // will call non-template func
	// template 1
	cout<<::max<>(97,100)<<endl; // force to call template func
	return 0;
}
