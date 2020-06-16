#include<iostream>
using namespace std;

template<typename T>
void sort(T& t, int n){
	for(int i = 0; i < n; i++){
		int p = i;
		for (int j = i; j < n; j++){
			if (t[p] < t[j])
				p = j;
		}
		int tmp = t[p];
		t[p] = t[i];
		t[i] = tmp;			
	}
}


template<typename T>
void show(T& t, int n){
	for(int i = 0; i < n; i++)
		cout<< t[i]<<"\t";
	cout<<endl;
}


int main(){

	int a[] = {2,4,6,3,1};
	sort(a, 5);
	show(a,5);

	char b[] = {'n','a','e','l'};
	sort(b,4);
	show(b,4);
	

	return 0;
}
