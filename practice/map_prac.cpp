#include<iostream>
#include<cstring>
#include<map>
using namespace std;

int main(){

	map<string, int> sal;
	sal["a"] = 10;
	sal["b"] = 20;
	sal.insert(map<string, int>::value_type("c",30));
	// c++ 11
	for(auto it=sal.begin(); it!=sal.end();it++)
		cout<<it->first<<","<<it->second<<endl;

	cout<<"input the wanted name:";
	string name;
	cin>>name;

	if(sal[name] != 0 )
		cout<<"its in"<<endl;
	else
		cout<<"its not in"<<endl;

	cout<<"input the name: ";
	string name_del;
	cin>>name_del;

    
	auto it_find = sal.find(name_del);

    if (it_find != sal.end())
		cout<<it_find->second<<endl;
	sal.erase(it_find);

	
	for(auto it=sal.begin(); it!=sal.end();it++)
		cout<<it->first<<","<<it->second<<endl;
	
	return 0;
}
