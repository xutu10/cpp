#include"Clock.h"
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Clock c1(1,1,1);
	c1.display();
	c1.update();
    return 0;
}
