#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Link{
	int data;
	struct Link* next;
};

struct Stack{
	struct Link* head;
	int size;	
};

void stack_init(struct Stack* stk){
	stk->head = NULL;
	stk->size = 0;
}

int stack_empty(struct Stack* stk){
	if(0 == stk->size)
		return 1;
	else
		return 0;
}

void stack_push(struct Stack* stk,const int data){
	struct Link* node = malloc(sizeof(struct Link));
	assert(NULL != node);
	node->data = data;
	node-> next = stk->head;
	stk->head = node;
	++stk->size;	
}

int stack_pop(struct Stack* stk){

	if(stack_empty(stk))
		return 0;
	
	struct Link* tmp = stk->head;
	stk->head = tmp->next;
	--stk->size;
	free(tmp);

	return 1;
}

void stack_cleanup(struct Stack* stk){
	struct Link* tmp;
	while(tmp = stk->head){
		stk->head = tmp->next;
		free(tmp);
		--stk->size;
	}
}

int main(int argc, char *argv[])
{
    struct Stack stk;
	stack_init(&stk);
	int i;
	for(i = 0;i<5;i++){
		stack_push(&stk,i);
	}
	printf ("1111\n");
	while(!stack_empty(&stk)){
		printf ("%d\n",stk.head->data);
		stack_pop(&stk);
	}
	printf ("2222\n");
    return 0;
}
