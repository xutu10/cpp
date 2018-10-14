#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Window.H>
using namespace std;

class mainWindow : public Fl_Window{

public:
	mainWindow(int w, int h, const char* t);
	~mainWindow();
	void _initMenuBar();
};

mainWindow::mainWindow(int w, int h, const char* t) : Fl_Window(w,h){
	this->_initMenuBar();
}

void mainWindow::_initMenuBar(){
		static const Fl_Menu_Item _menuItems[] = {
		{ "&Game", 0, 0, 0, FL_SUBMENU },
		{ "&New Game...", FL_COMMAND + 'n', (Fl_Callback *) menu_new_game_cb, this },
		{ "High Scores...", 0, (Fl_Callback *) show_high_scores_cb, this, FL_MENU_DIVIDER },
		{ "E&xit", FL_COMMAND + 'q', (Fl_Callback *) quit_cb, this },
		{ 0 },

		{ "&Help", 0, 0, 0, FL_SUBMENU },
		{ "About...", 0, (Fl_Callback *) show_about_cb, this },

		{ 0 },
		{ 0 }
	};

	// copy the menu items and create the menu bar
	this->_menuBar = new Fl_Menu_Bar(0, 0, this->w(), 30);
	this->_menuBar->copy(_menuItems);

	// add to window
	this->add(this->_menuBar);

}
