#pragma once

class Integer{
public:
	Integer(int a);
	~Integer();
	Integer& operator++();
//	friend Integer operator++(Integer& i);
//	friend Integer& operator++(Integer& i);
	Integer operator++(int i);
	// type casting overloading
	operator int();
	void display() const;
private:
	int n_;	
};
