#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

	int list[] = {1,2,3,5,4,5 };
	int counter = 0;
	
	for_each(list, list+sizeof(list)/sizeof(int),[&counter](int i){

		if( i == 5)
			counter++;
		});

	cout<<counter<<endl;
	//##########################
	cout<<"\nsort\n";
	vector<int> int_v = {3,8,5,3,10	};
	sort(begin(int_v), end(int_v), [](int a, int b){
			return a == b;
		});
	// 3,3,8,5,10
	for(auto &i : int_v)
		cout<<i<<",";
	cout<<endl;

	return 0;
}
