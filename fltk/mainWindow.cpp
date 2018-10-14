#include "mainWindow.h"
#include <FL/Fl_Menu_Item.H>

using namespace std;

mainWindow::mainWindow(int w,int h,const char* t): Fl_Window(w,h){

	this->_initMenuBar();
//	this->_initStatusBar();	
}

mainWindow::~mainWindow(){
	
}

void mainWindow::_initMenuBar(){

	static const Fl_Menu_Item _menuItems[] = {
		{ "Game", 0, 0, 0, FL_SUBMENU},
		{ "new game", 0,0,0},
		{ "high score", 0,0,0},
		{ "exit" , 0,0,0},
		{0},
		{ "help", 0,0,0, FL_SUBMENU},
		{ "about", 0,0,0},
 		{0},
		{0}		
	};

	this->_menuBar = new Fl_Menu_Bar(0, 0, 120, 30);
	this->_menuBar->copy(_menuItems);
	this->add(this->_menuBar);
	
};
