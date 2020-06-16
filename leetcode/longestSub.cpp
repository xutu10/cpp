#include<iostream>
using namespace std;
// 180ms, 7.2m

class Solution{
public:
	int lengthOfLongestSubstring(string s){
	
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

		return rslt.size();
  	}
};
