/*
 * Car.cpp
 *
 *  Created on: Apr 28, 2017
 *      Author: xutu
 */

#include "Car.h"
#include <iostream>
using namespace std;


// Car::Car(Manufacturer manufacturer) : manufacturer_(manufacturer){  // doesn't have manu_
Car::Car(Manufacturer manufacturer) {
	mileage_ = 0;
	manufacturer_ = manufacturer;
}

Car::~Car() {
	// TODO Auto-generated destructor stub
}

void Car::print(){
	cout<<"i am a car"<<endl;
}

