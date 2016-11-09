
/**  
 **   process the abstract syntax to generate codes
 ** 
 **/

#include <stdio.h>
#include <stdlib.h>
#include "hw7symtbl.h"
//#include "hw7ast.h"
#define ERROR(msg)  { fprintf(stderr, "%s\n", msg); exit(-1); }

int label = 1;
int return_type;

void printSym( SYMTBL symbol ) {
    printf("%s", symbol->sym_name);
    if (symbol->scope > 1) printf("_%d", symbol->scope);
}

/* you may need to include some auxiliary functions
   that help with printing instructions here */

/*  Traverse the syntax tree and build flow graph */
void traverse_ast(ASTNODE *node, int break_Label, int cont_Label)
{
    SYMTBL temp;

    /* define some additional variables that 
       you need to use here */
int count = label;
    switch(node->type)
      {
        case AST_PROGRAM_LIST:
	  traverse_ast(node->left,break_Label,cont_Label);
	  traverse_ast(node->right,break_Label,cont_Label);
	  break;
        case AST_PROGRAM:
          printf("\n\n     ");
          printf("FUNC ENTRY ");printSym(node->entry);printf("\n");
          return_type = node->entry->data_type;
          if (node->right)
             traverse_ast(node->right,break_Label,cont_Label);
          printf("     FUNC END ");printSym(node->entry);printf("\n");
	  break;
	case AST_LIST:
	  if (node->left)
	     traverse_ast(node->left,break_Label,cont_Label);
	  if (node->right)
	     traverse_ast(node->right,break_Label,cont_Label);
	  break;
        case AST_FUNC_CALL:
          /* to be completed */
	  traverse_ast(node->left,break_Label,cont_Label);
 	  temp=symtbl_new_temp(node->left->entry->data_type);
	  if(temp) {printSym(temp); printf("=");}
	  printf("CALL ");
	  node->entry = temp;
	  break;
        case AST_ARG_LIST:
          /* to be completed */
	  if (node->left)
	     traverse_ast(node->left,break_Label,cont_Label);
	  if (node->right)
	     traverse_ast(node->right,break_Label,cont_Label);
	  break;
        case AST_ARG:
          /* to be completed */
	  if (node->left)
	     traverse_ast(node->left,break_Label,cont_Label);
	  if (node->right)
	     traverse_ast(node->right,break_Label,cont_Label);
	  break;
	case AST_ASSIGN:
          traverse_ast(node->right,break_Label,cont_Label);
          temp = node->right->entry;

          /* may need to do type coercion with corresponding codes generation;
             if type coercion is needed, you need to re-define temp
             to point to the new temp variable created as the 
             result of type coercion.

             also, the left hand side of the assignment statement may be an array reference
          */
          node->entry = temp;
	  break;
        case AST_ARRAY_REF:
          /* to be completed */
		traverse_ast(node->left,break_Label,cont_Label);
		traverse_ast(node->right,break_Label,cont_Label);
	  break;
        case AST_ARRAY_INDEX:
          /* to be completed */
		traverse_ast(node->left,break_Label,cont_Label);
		traverse_ast(node->right,break_Label,cont_Label);
	  break;
        case AST_RETURN:
          if (return_type == TYPE_VOID &&  node->left) ERROR("function type is void but a data is returned");
          if (return_type == TYPE_VOID) { // !node->left 
             printf("     ");
             printf("RETURN\n");
             break;
          }
          traverse_ast(node->left,break_Label,cont_Label);
	  if(return_type == TYPE_FLOAT && node->left->entry->data_type == TYPE_INT) {
		ERROR("function type is int but a float data is returned");
	  }
          /* report an error
              ERROR("function type is int but a float data is returned");
             when there is a type mismatch */
           /* type coercion may be needed before returning the result */

          break;
	case AST_ID:
          temp = symtbl_new_temp(node->entry->data_type);
          printf("     ");printSym(temp);printf(" = ");printSym(node->entry);printf("\n");
          node->entry = temp;
	  break;
        case AST_INT:
          temp = symtbl_new_temp(TYPE_INT);
          printf("     ");printSym(temp);printf(" = ");printSym(node->entry);printf("\n");
          node->entry = temp;
          break;
        case AST_FLOAT:
          temp = symtbl_new_temp(TYPE_FLOAT);
          printf("     ");printSym(temp);printf(" = ");printSym(node->entry);printf("\n");
          node->entry = temp;
          break;
	case AST_ADD:
          traverse_ast(node->left,break_Label,cont_Label);
	  traverse_ast(node->right,break_Label,cont_Label);
          /* type coercion may be needed */
          /* create a new entry for the temp variable
             that holds the addition result */
	  if(node->left->entry->data_type == node->right->entry->data_type) {
		node->entry->data_type = node->left->entry->data_type;
	  }
	  else {
		node->entry->data_type = TYPE_FLOAT;
	  }

	  if(node->left->entry->data_type == TYPE_FLOAT && node->right->entry->data_type == TYPE_INT) {

		temp = symtbl_new_temp(TYPE_FLOAT);
	        printSym(node->left->entry);
		node->left->entry = temp;
	  }
	  if(node->left->entry->data_type == TYPE_INT && node->right->entry->data_type == TYPE_FLOAT) {
		temp = symtbl_new_temp(TYPE_FLOAT);
	        printSym(node->right->entry);
		node->right->entry = temp;
	  }  
	  printf("     ");
	  printSym(node->entry);
	  printf(" = "); printSym(node->left->entry);
	  printf(" + "); printSym(node->right->entry);
	  printf("\n");
	  break;
	case AST_SUB:
          traverse_ast(node->left,break_Label,cont_Label);
	  traverse_ast(node->right,break_Label,cont_Label);
          /* to be completed */
          if(node->left->entry->data_type == node->right->entry->data_type) {
		node->entry->data_type = node->left->entry->data_type;
	  }
	  else {
		node->entry->data_type = TYPE_FLOAT;
	  }

	  if(node->left->entry->data_type == TYPE_FLOAT && node->right->entry->data_type == TYPE_INT) {

		temp = symtbl_new_temp(TYPE_FLOAT);
	        printSym(node->left->entry);
		node->left->entry = temp;
	  }
	  if(node->left->entry->data_type == TYPE_INT && node->right->entry->data_type == TYPE_FLOAT) {
		temp = symtbl_new_temp(TYPE_FLOAT);
	        printSym(node->right->entry);
		node->right->entry = temp;
	  }  
	  printf("     ");
	  printSym(node->entry);
	  printf(" = "); printSym(node->left->entry);
	  printf(" - "); printSym(node->right->entry);
	  printf("\n");
          break;
	case AST_MUL:
          traverse_ast(node->left,break_Label,cont_Label);
	  traverse_ast(node->right,break_Label,cont_Label);
          /* to be completed */
          if(node->left->entry->data_type == node->right->entry->data_type) {
		node->entry->data_type = node->left->entry->data_type;
	  }
	  else {
		node->entry->data_type = TYPE_FLOAT;
	  }

	  if(node->left->entry->data_type == TYPE_FLOAT && node->right->entry->data_type == TYPE_INT) {

		temp = symtbl_new_temp(TYPE_FLOAT);
	        printSym(node->left->entry);
		node->left->entry = temp;
	  }
	  if(node->left->entry->data_type == TYPE_INT && node->right->entry->data_type == TYPE_FLOAT) {
		temp = symtbl_new_temp(TYPE_FLOAT);
	        printSym(node->right->entry);
		node->right->entry = temp;
	  }  
	  printf("     ");
	  printSym(node->entry);
	  printf(" = "); printSym(node->left->entry);
	  printf(" * "); printSym(node->right->entry);
	  printf("\n");
          break;
	case AST_DIV:
          traverse_ast(node->left,break_Label,cont_Label);
	  traverse_ast(node->right,break_Label,cont_Label);
          /* to be completed */
	  if(node->left->entry->data_type == node->right->entry->data_type) {
		node->entry->data_type = node->left->entry->data_type;
	  }
	  else {
		node->entry->data_type = TYPE_FLOAT;
	  }

	  if(node->left->entry->data_type == TYPE_FLOAT && node->right->entry->data_type == TYPE_INT) {

		temp = symtbl_new_temp(TYPE_FLOAT);
	        printSym(node->left->entry);
		node->left->entry = temp;
	  }
	  if(node->left->entry->data_type == TYPE_INT && node->right->entry->data_type == TYPE_FLOAT) {
		temp = symtbl_new_temp(TYPE_FLOAT);
	        printSym(node->right->entry);
		node->right->entry = temp;
	  }  
	  printf("     ");
	  printSym(node->entry);
	  printf(" = "); printSym(node->left->entry);
	  printf(" / "); printSym(node->right->entry);
	  printf("\n");
          break;
	case AST_MOD:
          traverse_ast(node->left,break_Label,cont_Label);
	  traverse_ast(node->right,break_Label,cont_Label);
          /* both the left and right operands should be of integer type */
          /* to be completed */
	  
          break;
	case AST_UMINUS:
          traverse_ast(node->left,break_Label,cont_Label);
          /* to be completed */
	  printf(" - ");
	  temp = symtbl_new_temp(node->left->entry->data_type);
	  break;
	case AST_AND:
          /* both the left and right operands should be of integer type */
          /* need to implement the short-circuit logic */ 
          /* need to generate branch statement, and introduce new label
             as target of the branch statement */
	  traverse_ast(node->left, break_Label,cont_Label);
	  if(node->left->entry->data_type == TYPE_FLOAT) {
	
          }
	  traverse_ast(node->right,break_Label,cont_Label);
// Check with 0	
  break;
	case AST_OR:
          /* both the left and right operands should be of integer type */
          /* need to implement the short-circuit logic */ 
          /* need to generate branch statement, and introduce new label
             as target of the branch statement */
	  traverse_ast(node->left, break_Label,cont_Label);
	  traverse_ast(node->right,break_Label,cont_Label);
          break;
	case AST_NOT:
          /* to be completed */
          traverse_ast(node->left,break_Label,cont_Label);
	  break;
	case AST_LT:
          traverse_ast(node->left,break_Label,cont_Label);
	  traverse_ast(node->right,break_Label,cont_Label);
          /* to be completed */
          break;
	case AST_GT:
          traverse_ast(node->left,break_Label,cont_Label);
	  traverse_ast(node->right,break_Label,cont_Label);
          /* to be completed */
          break;
	case AST_EQ:
          traverse_ast(node->left,break_Label,cont_Label);
	  traverse_ast(node->right,break_Label,cont_Label);
          /* to be completed */
          break;
	case AST_IF_THEN:
          traverse_ast(node->left,break_Label,cont_Label);
          /* need to generate branch statement, and introduce new label
             as target of the branch statement */
	  traverse_ast(node->right,break_Label,cont_Label);
          /* to be completed */
	  break;
        case AST_IF_ELSE:
          /* to be completed */
	  traverse_ast(node->left,break_Label,cont_Label);
	  count++;
          break;
        case AST_COND_EXP:
          /* the logic involved relates to that for
             handling IF-THEN-ELSE statement,
             and that for handling the expression that appears
             the right hand side of an assignment statement. */
	  traverse_ast(node->left,break_Label,cont_Label);
	  count++;
          break;
        case AST_WHILE:
          /* to be completed */
	  traverse_ast(node->left,break_Label,cont_Label);
	  traverse_ast(node->right,break_Label,cont_Label);
	  count++;
          break;
        case AST_BREAK:
          if (!break_Label) ERROR("break: no matching while statement");
          printf("goto %d\n",break_Label);
          break; 
        case AST_CONTINUE:
          if (!cont_Label) ERROR("continue: no matching while statement");
          printf("goto %d\n",cont_Label);
          break;  
        case AST_ARRAY_DIMS:
        case AST_ARRAY_DECL:
          break;
	default:
	  ERROR("Unknown AST node");
      }
}

main()
{
   mem_init();
   symtbl_init();
   ast_init();
   yyparse();
   traverse_ast(ast_root,0,0);
   symtbl_dump_all();
}

