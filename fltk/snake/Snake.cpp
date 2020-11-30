#include"Snake.h"

#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Box.H>
#include<FL/fl_draw.H> // fl_draw_box
#include<FL/fl_ask.H>

#include <iostream>
#include <time.h>
#include<algorithm> // std::find()
using namespace std;

static const int CELL_SIZE = 8;

void timer_cb(void* s){

	static_cast<Snake *>(s) -> snakeGo_();
	Fl::repeat_timeout(0.1, timer_cb, s);
	
}

Snake::Snake(int a, int b): Fl_Box(FL_NO_BOX, a, b,240,240," "){

	    x0_= a;
		y0_= b;

		dx_ = 1;
		dy_ = 0;
		// init the snake
		for(int i = 0; i < 5; i++){
			s_.push_back(Point(15-i, 15));
		}
		// store the last point to clear the drawing
		s_.push_back(s_[4]);
		
		// init new point
		int x, y;
		x = rand() % 30;
		y = rand() % 30;

		Bonus_ = new Point(x,y);

		Fl::repeat_timeout(0.5, timer_cb, this);
		
}

Snake::~Snake(){
	
}


void Snake::draw(){

		Fl_Box::draw(); // draw the large box
			
		for(int i = 0; i < s_.size()-1;i++)
			fl_draw_box(FL_UP_BOX, x0_+s_[i].x*CELL_SIZE, y0_+s_[i].y*CELL_SIZE, CELL_SIZE, CELL_SIZE, FL_GRAY);

		// clear the last point
		int size = s_.size()-1;
		fl_draw_box(FL_FLAT_BOX, x0_+s_[size].x*CELL_SIZE, y0_+s_[size].y*CELL_SIZE, CELL_SIZE, CELL_SIZE,FL_GRAY);
		
		fl_draw_box(FL_OFLAT_BOX, x0_+Bonus_->x*CELL_SIZE, y0_+Bonus_->y*CELL_SIZE, CELL_SIZE, CELL_SIZE, FL_RED);
		
}


int Snake:: handle(int e){

	if (e == FL_KEYDOWN){
		if(Fl::event_key() == FL_Up && dy_ != 1){
			dx_ = 0;
			dy_ = -1;
			return 1;
		}			
		else if(Fl::event_key() == FL_Left && dx_ != 1){
			dx_ = -1;
			dy_ = 0;
			return 1;
		}			
		else if(Fl::event_key() == FL_Right && dx_ != -1){
			dx_ = 1;
			dy_ = 0;
			return 1;
		}			
		else if(Fl::event_key() == FL_Down && dy_ != -1){
			dy_ = 1;
			dx_ = 0;
			return 1;
		}else{
			return 0;
		}			
	}

}

void Snake::snakeGo_(){

	for(int i = s_.size()-1; i > 0; i--){
		s_[i].x = s_[i-1].x;
		s_[i].y = s_[i-1].y;
 	}

	s_[0].x = s_[0].x + dx_;
	s_[0].y = s_[0].y + dy_;

	checkGameStatus_();

	this->redraw();
			
}

void Snake::checkGameStatus_(){

	if(s_[0].x < 0 || s_[0].x > 30 || s_[0].y < 0 || s_[0].y > 30){

		Fl::remove_timeout(timer_cb);
		fl_message("game over");
		exit(0);
	}

	auto rslt =	find(s_.begin()+1, s_.end(), s_[0]);
	if(rslt != s_.end()){

		Fl::remove_timeout(timer_cb);
		fl_message("game over");
		exit(0);

	}
		

	if(s_[0] == *Bonus_){
		auto first = s_.begin();
		Point newPoint(Bonus_->x + dx_, Bonus_->y + dy_);
		s_.insert(first, newPoint);

		//		fl_draw_box(FL_FLAT_BOX, x0_+Bonus_->x*CELL_SIZE, y0_+Bonus_->y*CELL_SIZE, CELL_SIZE, CELL_SIZE, FL_GRAY);
		delete Bonus_;

		int x, y;
		x = rand()%30;
		y = rand()%30;

		Bonus_ = new Point(x,y);
	}
	
}
	
