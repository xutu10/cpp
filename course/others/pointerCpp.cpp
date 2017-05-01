#include<iostream>
#include<cstring>

using namespace std;

int main(){

	char* name;
	string* str;
	name = new char[5];
	str = new string;
	strcpy(name,"xutu");
	*str = "it's good";
	
	cout<<"name "<<name<<endl;
	cout<<"*name "<<*name<<endl;
	cout<<"name[1]"<<name[1]<<endl;
	cout<< "str "<<str<<endl;
	cout<< "*str "<<*str<<endl;

	delete str;
	delete [] name;

	// memory leak
	// int* p = new int;  
	// *p = 43;
	// p = new int;   
	// *p = 23;   
	
	return 0;
}
