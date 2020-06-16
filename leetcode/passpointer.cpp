#include<iostream>
#include<stdio.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};



void createListNode(ListNode** list1, ListNode** list2){

	printf("%p %p\n", &list1, list1);
	ListNode* tmp1 = new ListNode;
	ListNode* tmp2 = new ListNode;
	ListNode* tmp3 = new ListNode;
	ListNode* tmp4 = new ListNode;

	tmp1->val = 2;
	tmp1->next = tmp2;
	tmp2->val = 4;
	tmp2->next = NULL;
	tmp3->val = 1;
	tmp3->next = tmp4;
	tmp4->val = 3;
	tmp4->next = NULL;
	
	*list1 = tmp1;

	printf("list1: %p %p %p\n", &list1,list1,*list1);
	printf("tmp1: %p %p %d\n", &tmp1,tmp1,*tmp1);

	*list2 = tmp3;

	printf("list2: %p %p %p\n", &list2,list2,*list2);
	printf("tmp3 %p %p %d\n", &tmp3,tmp3,*tmp3);

	
}

int main(){

	ListNode *list1,*list2;
	printf("%p %p\n", &list1, &list2);
	// createListNode(list);
	// if a pointer passed by adresse, parameter must be a double pointer to take
	createListNode(&list1, &list2);
	printf("list1: %p %p %d\n",&list1,list1,*list1);		
	printf("list2: %p %p %d\n",&list2,list2,*list2);		

	return 0;
}
