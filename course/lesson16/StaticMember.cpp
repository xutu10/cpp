#include"StaticMember.h"

using namespace std;

int StaticMember::objCounter = 0;// init 

StaticMember::StaticMember()
{
	++objCounter;
}


StaticMember::~StaticMember()
{
	--objCounter;	
}

int StaticMember::getObjCounter(){

	return objCounter;
}
