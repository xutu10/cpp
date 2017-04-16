#include <iostream>
 using namespace std;
/**
   1.check how to declare pointer in cpp
   2.check the const variable and const pointer
 */
int main(void){
  
  int a = 5;
  const int *p = &a; // declare *p as constant
  //*p = 200; as constant cannot be assigned again
  int * const p1 = &a; // declare p1 as constant
    //p1 =&b Error 
  cout<<"a="<<a<<endl;
  *p1 = 20;// *p1 can be changed, 
  //address of a store in pointer, 
  //a will be changed when the value of pointer to be changed
  cout<<"a="<<a<<endl;
  cout<<sizeof(p)<<sizeof(p1)<<endl;// size of pointer is 8
  return 0;
  
}
