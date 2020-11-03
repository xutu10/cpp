#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>

#include "newGameDialog.h"
#include "GameBoard.h"
#include "Scores.h"

class mainWindow : public Fl_Window{

	friend class GameBoard;
	
 public:
	mainWindow(int w, int h, const char*);
	~mainWindow();

 private:
	friend void about_cb(Fl_Widget*, void*);
	friend void timer_cb(void*);
	friend void new_game_cb(Fl_Widget*, void*);
	friend void select_new_game_cb(Fl_Widget*, void*);
	friend void show_high_scores_cb(Fl_Widget*, void*);
	
 private:
	void _initMenuBar();
	void _initStatusBar();
	void _aboutDialog();
	void _optionNewGameCb();
	//void _resetGame();
	void _reshapeMainwindow(int w, int h);
	void _updateGameStatus();
	void _gameWon(int);
	void _gameOver();
	void _showHighScores();
	void _newGame();
	int _checkScores(int) const;
	void _updateScores(int,int);
	
 private:
	Fl_Menu_Bar* _menuBar;
	Fl_Box* _statusBox;
	Fl_Box* _mines;
	Fl_Box* _timer;

	newGameDialog* _newgame = nullptr;
	GameBoard* gameBoard_ = nullptr;
	Scores* scores_ = nullptr;
};


#endif
