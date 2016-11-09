
#include "hw7ast.h"

/**
 **    Interface to the symbol table manager
 **/

typedef struct SYMTBL_ENTRY
{
    struct SYMTBL_ENTRY  *next;       /* link entries with the same hash values */
    struct SYMTBL_ENTRY  *scope_link; /* link entries according to scope level;
                                         exception: entries with scope level < 3 
                                         are not linked */
    char                 *sym_name;

    ASTNODE              *ast_link;       /* defined if entry is the name of a function when scope is 1 
                                                     in that case, link to list of parameters
                                             defined if symbol is an array; link to list of array dimensions 
                                             otherwise ast_link is NULL */

    int                   sym_type;
    int                   data_type;
    int                   scope;      /* scope level number that the symbol is in */ 
    int                   in_scope;   /* FALSE  if the symbol is not active
                                         TRUE   if the symbol is in scope   */
} SYMENTRY;

typedef SYMENTRY *SYMTBL;

SYMTBL Int;
SYMTBL Float;

/* symbol types */
#define SYMBOL_ID       0
#define SYMBOL_NUM      1
#define SYMBOL_FUNC     2
#define SYMBOL_PARA     3
#define SYMBOL_TEMP     4

/* data types */
#define TYPE_VOID      -1
#define TYPE_INT        0
#define TYPE_FLOAT      1 

void symtbl_init();              /* initialize symbol table */
void symtbl_dump_current();   /* print out all current symbol table entries */
void symtbl_dump_all();       /* print out all symbol table entries 
                                          (including entries that are not current) */
SYMTBL symtbl_install(char *sym, int stype, int dtype, int scope); /* find or create entry */
SYMTBL symtbl_lookup(char *sym);  /* lookup a symbolic name */
SYMTBL symtbl_new_temp(int dtype); /* create a new temp var */
void   symtbl_finalizeScope(); /* set variables in current scope level inactive */

