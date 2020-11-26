#include"Snake.h"

#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Box.H>
#include<FL/fl_draw.H> // fl_draw_box

#include <iostream>
#include <time.h>
using namespace std;

static const int CELL_SIZE = 8;

void timer_cb(void* s){

	static_cast<Snake *>(s) -> snakeGo_();

	Fl::repeat_timeout(0.5, timer_cb, s);
	
}

Snake::Snake(int a, int b): Fl_Box(FL_NO_BOX, a, b, 240, 240," "){

	    x0_= a;
		y0_= b;

		dx_ = 1;
		// init the snake
		for(int i = 0; i < 5; i++){
			s_.push_back(Point(15-i, 15));
		}
		
		// init new point
		int x, y;
		x = rand() % 30;
		y = rand() % 30;

		newP_ = new Point(x,y);

		Fl::repeat_timeout(0.5, timer_cb, this);

		
		
		cout<<"init finish"<<endl;
}

Snake::~Snake(){
	
}


void Snake::draw(){

		Fl_Box::draw(); // draw the large box
			
		for(auto p : s_)
			fl_draw_box(FL_UP_BOX, x0_+p.x*CELL_SIZE, y0_+p.y*CELL_SIZE, CELL_SIZE, CELL_SIZE, FL_GRAY);

		fl_draw_box(FL_UP_BOX, x0_+newP_->x*CELL_SIZE, y0_+newP_->y*CELL_SIZE, CELL_SIZE, CELL_SIZE, FL_RED);
		
}


int Snake:: handle(int e){

	dx_,dy_ = 0;	
	if (e == FL_KEYDOWN){
		if(Fl::event_key() == FL_Up)
			dy_ = 1; 
		if(Fl::event_key() == FL_Left)
			dx_ = -1;
		if(Fl::event_key() == FL_Right)
			dx_ = 1;
		if(Fl::event_key() == FL_Down)
			dy_ = -1;			
	}

	//	this->snakeGo_();			
}

void Snake::snakeGo_(){

	cout<<s_.size()<<endl;
	for(int i = s_.size()-1; i > 0; i--){
		s_[i].x = s_[i-1].x;
		s_[i].y = s_[i-1].y;
 	}

	s_[0].x = s_[0].x + dx_;
	s_[0].y = s_[0].y + dy_;

	this->redraw();
			
}
	
