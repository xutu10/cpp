#include<iostream>
using namespace std;

class Student{
public:
	Student(int a, char *name) : age_(a), name_(name){
		
	}
	// as inline code after declaration define
	void print() const {
		cout<<age_<<" "<<name_<<endl;
	}
	int age_;
	char* name_;
};


void show(const Student &stu){
	// the funciton must be defined as const func
	stu.print();
}

int main(){

	Student stu(5,"xutu");
	show(stu);
	
	return 0;
}
