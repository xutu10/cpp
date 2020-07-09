#include<iostream>
#include<typeinfo>
using namespace std;

// c++11
template<typename T, typename U>
auto getMin(T&& a, U&& b) -> decltype(a<b?a:b){

	return a<b?a:b;
}

int main(){

	auto rslt = getMin(3,3.5);
	cout<< typeid(rslt).name()<<endl;

	return 0;
}
