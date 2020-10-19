#include "mainWindow.h"
#include <FL/Fl_Menu_Item.H>
#include<FL/fl_ask.H>

#include<iostream>
#include<ctime>
#include<sstream>
#include<iomanip>
using namespace std;

void quit_cb(Fl_Widget*, void* ctx){
	exit(0);
}

void menu_new_game_cb(Fl_Widget*, void* ctx){
	mainWindow* m = static_cast<mainWindow *>(ctx);

	m->_newGameCb();
}


// void show_high_scores_cb(Fl_Widget*, void* ctx){
// 	mainWindow* m = static_cast<mainWindow *>(ctx);

// 	m->_showHighScores();
// }

void about_cb(Fl_Widget*, void* ctx){

	mainWindow* m = static_cast<mainWindow *>(ctx);

	m->_aboutDialog();
	
}

void timer_cb(void* ctx){

	static_cast<mainWindow *>(ctx)->_updateGameStatus();
	Fl::repeat_timeout(1.0, timer_cb, ctx);
}


mainWindow::mainWindow(int w,int h,const char* t): Fl_Window(w,h){

	this->_initMenuBar();
	this->_initStatusBar();	
}

mainWindow::~mainWindow(){
	
}

void mainWindow::_initMenuBar(){

	static const Fl_Menu_Item _menuItems[] = {
		{ "Game", 0, 0, 0, FL_SUBMENU},
		{ "new game", 0,(Fl_Callback*) menu_new_game_cb,this},
		{ "high score", 0,0,0},
		{ "exit" , 0,0,0},
		{0},
		{ "help", 0,0,0, FL_SUBMENU},
		{ "about", 0,(Fl_Callback*) about_cb,this},
 		{0},
		{0}		
	};

	this->_menuBar = new Fl_Menu_Bar(0, 0, 120, 30);
	this->_menuBar->copy(_menuItems);
	this->add(this->_menuBar);
	
}

void mainWindow::_initStatusBar(){

	this->_statusBox = new Fl_Box(FL_EMBOSSED_BOX,10,(30+18),32,32,nullptr);
	this->_mines = new Fl_Box(FL_BORDER_BOX,200,(30+18),48,32,"Mines");
	this->_timer = new Fl_Box(FL_BORDER_BOX,100,(30+18),48,32,"Timer");

	this->add(this->_statusBox);
	this->add(this->_mines);
	this->add(this->_timer);
	
}


void mainWindow::_aboutDialog(){

	fl_message_title("about");
	fl_message("this is tu xu");
	
}

void mainWindow::_newGameCb(){
    this->_newgame = new newGameDialog();

	this->_newgame->show();
	while(this->_newgame->shown()){
		Fl::wait();
	}

	int w = this->_newgame->getBoardW();
	int h = this->_newgame->getBoardH();
	int mines = this->_newgame->getMines();

	if(mines != 0){
		cout<<mines<<endl;
		this->_setupBoardSize(w,h,mines);
	}
	// after init GameBoard, delete Dialog
	//	delete this->_newgame;
}

void mainWindow::_setupBoardSize(int w, int h, int m){

	// this->_reshapeMainwindow(w,h);
	// this->_menuBar->size(w, 30);
	
	this->gameBoard_ = new GameBoard(10,100,w,h,m,this);

	this->add(gameBoard_);
	this->_updateGameStatus();
	
	Fl::repeat_timeout(1.0,timer_cb,this);
}

void mainWindow::_reshapeMainwindow(int w, int h){
	int newW,newH; 
	this->size(newW,newH);

	// TODO reshape statusbox, image and timer
	
}

int timer;
stringstream ss;

void mainWindow::_updateGameStatus(){

	if(gameBoard_->status_ == GAMEOVER){
		cout<<"gameover"<<endl;
		_gameOver();
	}
	else if(gameBoard_->status_ == WIN)
		_gameWon();
	else{
		// show the timer
		timer = gameBoard_->getGameTime();
		ss.str("");
		ss<<setfill('0')<<setw(3)<<timer;
		_timer->copy_label(ss.str().c_str());
		// show status, remain mines
		ss.str("");
		ss<<setfill('0')<<setw(2)<<gameBoard_->remainFlag_;
		_mines->copy_label(ss.str().c_str());
	}

	this->redraw();
}

void mainWindow::_resetGame(){

	Fl::remove_timeout(timer_cb,this);
    this-> gameBoard_->deactivate();
	delete gameBoard_;
}

void mainWindow::_gameOver(){

	// TODO set image
	this->_resetGame();
	
	Fl::wait(); // wait something happens
	fl_beep();
	fl_message("game over!!!");
  
}

void mainWindow::_gameWon(){
	// TODO set image
	this->_resetGame();

	Fl::wait();
	fl_beep();
	fl_message_title("game won!!!");
   
}
