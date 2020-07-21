#include<iostream>
#include<memory>

/**
   check the "cycle share_ptr" leds to memory leaks
 */

class B;

class A{
	
public:

	~A(){
		std::cout<<"A destructor"<<std::endl;
	}

	
	std::shared_ptr<B> b_ptr_;
	
	
};


class B{
	
public:
	~B(){
		std::cout<<"B destructor"<<std::endl;
	}


	std::shared_ptr<A> a_ptr;
	
};

int main(){

	std::weak_ptr<B> w_b;
	
	{
		auto aa = std::make_shared<A>();
		auto bb = std::make_sharedr<B>();

		aa->b_ptr_= bb;
		w_b = bb;
		// bb->a_ptr = aa; no leaks
		
		std::
			cout<<"counter of bb: "<< bb.use_count() <<std::endl;
		std::cout<<"counter of weak: "<< w_b.use_count() <<std::endl;
	}

	std::cout<<"counter of weak: "<< w_b.use_count() <<std::endl;

	
	return 0;
}
