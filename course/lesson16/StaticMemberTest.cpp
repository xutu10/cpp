#include"StaticMember.h"
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	
	// cout<<StaticMember::objCounter<<endl;
	cout<<StaticMember::getObjCounter()<<endl;
	StaticMember sm;
//	cout<<StaticMember::objCounter<<endl;
	
    return 0;
}
