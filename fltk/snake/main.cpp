#include"Snake.h"

#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<iostream>
#include<time.h>
using namespace std;

int main(int argc, char* argv[]){

	srand(time(NULL));
	Fl_Window* window = new Fl_Window(240, 240);
	Snake* snake = new Snake(0,0);
	
	window->end();
	window->show();	
	
	return Fl::run();
}
