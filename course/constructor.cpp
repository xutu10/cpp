#include<iostream>
using namespace std;

class Std{

public:
	explicit Std(int a):a_(a){
		
	}
	
	int a_;	
};

int main(int argc, char *argv[])
{
//    Std s = 5;  without explicit
	Std s(5);
	cout<<s.a_<<endl;
    return 0;
}
