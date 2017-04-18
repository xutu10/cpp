#include<iostream>
#include<cassert>
using namespace std;

int main(int argc, char** arg){

	// test for cout put() and write()
	// cout.put('h').put('H').put('\n');
	// char buf[] = "test1234";
	// cout.write(buf,5);

	// test for input
	// int a;
	// char c;
	// cin>>a>>c;
	// cout<<"a = "<<a<<"c is "<<c<<endl;

	// test for cin.get()
	// int a;
	// a = cin.get();  // return type is int(ascii)
	// cout<<a<<endl;

	// char ch1, ch2;
	// cin.get(ch1).get(ch2);   // get(&)
	// cout<<ch1<<" "<<ch2<<endl;

	// test for getline()
	// char buf[10] = {0};
	// cin.getline(buf,9);   // blank has no effect
	// cout<<buf<<endl;

	// getline against cout
	// char buf[10] = {0};
	// cin>>buf;    // stop at blank
	// cout<<buf<<endl;

	// read()
	// char buf[10] = {0};
	// cin.read(buf,10);  // no effect of blank and new line
	// cout<<buf<<endl;

	// putback()
	char buf[10], ch1,ch2;
	ch1 = cin.get();
	ch2 = cin.get();
	cin.putback(ch1);
	cin.getline(buf,9);
	cout<<buf<<endl;
	// input abcdf
	// out acdf
	
	return 0;
}
