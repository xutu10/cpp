#include<math.h>
#include<iostream>
//#include<cstdio>
using namespace std;

class Point{
	// this method doesn't belong to the class
	friend double calDistance(const Point& p1,const Point& p2);
public:
	Point(int x,int y);
	
private:
	int x_;
	int y_;

};

Point::Point(int x,int y):x_(x),y_(y){
	
}

double calDistance(const Point& p1,const Point& p2){

	double dx = p1.x_ - p2.x_;
	double dy = p1.y_ - p2.y_ ;
	double rt = sqrt(dx*dx + dy*dy);
	
	return rt;
}

int main(int argc, char *argv[])
{
    Point p1(3,4);
	Point p2(6,8);
	double rt;
    rt = calDistance(p1,p2);
	//	printf("%lf\n",rt);
		cout<<rt<<endl;
	
    return 0;
}
