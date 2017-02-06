#pragma once

class String{
public:
	String(char* str="");
	~String();
	String(const String& other);
	String& operator=(const String& s);
	void display();
	
private:
	char* AllocAndCopy(char* s);
	char* str_;
	
};
