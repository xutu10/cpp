#include<iostream>
using namespace std;

class Test{
public:
	Test(int x): x_(x),counter(0){
		
	}
	int get_x() const{
		return x_;
	}
	int get_x(){
		return x_;
	}
	void output() const{
		cout<<x_<<endl;
		counter++;
	}
private:
	int x_;
	mutable int counter;
	
};

int main(int argc, char *argv[])
{
	// const variable can only call const fun
    const Test a(10);
    return 0;
}
