#include"templ_array.h"


int main(){

	array<int> number(3);
	number[0] = 10;
	number[1] = 5;
	number[2] = 2;

	number.sort();
	number.show();

	array<char*> wordlist(3);
	wordlist[0] = "vb";
	wordlist[1] = "va";
	wordlist[2] = "ab";

	wordlist.show();
	wordlist.sort();
	wordlist.show();
	
	return 0;
}
