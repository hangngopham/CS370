
#include "mem.h"
#include "hw7symtbl.h"

main()
{
   mem_init();
   symtbl_init();
   ast_init();
   yyparse();
}

