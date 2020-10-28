#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Browser.H>
#include<FL/Fl_Select_Browser.H>
#include <iostream>
using namespace std;

Fl_Select_Browser* browser;


int main(int argc, char** argv){

	Fl_Window* window = new Fl_Window(300, 300);
	browser = new Fl_Select_Browser(50, 50, 100, 60, "Level");

	char* simple = "Simple";
	browser->insert(1, simple, 0);

	char* medium = "Medium";
	browser->insert(2, medium, 0);

	char* diffic = "Difficulty";
	browser->insert(3, diffic, 0);

	
	
	window->add(browser);
	

	window->end();
	window->show();	
	
	return Fl::run();

}
