#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){

	int arr1[] = {1,3,5,7,9	};
	int arr2[] = {1,5,3,8,9	};
	// just since c++11
	set<int> s1(begin(arr1),end(arr1));
	
	set<int> s2(begin(arr2),end(arr2));

	bool flag = false;
	if(s1 == s2)
		flag = true;
	cout<<flag<<endl;
	
	return 0;
}
