#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <ctime>

#include <FL/Fl_Box.H>


static const int CELL_SIZE = 16;


struct cellstatus{
	bool is_mine = false;
	bool is_flagged = false;
	bool is_uncovered = true;
	int aroundmines = -1;	
};

class GameBoard : public Fl_Box{
 public:
  GameBoard(int,int,int,int);
  ~GameBoard();
 
  virtual void draw();
  virtual int handle(int);

 private:
  void initGame(int);
  void calAroundMines();
  void checkAndUncoverAroundCells(int, int);
  
  int grid_width_, grid_height_, remain_mines_, remain_cells_, remain_flag_;
  std::vector<std::vector<cellstatus>> cells_;	
  int game_status_;      // enum running, won, over???
  time_t start_time_;
	
};

#endif