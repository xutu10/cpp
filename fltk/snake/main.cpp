#include"mainWindow.h"
#include<iostream>

using namespace std;

int main(int argc, char* argv[]){


	mainWindow* mw = new mainWindow(500, 500, "Snake_XUTU");

	mw->show(argc, argv);
	cout<<" snake"<<endl;
	
	return Fl::run();
}
