#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

class Solution{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){

		ListNode* rslt=NULL;
		ListNode*p1, *p2, *ptr;
		int sum=0, carry=0;
		p1 = l1;
		p2 = l2;
		while(p1 != NULL || p2 != NULL){
			int x = p1 != NULL ? p1->val : 0;
			int y = p2 != NULL ? p2->val : 0;
			
			sum = (x+y)%10 + carry;
			carry = (x+y)/10;

			cout<<x<<"+"<<y<<"="<<sum<<endl;
			
            ListNode* tmp = new ListNode;
    		tmp-> val = sum;
	    	tmp->next = NULL;
            
            if(rslt == NULL){
                rslt = tmp;
				ptr=rslt;
            }else{
				ptr->next = tmp;
				ptr=ptr->next;
			}
			
			p1= p1!=NULL ? p1->next : NULL;
			p2= p2!=NULL ? p2->next : NULL;
		}

		if(carry > 0){
			ListNode* tmp = new ListNode;
			tmp->val = carry;
			tmp->next = NULL;
            ptr->next=tmp;
		}


		return rslt;
		
	}
};

void createListNode(ListNode** list1, ListNode** list2){

	ListNode* tmp1 = new ListNode;
	ListNode* tmp2 = new ListNode;
	ListNode* tmp3 = new ListNode;
	ListNode* tmp4 = new ListNode;
	ListNode* tmp5 = new ListNode;
	ListNode* tmp6 = new ListNode;

	tmp1->val = 2;
	tmp1->next = tmp2;
	tmp2->val = 4;
	tmp2->next = tmp3;
	tmp3->val = 6;
	tmp3->next = NULL;

	*list1 = tmp1;
	
	tmp4->val = 1;
	tmp4->next = tmp5;
	tmp5->val = 3;
	tmp5->next = tmp6;
	tmp6->val = 5;
	tmp6->next = NULL;

	*list2 = tmp4;
	
}

int main(){
	// no use to create memory
	ListNode* list1, *list2;
	//	ListNode *list1, *list2;
	ListNode *p,*rslt;

	createListNode(&list1, &list2);

	p=list2;
	do{
	  cout<<p->val<<",";
	  p=p->next;
	}while(p!=NULL);
	
	cout<<endl;
	
	
	Solution* s = new Solution;
	rslt=s->addTwoNumbers(list1, list2);

	p = rslt;
	do{
	  cout<<p->val<<",";
	  p=p->next;
	}while(p!=NULL);
	
	cout<<endl;

	
	return 0;
}
