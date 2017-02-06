#include<iostream>
using namespace std;

//change the value of two params
void change1(int &a, int &b);// use reference
void change2(int *a,int *b);// use pointer

int main(int argc, char *argv[])
{
	int x = 9;
	int y =7;
	change1(x,y);
	change2(&x,&y);
		
    return 0;
}









