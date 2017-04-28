/*
 * Vehicle.h
 *
 *  Created on: Apr 28, 2017
 *      Author: xutu
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

enum Manufacturer {FORD, AUDI, HONDA, MERCEDES, OPEL};

class Vehicle {
public:
	Vehicle();
	int getMileage();
	void addToMileage(int);
	virtual void print();
	Manufacturer getManufacturer();
	virtual ~Vehicle();

protected:
	Manufacturer manufacturer_;
	int mileage_;
};

#endif /* VEHICLE_H_ */
