#include "Scores.h"

#include<cstring>
#include<vector>
#include<iostream>
using namespace std;

vector<string> diffiList = {"simple", "medium","hard"};


void selectCb(Fl_Widget*, void* w){

	Scores* b = static_cast<Scores*>(w);
	b->showScores_(b->brw_->value());
	
}

void okCb(Fl_Widget*, void * w){

	Scores* b = static_cast<Scores*>(w);
	b->hide();
	
}


Scores::Scores():Fl_Window(500,300,"Scores"){

	button_ = new Fl_Button(400, 250, 75, 30);
	button_ ->label("OK");
	button_ ->callback(okCb, this);
	
	brw_ = new Fl_Hold_Browser(10,30,100,60,"level");
	for(int i = 1; i < diffiList.size()+1; i++)
		brw_->insert(i, diffiList[i-1].c_str());

	brw_->callback(selectCb, this);

	out_ = new Fl_Multiline_Output(150, 30, 300, 100);

	// ?? necessary
	this->add(brw_);
	this->add(out_);
	this->end();
	this->show();
	
}

Scores::~Scores(){

	delete brw_, out_;
	
}

void Scores::showScores_(int level){

	string line;
	ifstream fin("record.txt");

	while(fin.is_open() && getline(fin, line)){
		if(line == diffiList[level-1]){
			for(int i = 0; i < 1; i++){
				getline(fin, line);
				out_->replace(0,out_->size(),line.c_str());
			}
			break;
		}
	}
	fin.close();
}
