#include<iostream>
#include<cstdlib>
using namespace std;

enum object{ROCK,PAPER,SCISSORS};

void playGame(int&,int&,int&);
void results();
object getPlay();
object AI();
object determine(object,object);


int main(){

	int menuChoice, p1Wins = 0 ,p2Wins = 0, tie = 0;
	do{
		cout<<"paper-rock-scissors"<<endl;
		cout<<"play game 1"<<endl;
		cout<<"display results 2"<<endl;
		cin>>menuChoice;
		if(!cin){
			cin.clear();
			cin.ignore(100,'\n');
		}
		switch(menuChoice){
		case 1:
			playGame(p1Wins,p2Wins,tie);
			break;
		case 2 :
			results();
			break;
		case 9:
			break;
		}
    }while(menuChoice != 9);
	
	return 0;
}

object getPlay(){

	object p1;
	char ch;
	cout<<"enter r for rock,s for scissors, p for papers"<<endl;
	cin>>ch;
	switch(ch){
	case 'r':
	case 'R':
		p1 = ROCK;
		break;
	case 's':
	case 'S':
		p1 = SCISSORS;
		break;
	case 'p':
	case 'P':
		p1 = PAPER;
		break;
	}
	return p1;
}

void playGame(int& win1, int& win2, int& tie){
	object player1, player2,winner;
	player1 = getPlay();
	switch(player1){
	case 0:
		cout<<"rock"<<endl;
		break;
	case 1:
		cout<<"paper"<<endl;
		break;
	case 2:
		cout<<"scissors"<<endl;
		break;
	}
	player2 = AI();
	winner = determine(player1, player2);
	
}

object AI(){
	int num = rand() % 3;
	object computer;

	switch(num){
	case 0:
		computer = ROCK;
		break;
	case 1:
		computer = PAPER;
		break;
	case 2:
		computer = SCISSORS;
		break;
	}
	return computer;
}
