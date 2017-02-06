
class private_test{
public:
	private_test(int, int, float);
	float _c;
	void show();
	enum status{FINDING, BACKING, FINISHED};
	int test_enum();
	
private:
	int _a;
	int _b;
	int status;
	const int _d = 3; 
	int add();
	
};

#include<iostream>
using namespace std;

private_test::private_test(int a,int b,float c): _a(a), _b(b), _c(c),status(FINDING) { }

int private_test::add(){
	return _a + _b;
}

int private_test::test_enum(){
	if(status == FINDING)
		cout<<"now is finding"<<endl;
}

void private_test::show(){
	cout<<"result is: "<<add()<<endl;
}


int main(){

	private_test pt(1,2,3.14);
	pt.show();
	cout<<"c is: "<<pt._c<<endl;
	pt.test_enum();
	//	pt.add();  private member function
	//	cout<<pt.a<<endl;  private member not visible outside class

	

	return 0;
}
