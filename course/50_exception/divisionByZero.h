#ifndef divisionByZero_H
#define divisionByZero_H

#include <iostream>
#include <string>

using namespace std;

class divisionByZero{
public:

divisionByZero(const char* str){

cout<<"constructor"<<str<<endl;
message_ = str;
}

divisionByZero(const divisionByZero& other){
message_ = other.message_ +"copy";
cout<<"copy constructor"<<message_<<endl;
}

string what(){

return message_;
}

~divisionByZero(){

cout<<"deconstructor"<<message_<<endl;
}
private:
string message_;
};

#endif 
