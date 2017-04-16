#include<iostream>
using namespace std;
#include<stdio.h>

// struct Student{
// 	char name;
// 	char a;
// 	int age;
// };
  
#pragma pack(2)
struct Student{
	char a;
	int b;
	char c;
};

#pragma pack()

int main(void){

  Student stud;
  cout<<sizeof(Student)<<endl;
  cout<<&stud<<endl;
//  char* c = &stud.a;
//  int* p = &stud.age;
//name:  5760 a:  5761 age: 5764
// a: 9552 b:9556 c:9560
  printf("%d %d %d",&stud.a,&stud.b,&stud.c);
//  cout<<&stud.a<<p<<endl;
  return 0;

}
