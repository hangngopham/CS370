#include "stack.h"

struct node {
	int data;
	struct node *ptr;
}*top,*top1,*temp;

// Create empty stack
void create() {
	top = NULL;
}

// Push data into stack
void push(int val) {
	if(top == NULL) {
		top = (struct node *)malloc(1*(sizeof(struct node)));
		top->ptr = NULL;
		top->data = val;
	}
	else {
		temp = (struct node*)malloc(1*(sizeof(struct node)));
		temp->ptr = top;
		temp->data = val;
		top = temp;
	}
}

// Pop operation on stack
void pop() {
	top1 = top;
	if(top1 == NULL) {
		printf("\n Error: trying to pop from empty stack");
		return;
	}
	else {
		top1 = top1->ptr;
	}
	printf("\n Popped value : %d", top->data);
	free(top);
	top = top1;
}

// Get value of top element
int getTop() {
	return top->data;
}

// Check whether the stack is empty or not
bool isEmpty() {
	if(top == NULL) {
		printf("\n Stack is empty");
		return 1;
	}
	else {
		printf("\n Stack is not empty");
		return 0;
	}
}

