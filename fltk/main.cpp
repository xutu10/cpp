#include "mainWindow.h"

int main(int argc, char* argv[]){
	mainWindow w(500,500,"minesweeper_XUTU");
	w.show(argc, argv);

	return Fl::run(); 
}
