#include <iostream>
using namespace std;
//struct Point{
class Point{
public://private protected
	int x;
	int y;
	Point(){
		x = 0;
		y = 0;
}
	~Point(){

	}
		
	void output(){
		// cout<<"in struct"<<cout<<x<<endl<<y<<endl;
		cout<<x<<endl<<y<<endl;
	}
	void output(int a, int b){
		// this->x = x;that need just when
		// this->y = y;	parameter is same as member name
		x = a;
		y = b;
	}
};
int main(int argc, char *argv[])
{
    Point pt;
	pt.output(7,8);
// pt.x = 5;
 	// pt.y = 8;
 	// cout<<pt.x<<endl<<pt.y<<endl;
	pt.output();
    return 0;
 }









