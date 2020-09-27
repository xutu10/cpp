#include <iostream>
#include <set>
#include<stdio.h>
using namespace std;
/*
  auto it : s iterates by value and ref
  
  in this there is no difference by value and ref
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
	Point p(1,1);
	Point p2(2,2);
	
	s.insert(p);
	s.insert(p2);
	// not work???
	//	s.erase(p);
	
	printf("address of p : %p \n", p);  // 0x01

	Point tmp(1,1);
	
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

	
	for(auto it : s){
		cout<<it.x<<","<<it.y<<endl;
		printf("value of it :%p \n",it);
	}
	
	return 0;	
}
