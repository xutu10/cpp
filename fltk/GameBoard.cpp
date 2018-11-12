#include "GameBoard.h"

GameBoard::GameBoard(int x, int y, int w, int h):Fl_Box(FL_NO_BOX, x, y,(w*CELL_SIZE), (h*CELL_SIZE),nullptr){
	grid_width_ = w;
	grid_height_ = h;

	cells_.clear();
	
	for (int i = 0; i<w;i++){
		cells_.push_back(std::vector<cellstatus>());
		
		for (int j = 0; j<h;j++){
			cells_[i].push_back(cellstatus());
		}
		
	}
	
	this->shapeBoard();
	start_time_ = time(nullptr);
	
}

GameBoard::~GameBoard(){
	
}
