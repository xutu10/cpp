#include"mainWindow.h"

#include<Fl/Fl_Menu_Item.H>
#include<FL/fl_ask.H>
//#include<Fl/Fl_Box.H>
#include<Fl/fl_draw.H>

#include<iostream>
using namespace std;

void newGame_cb(Fl_Widget*, void* m){

	mainWindow* window = static_cast<mainWindow* >(m);
	//	window->snake_ = new Snake(window->x(), window->y());
}

void timer_cb(void* m){

	mainWindow* window = static_cast<mainWindow* >(m);
	window->checkGameStatus_();
	
	Fl::repeat_timeout(1.0, timer_cb, m);
}

mainWindow::mainWindow(int w, int h, const char* text): Fl_Window(w,h){

	initMenu_();
	cout<<"1"<<endl;
	//	initGrid_();
	cout<<"2"<<endl;
	
}

mainWindow::~mainWindow(){

	//	delete menuBar_, snake_;
}

void mainWindow::initMenu_(){

	static const Fl_Menu_Item menuItems[] = {
		{ "Game", 0, 0, 0, FL_SUBMENU},
		{ "new game", 0,(Fl_Callback*) newGame_cb,this},
		{ "high score", 0,0,0},
		{ "exit" , 0,0,0},
		{0}		
	};

	this-> menuBar_ = new Fl_Menu_Bar(0, 0, 60, 30);
	this-> menuBar_->copy(menuItems);
	this->add(this->menuBar_);

	this->end();
	this->show();

}

void mainWindow::initGrid_(){
	int x, y;
	for(int i = 0; i< 30; i++){
		for(int j = 0; j < 30; j++){
			cout<<"3"<<endl;
			x = this->x() + i * CELL_SIZE;
			y = this->y() + j * CELL_SIZE;
			cout<<"4"<<endl;
			fl_draw_box(FL_UP_BOX, x, y,CELL_SIZE, CELL_SIZE,FL_GRAY);
			cout<<"5"<<endl;
		}
	}
}

void mainWindow::checkGameStatus_(){

	// if(snake_->status_ == GAMEOVER)
	// 	this-> gameOver_();
}

void mainWindow:: gameOver_(){

	Fl::remove_timeout(timer_cb, this);
	fl_message("game over!!!");

}
