#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Box.H>
#include<FL/fl_draw.H> // fl_draw_box

#include <iostream>
using namespace std;

class GameBoard: public Fl_Box{
public:
	GameBoard(int a, int y): Fl_Box(a, y, 250, 250,"mine"){
		x_=a;
		y_=y;
		// call the member of base class with bracket
		std::cout<<this->w()<<","<<this->x()<<std::endl;
	
	}

	void draw(){

		Fl_Box::draw(); // draw the large box
		fl_draw_box(FL_UP_BOX, x_+16, y_+16, 16, 16, FL_GRAY);
	}

	int handle(int e){

		if (e == FL_KEYDOWN){
			if(Fl::event_key() == FL_Up)
				cout<<"up"<<endl;
			if(Fl::event_key() == FL_Left)
				cout<<"left"<<endl;
		}
			
	}
	
private:
	int x_,y_;
};

int main(int argc, char** argv){

	Fl_Window* window = new Fl_Window(300, 300);
	GameBoard* box = new GameBoard(10,10);
	
	//	box->draw();
	
	//	fl_draw_box(FL_UP_BOX, x, y, 16, 16, FL_GRAY);

	// for (int i =0; i<10;i++){
	// 		x = i*16;
	// 	for (int j = 0; j<10;j++){
	// 		y = j*16;
	// 		fl_draw_box(FL_UP_BOX, x, y, 16, 16, FL_GRAY);
	// 	}
	// }

	window->end();
	window->show();	
	
	return Fl::run();

}
