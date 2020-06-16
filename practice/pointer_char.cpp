#include<iostream>
#include<cstring>
#include<stdio.h>

using namespace std;

int main(){

	char* tmp;
	char* tmp1;
	char* list = new char[2]; 
	list[0] = 'a';
	list[1] = 'c';

	tmp1 = list;
	printf("list0: %p list1: %p, pointer+1;%p \n", &list[0],&list[1],++tmp1);
	
	char* word = new char[2];
	// error *(++word), to which the word points is changed
	*word = 'b';
	*(word+1) = 'b';
	
	tmp = list;
	cout<<list<<","<<tmp<<endl;
	printf("address of list: %p, of tmp: %p \n", list, tmp);

	
	// list[0] = word[0]; normal assignment
	
	list = word;
	
	cout<<list<<","<<tmp<<endl;
	printf("address of list: %p, of tmp: %p \n", list, tmp);

	delete list, word;
	return 0;
}
