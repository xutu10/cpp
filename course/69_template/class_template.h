#ifndef CLASS_TEMPLATE
#define CLASS_TEMPLATE

template <class T>
class List{
 public:
	void isEmpty() const;
	void insert(const T&);
	
 protected:
	T list[10];
	int length;	
};

// after class template muss implement function template
template <class T>
void List<T>::insert(const T& e){
   
	
}



#endif  // CLASS_TEMPLATE
