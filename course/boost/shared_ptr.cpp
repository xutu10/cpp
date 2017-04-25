#include<iostream>
#include<boost/shared_ptr.hpp>
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
	boost::shared_ptr<X> p(new X);
	cout<<"p "<<p.use_count()<<endl;
	boost::shared_ptr<X> p1 = p;
	cout<<"p "<<p.use_count()<<" p1 "<<p1.use_count()<<endl;
	//p.reset();
	cout<<"p "<<p.use_count()<<" p1 "<<p1.use_count()<<endl;

	boost::shared_ptr<X> p2;
	p2 = p;
	cout<<p2.use_count()<<endl;
	p1.reset();
	cout<<"exit"<<endl;

	return 0;
		
}
