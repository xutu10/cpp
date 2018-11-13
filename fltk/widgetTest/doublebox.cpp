#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Box.H>
#include<FL/fl_draw.H> // fl_draw_box
#include<FL/Fl_PNG_Image.H>

#include <iostream>

class GameBoard: public Fl_Box{
public:
	GameBoard(int x, int y, int w, int h, const char* L=0): Fl_Box(x, y, w, h,L){
		x_=x;
		y_=y;
	
		img = new Fl_PNG_Image("flower.png");
	
	}

	void draw(){
		//Fl_Box::draw(); // draw the large box
		fl_draw_box(FL_UP_BOX, x_, y_, 16, 16, FL_GRAY);
		fl_draw_box(FL_UP_BOX, x_+16, y_+16, 16, 16, FL_GRAY);
		this->img->draw(50,50);
	}

private:
	int x_,y_;
	Fl_PNG_Image* img;														
};

int main(int argc, char** argv){
	Fl_Window* window = new Fl_Window(300, 300);
	GameBoard* box = new GameBoard(10,10, 250,250,"my box");
	
	//	Fl_Box::draw();
	std::cout<<"1"<<std::endl;

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
