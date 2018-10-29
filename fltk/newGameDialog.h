#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <FL/Fl_Window.H>

class newGameDialog: public Fl_Window{

public:
newGameDialog();
~newGameDialog();

private:
int _boardW, _boardH, _mines; 

protected:
 int getBoardW() const{
    return this->_boardW;
 }

 int getBoardH() const{
    return this->_boardH;
 }

 int getMines() const{
    return this->_mines;
 }

private:
friend void new_game_cb(Fl_Widget*, void*);
 friend void cancel_cb(Fl_Widget*, void*);

private:
Fl_Radio_Round_Button* _radBeginner;
 
};



#endif
