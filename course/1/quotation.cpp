#include<iostream>
using namespace std;

int main(void){

  int a = 12;
  int& b = a; // must initialize at declaration
  b = 15; // just assign a again
  cout<<a<<endl;
  int c =20;
  b = c;  // not quotation of c, just change a
  cout<<a<<endl;
}
