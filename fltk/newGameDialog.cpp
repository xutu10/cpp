#include "newGameDialog.h"

void cancel_cb(Fl_Widget*, void* ctx){

	newGameDialog *newgamedialog = static_cast<newGameDialog*> (ctx);
	newgamedialog-> hide();
}

void new_game_cb(Fl_Widget*, void*){
	
	
}
