#include"string_operator.h"

int main(int argc, char *argv[])
{
    String s = "abc";
	String s1(s);
	s.display();
	s1.display();

	String s2 = "zxc";

	String& ref = s2;
	ref.display();
	
	s2.display();
	s2 = s1;
	s2.display();

	String s3 = s1 +s2;
	s3.display();
//	String s3; no suitable constructor match
	// firstly "xxx" will be transfered to a obj
	// then call operator+
	String s4 = "qwe";
	s4 += s3;
//	s4.display();
	cout<<s4<<endl;

	String s5 = "zz";
	cin>>s5;
	cout<<s5<<endl;
	
    return 0;
}
