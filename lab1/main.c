#include "input_token.h"
#include "expr.h"
#include "error.h"
#include "BTree.h"

main(int argc, char *argv[])
{  Tree val;
   fpi = fopen( *++argv, "r" );
   val = evaluate_expression();
   //In order traversal
   printf("In-order traversal: ");
   in_order_traversal(val);
   printf("\n");
   
   //Post order traversal
   printf("Post-order traversal: ");
   post_order_traversal(val);
   printf("\n");
   
   //Evaluate expression
   int total = eval(val);
   printf("The integer value evaluated is %d \n", total);
   
}
