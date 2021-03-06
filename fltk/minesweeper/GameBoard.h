#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <ctime>
#include <set>

#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
// recursive definition
//#include "mainWindow.h"
class mainWindow;

static const int CELL_SIZE = 16;

struct Point{
	Point(int x, int y):x(x), y(y){}
	
	int x, y;	
};

inline bool operator<(const Point& p1, const Point& p2){
	if (p1.x == p2.x && p1.y == p2.y)
		return false;
	return true;
}

inline bool operator==(const Point& p1, const Point& p2){
	return (p1.x == p2.x) && (p1.y == p2.y);
}


struct cellstatus{
	bool is_mine = false;
	bool is_flagged = false;
	bool is_uncovered = false;
	int aroundmines = -1;	
};

enum GameStatus{
	RUN, WIN, GAMEOVER
};

class GameBoard : public Fl_Box{
 friend class mainWindow;

 public:
 GameBoard(int,int,int,int,int, mainWindow*);
  ~GameBoard();
 
  virtual void draw();
  virtual int handle(int);

  int getGameStatus() const {
	  return status_;
  };
  
  int getGameTime() const{
	  return difftime(time(nullptr), startTime_);
  }

 private:
  void initGame(int);
  void leftButton(int,int);
  void rightButton(int,int);
  void calAroundMines();
  void checkGameStatus();
  void checkAndUncoverAroundCells(int, int);

  int grid_width_, grid_height_, remain_cells_, remainFlag_;
  std::vector<std::vector<cellstatus>> cells_;	
  std::set<Point> remainMines_;
  // could be defined in Windows and update data in GameBoard
  GameStatus status_;     
  
  Fl_PNG_Image *imgMine_, *imgMineCrossed_, *imgFlag_;
  time_t startTime_;

  mainWindow* mainWindow_;
};

#endif
