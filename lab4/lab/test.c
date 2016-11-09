//Ryan Maez
//CS 370 Lab 4

#define IF   1
#define COND 2
#define ELSE 3
#define STMT 4
#define STACK_MAX 100

#include "lex.yy.c"
#include <stdio.h>
#include <errno.h>
#include <string.h>

/*Strucure defiiin for stack
obtaied from//http://groups.csail.mit.edu/graphics/classes/6.837/F04/cpp_notes/stack1.html*/
struct Stack {
    int     data[STACK_MAX];
    int     size;
};
typedef struct Stack Stack;

//iniiazlies stack S
void Stack_Init(Stack *S)
{
    S->size = 0;
}

//returns the top element in stack S
int Stack_Top(Stack *S)
{
    if (S->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return -1;
    } 

    return S->data[S->size-1];
}

//adds element d to the top of stack S
void Stack_Push(Stack *S, int d)
{
    if (S->size < STACK_MAX)
        S->data[S->size++] = d;
    else
        fprintf(stderr, "Error: stack full\n");
}

//removes element at top of stack S
void Stack_Pop(Stack *S)
{
    if (S->size == 0)
        fprintf(stderr, "Error: stack empty\n");
    else
        S->size--;
}

//prints cirrect word, based on int s, and correct indentation for word
void print(int s,int indent)
 {
     int i;
     for (i = 0; i < 4*indent; i++) 
         printf(" ");
     if(s==1)
       printf("IF");
     if(s==2)
       printf("  COND\n");
     if(s==3)
       printf("ELSE\n");
     if(s==4)
       printf("STMT\n");
}

//iterates through the stack and checks for error cases
//prints informative message based on the error
//immediately returns 1 if error is found
//if stack passes error tests, returns 0
int errorCheck (Stack* S)
{
	int x,y,z,i;
	for(i = S->size-1; i >=1 ; i--)
	{
		x = S->data[i];
		y = S->data[i-1];
		//if(i>1)
		//	z = S->data[i-2];
		if(x==IF && y != COND)
		{
			fprintf(stderr, "Error: If statement without condition\n");
			return 1; 
		}
		if(x==ELSE && y ==COND)
		{
			fprintf(stderr, "Error: Else statement with condition\n");
			return 1;
		}
		if(x==ELSE && y==ELSE)
		{
			fprintf(stderr, "Error: Else followed by else\n");
			return 1;
		}
		if(x==STMT && y==IF)
		{
			fprintf(stderr, "Error: Statement followed by if\n");
			return 1;
		}
	}
	return 0;
}

void main()
{	
	//creates two stacks, one to old word token, and one to old corresponding condition
	Stack* r = NULL;
	r = (Stack *)malloc(sizeof(Stack)); 
	Stack_Init(r);
	Stack* indent = NULL;
	indent = (Stack *)malloc(sizeof(Stack)); 
	Stack_Init(indent);

	//retreives token from yylex() and pushes into stack, also increments or decrements pos based on specific condtion, pushes pos for corresponding token to stack
	int c;
	int pos = 0;
   	while ( c = yylex() )
     		switch (c) 
		{
			case IF:
	   			Stack_Push(indent,pos++);
	    			Stack_Push(r,IF);
	   			break;
			case COND:
	    			Stack_Push(indent,pos);
	    			Stack_Push(r,COND);
	    			break;
			case ELSE:
	    			Stack_Push(indent,--pos);
	    			Stack_Push(r,ELSE);    
	    			pos++;
	    			break;
			case STMT:
	    			Stack_Push(indent,pos);
	    			Stack_Push(r,STMT);
	    			if(r->data[r->size-1]==STMT && r->data[r->size-2]==ELSE && r->data[r->size-3]==STMT && r->data[r->size-4]==COND && r->data[r->size-5]==IF)
	      				pos=pos-2;
	    			break;
      		}
	
	//creates two new stacks, t and indrev	
  	Stack *t =NULL;
  	t = (Stack *)malloc(sizeof(Stack)); 
  	Stack_Init(t);
  	Stack *indrev =NULL;
  	indrev = (Stack *)malloc(sizeof(Stack)); 
  	Stack_Init(indrev);
  	
	//while r and indent stacks are not empty, pops all elements into t and indrev
	//this is because with the way stacks work, the last token from the input was at the top in old stacks, new stacks contain first token at top
  	while(r->size != 0)
  	{
      		Stack_Push(t,Stack_Top(r));
      		Stack_Pop(r);   
      		Stack_Push(indrev,Stack_Top(indent));
      		Stack_Pop(indent);
  	}

	//calls check error, if this function finds an error, program is terminated, if not it proceeds
 	if(errorCheck(t)==1)
		return;

	//iterates through stack by popping until it is empty, and makes use of print function to print token with corresponding amount of indentation
  	while(t->size!=0)
  	{
     		int pos = Stack_Top(indrev);
     		Stack_Pop(indrev);
     		int x = Stack_Top(t);
     		switch(x)
      		{
       			case IF:
	    			print(x,pos); 
	    			break;
       			case COND:
	    			print(x,0);
	    			break;
			case ELSE:
	  			print(x,pos);  
	 			break;
			case STMT:
	  			print(x,pos);
	  			break;
      		}
      		Stack_Pop(t);
  	}	
}
