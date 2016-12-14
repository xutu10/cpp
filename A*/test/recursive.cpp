#include<iostream>
using namespace std;

// distance to his goal position for each number
int cost[9][9] = {{2,1,2,1,0,1,2,1,2}, // num 0
				  {0,1,2,1,2,3,2,3,4}, // 1
				  {1,0,1,2,1,2,3,2,3}, // 2
				  {2,1,0,3,2,1,4,3,2}, // 3
				  {3,2,1,2,1,0,3,2,1}, // 4
				  {4,3,2,3,2,1,2,1,0}, // 5
				  {3,2,3,2,1,2,1,0,1}, // 6
				  {2,3,4,1,2,3,0,1,2}, // 7			  
				  {1,2,3,0,1,2,1,2,3}, // 8			  
};
// optional positions to go according to current posisition of num 0
int option[9][4] = {{2,4},    // current position 1     
					{1,3,5},  // 2
					{2,6},    // 3
					{1,5,7},  // 4
					{2,4,6,8}, // 5
					{3,5,9},  //6 
					{4,8},    //7
					{5,7,9},  //8
					{6,8}	  //9
};

int expand(int status[5]);
int main(){

	int status[5] = {2,5,7,3,9};

	return 0;
}

int expand(){

	return 1;
}
