#include<iostream>
using namespace std;

int main(){
	// ts1 abcabcbb
	// ts2 aaaabbbb
	// ts3 a
	// ts4 aabcdcabcde
	string s("pwwkew");

	string rslt,tmp;
	for(int i=0;i<s.size();i++){
		tmp.clear();
		tmp.push_back(s[i]);
		for(int j = i+1;j<s.size();j++){
			if(tmp.find(s[j],0) == string::npos)
				tmp.push_back(s[j]);
			else
				break;
		}

		if(rslt.empty())
			rslt = tmp;
		else
			rslt = rslt.size() >= tmp.size() ? rslt : tmp;

		if(rslt.size() >= s.size()-i)
			break;
	}

	cout<<rslt<<endl;

	return 0;
}
