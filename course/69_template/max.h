#ifndef MAX_H
#define MAX_H

//#include<cstring>

template <typename T>
const T& max(const T& a, const T& b){
	return a<b? b:a;
}

// example for template overload by template
template <typename T>
const T& max(const T& a, const T& b, const T& c){
	return max(a,b) < c ? c:max(a,b);
}

// example for template overload by function
const int& max(const int& a, const int& b){
	return a<b? b:a;
}


// example for template specialization
template<>
const char* const& max(const char* const&a, const char* const&b){

	return strcmp(a,b) < 0 ? b : a;
}

#endif  // MAX_H
