#include<iostream>
using namespace std;

int main(void){
  char *p = "123";
  cout<<*p<<endl;// 1
  cout<<p<<endl;// 123
  cout<<(void*)p<<endl;// address
  return 0;
}
