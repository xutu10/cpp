#include<iostream>
using namespace std;

#define S(a) #a
#define C(a,b) a##b

int main(void){

  int xy = 100;
  cout<<S(zxcv)<<endl;
  cout<<C(x,y)<<endl;

}
