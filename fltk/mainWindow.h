#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>

#include "newGameDialog.h"
#include "GameBoard.h"

class mainWindow : public Fl_Window{

	friend class GameBoard;
	
 public:
	mainWindow(int w, int h, const char*);
	~mainWindow();

 private:
	friend void about_cb(Fl_Widget*, void*);
	friend void timer_cb(void*);
	friend void menu_new_game_cb(Fl_Widget*, void*);
 private:
	void _initMenuBar();
	void _initStatusBar();
	void _aboutDialog();
	void _newGameCb();
	void _resetGame();
	void _setupBoardSize(int w,int h,int m);
	void _reshapeMainwindow(int w, int h);
	void _updateGameStatus();
	void _gameWon();
	void _gameOver();
	
 private:
	Fl_Menu_Bar* _menuBar;
	Fl_Box* _statusBox;
	Fl_Box* _mines;
	Fl_Box* _timer;

	newGameDialog* _newgame = nullptr;
	GameBoard* gameBoard_ = nullptr;
};


#endif
