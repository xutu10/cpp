#include"Snake.h"

#include<algorithm>
#include<iostream>

#include<FL/Fl.H>
#include<FL/Fl_Box.H>
#include<FL/fl_draw.H>

using namespace std;

static const int CELL_SIZE = 8;


Snake::Snake(int x, int y): Fl_Box(x, y, 300,300, "my snake"){

	x0_ = x;
	y0_ = y;

    for(int i = 0; i < 5; i++){
		s_.push_back(Point(15+i, 15));
	}	

	checkGameStatus_();
}

Snake::~Snake(){

	
}


void Snake::draw(){

	Fl_Box::draw();

	cout<<"draw"<<endl;

	int x, y;
	// draw grid
	for(int i = 0; i< 30; i++){
		for(int j = 0; j < 30; j++){
	
			x = x0_ + i * CELL_SIZE;
			y = y0_ + j * CELL_SIZE;
			fl_draw_box(FL_UP_BOX, x, y,CELL_SIZE, CELL_SIZE,FL_GRAY);
			cout<<"5"<<endl;
		}
	}

	// draw snake
	for(auto i : s_){
		x = x0_ + i.x;
		y = y0_  + i.y;
		fl_draw_box(FL_UP_BOX, x, y, CELL_SIZE, CELL_SIZE, FL_DARK1);
	}
	
}

int Snake::handle(int event){

	
}

void Snake::checkGameStatus_(){

	this->redraw();
}
