#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Menu_Bar.H>

void createMenu(Fl_Menu_Bar *bar){
	static const Fl_Menu_Item _menuItems[] ={
		{ "Game", 0,0,0, FL_SUBMENU	},
		{"new game", 0,0,0},
		{"high score", 0,0,0,FL_MENU_DIVIDER},
		{"exit", 0,0,0},
		{0},
		{"help", 0,0,0,FL_SUBMENU},
		{"about", 0,0,0,FL_MENU_INACTIVE},		
		{0},
	};	

	bar->copy(_menuItems);

	

}


int main(int argc, char ** argv){

	Fl_Window *window = new Fl_Window(340,180);
	// Fl_Box *box = new Fl_Box(20,40,300,100,"Hello, World!");
	// box->box(FL_UP_BOX);
	// box->labelfont(FL_BOLD+FL_ITALIC);
	// box->labelsize(36);
	// box->labeltype(FL_SHADOW_LABEL);
	Fl_Menu_Bar *_menuBar = new Fl_Menu_Bar(0,0,100,30);
	createMenu(_menuBar);
	//window->add(_menuBar); segement fault
	window->end();
	window->show(argc, argv);
	return Fl::run();

}

