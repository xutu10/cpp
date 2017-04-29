#include<iostream>
using namespace std;

struct student{
	string firstName;
	string lastName;
};

void input(student[]);

int main(){

	student enrolled[2];
	input(enrolled);

	for(int i = 0; i < 2; i++)
		cout<<enrolled[i].firstName<<" "<<enrolled[i].lastName<<endl;
		
	return 0;
}

void input(student s[]){

	for(int i = 0; i < 2; i++){
		cout<<"entering first and last name"<<endl;
		cin >> s[i].firstName >> s[i].lastName;
	}	
}
