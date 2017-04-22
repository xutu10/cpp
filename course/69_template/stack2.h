#ifndef STACK2_H
#define STACK2_H

#include<stdexcept>

using namespace std;

// adding a normal type parameter as template param

template <typename T, int LENGTH>
class Stack2{
 public:
	Stack2();
	~Stack2();
	void push(const T& e);
	void pop();
	T& top();
	const T& top() const;
	bool isEmpty() const;
 private:
	T* element_;
	int position_;
};

template<typename T, int LENGTH>
Stack2<T,LENGTH>::Stack2(): position_(0){
	element_ = new T[LENGTH-1];
}

template<typename T,int LENGTH>
Stack2<T,LENGTH>::~Stack2(){
	delete[] element_;
}


template<typename T,int LENGTH>
bool Stack2<T,LENGTH>:: isEmpty() const{
	return position_==0;
}

 
template<typename T,int LENGTH>
void Stack2<T,LENGTH>::push(const T& element){
	if(position_ > LENGTH)
		throw out_of_range("cann't push, stack2 full");
	element_[position_++] = element;
}
	
template<typename T,int LENGTH>
void Stack2<T,LENGTH>::pop(){
	if(position_ <= 0)
		throw out_of_range("can't pop, stack2 empty");
	element_[--position_] = 0;
	
 }
	
template<typename T,int LENGTH>
T& Stack2<T,LENGTH>::top(){

	if(position_ <= 0)
		throw out_of_range("can't top, stack2 empty");

	return element_[position_-1];
 }

	
template<typename T,int LENGTH>
const T& Stack2<T,LENGTH>::top() const{

	if(position_ <= 0)
		throw out_of_range("can't top, stack2 empty");

	return element_[position_];
 }
 
 
#endif  // STACK2_H
