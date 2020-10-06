#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Box.H>
#include<FL/fl_draw.H> // fl_draw_box

#include <iostream>
#include <sstream>
#include <iomanip> // setfill, setw
#include <ctime>
using namespace std;

class GameBoard: public Fl_Box{
public:
	GameBoard(int a, int y, int wd, int h, const char* L=0): Fl_Box(a, y, wd, h,L){
		x_=a;
		y_=y;
		startTime_ = time(nullptr);
		time_ = new Fl_Box(FL_UP_BOX, x_, y_, 40, 25,"timer");

		// call the member of base class with bracket
		std::cout<<this->w()<<","<<this->x()<<std::endl;	
	}

	void show_time(){
		time_t timer = time(nullptr) - startTime_;
		stringstream ss;
		ss<<setfill('0')<<setw(3)<<timer;
		time_->copy_label(ss.str().c_str());
	}

	void draw(){

		Fl_Box::draw(); // draw the large box
		//fl_draw_box(FL_UP_BOX, x_, y_, 16, 16, FL_GRAY);

	}

private:
	int x_,y_;
	time_t startTime_;
	Fl_Box* time_;
};

void timer_cb(void* ctx){

	static_cast<GameBoard *>(ctx)->show_time();
    Fl::repeat_timeout(0.1,timer_cb, ctx);
}

int main(int argc, char** argv){

	Fl_Window* window = new Fl_Window(300, 300);
	GameBoard* box = new GameBoard(10,10, 250,250,"my box");
	
	window->end();
	window->show();

	Fl::repeat_timeout(1.0,timer_cb,box);
	
	
	return Fl::run();

}
