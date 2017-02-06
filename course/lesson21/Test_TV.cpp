#include"TV.h"
#include"TV_controller.h"
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	TV tv(5,6);
	TV_controller tvc;
	cout<<tv.volume_<<","<<tv.chanel_<<
		endl;
	tvc.volume_up(tv);
	cout<<tv.volume_<<","<<tv.chanel_<<
		endl;
    return 0;
}
