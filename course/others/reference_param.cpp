#include<iostream>
using namespace std;

// pass address
void getScore(int&);
void print(int);
// pass value
void getScore1(int);

int main(){

	int score;
	getScore1(score);
	print(score);
	
	return 0;
}

void getScore(int& score){

	cout<<"enter score"<<endl;
	cin>>score;
	
}

void print(int score){
	cout<<score<<endl;
}

void getScore1(int score){

	cout<<"enter score"<<endl;
	cin>>score;
	
}

