#ifndef SCORES_H
#define SCORES_H

#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Hold_Browser.H>
#include<FL/Fl_Multiline_Output.H>
#include<FL/Fl_Button.H>

#include<fstream>
#include<sstream> // istringstream



class Scores : public Fl_Window{
 public:
	Scores();
	~Scores();

 private:
	void showScores_(int);	
	
 private:
	friend void selectCb(Fl_Widget*, void*);
	friend void okCb(Fl_Widget*, void*);
	
 private:
	Fl_Hold_Browser* brw_;
	Fl_Multiline_Output* out_;
	Fl_Button* button_;
};

#endif
