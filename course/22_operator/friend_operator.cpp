#include<iostream>
using namespace std;

class Point{
public:
	Point(int a, int b):x_(a), y_(b){}

	// for ++p
	// void  operator++(){
	// 	x_ += 1;
	// 	y_ += 1;
	// }

	// for p++
	// void  operator++(int){
	// 	x_ += 2;
	// 	y_ += 2;
	// }
	
	// for ++p
	friend void operator++(Point& p){
		p.x_ += 3;
		p.y_ += 3;
	}
	
	void show(){
		cout<<x_<<","<<y_<<endl;
	}

private:
	int x_,y_;
};


int main(){

	Point p(2,3);
	//	p++;   
	p.show();
	++p;
	p.show();
	

	return 0;
}
