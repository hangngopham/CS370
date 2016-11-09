
%{

#include <stdio.h>

int indent=0;

void print( char* s ) {
     int i;
     for (i = 0; i < 4*indent; i++) 
         printf(" ");
     printf("%s\n", s);
}

%}

%token          IF COND ELSE STMT

%%

S : STMT        {print("stmt");}
  | I S         {indent--;}
  | I S E S     {indent--;}
  ;

I : IF COND     {print("if  cond"); indent++;}
  ;

E : ELSE        {indent--; print("else"); indent++;}
  ;

%%

#include "lex.yy.c"

void main()
{
   yyparse();
}
