#include"Snake.h"
#include"mainWindow.h"

#include<algorithm>
#include<FL/fl_draw.H>

Snake::Snake(int x, int y){

	x0_ = x;
	y0_ = y;
    for(int i = 0; i < 5; i++){
		s_.push_back(Point(15+i, 15));
	}

	drawThem_();
}

Snake::~Snake(){

	
}

void Snake::drawThem_(){

	int x, y;
	for(auto i : s_){
		x = x0_ + i.x;
		y = y0_  + i.y;
		fl_draw_box(FL_UP_BOX, x, y, CELL_SIZE, CELL_SIZE, FL_DARK1);
	}
	
}

