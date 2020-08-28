#include<iostream>
#include<cstring>
#include<stdio.h>
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

	String(String&& other) noexcept{

		cout<<"move"<<endl;
		
		len_ = other.len_;
		s_ = other.s_;
		
		other.len_ = 0;
		other.s_ = nullptr;
	}

	String& operator=(String&& other) noexcept{

		cout<<"operator move"<<endl;
		delete[] s_;

		len_ = other.len_;
		s_ = other.s_;
		printf("address of other.s:%p \n", other.s_);

		other.len_ = 0;
		other.s_ = nullptr;
		printf("address of s_:%p \n", s_);

		cout<<"in move: "<<s_<<endl;

		return *this;
	}
	
	void display(){
		cout<<s_<<endl;
		printf("address %p \n", s_);
	}
	
	~String(){
		cout<<"Distroyed"<<endl;
		delete[] s_;
	}

	char* s_;
	int len_;

};

int main(){

	// move assignment
	String h = "hello";
	h.display();

	char* ptr = h.s_;
	printf("ptr %s, address %p\n", ptr, ptr);

	cout<<"dest con???"<<endl;
	String dest("a");
	
	dest.display();
	// cast to rvl to call the move func
	//	String dest(String&& string);
	dest= move(h);
		
	h.display();
	dest.display();
	// cout does work anymore??
	printf("dest content %s\n",dest.s_);
	printf("ptr to: %p, content: %s\n", ptr,ptr);

	return 0;
}
