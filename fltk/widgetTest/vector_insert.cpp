#include<iostream>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;

int main(){

	vector<string> str_list = {	"aaa","bbb","ccc"};
	
	str_list.insert(str_list.begin()+1, "ddd");
	cout<<str_list.size()<<endl;

	for(auto it : str_list)
		cout<<it<<endl;

	str_list.erase(str_list.begin()+3);

	cout<<str_list.size()<<endl;
	for(auto it : str_list)
		cout<<it<<endl;

	stringstream ss;
	ss<<str_list[0]<<" "<<str_list[1];

	cout<<ss.str()<<endl;

	if(str_list[0] == "aaa")
		cout<<"yes"<<endl;
	
	return 0;
}
