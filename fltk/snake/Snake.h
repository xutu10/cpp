#ifndef SNAKE_H
#define SNAKE_H

#include<FL/Fl_Box.H>

#include<vector>

using namespace std;


struct Point{

Point(int x, int y):x(x),y(y){}

	int x,y;	
};

inline bool operator==(const Point& p1, const Point& p2){
	return (p1.x==p2.x && p1.y==p2.y); 
}

class Snake : public Fl_Box{

 public:
	Snake(int, int);
	~Snake();

	virtual void draw();
	virtual int handle(int);

 private:
	friend void timer_cb(void*);
	
 private:
	void checkGameStatus_();
	void snakeGo_();
	
 private:
	int x0_, y0_;
	int status_,points_;  // 0 run, 1 over
	int dx_, dy_;
	vector<Point> s_;
	Point* newP_;
};


#endif
