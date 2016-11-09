

%{
/* need this for the call to atof() below */
#include <math.h>
/* need this for printf(), fopen() and stdin below */
#include <stdio.h>
%}

digit                    [0-9]
letter                   [_A-Za-z]
id                       {letter}({letter}|{digit})*
int                      {digit}+
exp                      [Ee][+-]?{int}
intdot                   {int}"."
intdotint                {intdot}{int}
dotint                   "."{int}
float                    (({dotint}|{intdotint}|{intdot}){exp}?|{int}{exp})
quote                    \"[^"]*\"
comment                  "/*"([^*"]|{quote}|[*]+([^*/"]|{quote}))*[*]+"/"
ws 			 [ \t\n]+ 
%%

{int}                    {yylval.name=strdup(yytext);
                          return(INTdenotation);} 
{float}                  {yylval.name=strdup(yytext);
                          return(FLOATdenotation);}
void                     {return(VOID);}
break                    {return(BREAK);}
continue                 {return(CONTINUE);}
else                     {return(ELSE);}
float                    {return(FLOAT);}
if                       {return(IF);}
int                      {return(INT);}
return                   {return(RETURN);}
while                    {return(WHILE);}
{id}                     {yylval.name=strdup(yytext);
                          return(ID);}
"||"                     {return(OR);}
"&&"                     {return(AND);}
"=="                     {return(EQ);}
{comment}                {/* skip comments; no return */}
{ws}                     {/* no action and no return */} 
.                        {return(yytext[0]);}

%%


