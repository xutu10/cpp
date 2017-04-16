#include<iostream>
#include<string>
using namespace std;

int main(int arg, char** argc){

	int dividend, divisor, quotient;
	
	try{
		cin >> dividend;
		cin >> divisor;
		if( divisor == 0)
			//throw 0;
			throw divisor;
		quotient = dividend/divisor;
		cout<<"quotient = "<<quotient<<endl;
	}
	// catch(int){
	// 	cout<<"divisor is zero"<<endl;
	// }
	catch(int x){
		cout<<"divisor is"<<x<<endl;
	}
	return 0;	
}
