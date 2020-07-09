#include<iostream>
using namespace std;

class Person{
public:
	enum PersonType{AUDLT, CHILD, SENIOR};
	void setType(PersonType pt);
	PersonType getPt();

private:
	PersonType m_pt;
	
};


void Person::setType(PersonType pt){
	m_pt = pt;
}

//PersonType Person::getPt(){
auto Person::getPt() -> PersonType{
	return m_pt;
}

int main(){

	Person p;
	p.setType(Person::AUDLT);

	auto persontype = p.getPt();
	cout<< persontype << endl;

	p.setType(Person::CHILD);
	persontype = p.getPt();
	cout<< persontype << endl;
	// error, the type is decided by the initialization
	//persontype = 10
	
	return 0;
}
