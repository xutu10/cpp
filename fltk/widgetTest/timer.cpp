#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Box.H>
#include<FL/fl_draw.H> // fl_draw_box
#include<FL/Fl_PNG_Image.H>

#include <iostream>
#include <sstream>
#include <iomanip> // setfill, setw
#include <ctime>
using namespace std;

class GameBoard: public Fl_Box{
public:
	GameBoard(int a, int y, int wd, int h, const char* L=0): Fl_Box(a, y, wd, h,L){
		startTime_ = time(nullptr);
		time_ = new Fl_Box(FL_UP_BOX, this->x()+50, this->y(), 40, 16,"timer");
		img = new Fl_PNG_Image("mine.png");
	}

	void show_time(){
		//		time_t timer = time(nullptr) - startTime_;
		int timer = difftime(time(nullptr), startTime_);
		stringstream ss;
		ss<<setfill('0')<<setw(3)<<timer;
		time_->copy_label(ss.str().c_str());
	}

	void draw(){

		cout<<"draw"<<endl;
		
		Fl_Box::draw(); // draw the large box
		for(int i = 0; i< 10; i++){
			for(int j =0; j< 10; j++){
				fl_draw_box(FL_UP_BOX,this->x()+16+i*16,this->y()+16+j*16 , 16, 16, FL_GRAY);
			}
		}		
		img->draw(this->x()+16, this->y()+16);
		
	}

private:
	time_t startTime_;
	Fl_Box* time_;
	Fl_PNG_Image* img;
	
};

void timer_cb(void* ctx){

	static_cast<GameBoard *>(ctx)->show_time();
    Fl::repeat_timeout(1.0,timer_cb, ctx);
}

int main(int argc, char** argv){

	Fl_Window* window = new Fl_Window(300, 300);
	GameBoard* box = new GameBoard(10,10, 250,250,"my box");
	
	window->end();
	window->show();

	Fl::repeat_timeout(1.0,timer_cb,box);
	
	
	return Fl::run();

}
