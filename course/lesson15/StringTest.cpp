#include"String.h"
/*
  mutable copy
 */


int main(int argc, char *argv[])
{
    String s1("aaa");
	s1.display();
	
	String s2 = s1;	
	s2.display();
	// runtime Error, invoke default copy constructor,
	// 	equal to s2.str_ = s1.str_
	// two members of objects point to the same space
	// this space will be twice freed. That's Error

	// = is rather than operators, not initialisation
	// still equal to s2.str_ = s1.str_, when default is invoked
	String s3;
	// when the operator = redefinied, equal to s3.operator(s1)
	s3 = s1;
	s3.display();
	return 0;
}
