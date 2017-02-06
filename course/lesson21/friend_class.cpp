#include<iostream>
using namespace std;

class TV{
	friend class TV_controller;
public:
    TV(int volume,int chanel): volume_(volume),chanel_(chanel){
		
	}
	
private:
	int volume_;
	int chanel_;

};

class TV_controller{
public:
	void Volum_up(TV& tv){
		tv.volume_ += 1;
	}	
};
int main(int argc, char *argv[])
{
  
	
    return 0;
}
