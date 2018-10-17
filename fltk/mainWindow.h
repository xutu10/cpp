#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>

class mainWindow : public Fl_Window{

 public:
	mainWindow(int w, int h, const char*);
	~mainWindow();

 private:
	friend void about_cb(Fl_Widget*, void*);
	friend void timer_cb(void*);

 private:
	void _initMenuBar();
	void _initStatusBar();
	void _aboutDialog();
	
 private:
	Fl_Menu_Bar* _menuBar;
	Fl_Box* _statusBox;
	Fl_Box* _mines;
	Fl_Box* _timer;
};


#endif
