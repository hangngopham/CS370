#include<stdio.h>
#include "stack.h"
#define STACK_MAX 100

struct Stack {
    int data[STACK_MAX];
    int size;
};
typedef struct Stack* Stack;

// Initialize the stack
void Stack_Init(Stack s)
{
    s->size = 0;
}

// Check whether the stack is empty or not
/*int isEmpty() {
	if(this->size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}*/

// Return top element
int Stack_Top(Stack s)
{
    if (s->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return -1;
    } 

    return s->data[s->size-1];
}

// Push element into the stack
void Stack_Push(Stack s, int d)
{
    if (s->size < STACK_MAX)
        s->data[s->size++] = d;
    else
        fprintf(stderr, "Error: stack full\n");
}

// Pop element from the stack
void Stack_Pop(Stack s)
{
    if (s->size == 0)
        fprintf(stderr, "Error: stack empty\n");
    else
        s->size--;
}

int getSize(Stack s) {
	return s->size;
}


