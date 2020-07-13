#include<iostream>
#include<typeinfo>
using namespace std;

// c++11
template<typename T, typename U>
auto getMin(T&& a, U&& b) -> decltype(a<b?a:b){

	return a<b?a:b;
}

//c++14
template<typename T, typename U>
decltype(auto) getMax(T&& a, U&& b){
	return a > b? a:b;
}

int main(){


	// just for decltype
	int a = 0, b= 0;
	decltype(a + b) c = 0; //  c is int, a + b return a rval
	decltype(a += b) d = c; // d is int&, a += b return a lval

	d = 20;
	// c = 20 ???
	cout<< "d is a lval:"<< c << endl;
	
	auto rslt = getMin(3,3.5);
	cout<< typeid(rslt).name()<<endl;

	auto r = getMax(4.4 , 3);
	cout<<r<<endl;
	
	return 0;
}
