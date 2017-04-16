#include<iostream>
using namespace std;
int num = 10; // scope of document, valid until end of document

int add(int,int); // the variable can be omitted

int main(int argc, char *argv[])
{
    int num = 20;
	{// scope of block
		int num =30;
	}
	cout<<::num<<endl;
	cout<<num<<endl;

    return 0;
}
// scope of function, label3 is visiable for label1
int gototest(){
LABEL1:
	cout<<label1<<endl;
	goto LABEL3;
LABEL2:
	cout<<label2<<endl;
LABEL3:
	cout<<label3<<endl;
	goto LABEL2;
	
}
