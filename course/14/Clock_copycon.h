#pragma once

class Clock{
public:
	int second;
	int minute;
	int hour;
	Clock(int h, int m, int s);
	// there is default copyconstructor
	// only one param is acceptable
	Clock(const Clock& other);
	void display() const;
	void update();
	~Clock();	
};
