#include <iostream>
#include <set>
#include <algorithm>

struct Point{

	Point(int x,int y) : x(x),y(y){}

	int x, y;
	// p is the current element in set, "this" is the coming element which to be placed
	bool operator<(const Point& p) const{
		if ((x+y) == (p.x + p.y)){
			// return true;      // (0,1), (1,0)
			return false;  //(1,0), (0,1)     
		}
		return (x+y) < (p.x + p.y);
	}
	
	// bool operator==(const Point& p){ 
	// 	return (p.x == x) && (p.y == y);
	// }
};


int main(){

	std::multiset<Point> s;
	//	create set
	
	for (int i =0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			s.insert(Point(i,j));
	}

	std::set<Point> ::iterator it;

	for (it=s.begin();it!=s.end();it++)
		std::cout<<it->x<<","<<it->y<<std::endl;

	Point p1 = Point(1,1);
	
	it = s.find(p1);
	if (it != s.end()){
		
		std::cout<<"-------------"<<std::endl;
		it++;  // point to the previous element 
		std::cout<<it->x<<","<<it->y<<std::endl;
		
		s.erase(it);
	}
		
	
	// beginn searching and removing specific object
	// Point to = Point(1,2);
	
	// for (it=s.begin();it!=s.end();it++){
	// 	if (it->x == to.x && it->y == to.y)
	// 		s.erase(it);
	// }
	
	std::cout<<std::endl;
	for (it=s.begin();it!=s.end();it++)
		std::cout<<it->x<<","<<it->y<<std::endl;

	// end searching and removing specific object 
	
	
	// for (it=s.begin();it!=s.end();it++){
	// 	if (it->x == it->y)
	// 		s.erase(it);
	// }
	
	
	// for (it=s.begin();it!=s.end();it++)
	// std::cout<<it->x<<","<<it->y<<std::endl;

	return 0;	
}
