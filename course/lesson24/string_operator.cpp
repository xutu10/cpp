#include"string_operator.h"
#include<string.h>

String::String(const char* str){
	int len = strlen(str) + 1;
	str_ = new char[len];
	memset(str_,0,len);
	strcpy(str_,str);
}
// implement deep copying instead of shallow
String::String(const String& other){
	int len = strlen(other.str_) + 1;
	str_ = new char[len];
	memset(str_,0,len);
	strcpy(str_,other.str_);
}

String& String::operator=(const String& other){
	int len = strlen(other.str_) + 1;
	str_ = new char[len];
	memset(str_,0,len);
	strcpy(str_,other.str_);
	return *this;  //return content of the pointer
	//namely the object, ref is the second name of object.
}
String& String::operator=(char* str){
	delete[] str_;
	int len = strlen(str) + 1;
	str_ = new char[len];
	memset(str_,0,len);
	strcpy(str_,str);
//	cout<<"haha"<<endl;
	return *this;
}

String String::operator+=(const String& s){
	*this = *this + s;
	return *this;
	
}

void String::display(){
	cout<<str_<<endl;
}

String::~String(){
	delete[] str_;
}
String operator+(const String& s1,const String& s2){
	int len = strlen(s1.str_) +strlen(s2.str_);
	char* new_str = new char[len];
	memset(new_str,0,len);
	strcpy(new_str,s1.str_);
	strcat(new_str,s2.str_);

	
	String tmp(new_str);
	delete new_str;
	return tmp;
}

ostream& operator<<(ostream& os,const String& str){
	os<<str.str_;
	return os;
}

istream& operator>>(istream& is,String& str){
	char tmp[128];
	cin>>tmp;
	str = tmp;     // when const String& str leads to error
	               // const variable cann't be changed.
	return is; 
}

