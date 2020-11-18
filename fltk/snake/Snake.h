#ifndef SNAKE_H
#define SNAKE_H

#include<vector>

using namespace std;


struct Point{

Point(int x, int y):x(x),y(y){}

	int x,y;	
};

inline bool operator==(const Point& p1, const Point& p2){
	return (p1.x==p2.x && p1.y==p2.y); 
}

class Snake{

 public:
	Snake(int, int);
	~Snake();


 private:
	void checkGameStatus_();
	void drawThem_();
	int hanlde(int);

	
 private:
	int x0_, y0_;
	int status_,points_;  // 0 run, 1 over
	int dx_, dy_;
	vector<Point> s_;
};


#endif
