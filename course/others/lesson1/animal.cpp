#include<iostream>
using namespace std;

class Animal{
	public:
	Animal(int weight,int height){
		cout<<"animal construct"<<endl;
	}
	~Animal(){
		cout<<"animal deconstruct"<<endl;
	}
	void eat(){
		cout<<"animal eat"<<endl;
	}
	virtual void breathe(){
		cout<<"animal breathe"<<endl;
	}
   	// virtual void breathe()=0; as abstract method

	// the class, which include abstract method,is abstract class
	// cannot instance
	void sleep(){
		cout<<"animal sleep"<<endl;
	}
};

class Fish : public Animal{
	public:
	Fish():Animal(2,3){
		cout<<"fish construct"<<endl;
	}
	~Fish(){
	   	cout<<"fish deconstruct"<<endl;
	}
    void breathe(){
		//	Animal::breathe();
		cout<<"fish breathe"<<endl;
	}
};
void fn(Animal *ani){
	
	ani->breathe();
}

int main(int argc, char *argv[])
{
    Fish fish;
	//fish.breathe();
	Animal *aptr;
	aptr = &fish;
	fn(aptr);
	return 0;
}










