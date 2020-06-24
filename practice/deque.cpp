#include<iostream>
#include<deque>
#include<string>

using namespace std;

template<typename T>
void show(const deque<T>& d){
	auto it = d.cbegin();
	if(it != d.cend()){
		for(it; it != d.cend(); it++)
			cout<< *it <<"\t";
	    cout<<endl;
	}else{
		cout<<"container is empty"<<endl;
	}
 
}

template<typename T>
void reverse_show(const deque<T>& d){
	auto it = d.crbegin();
	if(it != d.crend()){
		for(it; it != d.crend(); it++)
			cout<< *it <<"\t";
	    cout<<endl;
	}else{
		cout<<"container is empty"<<endl;
	}
	
}


int main(){
	deque<int> di;
	di.push_back(2);
	di.push_front(3);
	di.push_back(8);

	cout<<di.front()<<endl;
	show(di);
	reverse_show(di);

	deque<string> ds;
	cout<<ds.size()<<endl;
	ds.push_back("bbb");
	ds.push_back("sss");
	cout<<ds.size()<<endl;
	ds.push_front("vvvv");
	cout<<ds.size()<<endl;

	reverse_show(ds);

	ds.clear();
	cout<<ds.size()<<endl;
	show(ds);
	
	return 0;
	
}
