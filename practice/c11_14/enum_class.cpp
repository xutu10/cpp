#include<iostream>
using namespace std;


enum Color{
	red, green, black
};

class Car{

public:
	Car(int t):type_(t){

		if(type_ == 1)
			carColor_ = Color::red;

		if(type_ == 2)
			carColor_ = Color::green;

	}


	void getColor(){
		cout<<carColor_<<endl;
	}
	
	~Car(){
		
	}

	
private:
	int type_;
	Color carColor_;
		
};

int main(){

	Car c(1);
	c.getColor();

	Car d(2);
	d.getColor();

	
	return 0;
}
