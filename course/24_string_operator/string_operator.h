#pragma once
#include<iostream>
using namespace std;

class String{
public:
	String(const char* str);// move constctor
	String(const String& other);
	String& operator=(const String& ohter);
	String& operator=(char* str);
	String operator+=(const String& s);
	void display();
	friend String operator+(const String& s1,const String& s2);
	friend ostream& operator<<(ostream& os,const String& str);
	friend istream& operator>>(istream& is, String& str);
	~String();
//	friend String opeartor+(const String& a,const String& b);
	
private:
	char* str_;	
};
