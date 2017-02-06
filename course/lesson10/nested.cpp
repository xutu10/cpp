#include<iostream>
using namespace std;

//1.inner class
class Outer{
public:
	class Inner{
		public:
		void fun();// {
		// 	cout<<"inner fun"<<endl;
		// }		
	};
public:
	Inner obj;
	void fun(){
		cout<<"outer fun"<<endl;
		obj.fun();
	}	
};

void Outer::Inner::fun(){
	cout<<"inner fun"<<endl;
}

//2. local class
void local(){
	class localC{
		public:
		int num;
		void init(int a){
			num = a;
			cout<<num<<endl;
		}		
	};// ; is important
	localC lc; // only in this block visiable
	lc.init(6);
}

int main(int argc, char *argv[])
{
    Outer o;
	o.fun();
	Outer::Inner i;
	i.fun();
	local();
    return 0;
}















