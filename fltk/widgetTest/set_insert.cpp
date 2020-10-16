#include<set>
#include<iostream>
#include<algorithm>

using namespace std;

/*
  two objects a and b are considered equivalent(not unique) if neither
  compares less than other: !comp(a,b) and !comp(b,a)
  example for the < below:
  a: 1,6, b: 0,7; in this case just one element will be inserted 
 */

struct Point{
	Point(int x, int y):x(x), y(y){}
	
	int x, y;	
};

inline bool operator<(const Point& p1, const Point& p2){
	if (p1.x == p2.x && p1.y == p2.y)
		return false;
	// 	return (p1.x + p1.y < p2.x + p2.y);
	return true;
}

inline bool operator==(const Point& p1, const Point& p2){ 
	return (p1.x == p2.x) && (p1.y == p2.y);
}

inline bool operator!=(const Point& p1, const Point& p2){
	return (p1.x != p2.x) || (p1.y != p2.y);
}


int main(){

	set<Point> remainMines_;
	
	int mines_placed=0,i,j = 0;
	int mines = 10;
	while (mines_placed < mines){
		i = rand() % 9;
		j = rand() % 9;
		
		mines_placed++;
		remainMines_.insert(Point(i,j));
			cout<<i<<","<<j<<endl;
	}
	
	cout<<remainMines_.size()<<endl;
	for(auto it : remainMines_)
		cout<<it.x<<","<<it.y<<endl;

	return 0;
}
