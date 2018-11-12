#include "newGameDialog.h"
#include<FL/Fl_Button.H>
#include<FL/Fl_Group.H>

static const int diffData[][3]={
	{9,9,10},
	{16,16,40},
	{16,30,99},
};


void cancel_cb(Fl_Widget*, void* ctx){

	newGameDialog *ngd = static_cast<newGameDialog*> (ctx);
	ngd-> hide();
}

void newgame_cb(Fl_Widget*, void* ctx){

	newGameDialog* ngd = static_cast<newGameDialog*>(ctx);
	ngd->_boardH = diffData[ngd->_diff][0];
	ngd->_boardW = diffData[ngd->_diff][1];
	ngd->_mines = diffData[ngd->_diff][2];

	ngd->hide();
}

void radio_cb(Fl_Widget*, void* ctx){
	newGameDialog* ngd = static_cast<newGameDialog*>(ctx);
		
	if(ngd->_radioBeginner->value() == 1){
		ngd->_diff = newGameDialog::Beginner;
	}else if (ngd->_radioIntermediate->value() == 1){
		ngd->_diff = newGameDialog::Intermediate;
	}else if (ngd->_radioExpert->value() == 1){
		ngd->_diff = newGameDialog::Expert;
	}else if (ngd->_radioCustom->value() == 1){
		ngd->_diff = newGameDialog::Custom;
	}

	if(ngd->_diff == newGameDialog::Custom) {
        ngd->_custW->activate();
        ngd->_custH->activate();
        ngd->_custMines->activate();
    } else {
        ngd->_custW->deactivate();
        ngd->_custH->deactivate();
        ngd->_custMines->deactivate();
	}
   
}

newGameDialog::newGameDialog() : Fl_Window(300,300,"new game"){

	Fl_Button* newButton = new Fl_Button(20, 220, 100, 25);
	newButton->label("new game");
	newButton->callback(newgame_cb,this);
	
	Fl_Button* cancelButton = new Fl_Button(150, 220, 60, 25);
	cancelButton->label("cancel");
	cancelButton->callback(cancel_cb,this);

	Fl_Group* radioGroup = new Fl_Group(10,10,100, 125);
	
	_radioBeginner = new Fl_Radio_Round_Button(30, 30, 20, 25,"Beginner");
	_radioBeginner->setonly();
	_radioBeginner->callback(radio_cb,this);
	radioGroup->add(_radioBeginner);

	_radioIntermediate = new Fl_Radio_Round_Button(30, 55, 20, 25,"Intermediate");
	_radioIntermediate->callback(radio_cb,this);
	radioGroup->add(_radioIntermediate);

	_radioExpert = new Fl_Radio_Round_Button(30, 80, 20, 25,"Expert");
	_radioExpert->callback(radio_cb,this);
	radioGroup->add(_radioExpert);

	_radioCustom = new Fl_Radio_Round_Button(30, 105, 20, 25,"Custom");
	_radioCustom->callback(radio_cb,this);
	radioGroup->add(_radioCustom);
	
	radioGroup->end();	
	//window->add(newButton);
	//window->add(cancelButton);

	_custH = new Fl_Spinner(200, 50, 50, 30);
	_custH->minimum(1);
	_custH->maximum(99);
	
    _custW = new Fl_Spinner(200, 85, 50, 30);
	_custW->minimum(1);
	_custW->maximum(99);
	
    _custMines = new Fl_Spinner(200, 115, 50, 30);
    _custMines->minimum(1);
    _custMines->maximum(99);

    _custH->deactivate();
	_custW->deactivate();
	_custMines->deactivate();
		
}

newGameDialog::~newGameDialog(){
	
}
