#include <iostream>
#include <set>

struct Point{

	Point(int x,int y) : x(x),y(y){}

	int x, y;

	bool operator<(const Point& p) const{
		if ((x+y) == (p.x + p.y)){
			return true;      
			// return false; // no sum of any element is same 
		}
		return (x+y) < (p.x + p.y);
	}
	
	bool operator==(const Point& p){ 
		return (p.x == x) && (p.y == y);
}

};

int main(){

	std::set<Point> s;
	//	create set
	for(int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			//	Point p = Point(i,j);
			s.insert(Point(i,j));
	}

	std::cout<<s.size()<<std::endl;
	
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
