#include<iostream>
using namespace std;

class Stack{
	// default accessibility of member
	struct Link{
		int data;
		Link* next;
		Link(int d,Link* n):data(d),next(n){
			
		}
	};

public:
	
	Stack():head(NULL),size(0){

	}

	~Stack(){
		Link* tmp;
		while(tmp = head){
			head = tmp->next;
			delete tmp;
			--size;
		}
	}

    bool empty(){

		return (0 == size);
	}

	void push(const int data){
		Link* node = new Link(data,head);
		head = node;
		++size;	
	}

    bool pop(){

		if(empty())
			return false;
	
	    Link* tmp = head;
//		data = tmp->data;
		head = tmp->next;
		--size;
	    delete tmp;

		return true;
	}
	
public:
	Link* head;
	int size;
};

int main(int argc, char *argv[])
{
    Stack stk ;
	int i;
	for(i = 0;i<5;i++){
		stk.push(i);
	}

	while(!stk.empty()){
		cout<<stk.head->data<<endl;
		stk.pop();
	}


    return 0;
}
