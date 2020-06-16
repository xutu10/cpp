#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main(){

	string s("abcbcda");
	map<char, int> tmp;
	map<char, int> :: iterator it;
	
	int ans=0,i=0,j=0;
	while(i<s.size()){
		it = tmp.find(s[i]);
		if(it!=tmp.end())
			j=max(it->second,j);

		ans = max(ans, i-j+1);
		tmp.insert(pair<char, int>(s[i],i++));		
	}

	cout<<ans<<endl;
	
	return 0;
}
