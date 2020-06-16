#include<iostream>
#include<stdio.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *rslt=NULL,*p;
        double num1=0, num2=0,sum=0;
        double whole = 1;

		do{
            num1 += l1->val * whole;
            whole *= 10;
            l1=l1->next;
        }while(l1 !=NULL);

        whole = 1;
        do{
            num2 += l2->val * whole;
            whole *= 10;
            l2=l2->next;
        }while(l2 !=NULL);

        sum = num1+num2;

		if(sum==0){
			ListNode* tmp = new ListNode;
			tmp->val=0;
			tmp->next=NULL;
			rslt=tmp;
		}
	
		while(sum > 1){
            ListNode* tmp = new ListNode;
            tmp->val = (int)sum%10;
			sum /=10;
			tmp->next = NULL;
			
			if(rslt == NULL){
			   rslt = tmp;			  
			}else{
                p = rslt;
				while(p->next !=NULL){
					p=p->next;
				}			  
                p->next = tmp;
            }
        }
	// p=rslt;
	// do{
	// 	cout<<p->val<<",";
	// 	p=p->next;
	// }while(p!=NULL);
	
	// cout<<endl;

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

	printf("list2: %p %p %p %p\n",&list2, list2,*list2,**list2);
	printf("tmp4: %p %p %d\n", &tmp4,tmp4,*tmp4);
	
}

int main(){
	// no use to create memory
	ListNode* list1, *list2;
	//	ListNode *list1, *list2;
	ListNode *p,*rslt;

	createListNode(&list1, &list2);
	// adress 0x090, 0x0f0, 2, 
	printf("list1,2: %p %d\n",list2, *list2);

	p=list2;
	do{
		cout<<p->val<<",";
		p=p->next;
	}while(p!=NULL);
	
	cout<<endl;

	
	Solution* s = new Solution;
	rslt=s->addTwoNumbers(list1, list2);
	
	return 0;
}
