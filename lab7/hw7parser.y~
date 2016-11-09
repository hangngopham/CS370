%{
#include "hw7symtbl.h"
#include <stdlib.h>
#include <stdio.h>

int data_type; 
int current_scope = 1;

void  yyerror(char  *s)  { fprintf(stderr,  "%s\n",  s); exit(-1); }

void arrayRefChecking(ASTNODE *reference, ASTNODE *decl) {
	if((reference && !decl) || (!reference && decl)) {
		yyerror("Error: Array declaration and array reference have different dimensions.\n");
	}
	reference->entry = decl->entry;
	arrayRefChecking(reference->left,decl->left);
}

void functionRefChecking(ASTNODE *argument, ASTNODE *param) {
	if ((argument->type==AST_ARG && param->type==AST_PARA_LIST)|| (argument->type==AST_ARG_LIST && param->type==AST_PARA)) yyerror("Wrong number of arguments"); 
	if(argument->type ==AST_ARG && param->type == AST_PARA) {
		if(argument->entry->data_type != param->entry->data_type) {
			yyerror("Argument and parameter do not have the same type\n");
		}
	}
        functionRefChecking(argument->left, param->left);
}
%}

%union {
        SYMTBL       entry;
        char        *name;
	ASTNODE     *node;
}

%start               programs
%token               VOID BREAK CONTINUE IF ELSE FLOAT INT 
%token               RETURN WHILE OR AND EQ
%token  <name>       ID INTdenotation FLOATdenotation
%type   <node>       program program_l arg_l arg array_dims para_dims array_indices array_index
%type   <node>       para_decl_l para_decl var_decl_l var_decl 
%type   <node>       compound stmnt_list 
%type   <node>       stmnt expr cond disjunction conjunction
%type   <node>       comparison relation sum term factor primary
%type   <entry>      programID array_dim

%%

programs    : program_l
	     { ast_root = $1;
	       symtbl_dump_current();
	       printf("\n\n");
	       ast_dump();
	       printf("\n\n");
	      }
                
            | var_decl_l program_l
	     { ast_root = ast_create_node(AST_LIST,0,$1,$2);
	       symtbl_dump_current();
	       printf("\n\n");
       	       ast_dump();
	       printf("\n\n");
	      }
             ;

program_l   : program 
             { $$ = $1; }
            | program_l program
             { $$ = ast_create_node(AST_PROGRAM_LIST,0,$1,$2); }
            ;

program     : type_spec programID '(' para_decl_l ')'{$2->ast_link = $4; current_scope = 2;} compound
		{$$ = ast_create_node(AST_PROGRAM,$2,$4,$7);
		ast_dump_subtree($$);
	        printf("\n");
	        symtbl_finalizeScope();
		}
			      
            | VOID {data_type=TYPE_VOID;} programID '(' para_decl_l ')'{$3->ast_link = $5; current_scope = 2;} compound
                {$$ = ast_create_node(AST_PROGRAM,$3,$5,$8);
		 ast_dump_subtree($$);
	         printf("\n");
	         symtbl_finalizeScope();
		}
            ;
	
programID   : ID
              { SYMTBL entry = symtbl_lookup($1);
		if((entry) && (entry->sym_type == SYMBOL_FUNC)) {
			yyerror("function already defined");
		}	
		$$ = symtbl_install($1,SYMBOL_FUNC, data_type,1);
	      }
            ;

para_decl_l : para_decl
              {$$ = $1;}
            | para_decl_l ',' para_decl
              {$$ = ast_create_node(AST_PARA_LIST,0,$1,$3); }
            ;

para_decl   : type_spec ID
              { SYMTBL entry = symtbl_lookup($2);
                if ((entry) && (entry->scope==2)) yyerror("parameter already defined\n");
                $$ = ast_create_node(AST_PARA, 
                     symtbl_install($2, SYMBOL_PARA, data_type,2), 0, 0); }
            | type_spec ID para_dims
              { SYMTBL entry = symtbl_lookup($2);
	        if((entry) && (entry->scope==2)) yyerror("parameter already defined\n");
	        $$ = ast_create_node(AST_PARA, symtbl_install($2, $3,data_type,2),$3,0);
	      }
            ;

para_dims   : '[' ']'
              {
		SYMTBL entry = symtbl_install("1", SYMBOL_NUM, TYPE_INT,0);
		$$ = ast_create_node(AST_ARRAY_DIMS,entry,0,0);
	       }
            | para_dims array_dim
              {$$ = ast_create_node(AST_ARRAY_DIMS,$2,$1,0);}
            ;

var_decl_l  : var_decl ';'
              {$$ = $1;}
            | var_decl_l var_decl ';' 
              {$$ = ast_create_node(AST_LIST,0,$1,$2);}
            ;

var_decl    : type_spec     ID  
              { SYMTBL entry = symtbl_lookup($2);
                if ((entry) && (entry->scope==current_scope)) yyerror("variable name already defined\n");
                entry = symtbl_install($2, SYMBOL_ID, data_type, current_scope);
                $$ = 0;
              }

            | type_spec     ID '=' expr
              { SYMTBL entry = symtbl_lookup($2);
                if ((entry) && (entry->scope==current_scope)) yyerror("variable name already defined\n");
                entry= symtbl_install($2, SYMBOL_ID, data_type, current_scope);
	        
                $$ = ast_create_node(AST_ASSIGN, (entry->data_type)?Float:Int, ast_create_node(AST_ID, entry, 0, 0), $4);
              }

            | type_spec     ID array_dims
              { SYMTBL entry = symtbl_lookup($2);
                if ((entry) && (entry->scope==current_scope)) yyerror("variable name already defined\n");
                $$ = ast_create_node(AST_ARRAY_DECL, symtbl_install($2, $3, data_type,current_scope),$3, 0);}

            | var_decl  ',' ID array_dims
              { SYMTBL entry = symtbl_lookup($3);
                if ((entry) && (entry->scope==current_scope)) yyerror("variable name already defined\n");
                entry = symtbl_install($3, $4, data_type, current_scope);
                $$ = ast_create_node(AST_LIST,0,$1,ast_create_node(AST_ARRAY_DECL,entry,$4,0)) ;
             }

            | var_decl  ',' ID  
              { SYMTBL entry = symtbl_lookup($3);
                if ((entry) && (entry->scope==current_scope)) yyerror("variable name already defined\n");
                entry = symtbl_install($3, SYMBOL_ID, data_type, current_scope);
                $$ = $1;
              }
            | var_decl  ',' ID '=' expr
              { SYMTBL entry = symtbl_lookup($3);
                if ((entry) && (entry->scope==current_scope)) yyerror("variable name already defined\n");
                entry= symtbl_install($3, SYMBOL_ID, data_type, current_scope);
                $$ = ast_create_node(AST_LIST, 0, $1, ast_create_node(AST_ASSIGN, (entry->data_type)?Float:Int, ast_create_node(AST_ID, entry, 0, 0), $5));
              }
            ;

array_dims  : array_dim
              {$$ = ast_create_node(AST_ARRAY_DIMS,$1,0,0);}
            | array_dims array_dim
              {$$ = ast_create_node(AST_ARRAY_DIMS, $2,$1,0);}
            ;

array_dim   : '[' INTdenotation ']'
             { SYMTBL entry = symtbl_lookup($2);
	       if(!entry) {
	       	     entry = symtbl_install($2,SYMBOL_NUM, TYPE_INT,0);
	       }
	       $$ = entry; }
            ;

type_spec   : INT 
             { data_type = TYPE_INT; }
            | FLOAT 
             { data_type = TYPE_FLOAT; }
            ;

compound    : '{' {current_scope++;} var_decl_l stmnt_list '}'
             { $$ = ast_create_node(AST_LIST, 0, $3, $4);
	       symtbl_dump_current();
	       symtbl_finalizeScope();
	       current_scope--; }
            | '{' stmnt_list '}'
             {  $$ = $2; }
            | '{'         '}'
             {  $$ = 0;  }
            ;

stmnt_list  : stmnt 
             { $$ = $1; }
            | stmnt_list stmnt
             { $$ = ast_create_node(AST_LIST, 0, $1, $2); }
            ;

stmnt       : compound
              { $$ = $1; }
            | IF '(' expr ')' stmnt ELSE stmnt
              { $$ = ast_create_node(AST_IF_ELSE, 0, $3, 
                     ast_create_node(AST_TWO_SIDED, 0, $5, $7)); }       
            | IF '(' expr ')' stmnt 
              { $$ = ast_create_node(AST_IF_THEN, 0, $3, $5) ; }
            | WHILE '(' expr ')' stmnt
              { $$ = ast_create_node(AST_WHILE, 0, $3, $5) ; }
            | BREAK       ';'
              { $$ = ast_create_node(AST_BREAK, 0, 0, 0) ; }
            | CONTINUE    ';'
              { $$ = ast_create_node(AST_CONTINUE, 0, 0, 0) ; }
            | RETURN ';'
              { $$ = ast_create_node(AST_RETURN, 0, 0, 0) ; }
            | RETURN expr ';'
              { $$ = ast_create_node(AST_RETURN, 0, $2, 0) ; }
            | expr        ';'
              { $$ = $1; }
            |             ';'
              { $$ = 0; }
            ; 

expr        : ID '=' expr 
               { SYMTBL entry = symtbl_lookup($1);
                if (!entry) yyerror("identifier undefined\n");
                if (entry && (entry->sym_type == SYMBOL_FUNC)) yyerror("identifier is a function name; cannot be assigned a value\n"); 
		if (entry->data_type == TYPE_INT && $3->entry->data_type == TYPE_FLOAT) yyerror("conflict type: float cannot be assigned to integer\n");
                $$ = ast_create_node(AST_ASSIGN, (entry->data_type)?Float:Int, ast_create_node(AST_ID, entry, 0, 0), $3); 
              }
            | ID array_indices '=' expr 
              { 
		SYMTBL entry = symtbl_lookup($1);
	        if (!entry) yyerror("identifier undefined\n");
	        if (entry && (entry->sym_type == SYMBOL_FUNC)) yyerror("identifier is a function name; cannot be assigned a value\n");
		if (entry->data_type == TYPE_INT && $4->entry->data_type == TYPE_FLOAT) yyerror("conflict type: float cannot be assigned to integer\n");
		//arrayRefChecking($2,entry->ast_link);
		$$ = ast_create_node(AST_ASSIGN,entry->data_type?Float:Int, ast_create_node(AST_ID,entry,$2,0),$4);

	      }
            | cond 
              { $$ = $1; }
            ;

cond        : disjunction
              { $$ = $1; }              
            | disjunction '?' expr ':' cond
	      { 	
		if(($1->entry->data_type == TYPE_VOID) || ($3->entry->data_type == TYPE_VOID) || ($5->entry->data_type == TYPE_VOID)) yyerror("cond cannot be used for type void\n");
		$$ = ast_create_node(AST_COND_EXP, ($3->entry->data_type ||$5->entry->data_type)?Float:Int, $1, ast_create_node(AST_ALT,($3->entry->data_type ||$5->entry->data_type)?Float:Int, $3, $5)); }
            ;

disjunction : conjunction
              { $$ = $1; } 
             
            | disjunction OR conjunction
              { 
		if(($1->entry->data_type == TYPE_VOID) || ($3->entry->data_type == TYPE_VOID)) yyerror("|| cannot be used for type void\n");
		if(($1->entry->data_type == TYPE_FLOAT)||($3->entry->data_type==TYPE_FLOAT)) yyerror("|| can only be used for integer\n");
		$$ = ast_create_node(AST_OR, Int, $1, $3) ; }
            ;

conjunction : comparison
              { $$ = $1; }             
            | conjunction AND comparison
              {
		if(($1->entry->data_type == TYPE_VOID) || ($3->entry->data_type == TYPE_VOID)) yyerror("&& cannot be used for type void\n");
		if(($1->entry->data_type == TYPE_FLOAT)||($3->entry->data_type==TYPE_FLOAT)) yyerror("&& can only be used for integer\n");
 		$$ = ast_create_node(AST_AND, Int, $1, $3) ; }
            ;

comparison  : relation 
             { $$ = $1; }
            | relation EQ relation
             { 
		if(($1->entry->data_type == TYPE_VOID) || ($3->entry->data_type == TYPE_VOID)) yyerror("== cannot be used for type void\n");
		if(($1->entry->data_type == TYPE_FLOAT)||($3->entry->data_type==TYPE_FLOAT)) yyerror("== can only be used for integer\n");
		$$ = ast_create_node(AST_EQ, Int, $1, $3) ; }
            ;

relation    : sum 
             { $$ = $1; }             
            | sum '<' sum
             { 
		if(($1->entry->data_type == TYPE_VOID) || ($3->entry->data_type == TYPE_VOID)) yyerror("< cannot be used for type void\n");
		if(($1->entry->data_type == TYPE_FLOAT)||($3->entry->data_type==TYPE_FLOAT)) yyerror("< can only be used for integer\n");
		$$ = ast_create_node(AST_LT, Int, $1, $3) ; }  
            | sum '>' sum
              { 
		if(($1->entry->data_type == TYPE_VOID) || ($3->entry->data_type == TYPE_VOID)) yyerror("> cannot be used for type void\n");
		if(($1->entry->data_type == TYPE_FLOAT)||($3->entry->data_type==TYPE_FLOAT)) yyerror("> can only be used for integer\n");
$$ = ast_create_node(AST_GT, Int, $1, $3) ; }  
            ;

sum         : term  
             { $$ = $1; }          
            | sum '+' term
             { 
		if($1->entry->data_type == TYPE_VOID || $3->entry->data_type == TYPE_VOID) yyerror("+ cannot be used for type void\n");
		$$ = ast_create_node(AST_ADD,($1->entry->data_type)||($3->entry->data_type)?Float:Int, $1, $3) ; }   
            | sum '-' term
	     {
		if($1->entry->data_type == TYPE_VOID || $3->entry->data_type == TYPE_VOID) yyerror("+ cannot be used for type void\n");
                $$ = ast_create_node(AST_SUB, ($1->entry->data_type)||($3->entry->data_type)?Float:Int, $1, $3) ; }
            ;

term        : factor 
              { $$ = $1; }    
            | term '*' factor
	      {
	       if(($1->entry->data_type ==TYPE_VOID)||($3->entry->data_type==TYPE_VOID)) yyerror("* cannot be used for type void\n");
               $$ = ast_create_node(AST_MUL, (($1->entry->data_type)||($3->entry->data_type))?Float:Int, $1, $3) ; }                
            | term '/' factor
		{
		if(($1->entry->data_type ==TYPE_VOID)||($3->entry->data_type==TYPE_VOID)) yyerror("/ cannot be used for type void\n");
               $$ = ast_create_node(AST_DIV, (($1->entry->data_type)||($3->entry->data_type))?Float:Int, $1, $3) ; }                
            | term '%' factor
               { 
		if(($1->entry->data_type ==TYPE_VOID)||($3->entry->data_type==TYPE_VOID)) yyerror("% cannot be used for type void\n");
		if(($1->entry->data_type == TYPE_FLOAT) ||($3->entry->data_type==TYPE_FLOAT)) yyerror("% can only be used for integer\n");
		$$ = ast_create_node(AST_MOD, Int, $1, $3) ; }               
            ;

factor      : primary 
               { $$ = $1; }             
            | '!' factor
               {
	         if($2->entry->data_type == TYPE_VOID) {
		      yyerror("! cannot be used for type void\n");
	         }
		 if($2->entry->data_type == TYPE_FLOAT) {
		      yyerror("! can only be used for integer\n");
	         }
		  $$ =  ast_create_node(AST_NOT, Int, $2,  0) ;
		}
		              
            | '-' factor 
              { 
		if($2->entry->data_type == TYPE_VOID) {
		      yyerror("- cannot be used for type void\n");
	         }
		$$ = ast_create_node(AST_UMINUS,$2->entry->data_type?Float:Int, $2,  0) ; 
		
	      }                
            ;

primary     : INTdenotation
              { SYMTBL entry = symtbl_lookup($1);
                if (!entry) entry = symtbl_install($1,SYMBOL_NUM,TYPE_INT,0); 
                $$ = ast_create_node(AST_INT,entry,0,0); }                
            | FLOATdenotation
              { SYMTBL entry = symtbl_lookup($1);
                if (!entry) entry= symtbl_install($1,SYMBOL_NUM,TYPE_FLOAT,0); 
                $$ = ast_create_node(AST_FLOAT, entry, 0,  0); }                
            | ID
	      { SYMTBL entry = symtbl_lookup($1);
                if (!entry) yyerror("identifier undefined\n"); 
                if (entry && (entry->sym_type == SYMBOL_FUNC)) yyerror("identifier is a function name; cannot be assigned a value\n"); 
                $$ = ast_create_node(AST_ID, entry, 0,  0); }                
            | ID '(' arg_l ')'
	      { SYMTBL entry = symtbl_lookup($1);
	        if(!entry) yyerror("identifier undefined\n");
	        if(entry && (entry->sym_type == SYMBOL_FUNC)) yyerror("identifier is a function name; cannot be assigned a value\n");
		//functionRefChecking($3,entry->ast_link);
	        $$ = ast_create_node(AST_FUNC_CALL, entry,$3,0);
	      }
            | ID array_indices
	      { SYMTBL entry = symtbl_lookup($1);
	        if(!entry) yyerror("identifier undefined\n");
	        if(entry && (entry->sym_type == SYMBOL_FUNC)) yyerror("identifier is a function name; cannot be assigned a value\n");
	        $$ = ast_create_node(AST_ARRAY_REF, 0, $2,0);
	      }
            | '(' expr ')'
              { $$ = $2; }
            ;

arg_l       : arg
              {$$ =$1;}
            | arg_l ',' arg
              {$$ = ast_create_node(AST_ARG_LIST,0,$1,$3);}
            ;

arg         : expr
	      {$$ = ast_create_node(AST_ARG,$1->entry->data_type?Float:Int,$1,0);}
            ;
              
array_indices : array_index
                {$$ = ast_create_node(AST_ARRAY_INDEX,0,0,$1);}
              | array_indices array_index
                {$$ = ast_create_node(AST_ARRAY_INDEX,0,$1,$2);}
              ;

array_index : '[' expr ']'
              {
		if($2->entry->data_type != TYPE_INT) {
			yyerror("array index is not an integer\n");
		}
		$$ = $2;}
            ;

%%

#include "lex.yy.c"
