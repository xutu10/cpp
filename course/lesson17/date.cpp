#include<iostream>
using namespace std;

class Date{
public:
	Date(int year):year_(year){
		
	}

	static bool IsLeapYear(int year){
		return(0 == year % 4);
	}

	bool IsLeapYear(){
		return (0 == year_ % 4);
	}
private:
	int year_;	
};

int main(int argc, char *argv[])
{
    Date d(2013);
	cout<<d.IsLeapYear()<<endl;
	// no object is needed to call the func
	cout<<Date::IsLeapYear(2012)<<endl;
	
    return 0;
}
