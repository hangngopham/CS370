

%{
/* need this for the call to atof() below */
#include <math.h>
/* need this for printf(), fopen() and stdin below */
#include <stdio.h>
%}

/* regular definitions (to be completed) */
digit   [0-9]
int     {digit}+
exp 	[Ee][+-]*
dotThenint  ("."){int}
intThendot  {int}(".")*
float (({dotThenint}|{intThendot}|{int}(\.)*{int}){exp}?{int})
ID      [A-Za-z][A-Za-z0-9]*
comment \/\*([^*"]*|\"[^"]*\"|\*+[^\/])*\*\/
ws [ \t\n]+

%%

{int}                    {
                         printf("An integer:                    %s (%d)\n", 
                                yytext, atoi(yytext));
                         }

{float}                  {
                         printf("A float:                       %s (%g)\n", 
                                   yytext, atof(yytext));
                         }

void|break|continue|else|float|if|int|return|while {
                         printf("A keyword:                     %s\n", 
                                 yytext); }

{ID}                     {
                         printf("An identifier:                 %s\n", 
                                 yytext); }

"+"|"-"|"*"|"/"|"%"|"!"|"?"|":"|"="|","|"<"|">"|";"|"("|")"|"{"|"}"  {
                         printf("operator/bracket/other char:   %s\n",
                                 yytext); }

"||"                     printf("Disjunction operator:          %s\n", yytext);

"&&"                     printf("Conjunction operator:          %s\n", yytext);

"=="                     printf("Equality operator:             %s\n", yytext);

{comment}                {
                         printf("Comment:                       %s\n", yytext);
                         }

[ \t\n]+                 /* eat up white space */ ;

.                        printf("Unrecognized character:        %s\n", yytext);

%%

int main()
{
                         yylex();
}
