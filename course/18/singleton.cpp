#include<iostream>
using namespace std;

class Singleton{
public:
	static Singleton* GetInstance(){
		if(instance_ == NULL)
			instance_ = new Singleton;
		return instance_;
	}
	// avoid memory leaks
	~Singleton(){
		
	}

	// static void free(){
	// 	delete instance_;
	// }
	class Garbo{
	public:
		~Garbo(){
			if(Single::instance_ != NULL)
				delete instance_;
		}
	}

private:
	// declare copy constructor as private
	Singleton(const Singleton& ohter);
	// assignment as private too
	Singleton=(const Singleton& ohter);
	Singleton(){
		
	}

	static Singleton* instance_;
	// automatic call the ~Garbo() at end of lifecycle of garbo_;
	static Garbo garbo_;
};
Singleton::Garbo Singleton::garbo_;
Singleton* Singleton::instance_;

int main(int argc, char *argv[])
{
    // Singleton s1;
	// return the same instance whatever how many times it's called.
	Singleton* s = Singleton :: GetInstance();
	Singleton* s1 = Singleton :: GetInstance();
	// copy constructor
//	Singleton s3(*s);
	//s3 = s1;
	Singleton::free();
    return 0;
}
