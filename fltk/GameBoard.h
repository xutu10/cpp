#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <ctime>
#include <set>

#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>

static const int CELL_SIZE = 16;

struct Point{
	Point(int x, int y):x(x), y(y){}
	
	int x, y;	
};

inline bool operator<(const Point& p1, const Point& p2){
	if (p1.x == p2.x && p1.y == p2.y)
		return false;
	return (p1.x + p2.y < p2.x + p2.y);
}

inline bool operator==(const Point& p1, const Point& p2){ 
	return (p1.x == p2.x) && (p1.y == p2.y);
}

inline bool operator!=(const Point& p1, const Point& p2){
	return (p1.x != p2.x) || (p1.y != p2.y);
}


struct cellstatus{
	bool is_mine = false;
	bool is_flagged = false;
	bool is_uncovered = true;
	int aroundmines = -1;	
};

class GameBoard : public Fl_Box{
 friend class MainWindow;

 public:
  GameBoard(int,int,int,int);
  ~GameBoard();
 
  virtual void draw();
  virtual int handle(int);

  int getGameStatus() const {
	  return game_status_;
  };
  
  int getGameTime() const{
	  return difftime(time(nullptr), start_time_);
  }

 private:
  void initGame(int);
  void calAroundMines();
  void checkGameStatus();
  void checkAndUncoverAroundCells(int, int);
  
  int grid_width_, grid_height_, remain_cells_, remain_flag_;
  std::vector<std::vector<cellstatus>> cells_;	
  std::multiset<Point> remain_mines_;
  int game_status_;      // enum running 1, won 2, over 3???
  
  Fl_PNG_Image *imgMine_, *imgMineCrossed_, *imgFlag_;
  time_t start_time_;

};

#endif
