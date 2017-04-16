#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> INT_VECTOR;

void show_vector(const INT_VECTOR& v){
		int i;
	for(i =0; i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl; 
}

void show_vector1(INT_VECTOR& v){
	//INT_VECTOR::const_iterator it;
	INT_VECTOR::iterator it;
	// operator ++ overloading, it++ one more time to be called
	for(it=v.begin();it!=v.end();++it){
		cout<<*it;
	}
	
}

int main(int argc, char *argv[])
{
    INT_VECTOR v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	show_vector(v);
	show_vector1(v);

	
    return 0;
}
