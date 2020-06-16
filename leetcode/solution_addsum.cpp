#include<iostream>
#include<vector>
#include<map>
#include<stdio.h>
using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int> nums, int target){
		map<int, int> helper;
		vector<int> rslt;
		
		for(int i=0;i<nums.size();i++){
			int complement = target - nums[i];
			map<int,int> :: iterator it_find;
			it_find = helper.find(complement);
			if(it_find != helper.end()){
				rslt.push_back(it_find->second);
				rslt.push_back(i);
				return rslt; 
			}
			
			helper.insert(pair<int,int>(nums[i], i));

		}
	}
};



int main(){
	Solution* s = new Solution;

	vector<int> input,output;
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);

	printf("%p %p %p\n", &input, input, &input[1]);
	// address 0x01, 0x01, 0x1234
	
	output = s->twoSum(input, 4);

	// vector<int> :: iterator it;
	// for(it=output.begin(); it!=output.end();it++)
	// 	cout<<*it<<" and ";
	// cout<<endl;

	// only for c++11, 
	// for(int i : output){
	// 	cout<<output[i]<<" ";
	// }
	

	


	return 0;
}
