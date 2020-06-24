#include<iostream>
#include<utility>
#include<stdio.h>

using namespace std;

int main(){


	pair<string, int> p1;
	pair<string, int> p2("aaa",1);

	p1.first = "bbb";
	p1.second = 2;

	cout<<p1.first<<","<<p1.second<<endl;

	p1 = pair<string, int>("ccc",3);
	cout<<p1.first<<","<<p1.second<<endl;

	printf("address of p1.first : %p %p \n", &p1, &(p1.first));
	string s = get<0>(p1);
	printf("address of s: %p\n", &s);

	string& ss =  get<0>(p1);
	printf("address of ss: %p\n", &ss);

	return 0;
}
