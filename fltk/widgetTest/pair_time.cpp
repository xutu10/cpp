#include<iostream>
#include<fstream>
#include<algorithm>
#include<ctime>
#include<unistd.h> // sleep
using namespace std;

int main(){

	srand(time(NULL));	
	ofstream record;
	record.open("record.txt");

	for(int i = 0; i < 5; i++){
		int sleepTime = rand()%5;
		time_t startTime = time(nullptr);
		time_t calendarTime = startTime ;
		
		char* showTime = asctime(localtime(&calendarTime));
		sleep(sleepTime);
		time_t  diff = time(nullptr) - startTime ;

		record<<diff<<","<<showTime<<endl;
		
	}

	record.close();	
	
	return 0;
}
