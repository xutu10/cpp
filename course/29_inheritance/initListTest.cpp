#include<iostream>
using namespace std;

enum Manu { FORD, BMW};

class Vehicle{
protected:
	Manu manu_;
};

class Car : public Vehicle{

	Car(Manu manu){
		manu_ = manu;
	}	
};

int main(){

	
	
	return 0;
}
