#include "GameBoard.h"
#include "mainWindow.h"

#include <sstream>
#include <iostream>
#include <algorithm>
#include <FL/fl_draw.H>
#include <FL/Fl.H>

using namespace std;

static const Fl_Color count_colors[] = {
	fl_rgb_color(1, 0, 254),	// 1
	fl_rgb_color(1, 127, 1),	// 2
	fl_rgb_color(254, 0, 0),	// 3
	fl_rgb_color(1, 0, 128),	// 4
	fl_rgb_color(129, 1, 2),	// 5
	fl_rgb_color(0, 128, 129),	// 6
	fl_rgb_color(0, 0, 0),		// 7
	fl_rgb_color(128, 128, 128),// 8
};


GameBoard::GameBoard(int x, int y, int w, int h, int num, mainWindow* mw):Fl_Box(FL_NO_BOX, x, y,(w*CELL_SIZE), (h*CELL_SIZE),nullptr){

	grid_width_ = w;
	grid_height_ = h;
	int mines_num = num;
	mainWindow_ = mw;
	// mainwindow object is neccessary ???
	status_ = RUN;
	cells_.clear();
	// init cells, double array
	for (int i = 0; i < w;i++){
		cells_.push_back(std::vector<cellstatus>());
		
		for (int j = 0; j < h;j++){
			cells_[i].push_back(cellstatus());
		}
	}
	
	this->initGame(mines_num);

	imgMine_ = new Fl_PNG_Image("images/mine.png");
    imgMineCrossed_ = new Fl_PNG_Image("images/mine_crossed.png");
	imgFlag_ = new Fl_PNG_Image("images/flag.png");

	startTime_ = time(nullptr);
	cout<<"init completed"<<endl;

}

GameBoard::~GameBoard(){

	delete imgMineCrossed_, imgMine_, imgFlag_;
}

void GameBoard::initGame(int mines){

	remainMines_.clear();
	int mines_placed = 0;
	int i,j;
	// in mainwindow the func will be called
	// remain_mines_ = remain_flag_= mines;
	while (mines_placed < mines){
		i = rand() % grid_width_;
		j = rand() % grid_height_;
		
		if(cells_[i][j].is_mine != true ){
			cells_[i][j].is_mine = true;
			mines_placed++;
			remainMines_.insert(Point(i,j));
		}
	}
	calAroundMines();
}

void GameBoard::calAroundMines(){
	int around_mines_num;

	for (int i =0; i< grid_width_; i++){
		for (int j = 0; j < grid_height_; j++){
			around_mines_num = 0;
			if (i-1 >= 0 && j-1 >= 0 && cells_[i-1][j-1].is_mine == true)
				around_mines_num++;
			if (j-1 >= 0 && cells_[i][j-1].is_mine == true)
				around_mines_num++;
			if (i+1 < grid_width_ && j-1>=0 && cells_[i+1][j-1].is_mine == true)
				around_mines_num++;
			if (i-1 >= 0 && cells_[i-1][j].is_mine == true)
				around_mines_num++;
			if (i+1 < grid_width_ && cells_[i+1][j].is_mine == true)
				around_mines_num++;
			if (i-1 >= 0 && j+1 < grid_height_ && cells_[i-1][j+1].is_mine == true)
				around_mines_num++;
			if (j+1 < grid_height_ && cells_[i][j+1].is_mine == true)
				around_mines_num++;
			if (i+1 < grid_width_ && j+1 < grid_height_ && cells_[i+1][j+1].is_mine == true)
				around_mines_num++;
			
			cells_[i][j].aroundmines = around_mines_num;
		}
	}
}

//???
void GameBoard::draw(){

	cout<<"draw"<<endl;
	Fl_Box::draw();
	int x, y;
	Fl_Color c = FL_DARK1;
	
	for (int i = 0; i < grid_width_;i++){
		for (int j = 0; j < grid_height_; j++){
			x = this->x() + i * CELL_SIZE;
			y = this->y() + j * CELL_SIZE;
			
			cellstatus this_cell = cells_[i][j];
			if (this_cell.is_uncovered == true){
				// TODO flexible height with variable 
				Fl_Box(FL_UP_BOX, x, y, CELL_SIZE, CELL_SIZE, 0);
			}
			
			if (this_cell.is_uncovered == false && this_cell.is_mine == true){
				// draw mine 
				c = FL_RED;
				fl_draw_box(FL_BORDER_BOX, x, y, CELL_SIZE, CELL_SIZE, c);
				imgMineCrossed_->draw(x,y);
			}
			
			if (this_cell.is_uncovered == false && this_cell.is_mine == false){
				if (this_cell.aroundmines = 0){
					c = FL_DARK1;
					
				}else {
					std::stringstream s;
					s<<this_cell.aroundmines;
					fl_color(count_colors[this_cell.aroundmines-1]); //??? TODO
					fl_font(FL_COURIER | FL_BOLD, 16);
					// TODO align to top??
					fl_draw(s.str().c_str(), x+2, y - fl_descent() + fl_height());	
				}
				fl_draw_box(FL_BORDER_BOX, x, y, CELL_SIZE, CELL_SIZE, c);
			}
			
			if (this_cell.is_flagged == true){
				imgFlag_->draw(x,y);
 			}
		}
	}
	cout<<"draw end"<<endl;
}	

int GameBoard::handle(int event){

	cout<<"handle"<<endl;
	Fl::wait();
	
	return 0;
}

// int GameBoard::handle(int event){

// 	cout<<"handle"<<endl;
	
// 	int x, y,i,j;

// 	x = Fl::event_x();
// 	y = Fl::event_y();
// 	// if event beginning 
// 	if (event == FL_PUSH){
// 		// check if out of the gameborder
// 		if(x < this->x() || x > this->x() + grid_width_ * CELL_SIZE ||
// 		   y < this->y() || y  > this->y() + grid_height_ * CELL_SIZE )
// 			return 0;
			
// 		return 1;
		
// 	}else if(event == FL_RELEASE){
// 		// check if out of the gameborder
// 		if(x < this->x() || x > this->x() + grid_width_ * CELL_SIZE ||
// 		   y < this->y() || y > this->y() + grid_height_ * CELL_SIZE )
// 			return 0;

// 		return 1;
// 	}// if event end
	
// 		i = (x - this->x())/CELL_SIZE;
// 		j = (y - this->y())/CELL_SIZE;
   
// 		// if event_button left mouse	
// 		if (Fl::event_button() == FL_LEFT_MOUSE && cells_[i][j].is_uncovered == false){
// 			if (cells_[i][j].is_mine == true){
// 				status_ = GameStatus::GAMEOVER;
// 			}else{
// 				cells_[i][j].is_uncovered = true;
// 				remain_cells_--;
// 				// TODO
// 				//	checkAroundCells(x,y);
// 			}
// 		}
// 		//else if event_button right mouse
// 		else if (Fl::event_button() == FL_RIGHT_MOUSE && cells_[i][j].is_uncovered == true && cells_[i][j].is_flagged == false ){
// 			cells_[i][j].is_flagged == true;
// 			remainFlag_--;
		
// 			if (cells_[i][j].is_mine == true){
// 				Point temp_p = Point(i,j);	
// 				remainMines_.erase(std::find(remainMines_.begin(), remainMines_.end(), temp_p));
// 			}
// 		}
// 		// else if event_button right mouse
// 		else if (Fl::event_button() == FL_RIGHT_MOUSE && cells_[x][y].is_flagged == true){
// 			cells_[x][y].is_flagged == false;
// 			remainFlag_++;
			
// 			if (cells_[x][y].is_mine == true){
// 				Point temp_p = Point(i,j);
// 				remainMines_.insert(temp_p);
// 			}		
// 		}else{
// 		return Fl_Box::handle(event); // ???
// 	}

// 	// TODO
// 	this-> checkGameStatus();
// 	this-> mainWindow_-> _updateGameStatus();

// 	cout<<"handle end"<<endl;
	
// 	return 1;
// }

void GameBoard::checkAndUncoverAroundCells(int i, int j){
	
	if (cells_[i][j].aroundmines == 0){
		if (i-1 >= 0 && j-1 >= 0 && cells_[i-1][j-1].is_flagged != true){
				cells_[i-1][j-1].is_uncovered = true;
				remain_cells_--;
				checkAndUncoverAroundCells(i-1, j-1);
		}
		if (j-1 >= 0 && cells_[i][j-1].is_flagged != true){
				cells_[i][j-1].is_uncovered =true;
				remain_cells_--;
				checkAndUncoverAroundCells(i,j-1);
		}
		if (i+1 < grid_width_ && j-1>=0 && cells_[i+1][j-1].is_flagged != true){
				cells_[i+1][j-1].is_uncovered =true;
				remain_cells_--;
				checkAndUncoverAroundCells(i+1,j-1);
		}
		if (i-1 >= 0 && cells_[i-1][j].is_flagged != true){
				cells_[i-1][j].is_uncovered =true;
				remain_cells_--;
				checkAndUncoverAroundCells(i-1,j);
		}
		if (i+1 < grid_width_ && cells_[i+1][j].is_flagged != true){
				cells_[i+1][j].is_uncovered =true;
				remain_cells_--;
				checkAndUncoverAroundCells(i+1,j);
		}
		if (i-1 >= 0 && j+1 < grid_height_ && cells_[i-1][j+1].is_flagged != true){
				cells_[i-1][j+1].is_uncovered =true;
				remain_cells_--;
				checkAndUncoverAroundCells(i-1,j+1);
		}
		if (j+1 < grid_height_ && cells_[i][j+1].is_flagged != true){
				cells_[i][j+1].is_uncovered =true;
				remain_cells_--;
				checkAndUncoverAroundCells(i,j+1);
		}
		if (i+1 < grid_width_ && j+1 < grid_height_ && cells_[i+1][j+1].is_flagged != true){
				cells_[i+1][j+1].is_uncovered =true;
				remain_cells_--;
				checkAndUncoverAroundCells(i+1,j+1);
		}
		
		this->redraw();
	}			
}

void GameBoard::checkGameStatus(){
	// TODO reset game_status_ for each new game??

	if(status_ == GAMEOVER){
		
	}else if (remain_cells_ == 0)
		status_ = WIN;
	else{
		status_ = RUN;
	}
		
}
