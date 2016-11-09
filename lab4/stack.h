#ifndef Stack_H
#define Stack_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Stack* Stack;
 
void Stack_Init(Stack s);
int isEmpty();
int Stack_Top(Stack s);
void Stack_Push(Stack s, int d);
void Stack_Pop(Stack s);

#endif



