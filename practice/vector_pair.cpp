#include<iostream>
#include<vector>
#include<cstring>
#include<list>

using namespace std;


//template<>  no matched template
void show(const vector<pair<int, string> > a){
	for(auto const_it = a.cbegin();const_it!=a.cend();const_it++)
		cout<<const_it->first<<","<<const_it->second<<endl;
}

void show(const list<pair<int, string> > a){
	for(auto const_it = a.cbegin();const_it!=a.cend();const_it++)
		cout<<const_it->first<<","<<const_it->second<<endl;
}


int main(){

	vector<pair<int, string> > a;

	string s("vvv");
	a.push_back(pair<int, string>(1,s));

	show(a);

	list<pair<int, string> > lis;
	lis.push_back(pair<int,string>(1,"llll"));
	show(lis);


	return 0;
}
