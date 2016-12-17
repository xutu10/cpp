#include<iostream>
#include<vector>
using namespace std;

// distance to his goal position for each number
vector<vector<int> > cost;
vector<vector<int> > options;
vector<int > goal =  {5,1,2,3,6,9,8,7,4};


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
int options[9][4] = {{2,4},    // current position 1     
					{1,3,5},  // 2
					{2,6},    // 3
					{1,5,7},  // 4
					{2,4,6,8}, // 5
					{3,5,9},  //6 
					{4,8},    //7
					{5,7,9},  //8
					{6,8}	  //9
};

void init_vector();
int expand(int[]);
bool is_goal(int[],int[]);
int main(){

	int status[9] = {8,4,1,3,6,9,4,7,2};
	return 0;
}

int expand(int arr[]){

	if(is_goal(arr,goal))
		return 1;

	int option[] = 
	
	
	return 1;
}

bool is_goal(int arr1[],int arr2[]){
	bool flag = true;

	for(int i =0;i<9;i++){
		if(arr1[i] != arr2[i]){
			flag = false;
			break;
		}
	}
	return flag;
}

void init_vector(){

	
}
