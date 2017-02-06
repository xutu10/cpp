#include<iostream>
using namespace std;

void fun(int a, int b){
  cout<<"int fun"<<endl;
}

void fun(double a, double b){
  cout<<"double fun"<<endl;
}

int main(void){
  
  //  use of new
  int *p = new int(22);
  cout<<*p<<endl;
  int *p1 = new int[10];
  // use of delete
  delete p;
  delete[] p1;

  fun(2,3);
  fun(2.3,3.4);

  return 0;

}
