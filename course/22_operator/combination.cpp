#include<iostream>
#include<cstring>
using namespace std;

struct Person{

	int salary;
	char* name;
	
};


class Datebase{

public:

	Datebase(int num):max_(num){

		employees_ = new Person[max_];
	}


	int& operator[](const char* name){
		Person* p;
		// TODO, check if employees is null
		for(p=employees_;p<employees_+cur_number_;p++){
			if(0 == strcmp(name, p->name))
				return p->salary;
		}

		p = employees_+ cur_number_++;
		p->name = new char[strlen(name)+1];
		strcpy(p->name, name);
		p->salary = 0;
		return p->salary;
	}

	void show(){
		for(int i = 0;i<cur_number_;i++)
			cout<<"name:"<<employees_[i].name<<" salary:"<<employees_[i].salary<<endl;
	}

private:
	Person *employees_;
	int max_;
	int cur_number_;

};

int main(){

	Datebase b(3);
	b["aaa"] = 1000;
    b["bbb"] = 2000;
	b["ccc"] = 3000;
	b.show();

	b["bbb"] = 1500;
	b.operator[]("ccc") = 10;
	b.show();

	Datebase* newbase = new Datebase(2);
	//	newbase["vvvv"] = 10; Operator override doesn't work for pointer
	
	
	return 0;
}
