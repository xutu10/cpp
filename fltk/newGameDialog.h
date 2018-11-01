#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <FL/Fl_Window.H>
#include<FL/Fl_Radio_Round_Button.H>

class newGameDialog: public Fl_Window{

public:
newGameDialog();
~newGameDialog();

 enum Diffculty{
	 Beginner = 0,
 	 Intermediate = 1,
	 Expert = 2,
	 Custom = 3
 };

 
private:
 int _boardW, _boardH, _mines; 
 Diffculty _diff = Beginner;

 Fl_Radio_Round_Button* _radioBeginner;
 Fl_Radio_Round_Button* _radioIntermediate;
 Fl_Radio_Round_Button* _radioExpert;

 
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

 Diffculty getDiffculty() const{
	 return this->_diff;
 }
 
private:
 friend void newgame_cb(Fl_Widget*, void*);
 friend void cancel_cb(Fl_Widget*, void*);
 friend void radio_cb(Fl_Widget*, void*);
/* private: */
/* Fl_Radio_Round_Button* _radBeginner; */

};



#endif
