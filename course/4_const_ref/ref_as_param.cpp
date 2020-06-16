#include<iostream>
using namespace std;


class Point{

public:
	Point(int x, int y):_x(x), _y(y){}
	friend void add(Point&);
	void show(){
		cout<< this->_x << "," << this->_y<<endl;
	}
protected:
	int _x;
	int _y;	
};

void add (Point& p){
	p._x +=1;
	p._y +=2;
	
}


int main(){

	Point p(1,2);
	add(p);
	p.show();

	cout<<"----------"<<endl;
	Point* pptr = new Point(2,4);
	add(*pptr);
	pptr->show();
		
	return 0;
}
