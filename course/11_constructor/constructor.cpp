#include"constructor.h"
#include <iostream>
using namespace std;

constructor::constructor(){
	value =60;
}


constructor::constructor(int a){
	value =a;
}

constructor::~constructor(){
	cout<<"destory"<<value<<endl;
}

void constructor::display(){
	cout<<value<<endl;
}

