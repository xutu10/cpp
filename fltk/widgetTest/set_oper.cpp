#include <iostream>
#include <set>

struct Point{

	Point(int x,int y) : x(x),y(y){}

	int x, y;
	// p is the current element in set, "this" is the coming element which to be placed
	bool operator<(const Point& p) const{
		if ((x+y) == (p.x + p.y)){
			return true;      // (0,1), (1,0)
			// return false;  (1,0), (0,1)     
			// return false; // no sum of any element is same 
		}
		return (x+y) < (p.x + p.y);
	}
	
	bool operator==(const Point& p){ 
		return (p.x == x) && (p.y == y);
	}

};

int main(){

	std::multiset<Point> s;
	//	create set
	
	s.insert(Point(1,0));
	s.insert(Point(0,1));
	
	std::set<Point> ::iterator it;

	for (it=s.begin();it!=s.end();it++)
		std::cout<<it->x<<","<<it->y<<std::endl;

	// for (it=s.begin();it!=s.end();it++){
	// 	if (it->x == it->y)
	// 		s.erase(it);
	// }
	// std::cout<<std::endl;
	// for (it=s.begin();it!=s.end();it++)
	// 	std::cout<<it->x<<","<<it->y<<std::endl;

	return 0;	
}
