#pragma once

class Complex{
public:
	Complex(int r, int i);
	Complex();
	~Complex();
	Complex& add(Complex& anohter);
//	Complex operator+(Complex& other);
	friend Complex operator+(Complex& c1,Complex& c2);
public:
	int real_;
	int imag_;
};
