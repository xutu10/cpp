#ifndef _FACTORY_H
#define _FACTORY_H

#include<map>
#include<string>
using namespace std;

typedef void* (*CREATE)();
class Factory{
public:
	static void* create_obj(const string& name){
		map<string,CREATE>::const_iterator it;
		it = map_.find(name);
		if(it == map_.end())
			return 0;
		else{
			return it->second();
		}
	}
	
	static void* Register(const string& name, CREATE fun){
		map_[name] = fun;
	}
	
private:
	static map<string,CREATE> map_;
};

__attribute((weak))map<string,CREATE> Factory::map_;

class Register{
public:
	Register(const string& name, CREATE fun){
		Factory::Register(name,fun);
	}
};
// creating a object will automatic call the constructor to call the func list( Register func) 

#define REGISTER_CLASS(class_name) \
class class_name##Register{ \
public: \
	static void* new_instance(){ \
		return new class_name;	 \
	} \
private: \
	static Register reg_; \
};\
 Register class_name##Register::reg_(#class_name,class_name##Register::new_instance); \

// belongs to macro, or with end symbol \ is ok too.
// usage of # is to invert class_name to string. it can be used only in macro.

#endif //_Factory_H
