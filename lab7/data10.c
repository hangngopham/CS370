#include<stdio.h>
#include<stdlib.h>
int main() {


	int x = 5-1;
	int y = 6;

	int sum = 0;
	/*if(x == 5) {
		if(y == 7) {
			sum = x+y;
			printf("Sum: %d\n",sum);
		}
		else {
		sum = x;
		printf("Sum: %d\n",sum);
		}
	}
	else {
	printf("Sum: is 0\n");
	}*/
	(x==5)?((y==7)?(sum=x+y):(sum=x)):(sum=0);
	printf("Sum is: %d\n",sum);

	return 0;

}





if($1->entry->data_type == TYPE_VOID) yyerror("+ cannot be used for type void\n");
		if($3->entry->data_type == TYPE_VOID) yyerror("+ cannot be used for type void\n");
		if($1->entry->data_type == TYPE_FLOAT) yyerror("+ cannot be used for type float\n");
		if($3->entry->data_type == TYPE_FLOAT) yyerror("+ cannot be used for type float\n");



(($1->entry->data_type != TYPE_VOID) || ($3->entry->data_type != TYPE_VOID))? ((($1->entry->data_type == TYPE_FLOAT)||($3->entry->data_type == TYPE_FLOAT))?Float:Int):yyerror()




















