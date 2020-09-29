#include <iostream>
#include <set>
#include <algorithm>
#include<stdio.h>
using namespace std;
/*
1.  auto it : s iterates by value and ref
  
  in this there is no difference by value and ref

2. set.find(Point), set.erase(Point) not work. set.erase(it) ok
   instead std::find() can be used

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
	// Point p(1,1);
	// Point p2(2,2);
	
	s.insert(Point(1,1));
	s.insert(Point(2,2));
	// not work???
	//	s.erase(p);

	for(auto it : s){
		cout<<it.x<<","<<it.y<<endl;
	}

	Point tmp(1,1);

	// ok
	// auto if_find = std::find(s.begin(), s.end(), tmp) ;
	// if(if_find != s.end())
	// 	s.erase(if_find);

	// ok
	s.erase(std::find(s.begin(), s.end(), tmp));
	
	for(auto it : s){
		cout<<it.x<<","<<it.y<<endl;
	}
	
	
	// not work
	// for(auto &it : s){
	// 	printf("address : %p \n", it);   //0x01, 0x02;
	// 	if(tmp == it){
	// 		cout<<"deleted"<<endl;
	// 		s.erase(p);
	// 		//s.erase(it);
	// 	}		
	// }

	// it works
	// for (auto it=s.begin(); it != s.end();it++){
	// 	if (*it  == tmp)
	// 		s.erase(it);
	// }

	// auto it = s.find(tmp);
	// if(it != s.end()){
	// 	s.erase(it);
	// 	cout<<"deleted"<<endl;
	// }
		
	
	return 0;	
}
