#include<iostream>
using namespace std;



template<typename T1, typename T2>
void init(const T2& obj){

	T1 val = obj.getVal() -1 ;
	cout<< val <<endl;
}


template<typename T>
void add(const T& obj){
	auto val = obj.getVal()+1;
	cout<< val <<endl;
}


class Int{
public:
	Int(int a): m_val(a){
		
	}
	// must be const, otherwise it cann't be called by const obj
	int getVal() const{
		return m_val;
	}

private:
	int m_val;
	
};

int main(){

	Int i(2);
	init<int>(i);
	add(i);

	return 0;
}
