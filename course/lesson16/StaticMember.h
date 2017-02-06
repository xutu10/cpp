#pragma once

class StaticMember{
public:
	StaticMember();
	~StaticMember();
	static int getObjCounter();
private:
	static int objCounter;  //just declaration, not initialized yet
};
