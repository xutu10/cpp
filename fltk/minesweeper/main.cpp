#include "mainWindow.h"
#include<time.h>

int main(int argc, char* argv[]){

	srand(time(NULL));
	mainWindow* w = new mainWindow(500,500,"minesweeper_XUTU");
	//GameBoard* box = new GameBoard(100,100,9,9,10,w);
	
	w->show(argc, argv);
		
	return Fl::run(); 
}
