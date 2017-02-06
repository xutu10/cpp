#include<iostream>
using namespace std;
/**
   const_cast can work for that a function get a param
 */
void foo1(int val){
	cout<<"foo1 "<<val<<endl;
}
void foo2(int &val){
	cout<<"foo2 "<<val<<endl;
}


int main(int argc, char *argv[])
{
	/**
	   const_cast example for pointer
	 */
    const int val = 100;
	// int n = const_cast<int>(val); not suitable for object

	// int* p = &val; can't assign  &val to const int*
	int* p = const_cast<int*>(&val); // remove the character of const
	//&!!!
	// p point to val, but cannot change the value of val
	*p = 200;
	// p point to val,but the value of val will not be changed
	// when *p is assigned, namely val = 100, *p = 200;
	// as usual the vaule of val can be changed when *p is changed 
	cout<<"address of val:"<<&val<<" address of p:"<<p<<endl;
	// address are same
	cout<<"value of val:"<<val<<" value of p:"<<*p<<endl; // "100,200"???

	/**
	   cons_cast example for reference
	 */
	const int val2 = 200;
	// int& refval2 = val2; doen't work
	int& refval2 =  const_cast<int&>(val2);
	refval2 = 300;
	cout<<val2<<refval2<<endl;    //200,300???
	foo1(const_cast<int&>(val2)); // 300
    foo2(const_cast<int&>(val2)); // 300
    return 0;
}








