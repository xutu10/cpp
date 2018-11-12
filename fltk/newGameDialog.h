#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <FL/Fl_Window.H>
#include<FL/Fl_Radio_Round_Button.H>
#include<FL/Fl_Spinner.H>

class newGameDialog: public Fl_Window{

public:
newGameDialog();
~newGameDialog();

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
 
  enum Diffculty{
	 Beginner = 0,
 	 Intermediate = 1,
	 Expert = 2,
	 Custom = 3
 };

 
private:
 int _boardW, _boardH, _mines; 
 Diffculty _diff = Beginner;

 Fl_Spinner* _custW;
 Fl_Spinner* _custH;
 Fl_Spinner* _custMines;
 
 Fl_Radio_Round_Button* _radioBeginner;
 Fl_Radio_Round_Button* _radioIntermediate;
 Fl_Radio_Round_Button* _radioExpert;
 Fl_Radio_Round_Button* _radioCustom;
  
 
private:
 friend void newgame_cb(Fl_Widget*, void*);
 friend void cancel_cb(Fl_Widget*, void*);
 friend void radio_cb(Fl_Widget*, void*);
/* private: */
/* Fl_Radio_Round_Button* _radBeginner; */

};



#endif
