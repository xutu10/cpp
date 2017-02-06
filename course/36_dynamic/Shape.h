#pragma once

class Shape{
public:
	virtual void draw() = 0;
	virtual ~Shape(){
		
	}
};

class Circle : public Shape{
public:
	void draw();
	~Circle();
};

class Square : public Shape{
public:
	void draw();
	~Square();
};

class Rectangle : public Shape{
public :
	void draw();
	~Rectangle(); 
};
