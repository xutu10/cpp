#include<iostream>
#include<cstring>
#include<memory>  // unique_ptr
#include<algorithm> // copy
#include<vector>

template<typename T>
class Buffer{
public:
	//	Buffer():m_size(16), m_buffer(new T[16]){	}

	//Buffer()=default; ???
	
	Buffer(const std::string& name = " ", size_t size = 16):m_name(name), m_size(size){

		if (size > 0)
			m_buffer = std::make_unique<std::vector<T>>(size);
		else
			m_buffer = nullptr;
	}

	Buffer(const Buffer& other): m_name(other.m_name), m_size(other.m_size){
		auto src = other.m_buffer.get();
		auto dest = m_buffer.get();
		
		std::copy(src->begin(), src->end(), dest->begin());
	}

	void fillBuffer(std::vector<T>& data){
		size_t data_size = data.size();
		size_t copy_size = data_size >= m_size ? m_size : data_size;

		m_buffer->swap(data);	

	}

	void show() {
		std::cout<<m_name<<","<<m_size<<std::endl;

		auto tmp_ptr = m_buffer.get();
		if (tmp_ptr->size() > 0){
			for(auto it : *tmp_ptr)
				std::cout<<it<<",";
			std::cout<<"\n";
		}
	}

	
private:
	std::string m_name;
	size_t m_size;
	std:: unique_ptr<std::vector<T> > m_buffer;
		
};

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
	
	
	return 0;
}
