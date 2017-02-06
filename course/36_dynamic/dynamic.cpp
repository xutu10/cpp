#include"Shape.h"
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
	
    return 0;
}
