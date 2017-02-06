#include"String.h"
#include<string.h>
#include<iostream>
using namespace std;

String::String(char* str){

	str_ = AllocAndCopy(str);
}

String::~String(){
	delete[] str_;
}


String::String(const String& s){

    str_ = AllocAndCopy(s.str_);
	
}
// return referenc, in order to invoke copycon as few as possible 
String& String::operator =(const String& s){
	if(this == &s)
		return *this;
	delete[] str_;
	str_ = AllocAndCopy(s.str_);
	return *this;
}

// mutable copy
char* String::AllocAndCopy(char* s){
	int len = sizeof(s) + 1;
	char* ret = new char(len);
	memset(ret,0,len);
	strcpy(ret,s);
	return ret;
}

void String:: display(){
	cout<<str_<<endl;
}
