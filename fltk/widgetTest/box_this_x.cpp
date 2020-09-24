#include<iostream>
#include<FL/Fl_Box.H>
#include<FL/Fl_Window.H>

using namespace std;

int main(){

	Fl_Window* window = new Fl_Window(300,300);
	
	Fl_Box* Box = new Fl_Box(10,10,30, 30);
	// x(), y() func of Fl_Box
	cout<<"x: "<<Box->x()<<", y: "<<Box->y()<<endl;

	return 0;
}
