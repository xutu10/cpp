#include<iostream>
#include<vector>
#include<set>
#include<utility>
using namespace std;


vector<int>  goal =  {4,0,1,2,5,8,7,6,3};

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
vector<vector<int> > options = {{0,3},    // current position 0
				      {0,2,4},  // 1
					  {1,5},    // 2
					  {0,4,6},  // 3
					  {1,3,5,7}, // 4
					  {2,4,8},  //5
					  {3,7},    //6
					  {4,6,8},  //7
					  {5,7}	  //8
};

int expand(vector<int> );
vector<int> change(vector<int>, int);


int main(){

	vector<int> status = {7,3,0,2,4,8,5,6,1};
	return 0;
}

int expand(vector<int>  status){

	if(status == goal)
		return 1;

	// get the current position of num 0
	int pos0 = status[0];
	// get the options base on the current position of 0
	int alter_nums = options[pos0].size();
	vector<int > alter;
	// pack the options in a vector
 	for(int i = 0; i < alter_nums;i++)
		alter.push_back(options[pos0][i]);

	// store the cost for all alternatives
	set<pair<int,int> > alter_cost;
	// swap position in the alternative list and num 0
	// compute the cost of each alternative
	// sort the alternatives by cost in ascent order

	// walk through the alternatives
   	for(int i = 0; i<alter_nums;i++){
		vector<int> tem ;
		tem = change(status,alter[i]);
		int tem_cost = 0;
		// walk through the cost according to the current status
		// sum the cost for this alternative
		for(int j = 0; j<9;j++)
			tem_cost += cost[j][tem[j]]; 

		//pack the altertive position and its cost in set
		// automatic sorted by key, key is the cost, value is position
		pair<int,int> tem_set = make_pair(tem_cost,alter[i]);
		alter_cost.insert(tem_set);
	}

	set<pair<int,int> > :: iterator it;
	for(it= alter_cost.begin();it!=alter_cost.end();it++){
		vector<int> new_status = change(status,it->second);
		expand(new_status);
	}
	
	return 1;
}

// search the current position of the number,which will be swaped by num 0, then swap
vector<int> change(vector<int> status, int num){
	int i = 0;
	for(i = 0; i < 9  && num != status[i];i++ );
	swap(status[0],status[i]);

	return status;
}
