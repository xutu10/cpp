#include"Shape.h"
#include "Factory.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void draw_all_shapes(const vector<Shape*>& v){
	vector<Shape*>::const_iterator it;
	for(it = v.begin();it!= v.end();++it){
		(*it)->draw();
	}
}

void delete_all_shapes(const vector<Shape*>& v){
	vector<Shape*>::const_iterator it;
	for(it=v.begin();it!=v.end();++it){
		delete(*it);
	}
}

int main(int argc, char *argv[])
{
    vector<Shape*> v;

	Shape* ps;
	ps = (Shape*)Factory::create_obj("circle");
	v.push_back(ps);
	ps = (Shape*)Factory::create_obj("square");
	v.push_back(ps);
	ps = (Shape*)Factory::create_obj("triangle");
	v.push_back(ps);

	draw_all_shapes(v);
	delete_all_shapes(v);

	
    return 0;
}
