#include<iostream>
#include<string>
using namespace std;


class Myexception{
public:
	Myexception(const char* message):message_(message){
		cout<<"my execption"<<endl;
	}

	Myexception(const Myexception& other):message_(other.message_){
		cout<<"copy myexception"<<endl;
	}
	~Myexception(){
		cout<<"desconstructor myexception"<<endl;
	}

	const char* catch_exception() const{
		return message_.c_str();
	}
	
private:
	string message_;
	
};

double divide(double a, double b){

	if(b == 0.0){
		Myexception e("divided by zero"); // local object, desconstructor is called after func divide, because it's lifecycle is over
		throw e;   // call copy constructor
		// throw Myexception("....") copy constructor will be never called and this object will be direct passed to catch
	}else
		return a / b;
	
}

int main(){

	try{
		cout<<divide(5.0, 0.0)<<endl;
	}
	catch(Myexception& e){ // copy constructed object is passed here
		cout<<"in catch"<<endl;
		cout<<e.catch_exception()<<endl;
	}
	return 0;
}
