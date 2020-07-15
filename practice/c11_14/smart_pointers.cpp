#include<iostream>
#include<memory>

using namespace std;

/**
   Test for unique_ptr, share_ptr, weak_ptr since c++14
 */
class A{
public:
	A(int size):m_size(size){
		cout<<"constructor"<<endl;
		m_data = new int[m_size];
	}

	void getSize(){
		cout<<"size: "<<m_size<<endl;
	}
	

	~A(){
		cout<<"destroyed"<<endl;
		if(m_data != nullptr)
			delete[] m_data;
	}

private:
	int m_size;
	int* m_data; 
	// int m_data[];
};

void getSize(shared_ptr<A> a){

	a->getSize();
	
}

void getSize(A* a){
	cout<<"origin pointer"<<endl;
	a->getSize();
}

int main(){

	{
		shared_ptr<A> s;
		weak_ptr<A> w;
		{
			unique_ptr<A> u_ptr = make_unique<A>(5);
			// it's not allowed for unique_ptr
			//		unique_ptr<A> a = u_ptr;
			shared_ptr<A> s_ptr = make_shared<A>(10); 
			getSize(s_ptr);
			shared_ptr<A> sw_ptr = make_shared<A>(6);
			getSize(sw_ptr);
			
			s = s_ptr;
			w = sw_ptr;
			// get the origin pointer
			A* a = sw_ptr.get();
			getSize(a);
			cout<<"end1"<<endl;
			// unique_ptr will be destroyed after this scope
			// sw_ptr will be destroyed after this scope
		   
		}
			cout<<"end2"<<endl;
			// s_ptr will be destroyed after this scope because of s
	}
	
	cout<<"end"<<endl;
	

	return 0;
}
