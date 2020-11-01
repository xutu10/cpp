#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Browser.H>
#include<FL/Fl_Hold_Browser.H>
#include <iostream>
#include<FL/Fl_Multiline_Output.H>
#include<FL/fl_ask.H>
using namespace std;

Fl_Multiline_Output* out;

void cb_select(Fl_Widget*, void* b){

	Fl_Hold_Browser* brw = static_cast<Fl_Hold_Browser*>(b);

	int current = brw->value();

	switch(current){
	case 1:	cout<<"first is selected"<<endl; break;
	case 2: cout<<"second is selected"<<endl; break;
	default: break;
		
	}

	char* s = "show";
	
	if(current){
		out->value(s);
	}
		
}

int main(int argc, char** argv){

	Fl_Window window(500, 500);
	Fl_Hold_Browser* browser = new Fl_Hold_Browser(10, 10, 100, 60, "Level");
    out = new Fl_Multiline_Output(200, 10, 100,50);

	char* simple = "Simple";
	browser->insert(1, simple, 0);
	
	char* medium = "Medium";
	browser->insert(2, medium, 0);

	char* diffic = "Difficulty";
	browser->insert(3, diffic, 0);


	browser->callback(cb_select,browser);
	
	// if(browser.selected(1))
	// 	cout<<"first is selected"<<endl;
	
	window.add(browser);
	window.end();
	window.show();	

	const char* name = fl_input("your name","me");
	cout<<name<<endl;
		
	return Fl::run();

}
