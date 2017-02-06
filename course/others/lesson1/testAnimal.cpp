#include"Fish.h"
#include"animal.h"
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	Fish fish;
	fish.breathe();
	Animal animal(30,40);
	animal.breathe();
    return 0;
}
