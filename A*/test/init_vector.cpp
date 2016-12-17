#include<iostream>
#include<vector>
using namespace std;

int main(){

	vector<vector<int> > cost = {{2,1,2,1,0,1,2,1,2}, // num 0
				  {0,1,2,1,2,3,2,3,4}, // 1
				  {1,0,1,2,1,2,3,2,3}, // 2
				  {2,1,0,3,2,1,4,3,2}, // 3
				  {3,2,1,2,1,0,3,2,1}, // 4
				  {4,3,2,3,2,1,2,1,0}, // 5
				  {3,2,3,2,1,2,1,0,1}, // 6
				  {2,3,4,1,2,3,0,1,2}, // 7			  
				  {1,2,3,0,1,2,1,2,3}, // 8			  
};

	vector<vector<int> > options =  {{2,4},    // current position 1                	  {1,3,5},  // 2
					{2,6},    // 3
					{1,5,7},  // 4
					{2,4,6,8}, // 5
					{3,5,9},  //6 
					{4,8},    //7
					{5,7,9},  //8
					{6,8}	  //9
};
	vector<int > goal =  {5,1,2,3,6,9,8,7,4};

	for(vector<int> v:cost){
		for(int i : v)
			cout<<i<<",";
		cout<<endl;
	}
		

	for(vector<int> v:options){
		for(int i : v)
			cout<<i<<",";
		cout<<endl;
	}
		
	
	
	return 0;
}
