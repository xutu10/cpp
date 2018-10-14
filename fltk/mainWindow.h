#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>

class mainWindow : public Fl_Window{

 public:
	mainWindow(int w, int h, const char*);
	~mainWindow();

 private:
	void _initMenuBar();
	void _initStatusBar();

 private:
	Fl_Menu_Bar* _menuBar;
	
};


#endif
