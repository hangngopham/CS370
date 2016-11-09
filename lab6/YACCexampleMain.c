
#include "mem.h"
#include "symtbl.h"
#include "ast.h"

main()
{
   mem_init();
   symtbl_init();
   ast_init();
   yyparse();
}

