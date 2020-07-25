#include<iostream>
#include<cstring>
#include<memory>  // unique_ptr
#include<algorithm> // copy
#include<vector>

/**
   move=, move constr, std::copy, unique_ptr<vector>

 */

template<typename T>
class Buffer{
public:
	//	Buffer():m_size(16), m_buffer(new T[16]){	}

	//Buffer()=default; ???
	
	Buffer(const std::string& name = " ", size_t size = 16):m_name(name), m_size(size){

		std::cout<<"constr"<<std::endl;

		if (size > 0)
			m_buffer = std::make_unique<std::vector<T>>(size);
		else
			m_buffer = nullptr;
	}

	Buffer(const Buffer& other): m_name(other.m_name), m_size(other.m_size){
		std::cout<<"copy constr"<<std::endl;
		m_buffer = std::make_unique<std::vector<T>>(m_size);		
		std::copy(other.m_buffer->begin(), other.m_buffer->end(), m_buffer->begin());
	}

	Buffer& operator=(const Buffer& other){
		std::cout<<"copy ="<<std::endl;
		//		if(*this != other){ // no != operator in Buffer
		if(this != &other){
			if(other.m_size > m_size){
				m_buffer = nullptr;
				m_size = other.m_size;
				m_buffer = std::make_unique<std::vector<T>>(m_size);
			}

			std::copy(other.m_buffer->begin(), other.m_buffer->end(), m_buffer->begin());
		}
		
		return *this;
	}

	Buffer(Buffer&& tmp):m_name(std::move(tmp.m_name)), m_size(tmp.m_size),
						 m_buffer(std::move(tmp.m_buffer)){

		std::cout<<"move constr"<<std::endl;
		tmp.m_size = 0;
		tmp.m_buffer = nullptr;
	}


	Buffer& operator=(Buffer&& tmp){
		std::cout<<"move ="<<std::endl;
		m_size = tmp.m_size;
		m_name = std::move(tmp.m_name);
		m_buffer = std::move(tmp.m_buffer);

		tmp.m_size = 0;

		return *this;
		
	}

	void fillBuffer(std::vector<T>& data){
		size_t data_size = data.size();
		size_t copy_size = data_size >= m_size ? m_size : data_size;
		// check size, TODO
		m_buffer->swap(data);	

	}

	
	void show() {
		std::cout<<m_name<<","<<m_size<<std::endl;

		//		auto tmp_ptr = m_buffer.get();
		if (m_buffer->size() > 0){
			for(auto it : *m_buffer)
				std::cout<<it<<",";
			std::cout<<"\n";
		}
	}


	~Buffer(){
		std::cout<<"destr"<<std::endl;
	}
	
private:
	std::string m_name;
	size_t m_size;
	std:: unique_ptr<std::vector<T> > m_buffer;
		
};

// return as Buffer<T>& leds to error, object will be destroyed after the function
// if as Buffer<T>, object will be destoryed after the assignment
template<typename T>
Buffer<T> getBuffer(const std::string& name){

	Buffer<T> newOne(name, 16);

	return newOne;
}

int main(){

	Buffer<int> int_buff("intBuffer");
	std::vector<int> int_data{1,2,3,4,5};
	
	int_buff.fillBuffer(int_data);
	int_buff.show();
	
	std::vector<char> char_data{'a','b','c'};
	//	Buffer<char> char_buff; default???
	Buffer<char> char_buff("char buffer",5);
	char_buff.fillBuffer(char_data);
	char_buff.show();

	std::cout<<"backup"<<std::endl;
	Buffer<char> char_buff_backup(char_buff);
	char_buff_backup.show();


	std::cout<<"b1"<<std::endl;
	Buffer<int> b1;
	b1 = getBuffer<int>("haha");
	
	std::cout<<"b2"<<std::endl;
	Buffer<int> b2 = b1;

	// no output???
	std::cout<<"b3"<<std::endl;
	Buffer<int> b3 = getBuffer<int>("tmp");

	// no output???
	std::cout<<"b4"<<std::endl;
	Buffer<int> b4(getBuffer<int>("aa"));
	
	
	return 0;
}
