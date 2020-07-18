#include<iostream>
#include<algorithm>


/**
   Test for begin() and end() since c11
 */
template<typename It>
void doSome(It begin, It end){
	std::cout<<"for each "<<std::endl;
	std::for_each(begin, end, [](int n){
		std::cout<<n<<std::endl;
	});

	auto is_odd = [](int n){
		return n%2 == 1;
	};

	std::cout<<"find an odd: "<<std::endl;
	auto pos = std::find_if(begin, end, is_odd);
	if(pos != end)
		std::cout<<*pos<<std::endl;
}

template<typename T>
void foo(T t){
	std::cout<<"first"<<std::endl;
	doSome(std::begin(t), std::end(t));
}

// specified ref to an array
template<typename T, size_t N>
void foo(T (&arr)[N]){
	std::cout<<"second"<<std::endl;
	doSome(std::begin(arr), std::end(arr));
}

// or
// template<typename T>
// void foo(T* arr){
// 	std::cout<<"second"<<std::endl;
// 	doSome(std::begin(*arr), std::end(*arr));
// }


int main(){

	// the second will be called, T's type is array int[3]
	int arr[] = {1,2,5};
	foo(arr);
	// the first will be called
	std::vector<int> v{2,4,6};
	foo(v);
	
	return 0;
}
