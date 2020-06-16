#include<iostream>
using namespace std;


int main(){

	string s("abcabcbb");

	//	cout<<s[0]<<endl;
	
	// cout<<s->size()<<endl;

	// string::iterator it;
	// for(it=s->begin();it!=s->end();++it)
	// 	cout<<*it<<",";
	// cout<<endl;

	// str->erase(0,1);
	// cout<<*str<<endl;
	string rslt, tmp;
	size_t found;
	for(int i=0;i<s.size();i++){
		found = s.find_first_of(s[i],i+1);
		tmp = s.substr(i,found-i);
		cout<<i<<","<<found<<","<<tmp<<endl;

		if(rslt.empty()){
			rslt = tmp;
		}else{
			rslt = rslt.size() >= tmp.size()? rslt : tmp;
		}

		if(rslt.size() > s.size()-i)
			break;
	}

	cout<<rslt<<endl;
	
}
