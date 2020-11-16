#include"mainWindow.h"
#include<Fl/Fl_Menu_Item.H>
#include<FL/fl_ask.H>

#include<iostream>
using namespace std;

void newGame_cb(Fl_Widget*, void* m){

	mainWindow* window = static_cast<mainWindow* >(m);
	window->snake_ = new Snake();
}

void timer_cb(void* m){

	mainWindow* window = static_cast<mainWindow* >(m);
	window->checkGameStatus_();
	
	Fl::repeat_timeout(1.0, timer_cb, m);
}

mainWindow::mainWindow(int w, int h, const char* text): Fl_Window(w,h){

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

}

mainWindow::~mainWindow(){

	delete menuBar_, snake_;
}


void mainWindow::checkGameStatus_(){

	// if(snake_->status_ == GAMEOVER)
	// 	this-> gameOver_();
}

void mainWindow:: gameOver_(){

	Fl::remove_timeout(timer_cb, this);
	fl_message("game over!!!");

}
