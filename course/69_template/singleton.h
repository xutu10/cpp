#ifndef SINGLETON_H
#define SINGLETON_H

#include<iostream>
using namespace std;

template <typename T>
class Singleton{
 public:
	static T& GetInstance(){
		static T instance;
		return instance;
	}

 private:
	Singleton(const Singleton& other);
	Singleton& operator=(const Singleton& other);
	Singleton();
	~Singleton();
};    

#endif // SINGLETON_H
