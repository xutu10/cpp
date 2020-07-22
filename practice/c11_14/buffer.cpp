#include<iostream>
#include<cstring>
#include<memory>  // unique_ptr
#include<algorithm> // copy

template<typename T>
class Buffer{
public:
	//	Buffer():m_size(16), m_buffer(new T[16]){	}

	Buffer(const std::string& name = " ", size_t size = 16):m_name(name), m_size(size){

		if (size > 0)
			m_buffer = std::make_unique<std::vector<T>>(size);
		else
			m_buffer = nullptr;
	}

	Buffer(const Buffer& other){
		
	}

	void fillBuffer(const T* data){
		size_t data_size = sizeof(data)/sizeof(data[0]);
		size_t copy_size = data_size >= m_size ? m_size : data_size;

		auto it = m_buffer->begin();
		std::copy(data, data + copy_size, it);

	}

	void show() {
		std::cout<<m_name<<","<<m_size<<std::endl;
		auto it = m_buffer->get();
		for(auto m :  )
			std::cout<< m <<",";
		std::cout<<std::endl;
	}

private:
	std::string m_name;
	size_t m_size;
	std:: unique_ptr<std::vector<T> > m_buffer;
		
};

int main(){

	Buffer<int> int_buff;
	int_buff.show();
	Buffer<char> char_buff("buff char", 10);
	char_buff.show();
	
	return 0;
}
