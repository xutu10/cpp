#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

/*
  practice for packing the info including len and data from buffer 
 */

template<typename NumTpye>
void packSize(char* buffer, NumTpye buffSize){

	auto size = sizeof(buffSize);
	cout<<size<<endl;
	printf("%d \n", buffSize);
	for(int i = 0; i < size ; i++){
		buffer[i] = buffSize & 0xff;
		buffSize >>= 8;
	}	
}


int main(){


	uint8_t buff_size = 10;
	string buffer;
	buffer[0] = 0xff;
	// can be printed out
	cout<<buffer[0]<<endl;

    string s;
	s = "111";
	cout<<s<<endl;
	s.insert(3,1,0x2b);
	cout<<"insert: "<<s<<endl;

	// char data[3];
	// data[0] = 0x01;
	// data[1] = 0xa;
	// data[2] = 0x10;

	// s.insert(0,data);
	// cout<<s<<endl;

	
	// if &buffer as argument, the type not match, could be the operator[] func of string
	packSize(&buffer[1], buff_size);

	//	printf("%s\n", buffer[0]);
	
	return 0;
}

