#include<iostream>
#include<cstring>
using namespace std;

class String{
public:
	String() = default;
	String(const char* c){
		cout<<"created"<<endl;
		len_ = strlen(c);
		s_ = new char[len_];
		memcpy(s_, c, len_);
	}

	String(const String& other){
		cout<<"copied"<<endl;
		len_ = other.len_;
		s_ = new char[len_];
		memcpy(s_, other.s_, len_);

	}


	void display(){
		cout<<s_<<endl;
	}
	
	~String(){
		cout<<"Distroyed"<<endl;
		delete s_;
	}

private:
	char* s_;
	int len_;
	
};

class Entity{
public:
	Entity(const String& s)
		:name_(s)
	{
		cout<<"entity constructor"<<endl;
	}

	Entity(String&& s)
		:name_(move(s))
	//	:name_((String&&) s) instead
	{
		cout<<"entity moved"<<endl;
	}

		
	~Entity(){
		cout<<"entity destructor"<<endl;
	}


private:
	String name_;
	
};

int main(){

	//  one String constructor, one copied to Entity, twice allocations 
	//	Entity aa(String("aaa"));
	Entity bb("bb");
	cout<<"over"<<endl;

	
	return 0;
}
