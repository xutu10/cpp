#include<iostream>
#include<thread>

//using namespace std;
// g++ -Wall -g -std=c++11 -pthread thread_prac.cpp

void foo(){
	for(int i = 0;i<5;i++ )
		std::cout<<"foo "<<i<<std::endl;
}

void bar(int i){

	for(int j = 0; j < i; j++)
		std::cout<<"bar "<<j<<std::endl;
}

int main(){


	std::thread first(foo);
	std::thread second(bar,3);

	//	std::cout<<first.get_id()<<std::endl;
	//	std::cout<<second.get_id()<<std::endl;
	std::cout<<"start "<<std::endl;

	first.join();
	second.join();
	
	std::cout<<"end"<<std::endl;	

	return 0;
}
