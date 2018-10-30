#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Button.H>
#include<FL/Fl_Radio_Round_Button.H>
#include<iostream>
using namespace std;

void newgame_cb(Fl_Widget*, void*){
	cout<<"this is new game"<<endl;
}

void cancelgame_cb(Fl_Widget*, void*){
	exit(0);
}

int main(int argc, char** argv){

	Fl_Window* window = new Fl_Window(300, 300);
	Fl_Button* newButton = new Fl_Button(20, 220, 100, 25);
	newButton->label("new game");
	newButton->callback(newgame_cb);
	
	Fl_Button* cancelButton = new Fl_Button(150, 220, 50, 25);
	cancelButton->label("cancel");
	cancelButton->callback(cancelgame_cb);

	Fl_Radio_Round_Button* radioBeginner = new Fl_Radio_Round_Button(50, 100, 20, 150,"Beginner");
	//radioBeginner->setonly();
	
	//window->add(newButton);
	//window->add(cancelButton);

	window->end();
	window->show();

	return Fl::run();
}
