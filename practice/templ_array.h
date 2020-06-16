#ifndef TEMPL_ARRAY_H
#define TEMPL_ARRAY_H
#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class array{
 public:
	array(int);
	~array();
	void sort();
	T& operator[](int);
	void show() const;
	
 private:
	T* elements_;
	int len_;
	
};

template<typename T>
array<T>:: array(int len): len_(len){
	elements_ = new T[len];
}

template<typename T>
array<T>::~array(){
	
	delete elements_;
	
}

template<typename T>
void array<T>::show() const{
	for(int i = 0; i < len_; i++)
		cout<<elements_[i]<<",";
	cout<<endl;
}


template<typename T>
T& array<T>::operator[](int num){
	if(num < 0 || num > len_)
		exit(1);
	return elements_[num];
}


template<typename T>
void array<T>::sort(){
	for(int i = 0; i < len_;i++){
		int p = i;
		for(int j = i; j < len_; j++){
			if (elements_[p]  > elements_[j])
				p = j;
		}
		T tmp =elements_[i];
		elements_[i] = elements_[p];
		elements_[p] = tmp;
	}
}

template<>
void array<char*>:: sort(){

	for(int i = 0; i < len_; i++){
		int p = i;

		for(int j = i; j < len_; j++){
			if(strcmp(elements_[p], elements_[j]) > 0)
				p = j;
		}
		char* tmp = elements_[i];
		elements_[i] = elements_[p];
		elements_[p] = tmp;
	}
	
}





#endif
