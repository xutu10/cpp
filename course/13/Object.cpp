#include <iostream>
using namespace std;

/*
  1. when these two classes have default constructor, output like below
     object con
	 container con
	 container de
	 object con
  2. object member whose class no default constructor must be also in initlist
  3. constant member and reference member must be ininitialized in initlist

 */


class Object{
public:
	//1. Object(){
	// 	cout<<"Object con"<<endl;
	// }
	
	Object(int n): num(n), var(66), refnum(num)
	{
		//here is just assignment not initialize
		// var =10; Error, 
		// refnum = num;
		cout<<"Object con  "<<num<<endl;
		
	}
	~Object(){
		cout<<"Object de "<<num<<endl;
	}
private:
	int num;
	const int var;
	int& refnum;
};

class Container{
public:
	Container(Object o1=1,Object o2=0): obj1(o1), obj2(o2)
	{
		cout<<"Conatainer con"<<endl;
	}
	~Container(){
		cout<<"Conatainer de"<<endl;
	}
private:
	Object obj1;
	Object obj2;
};

int main(int argc, char *argv[])
{
    Container c(66,88);
    return 0;
}
