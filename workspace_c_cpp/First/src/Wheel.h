/*
 * Wheel.h
 *
 *  Created on: Apr 28, 2017
 *      Author: xutu
 */

#ifndef WHEEL_H_
#define WHEEL_H_

class Wheel {
public:
	Wheel();
	Wheel(int , bool);
	int getRimDiameter();
	bool isAluminium();
	virtual ~Wheel();

private:
	int rimDiameter_ = 18;
	bool aluminium_ = false;
};

#endif /* WHEEL_H_ */
