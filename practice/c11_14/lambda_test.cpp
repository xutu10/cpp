#include<iostream>
#include<algorithm>

using namespace std;

int main(){

	int list[] = {1,2,3,5,4,5 };
	int counter = 0;
	
	for_each(list, list+sizeof(list)/sizeof(int),[&counter](int i){

		if( i == 5)
			counter++;
		});

	cout<<counter<<endl;

	return 0;
}
