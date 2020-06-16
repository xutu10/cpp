#include<iostream>
#include<string>
using namespace std;

class Person{

public:
	Person(string& s, int a):name_(&s), age_(a){	}

	// with explicit, p2 is not allowed
	explicit Person(const Person& p){
		cout<<"copy"<<endl;
		name_= new string(*p.name_);
		age_ = p.age_;
	}

	void change(string& name){
		//		name_ = &name; working too
		*name_ = name;
	}
	
	void show(){
		cout<<*name_<<","<<age_<<endl;
	}
	
private:
	string* name_;
	int age_;	
};

int main(){

	string s("xu");
	Person p(s, 10);
	p.show();
	Person p1(p);
	//	Person p2=p1;
	p1.show();
	//	p2.show();
	
	string t("tu");
	p.change(t);
	p.show();
	p1.show();
	
	return 0;
}

