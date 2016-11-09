#define IF   1
#define COND 2
#define ELSE 3
#define STMT 4

#include "lex.yy.c"
#include "stack.c"

void print(int val, int space) {
		int i;
		if(val == COND) {
			printf("  COND\n");
		}
		if(val == IF) {	
			for(i = 0; i < 4*space; i++) {
				printf(" ");
			}
			printf("IF");
		}
		if(val == ELSE) {
			for(i = 0; i < 4*space; i++) {
				printf(" ");
			}
			printf("ELSE\n");
		}
		if(val == STMT) {
			for(i = 0; i < 4*space; i++) {
				printf(" ");
			}
			printf("STMT\n");
		}
}
void main() {
	Stack words;
	words = malloc(sizeof(Stack));
	Stack_Init(words);

	Stack indent;
	indent = malloc(sizeof(Stack));
	Stack_Init(indent);

	int c;
	int a = 0;
	while (c = yylex()) {
	      	switch (c) {		
		 case IF:   
			Stack_Push(indent,a);
			Stack_Push(words,IF);
			break;
		 case COND: 
			Stack_Push(indent,a++);
			Stack_Push(words,COND);
			break;
		 case ELSE: 
			Stack_Push(indent,--a);
			Stack_Push(words,ELSE);
			a++;
			break;
		 case STMT: 
			Stack_Push(indent,a);
			Stack_Push(words,STMT);
			if(words->data[words->size-1] == STMT && words->data[words->size-2] == ELSE && words->data[words->size-3] == STMT && words->data[words->size-4] == COND && words->data[words->size-5]== IF) {
				a = a-2;
			}
			break;

	      	}
	}
	

	Stack(wstack);
	wstack = malloc(sizeof(Stack));
	Stack_Init(wstack);
	Stack(istack);
	istack = malloc(sizeof(Stack));
	Stack_Init(istack);

	int count1 = words->size-1;
	while(count1!=0) {
		Stack_Push(wstack, Stack_Top(words));
		int top = Stack_Top(wstack);
		printf("%d\n",top);
		Stack_Pop(words);
		count1--;
	}

	int count2 = indent->size-1;
	while(count2 != 0) {
		Stack_Push(istack, Stack_Top(indent));
		Stack_Pop(indent);
	//	int top = Stack_Top(istack);
	//	printf("%d\n",top);
		count2--;
	}

	while(wstack->size != 0 && istack->size !=0) {
		int top = (int)Stack_Top(wstack);

		int pos = (int)Stack_Top(istack);

		print(top,pos);	
		Stack_Pop(wstack);
		Stack_Pop(istack);
	}
}



/*while (c = yylex()){
     		switch (c) 
		{
			case IF:
	   			Stack_Push(indent,a);
	    			Stack_Push(words,IF);
	   			break;
			case COND:
	    			Stack_Push(indent,a++);
	    			Stack_Push(words,COND);
	    			break;
			case ELSE:
	    			Stack_Push(indent,--a);
	    			Stack_Push(words,ELSE);    
	    			a=a+1;
	    			break;
			case STMT:
	    			Stack_Push(indent,a);
	    			Stack_Push(words,STMT);
	    			if(words->data[words->size-1]==STMT && words->data[words->size-2]==ELSE && words->data[words->size-3]==STMT && words->data[words->size-4]==COND && words->data[words->size-5]==IF)
	      				a=a-2;
	    			break;
      		}
}*/



















