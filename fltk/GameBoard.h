#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <ctime>

#include <FL/Fl_Box.H>


static const int CELL_SIZE = 16;


struct cellstatus{
	bool is_mine = false;
	bool is_flagged = false;
	bool is_uncovered = false;
	int aroundmines = -1;	
};

class GameBoard : public Fl_Box{
 public:
  GameBoard(int,int,int,int);
  ~GameBoard();
  virtual void draw();
  virtual int handle(int);

 private:
  int shapeBoard();
  void uncover();
  int checkAroundcell();
  
  int grid_width_, grid_height_;
  std::vector<std::vector<cellstatus>> cells_;	
  int game_status_;      // enum running, won, over???
  time_t start_time_;
	
};

#endif
