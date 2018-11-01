#include "newGameDialog.h"
#include<FL/Fl_Radio_Round_Button.H>
#include<FL/Fl_Spinner.H>
#include<FL/Fl_Button.H>
#include<FL/Fl_Group.H>

static const int diffData[][3]={
	{9,9,10},
	{16,16,40},
	{16,30,99},
};


void cancel_cb(Fl_Widget*, void* ctx){

	newGameDialog *newgame = static_cast<newGameDialog*> (ctx);
	newgame-> hide();
}

void newgame_cb(Fl_Widget*, void* ctx){

	newGameDialog* newgame = static_cast<newGameDialog*>(ctx);
	
		// newgame->hide(); ???
}

newGameDialog::newGameDialog() : Fl_Window(300,300,"new game"){

	Fl_Button* newButton = new Fl_Button(20, 220, 100, 25);
	newButton->label("new game");
	newButton->callback(newgame_cb);
	
	Fl_Button* cancelButton = new Fl_Button(150, 220, 60, 25);
	cancelButton->label("cancel");
	cancelButton->callback(cancel_cb);

	Fl_Radio_Round_Button* radioBeginner = new Fl_Radio_Round_Button(30, 30, 20, 150,"Beginner");
	Fl_Radio_Round_Button* radioIntermediate = new Fl_Radio_Round_Button(30, 55, 20, 150,"Intermediate");
	Fl_Radio_Round_Button* radioExpert = new Fl_Radio_Round_Button(30, 80, 20, 150,"Expert");
	radioBeginner->setonly();
	
	//window->add(newButton);
	//window->add(cancelButton);

	Fl_Spinner* custH = new Fl_Spinner(200, 50, 50, 30);
	custH->minimum(1);
	custH->maximum(99);
	
	Fl_Spinner* custW = new Fl_Spinner(200, 85, 50, 30);
	custW->minimum(1);
	custW->maximum(99);
	
	Fl_Spinner* custMines = new Fl_Spinner(200, 115, 50, 30);
	custMines->minimum(1);
	custMines->maximum(99);

	// custH->deactivate();
	// custW->deactivate();
	// custMines->deactivate();
		
}

newGameDialog::~newGameDialog(){
	
}
