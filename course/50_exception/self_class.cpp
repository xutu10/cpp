#include "divisionByZero.h"
#include<iostream>
using namespace std;

// class DivByZero{
	
// };

int main(){

	int dividend, divisor, quotient;

	// try{
	// 	cin >> dividend;
	// 	cin >> divisor;
	// 	if( divisor == 0)
	// 		throw DivByZero();    // throws anonymous object
	// 	quotient = dividend/divisor;
	// 	cout<<"quotient = "<<quotient<<endl;
	// }
	// catch(DivByZero){
	// 	cout<<"divisor is zero"<<endl;
	// }

	try{
		cin >> dividend;
		cin >> divisor;
		if( divisor == 0)
			//throw divisionByZero();    // throws anonymous object
			throw divisionByZero("haha");
		quotient = dividend/divisor;
		cout<<"quotient = "<<quotient<<endl;
	}
	catch(divisionByZero obj){
		cout<<"error is by "<<obj.what()  <<endl;
	}


	return 0;
}
