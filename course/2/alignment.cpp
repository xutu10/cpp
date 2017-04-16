#include<iostream>
using namespace std;

struct A{
	char a;
	char b;
	char c;
	char d;
};

int main(int argc, char *argv[])
{
    cout<<sizeof(struct A)<<endl;
    return 0;
}
