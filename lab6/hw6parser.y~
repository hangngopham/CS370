
%{

#include "symtbl.h"
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

int data_type; 
int current_scope;

void  yyerror(char  *s)  {
      fprintf(stderr,  "%s\n",  s);
}


%}

%union {
        SYMTBL       entry;
        char        *name;
        ASTNODE     *node;
}

%start               program
%token               VOID BREAK CONTINUE IF ELSE FLOAT INT 
%token               RETURN WHILE OR AND EQ
%token  <name>       ID INTdenotation FLOATdenotation
%type   <node>       program para_decl_l para_decl var_decl_l var_decl
%type   <node>       compound stmnt_list 
%type   <node>       stmnt expr condition disjunction conjunction
%type   <node>       comparison relation sum term factor primary
%type   <entry>      programID


%%

program     : func_spec programID '(' para_decl_l ')' compound
              {ast_root= ast_create_node(AST_PROGRAM, $2, $4, $6);
	      symtbl_dump_current();
	      ast_dump();}
            ;

programID   : ID {$$ = symtbl_install($1,SYMBOL_ID,data_type,1); }
            ;

para_decl_l : para_decl 
	      {$$ = $1;}
	    | para_decl_l ',' para_decl
	      {$$ = ast_create_node(AST_PARA_LIST, 0, $1, $3);}
            ;

para_decl   : type_spec	ID
		{SYMTBL entry = symtbl_lookup($2);
		if((entry)&&(entry->scope==2)) {
		yyerror("parameter already defined\n");
		}
		entry = symtbl_install($2, SYMBOL_ID, data_type,2);
		$$=ast_create_node(AST_PARA,entry,0,0);
		}
            ;

var_decl_l  : var_decl ';'
	    {$$ = $1;}
            | var_decl_l var_decl ';' 
	    {$$ = ast_create_node(AST_LIST,0,$1,$2);}
            ;

var_decl    : type_spec	ID  
		{SYMTBL entry = symtbl_lookup($2);
		if((entry)&&(entry->scope==3)) {
			yyerror("variable already defined\n");
		}
		symtbl_install($2,SYMBOL_ID,data_type,3);
		$$=0;
		}
	    | type_spec	ID '=' expr {
		SYMTBL entry = symtbl_lookup($2);
		if((entry) && (entry->scope == 3)) {
			yyerror("variable already defined\n");
		}
		entry = symtbl_install($2,SYMBOL_ID,data_type,3);
		$$ = ast_create_node(AST_ASSIGN,0,ast_create_node(AST_ID,entry,0,0),$4);
		}
	    | var_decl	',' ID {
		SYMTBL entry = symtbl_lookup($3);
                if ((entry) && (entry->scope==3)) {
			yyerror("variable already defined\n");
		}
                symtbl_install($3, SYMBOL_ID, data_type, 3);
                $$ = $1;
              }
	    | var_decl	',' ID '=' expr { 
		SYMTBL entry = symtbl_lookup($3);
                if ((entry) && (entry->scope==3)) {
			yyerror("variable already defined\n");
		} 	               
		entry= symtbl_install($3, SYMBOL_ID, data_type, 3);
                $$ = ast_create_node(AST_LIST, 0, $1, ast_create_node(AST_ASSIGN, 0,ast_create_node(AST_ID, entry, 0, 0), $5));
              } 
            ;

func_spec   : INT 
              { data_type = TYPE_INT; }
            | FLOAT 
              { data_type = TYPE_FLOAT; }
            | VOID
              { data_type = TYPE_VOID; }
            ;

type_spec   : INT 
              { data_type = TYPE_INT; }
            | FLOAT 
              { data_type = TYPE_FLOAT; }
            ;

compound    : '{' '}' {$$=0;}
  	    | '{' stmnt_list '}' {$$ = $2;}
	    | '{' var_decl_l stmnt_list '}'{$$ = ast_create_node(AST_LIST,0,$2,$3);}
            ;

stmnt_list  : stmnt {$$ = $1;}
	    | stmnt_list stmnt {$$ = ast_create_node(AST_LIST,0,$1,$2);}
            ;

stmnt       : compound  	{$$ = $1;}
	    | IF '(' expr ')' stmnt	{ $$ = ast_create_node(AST_IF_THEN,0,$3,$5);}
	    | IF '(' expr ')' stmnt ELSE stmnt {$$ = ast_create_node(AST_IF_ELSE, 0, $3, ast_create_node(AST_TWO_SIDED,0,$5,$7));}
	    | WHILE '(' expr ')' stmnt 	{$$ = ast_create_node(AST_WHILE,0,$3,$5);}
	    | BREAK ';' 	{$$ = ast_create_node(AST_BREAK,0,0,0);}
	    | CONTINUE ';' 	{$$ = ast_create_node(AST_CONTINUE,0,0,0);}
	    | RETURN expr ';' 	{$$ = ast_create_node(AST_RETURN,0,$2,0);}
	    | expr ';' 	{$$ = $1;}	 
	    | ';' 		{$$ = 0;}
            ;

expr        : ID '=' expr 
		{
		SYMTBL entry = symtbl_lookup($1);
		if(!entry) {
			yyerror("identifier undefined\n");
		}
		$$ = ast_create_node(AST_ASSIGN,0,ast_create_node(AST_ID,entry,0,0),$3);
		}
	    | condition   {$$ = $1;}
	    ;

condition   : disjunction 			 { $$ = $1; }
   	    | disjunction '?' expr ':' condition 
		{ $$ = ast_create_node(AST_COND_EXP,0,$1,ast_create_node(AST_ALT,0,$3,$5)); }
            ;

disjunction : conjunction 		 { $$ = $1; }
	    | disjunction OR conjunction { $$ = ast_create_node(AST_OR, 0, $1, $3); }
            ;

conjunction : comparison		 { $$ = $1; }
	    | conjunction AND comparison { $$ = ast_create_node(AST_AND, 0, $1, $3); }
	    ;
          
comparison  : relation 		   { $$ = $1; }
	    | relation EQ relation { $$ = ast_create_node(AST_EQ, 0, $1, $3); }
            ;

relation    : sum 	  { $$ = $1; }
	    | sum '<' sum { $$ = ast_create_node(AST_LT, 0, $1, $3); }
	    | sum '>' sum { $$ = ast_create_node(AST_GT, 0, $1, $3); }
            ;

sum         : term	   { $$ = $1; }
	    | sum '+' term { $$ = ast_create_node(AST_ADD, 0, $1, $3); }
	    | sum '-' term { $$ = ast_create_node(AST_SUB, 0, $1, $3); }
            ;

term        : factor          { $$ = $1; }
	    | term '*' factor { $$ = ast_create_node(AST_MUL, 0, $1, $3); }
	    | term '/' factor { $$ = ast_create_node(AST_DIV, 0, $1, $3); }
	    | term '%' factor { $$ = ast_create_node(AST_MOD, 0, $1, $3);  }
            ;

factor      : primary    { $$ = $1; }
	    | '!' factor { $$ = ast_create_node(AST_NOT,0,$2,0); } 
	    | '-' factor { $$ = ast_create_node(AST_UMINUS, 0,$2,0); } 
            ;

primary     : INTdenotation {
		SYMTBL entry = symtbl_lookup($1);
		if (!entry) {
			entry = symtbl_install($1,SYMBOL_NUM,TYPE_INT,0);
		}
		$$ = ast_create_node(AST_INT,entry,0,0); 
		}
	    | FLOATdenotation {
		SYMTBL entry = symtbl_lookup($1);
		if(!entry) {entry = symtbl_install($1, SYMBOL_NUM, TYPE_FLOAT,0);}
		$$= ast_create_node(AST_FLOAT, entry,0,0);
		}
	    | ID  {
		SYMTBL entry = symtbl_lookup($1);
		if(!entry){
			yyerror("identifier undefined\n");
		}
		if(entry && (entry->scope==1)) {
			yyerror("identifier undefined\n");
		}
		$$ = ast_create_node(AST_ID,entry,0,0);
		}

	    | '(' expr ')' {$$ = $2;}
            ;

%%

#include "lex.yy.c"
