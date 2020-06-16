#ifndef MAX_H
#define MAX_H

//#include<cstring>
#include<iostream>
using namespace std;

template <typename T>
const T& max(const T& a, const T& b){
	cout<<"templ 1"<<endl;
	return a<b? b:a;
}

// example for template overload by template
template <typename T>
const T& max(const T& a, const T& b, const T& c){
	cout<<"templ 2 with 3 params"<<endl;

	return ::max(a,b) < c ? c: ::max(a,b);
}

// example for template overload by function
const int& max(const int& a, const int& b){
	cout<<"templ 3 int"<<endl;

	return a<b? b:a;
}


// example for template specialization
template<>
const char* const& max(const char* const&a, const char* const&b){
	cout<<"templ 4 special char"<<endl;

	return strcmp(a,b) < 0 ? b : a;
}

#endif  // MAX_H
