#include"Shape.h"
#include"Factory.h"
#include<iostream>
using namespace std;

void Circle::draw(){
	cout<<"circle draw"<<endl;
}

Circle::~Circle(){
	cout<<"circle desconstructor"<<endl;
}

void Square::draw(){
	cout<<"square draw"<<endl;
}

Square::~Square(){
	cout<<"squre desconstructor"<<endl;
}

void Rectangle::draw(){
	cout<<"rectangle draw"<<endl;
}
Rectangle::~Rectangle(){
	cout<<"rectangle desconstructor"<<endl;
}

//mean that class Circle support dynamic creation.
REGISTER_CLASS(Circle);
REGISTER_CLASS(Square);
REGISTER_CLASS(Rectangle);

