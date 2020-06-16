#include<iostream>
using namespace std;

class Point{


public:

	Point(int a, int b):x_(a), y_(b){}

	// variante 1
	// void operator=(Point& p){
	// 	x_ = p.x_ +1;
	// 	y_ = p.y_ +1;
	// }

	Point &operator=(const Point& p){
		x_ = p.x_ + 2;
		y_ = p.y_ + 2;

		return *this;
	}

	void operator()(int a, int b){
		x_ = a;
		y_ = b;
	}
	
	void show(){
		cout<<x_<<","<<y_<<endl;
	}

private:
	int x_, y_;
	
};


int main(){


	Point p1(1,2);
	Point p2(3,4);
	Point p3(6,6);
	
	//  p1 = p2  variante 1, ok
	p1 = p2 = p3;  // for variante 1 not working
	
	p1.show();  // 10, 10
	p2.show(); // 8, 8

	p1(1,1);
	p1.show();
	
	return 0;
}
