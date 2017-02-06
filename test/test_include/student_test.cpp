#include "student.h"
#include <iostream>
using namespace std;

/* test if it's neccessary to include "person.h" in this file
 * it's no need, because student.h already includes it
 */

int main(){

	Person p(11);
	Student s(p);
	cout<<s._s.age<<endl;
	
	return 0;
}
