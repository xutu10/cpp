#include<iostream>
#include<boost/scoped_ptr.hpp>

using namespace std;

class X{

public:
	X(){
		cout<<"X"<<endl;
	}

	~X(){

		cout<<"~X"<<endl;
	}
};

int main(){

	cout<<"entrance"<<endl;
	{
		boost::scoped_ptr<X> p(new X);
		// boost::scoped_ptr<X> p2(p); can't be copied and assigned
	}
	cout<<"exit"<<endl;

	return 0;
		
}
