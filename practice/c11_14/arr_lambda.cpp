#include<iostream>
#include<functional>
using namespace std;

struct pointer{

	int x_;
	int y_;	
};


pointer p_arr[4] = {

	{
		1,1
	},
	{
		2,2
	},
	{
		3,3
	},
	{
		4,5
	}	
};


/*
 define a function which can be called with lambda
*/
void show_array(pointer* p, function<void(pointer)> fn){

	cout<<"show in function"<<endl;
	
	for(int i = 0; i < 4; i++){
		fn(p_arr[i]);
	}
	// Range-based for loops just work with array not pointer
	//	for(auto it : p)
	
}

int main(){

	int i = 0;
	
	show_array(p_arr, [&i](pointer p){
			cout<<p.x_<<","<<p.y_<<endl;
			i++;
		});

	cout<<"num of array: "<<i<<endl;
	
	// for(auto it : p_arr)
	// 	std::cout<<it.x_<<","<<it.y_<<std::endl;

	

	return 0;
}


	
