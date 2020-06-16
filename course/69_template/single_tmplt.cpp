#include<iostream>
#include"singleton.h"
using namespace std;

class applicationImpl{

public:
	applicationImpl(){
		cout<<"applicationImpl"<<endl;
	}
	~applicationImpl(){
		cout<<"~applicationImpl"<<endl;
	}
	void run(){
		cout<<"application run..."<<endl;
	}
};

typedef Singleton<applicationImpl> Application;

int main(){

	// Application a; in this way can't create object
	Application::GetInstance().run();
	Application::GetInstance().run();

	return 0;
}
