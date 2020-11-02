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

void new_game_cb(Fl_Widget*, void* ctx){

	mainWindow* m = static_cast<mainWindow *>(ctx);
	m->_newGame();
}

void select_new_game_cb(Fl_Widget*, void* ctx){

	mainWindow* m = static_cast<mainWindow *>(ctx);
	m->_optionNewGameCb();
}


void show_high_scores_cb(Fl_Widget*, void* ctx){

	mainWindow* m = static_cast<mainWindow *>(ctx);
	m->_showHighScores();
}

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

	// need in mainwindow ??? or in class seperately
	delete _newgame, gameBoard_, scores_;
}

void mainWindow::_initMenuBar(){

	static const Fl_Menu_Item _menuItems[] = {
		{ "Game", 0, 0, 0, FL_SUBMENU},
		{ "new game", 0,(Fl_Callback*) new_game_cb,this},
		{ "option", 0,(Fl_Callback*) select_new_game_cb,this},
		{ "high score", 0,(Fl_Callback*)show_high_scores_cb,this},
		{ "exit" , 0,(Fl_Callback*)quit_cb},
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
	// no need
	//	this->_statusBox = new Fl_Box(FL_EMBOSSED_BOX,10,(30+18),32,32,nullptr);
	this->_mines = new Fl_Box(FL_BORDER_BOX,200,(30+18),48,32,"Mines");
	this->_timer = new Fl_Box(FL_BORDER_BOX,100,(30+18),48,32,"Timer");

	//this->add(this->_statusBox);
	this->add(this->_mines);
	this->add(this->_timer);
	
}


void mainWindow::_aboutDialog(){

	fl_message_title("about");
	fl_message("this is tu xu");
	
}

void mainWindow::_showHighScores(){

	this->scores_ = new Scores();
	this->scores_ -> show();

	while(this->scores_->shown())
		Fl::wait();
}

void mainWindow::_optionNewGameCb(){
    this->_newgame = new newGameDialog();

	this->_newgame->show();
	while(this->_newgame->shown()){
		Fl::wait();
	}

	_newGame();
	// after init GameBoard, delete Dialog
	//	delete this->_newgame;
}

void mainWindow::_newGame(){

	// this->_reshapeMainwindow(w,h);
	// this->_menuBar->size(w, 30);

	// after delete not nullptr???
	if(this->gameBoard_!= nullptr)
		delete this->gameBoard_;
	
	cout<<"1"<<endl;	

	int w = this->_newgame->getBoardW();
	int h = this->_newgame->getBoardH();
	int mines = this->_newgame->getMines();

	cout<<w<<","<<h<<","<<mines<<endl;
	if(mines != 0)
		this->gameBoard_ = new GameBoard(10,100,w,h,mines,this);

	cout<<"3"<<endl;
	
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

	timer = gameBoard_->getGameTime();

	if(gameBoard_->status_ == GAMEOVER){
		cout<<"gameover"<<endl;
		_gameOver();
	}
	else if(gameBoard_->status_ == WIN){
		cout<<"game won"<<endl;
		_gameWon(timer);
	}else{
		// show the timer
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

// no more need
void mainWindow::_resetGame(){

    this-> gameBoard_->deactivate();
	// if (!= nullptr) not work???
	//	delete gameBoard_;
}

void mainWindow::_gameOver(){

	// TODO set image
	Fl::remove_timeout(timer_cb,this);
	fl_message("game over!!!");
    this-> gameBoard_->deactivate();
  
}

void mainWindow::_gameWon(int timer){
	// TODO set image
	Fl::remove_timeout(timer_cb,this);
	fl_message("game won!!!");

	_checkScores(timer);

    this-> gameBoard_->deactivate();
   
}

void mainWindow::_checkScores(int timer){

	

	
}
