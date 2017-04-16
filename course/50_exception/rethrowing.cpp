#include"divisionByZero.h"
#include<iostream>

using namespace std;

void doDivision() throw (divisionByZero);

int main(int argc, char** arg){

	try{
		doDivision();
	}
	catch(divisionByZero& obj){
		cout<<"in main:"<<obj.what()<<endl;
	}

	return 0;
}

void doDivision() throw (divisionByZero){

	int dividend, divisor,quotient;
	
	try{
		dividend = 10;
		divisor = 0;
		if( divisor == 0)
			throw divisionByZero("haha");    // throws anonymous object
		
		quotient = dividend/divisor;
		cout<<"quotient = "<<quotient<<endl;
	}
	catch(divisionByZero){
		throw;
	}

}
