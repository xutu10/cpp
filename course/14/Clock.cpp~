#include"Clock.h"
#include<iostream>
using namespace std;

// Clock::Clock(int h=0,int m=0,int s=0){
// 	second = s;
// 	minute = m;
// 	hour = h;
// }

//structor with initialize list

Clock:: Clock(int h,int m,int s): hour(h),minute(m),second(s){
	
}

Clock::~Clock(){
	cout<<"destory"<<endl;
}

void Clock::display(){

	cout<<hour<<","<<minute<<","<<second<<endl;
	
}

void Clock::update(){
	second++;
	display();
}
