#include<boost/shared_ptr.hpp>
#include<iostream>
#include<memory>
#include<vector>
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

	vector<auto_ptr<X> > v;
	auto_ptr<X> p(new X);
	// 	v.push_back(p); error

	vector<boost::shared_ptr<X> > shared_v;
	boost::shared_ptr<X> shared_p(new X);
	// pushback will create another sharedptr referencing to X
	shared_v.push_back(shared_p);
	cout<<shared_p.use_count()<<endl;
	
	return 0;
}
