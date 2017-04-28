/*
 * Car.h
 *
 *  Created on: Apr 28, 2017
 *      Author: xutu
 */

#ifndef CAR_H_
#define CAR_H_

#include "Vehicle.h"
#include "Wheel.h"

class Car: public Vehicle {
public:
	Car(Manufacturer);
	Car(Manufacturer, int);
	void print();
	virtual ~Car();

protected:
	Wheel wheel_;
};

#endif /* CAR_H_ */
