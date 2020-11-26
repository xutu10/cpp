#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Menu_Bar.H>

#include"Snake.h"

class mainWindow : public Fl_Window{

 public:
	mainWindow(int w, int h, const char*);
	~mainWindow();

 private:
	friend void newGame_cb(Fl_Widget*, void*);
	friend void timer_cb(void*);

	void initMenu_();
	void checkGameStatus_();
	void gameOver_();

 private:
	Fl_Menu_Bar* menuBar_;
	Snake* snake_;
	
};

#endif 
