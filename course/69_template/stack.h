#ifndef STACK_H
#define STACK_H

#include<stdexcept>

using namespace std;

template <typename T>
class Stack{
 public:
	Stack(int length);
	~Stack();
	void push(const T& e);
	void pop();
	T& top();
	const T& top() const;
	bool isEmpty() const;
 private:
	T* element_;
	int length_;
	int position_;
};

template<typename T>
Stack<T>::Stack(int length): length_(length), position_(0){
	element_ = new T[length_-1];
}

template<typename T>
Stack<T>::~Stack(){
	delete[] element_;
}


template<typename T>
bool Stack<T>:: isEmpty() const{
	return position_==0;
}

 
template<typename T>
void Stack<T>::push(const T& element){
	if(position_ > length_)
		throw out_of_range("cann't push, stack full");
	element_[position_++] = element;
}
	
template<typename T>
void Stack<T>::pop(){
	if(position_ <= 0)
		throw out_of_range("can't pop, stack empty");
	element_[--position_] = 0;
	
 }
	
template<typename T>
T& Stack<T>::top(){

	if(position_ <= 0)
		throw out_of_range("can't top, stack empty");

	return element_[position_-1];
 }

	
template<typename T>
const T& Stack<T>::top() const{

	if(position_ <= 0)
		throw out_of_range("can't top, stack empty");

	return element_[position_];
 }
 
 
#endif  // STACK_H
