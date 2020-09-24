#include <iostream>
#include <set>

/*
1. argument which is const as "this"" passed to the function, the function must be const

2. auto it : s iterates by value
 */


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

	// Element which is stored in set as const
	// *it as this is passed to this function, in this case function must be const
	bool operator==(const Point& p) const{ 
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
	
	for (auto it : s)
		std::cout<<it.x<<","<<it.y<<std::endl;

	// test function earse(find())
	Point p(1,1);
	std::cout<<"###################"<<std::endl;
	// erase(it) not work??? => auto it by value
	
	for (auto &it : s){
		if (it  == p)
			s.erase(it);
	}

	// it works
	// for (auto it=s.begin(); it != s.end();it++){
	// 	if (*it  == p)
	// 		s.erase(it);
	// }

	
	for (auto it : s)
	std::cout<<it.x<<","<<it.y<<std::endl;

	return 0;	
}
