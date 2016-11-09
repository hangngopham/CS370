/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 2 "hw7parser.y"

#include "hw7symtbl.h"
#include <stdlib.h>
#include <stdio.h>

int data_type; 
int current_scope = 1;

void  yyerror(char  *s)  { fprintf(stderr,  "%s\n",  s); exit(-1); }

void matchArgPara(ASTNODE *arg, ASTNODE *par) {
   if (arg->entry->data_type != par->entry->data_type) yyerror("argument type and parameter type mismatch");
   if (arg->left->type == AST_ID && !(arg->left->entry->ast_link) && !par->left) return; 
   if (arg->left->type == AST_ID &&   arg->left->entry->ast_link  &&  par->left) return; 
   if (arg->left->type != AST_ID                                  && !par->left) return;
   yyerror("argument and parameter mismatch; one is an array, the other is not");
}

void matchFuncRefs(ASTNODE *arg, ASTNODE *par) { 
   if (arg->type==AST_ARG && par->type==AST_PARA_LIST) yyerror("func call has wrong number of arguments"); 
   if (arg->type==AST_ARG_LIST && par->type==AST_PARA) yyerror("func call has wrong number of arguments"); 
   if (arg->type==AST_ARG      && par->type==AST_PARA) {matchArgPara(arg,par); return;}
   matchArgPara(arg->right, par->right);
   matchFuncRefs(arg->left, par->left);
}

void matchArrayRefs( ASTNODE *ref, ASTNODE *def ) {
   if (!ref && !def) return;
   if ( ref && !def) yyerror("array ref has different dimension as declared\n"); 
   if (!ref &&  def) yyerror("array ref has different dimension as declared\n");
   ref->entry =  def->entry;
   matchArrayRefs(ref->left, def->left);
}


/* Line 371 of yacc.c  */
#line 104 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VOID = 258,
     BREAK = 259,
     CONTINUE = 260,
     IF = 261,
     ELSE = 262,
     FLOAT = 263,
     INT = 264,
     RETURN = 265,
     WHILE = 266,
     OR = 267,
     AND = 268,
     EQ = 269,
     ID = 270,
     INTdenotation = 271,
     FLOATdenotation = 272
   };
#endif
/* Tokens.  */
#define VOID 258
#define BREAK 259
#define CONTINUE 260
#define IF 261
#define ELSE 262
#define FLOAT 263
#define INT 264
#define RETURN 265
#define WHILE 266
#define OR 267
#define AND 268
#define EQ 269
#define ID 270
#define INTdenotation 271
#define FLOATdenotation 272



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 38 "hw7parser.y"

        SYMTBL       entry;
        char        *name;
	ASTNODE     *node;


/* Line 387 of yacc.c  */
#line 185 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 213 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   272

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,     2,     2,    35,     2,     2,
      18,    19,    33,    31,    20,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    28,    23,
      29,    24,    30,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    21,     2,    22,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    14,    22,    23,
      24,    33,    35,    37,    41,    44,    48,    51,    54,    57,
      61,    64,    69,    73,    78,    82,    88,    90,    93,    97,
      99,   101,   102,   108,   112,   115,   117,   120,   122,   130,
     136,   142,   145,   148,   151,   155,   158,   160,   164,   169,
     171,   173,   179,   181,   185,   187,   191,   193,   197,   199,
     203,   207,   209,   213,   217,   219,   223,   227,   231,   233,
     236,   239,   241,   243,   245,   250,   253,   257,   259,   263,
     265,   267,   270
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    39,    -1,    48,    39,    -1,    40,    -1,
      39,    40,    -1,    -1,    52,    44,    18,    45,    19,    41,
      53,    -1,    -1,    -1,     3,    42,    44,    18,    45,    19,
      43,    53,    -1,    15,    -1,    46,    -1,    45,    20,    46,
      -1,    52,    15,    -1,    52,    15,    47,    -1,    21,    22,
      -1,    47,    51,    -1,    49,    23,    -1,    48,    49,    23,
      -1,    52,    15,    -1,    52,    15,    24,    57,    -1,    52,
      15,    50,    -1,    49,    20,    15,    50,    -1,    49,    20,
      15,    -1,    49,    20,    15,    24,    57,    -1,    51,    -1,
      50,    51,    -1,    21,    16,    22,    -1,     9,    -1,     8,
      -1,    -1,    25,    54,    48,    55,    26,    -1,    25,    55,
      26,    -1,    25,    26,    -1,    56,    -1,    55,    56,    -1,
      53,    -1,     6,    18,    57,    19,    56,     7,    56,    -1,
       6,    18,    57,    19,    56,    -1,    11,    18,    57,    19,
      56,    -1,     4,    23,    -1,     5,    23,    -1,    10,    23,
      -1,    10,    57,    23,    -1,    57,    23,    -1,    23,    -1,
      15,    24,    57,    -1,    15,    69,    24,    57,    -1,    58,
      -1,    59,    -1,    59,    27,    57,    28,    58,    -1,    60,
      -1,    59,    12,    60,    -1,    61,    -1,    60,    13,    61,
      -1,    62,    -1,    62,    14,    62,    -1,    63,    -1,    63,
      29,    63,    -1,    63,    30,    63,    -1,    64,    -1,    63,
      31,    64,    -1,    63,    32,    64,    -1,    65,    -1,    64,
      33,    65,    -1,    64,    34,    65,    -1,    64,    35,    65,
      -1,    66,    -1,    36,    65,    -1,    32,    65,    -1,    16,
      -1,    17,    -1,    15,    -1,    15,    18,    67,    19,    -1,
      15,    69,    -1,    18,    57,    19,    -1,    68,    -1,    67,
      20,    68,    -1,    57,    -1,    70,    -1,    69,    70,    -1,
      21,    57,    22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    57,    57,    64,    73,    75,    79,    79,    86,    86,
      86,    95,   102,   104,   108,   114,   123,   125,   129,   131,
     135,   141,   151,   158,   166,   172,   185,   187,   191,   198,
     200,   205,   204,   214,   216,   220,   222,   226,   228,   231,
     233,   235,   237,   239,   241,   243,   245,   249,   261,   274,
     278,   280,   289,   291,   301,   303,   313,   315,   322,   324,
     329,   336,   338,   343,   350,   352,   357,   362,   371,   373,
     378,   384,   389,   394,   400,   407,   415,   419,   421,   425,
     429,   431,   435
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "BREAK", "CONTINUE", "IF",
  "ELSE", "FLOAT", "INT", "RETURN", "WHILE", "OR", "AND", "EQ", "ID",
  "INTdenotation", "FLOATdenotation", "'('", "')'", "','", "'['", "']'",
  "';'", "'='", "'{'", "'}'", "'?'", "':'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "$accept", "programs", "program_l",
  "program", "$@1", "$@2", "$@3", "programID", "para_decl_l", "para_decl",
  "para_dims", "var_decl_l", "var_decl", "array_dims", "array_dim",
  "type_spec", "compound", "$@4", "stmnt_list", "stmnt", "expr", "cond",
  "disjunction", "conjunction", "comparison", "relation", "sum", "term",
  "factor", "primary", "arg_l", "arg", "array_indices", "array_index", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    40,    41,
      44,    91,    93,    59,    61,   123,   125,    63,    58,    60,
      62,    43,    45,    42,    47,    37,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    41,    40,    42,    43,
      40,    44,    45,    45,    46,    46,    47,    47,    48,    48,
      49,    49,    49,    49,    49,    49,    50,    50,    51,    52,
      52,    54,    53,    53,    53,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    62,
      62,    63,    63,    63,    64,    64,    64,    64,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      69,    69,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     0,     7,     0,     0,
       8,     1,     1,     3,     2,     3,     2,     2,     2,     3,
       2,     4,     3,     4,     3,     5,     1,     2,     3,     1,
       1,     0,     5,     3,     2,     1,     2,     1,     7,     5,
       5,     2,     2,     2,     3,     2,     1,     3,     4,     1,
       1,     5,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     1,     1,     1,     4,     2,     3,     1,     3,     1,
       1,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,    30,    29,     0,     2,     4,     0,     0,     0,
       0,     1,     5,     0,     3,     0,     0,    18,    20,     0,
      11,     0,    19,    24,     0,     0,    22,    26,     0,     0,
       0,    23,     0,    73,    71,    72,     0,     0,     0,    21,
      49,    50,    52,    54,    56,    58,    61,    64,    68,    27,
       0,    12,     0,     0,    25,    28,     0,     0,     0,    75,
      80,     0,    73,    70,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     0,    14,     9,
      79,     0,    77,     0,    47,     0,    81,    76,    75,    53,
       0,    55,    57,    59,    60,    62,    63,    65,    66,    67,
       0,    13,     0,    15,     0,    74,     0,    82,    48,     0,
      31,     7,    16,    17,    10,    78,    51,     0,     0,     0,
       0,     0,    46,    34,    37,     0,     0,    35,     0,    41,
      42,     0,    43,     0,     0,     0,     0,    33,    36,    45,
       0,    44,     0,     0,    20,     0,     0,    32,    39,    40,
       0,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,   100,    10,   104,    19,    50,    51,
     103,     7,     8,    26,    27,    52,   124,   125,   126,   127,
     128,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      81,    82,    59,    60
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -121
static const yytype_int16 yypact[] =
{
      24,  -121,  -121,  -121,    16,    24,  -121,    24,    21,     9,
      14,  -121,  -121,    14,    24,    46,    25,  -121,    58,     4,
    -121,    34,  -121,    62,    26,     2,    38,  -121,    49,    49,
       2,    38,    43,    96,  -121,  -121,     2,    57,    57,  -121,
    -121,     1,    54,  -121,    64,    76,   108,  -121,  -121,  -121,
     104,  -121,    56,   111,  -121,  -121,     2,     2,     2,    63,
    -121,    69,    77,  -121,  -121,    57,     2,    57,    57,    57,
      57,    57,    57,    57,    57,    57,  -121,    49,    73,  -121,
    -121,   133,  -121,    78,  -121,     2,  -121,  -121,    94,    54,
      93,  -121,  -121,   134,   134,   108,   108,  -121,  -121,  -121,
     109,  -121,   114,    38,   109,  -121,     2,  -121,  -121,    57,
      86,  -121,  -121,  -121,  -121,  -121,  -121,   121,   123,   139,
     179,   141,  -121,  -121,  -121,    49,   122,  -121,   144,  -121,
    -121,     2,  -121,   146,     2,    45,   149,  -121,  -121,  -121,
     161,  -121,   163,   145,    95,   168,   168,  -121,   182,  -121,
     168,  -121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,   183,     7,  -121,  -121,  -121,   188,   170,   115,
    -121,    80,    -6,   178,   -23,     0,   -61,  -121,    68,  -120,
     -21,    97,  -121,   142,   143,   140,   106,   116,   -27,  -121,
    -121,   103,   150,   -57
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -12
static const yytype_int16 yytable[] =
{
       9,    15,    86,    49,    39,    13,   138,     9,    49,    54,
      63,    64,    12,    65,    13,    61,    11,    33,    34,    35,
      36,    12,    28,   138,    18,   148,   149,     1,    66,    20,
     151,    86,     2,     3,    37,    80,    83,    84,    38,   111,
      23,    16,    32,   114,    17,    90,    97,    98,    99,   117,
     118,   119,    29,     2,     3,   120,   121,     2,     3,    24,
      33,    34,    35,    36,   108,    55,    16,    67,   122,    22,
     110,    78,    62,    34,    35,    36,   -11,    37,    68,    24,
     113,    38,    25,    24,    57,    80,    30,    85,    87,    37,
     117,   118,   119,    38,   102,    56,   120,   121,    57,   133,
     107,    33,    34,    35,    36,    69,    70,    71,    72,   122,
     140,   110,   123,   142,    56,    57,    24,    57,    37,    25,
      58,   109,    38,    76,    77,   136,   117,   118,   119,    15,
      79,    77,   120,   121,   110,   136,   112,    33,    34,    35,
      36,    73,    74,    75,   129,   122,   130,   110,   137,   117,
     118,   119,   105,   106,    37,   120,   121,   131,    38,   134,
      33,    34,    35,    36,   144,    71,    72,   139,   122,   141,
     110,   147,   117,   118,   119,    93,    94,    37,   120,   121,
     145,    38,   146,    33,    34,    35,    36,    95,    96,   150,
      14,   122,   101,   110,    33,    34,    35,    36,    21,    53,
      37,    31,   132,   143,    38,   135,   116,    89,    92,   115,
      91,    37,    88,     0,     0,    38
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-121)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,     7,    59,    26,    25,     5,   126,     7,    31,    30,
      37,    38,     5,    12,    14,    36,     0,    15,    16,    17,
      18,    14,    18,   143,    15,   145,   146,     3,    27,    15,
     150,    88,     8,     9,    32,    56,    57,    58,    36,   100,
      15,    20,    16,   104,    23,    66,    73,    74,    75,     4,
       5,     6,    18,     8,     9,    10,    11,     8,     9,    21,
      15,    16,    17,    18,    85,    22,    20,    13,    23,    23,
      25,    15,    15,    16,    17,    18,    18,    32,    14,    21,
     103,    36,    24,    21,    21,   106,    24,    24,    19,    32,
       4,     5,     6,    36,    21,    18,    10,    11,    21,   120,
      22,    15,    16,    17,    18,    29,    30,    31,    32,    23,
     131,    25,    26,   134,    18,    21,    21,    21,    32,    24,
      24,    28,    36,    19,    20,   125,     4,     5,     6,   135,
      19,    20,    10,    11,    25,   135,    22,    15,    16,    17,
      18,    33,    34,    35,    23,    23,    23,    25,    26,     4,
       5,     6,    19,    20,    32,    10,    11,    18,    36,    18,
      15,    16,    17,    18,    15,    31,    32,    23,    23,    23,
      25,    26,     4,     5,     6,    69,    70,    32,    10,    11,
      19,    36,    19,    15,    16,    17,    18,    71,    72,     7,
       7,    23,    77,    25,    15,    16,    17,    18,    10,    29,
      32,    23,    23,   135,    36,   125,   109,    65,    68,   106,
      67,    32,    62,    -1,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     8,     9,    38,    39,    40,    48,    49,    52,
      42,     0,    40,    52,    39,    49,    20,    23,    15,    44,
      15,    44,    23,    15,    21,    24,    50,    51,    18,    18,
      24,    50,    16,    15,    16,    17,    18,    32,    36,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    51,
      45,    46,    52,    45,    57,    22,    18,    21,    24,    69,
      70,    57,    15,    65,    65,    12,    27,    13,    14,    29,
      30,    31,    32,    33,    34,    35,    19,    20,    15,    19,
      57,    67,    68,    57,    57,    24,    70,    19,    69,    60,
      57,    61,    62,    63,    63,    64,    64,    65,    65,    65,
      41,    46,    21,    47,    43,    19,    20,    22,    57,    28,
      25,    53,    22,    51,    53,    68,    58,     4,     5,     6,
      10,    11,    23,    26,    53,    54,    55,    56,    57,    23,
      23,    18,    23,    57,    18,    48,    52,    26,    56,    23,
      57,    23,    57,    55,    15,    19,    19,    26,    56,    56,
       7,    56
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 58 "hw7parser.y"
    { ast_root = (yyvsp[(1) - (1)].node); 
                symtbl_dump_current();
                printf("\n\n");
                ast_dump();
                printf("\n\n"); 
              }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 65 "hw7parser.y"
    { ast_root = ast_create_node(AST_LIST, 0, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); 
                symtbl_dump_current();
                printf("\n\n");
                ast_dump();
                printf("\n\n"); 
              }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 74 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 76 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_PROGRAM_LIST, 0, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 79 "hw7parser.y"
    {(yyvsp[(2) - (5)].entry)->ast_link = (yyvsp[(4) - (5)].node); current_scope = 2;}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 80 "hw7parser.y"
    {
                (yyval.node) = ast_create_node(AST_PROGRAM, (yyvsp[(2) - (7)].entry), (yyvsp[(4) - (7)].node), (yyvsp[(7) - (7)].node));
                ast_dump_subtree((yyval.node));
                printf("\n\n");
                symtbl_finalizeScope();
              }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 86 "hw7parser.y"
    { data_type = TYPE_VOID; }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 86 "hw7parser.y"
    {(yyvsp[(3) - (6)].entry)->ast_link = (yyvsp[(5) - (6)].node); current_scope = 2;}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 87 "hw7parser.y"
    {
                (yyval.node) = ast_create_node(AST_PROGRAM, (yyvsp[(3) - (8)].entry), (yyvsp[(5) - (8)].node), (yyvsp[(8) - (8)].node));
                ast_dump_subtree((yyval.node));
                printf("\n\n");
                symtbl_finalizeScope();
              }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 96 "hw7parser.y"
    { SYMTBL entry = symtbl_lookup((yyvsp[(1) - (1)].name));
                if ((entry) && (entry->sym_type==SYMBOL_FUNC)) yyerror("function already defined\n");
                (yyval.entry) = symtbl_install((yyvsp[(1) - (1)].name),SYMBOL_FUNC,data_type,1); 
              }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 103 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 105 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_PARA_LIST, 0, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 109 "hw7parser.y"
    { SYMTBL entry = symtbl_lookup((yyvsp[(2) - (2)].name));
                if ((entry) && (entry->scope==2)) yyerror("parameter already defined\n"); 
                (yyval.node) = ast_create_node(AST_PARA, 
                     symtbl_install((yyvsp[(2) - (2)].name), SYMBOL_PARA, data_type,2), 0, 0); 
              }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 115 "hw7parser.y"
    { SYMTBL entry = symtbl_lookup((yyvsp[(2) - (3)].name));
                if ((entry) && (entry->scope==2)) yyerror("parameter already defined\n"); 
                entry = symtbl_install((yyvsp[(2) - (3)].name), SYMBOL_PARA, data_type, 2);
                entry->ast_link = (yyvsp[(3) - (3)].node);
                (yyval.node) = ast_create_node(AST_PARA, entry, (yyvsp[(3) - (3)].node), 0); 
              }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 124 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_ARRAY_DIMS, 0,  0, 0); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 126 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_ARRAY_DIMS, (yyvsp[(2) - (2)].entry), (yyvsp[(1) - (2)].node), 0); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 130 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 132 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_LIST, 0, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node)); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 136 "hw7parser.y"
    { SYMTBL entry = symtbl_lookup((yyvsp[(2) - (2)].name));
                if ((entry) && (entry->scope==current_scope)) yyerror("variable name already defined\n");
                symtbl_install((yyvsp[(2) - (2)].name), SYMBOL_ID, data_type, current_scope);
                (yyval.node) = 0;
              }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 142 "hw7parser.y"
    { if ((yyvsp[(4) - (4)].node)->entry->data_type == TYPE_VOID) yyerror("a function call that returns void cannot be on the right hand side of an assignment statement\n");
                SYMTBL entry = symtbl_lookup((yyvsp[(2) - (4)].name));
                if ((entry) && (entry->scope==current_scope)) yyerror("variable name already defined\n");
                entry= symtbl_install((yyvsp[(2) - (4)].name), SYMBOL_ID, data_type, current_scope);
                if (!entry->ast_link && (yyvsp[(4) - (4)].node)->type == AST_ID && (yyvsp[(4) - (4)].node)->entry->ast_link) yyerror("assignment of an array to a non-array  variable"); 
                if (entry->data_type==TYPE_INT && (yyvsp[(4) - (4)].node)->entry->data_type==TYPE_FLOAT) yyerror("cannot assign a float value to an integer variable\n");
                (yyval.node) = ast_create_node(AST_ASSIGN, entry->data_type?Float:Int,
                     ast_create_node(AST_ID, entry, 0, 0), (yyvsp[(4) - (4)].node));
              }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 152 "hw7parser.y"
    { SYMTBL entry = symtbl_lookup((yyvsp[(2) - (3)].name));
                if ((entry) && (entry->scope==current_scope)) yyerror("variable name already defined\n");
                entry = symtbl_install((yyvsp[(2) - (3)].name), SYMBOL_ID, data_type, current_scope);
                entry->ast_link = (yyvsp[(3) - (3)].node);
                (yyval.node) = ast_create_node(AST_ARRAY_DECL, entry, (yyvsp[(3) - (3)].node), 0);
              }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 159 "hw7parser.y"
    { SYMTBL entry = symtbl_lookup((yyvsp[(3) - (4)].name));
                if ((entry) && (entry->scope==current_scope)) yyerror("variable name already defined\n");
                entry = symtbl_install((yyvsp[(3) - (4)].name), SYMBOL_ID, data_type, current_scope);
                entry->ast_link = (yyvsp[(4) - (4)].node);
                (yyval.node) = ast_create_node(AST_LIST, 0, (yyvsp[(1) - (4)].node), 
                     ast_create_node(AST_ARRAY_DECL, entry, (yyvsp[(4) - (4)].node), 0));
              }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 167 "hw7parser.y"
    { SYMTBL entry = symtbl_lookup((yyvsp[(3) - (3)].name));
                if ((entry) && (entry->scope==current_scope)) yyerror("variable name already defined\n");
                symtbl_install((yyvsp[(3) - (3)].name), SYMBOL_ID, data_type, current_scope);
                (yyval.node) = (yyvsp[(1) - (3)].node);
              }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 173 "hw7parser.y"
    { if ((yyvsp[(5) - (5)].node)->entry->data_type == TYPE_VOID) yyerror("a function call that returns void cannot be on the right hand side of an assignment statement\n");
                SYMTBL entry = symtbl_lookup((yyvsp[(3) - (5)].name));
                if ((entry) && (entry->scope==current_scope)) yyerror("variable name already defined\n");
                entry= symtbl_install((yyvsp[(3) - (5)].name), SYMBOL_ID, data_type, current_scope);
                if (!entry->ast_link && (yyvsp[(5) - (5)].node)->type == AST_ID && (yyvsp[(5) - (5)].node)->entry->ast_link) yyerror("assignment of an array to a non-array  variable"); 
                if (entry->data_type==TYPE_INT && (yyvsp[(5) - (5)].node)->entry->data_type==TYPE_FLOAT) yyerror("cannot assign a float value to an integer variable\n");
                (yyval.node) = ast_create_node(AST_LIST, 0, (yyvsp[(1) - (5)].node), 
                     ast_create_node(AST_ASSIGN, entry->data_type?Float:Int, 
                     ast_create_node(AST_ID, entry, 0, 0), (yyvsp[(5) - (5)].node)));
              }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 186 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_ARRAY_DIMS, (yyvsp[(1) - (1)].entry),  0, 0); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 188 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_ARRAY_DIMS, (yyvsp[(2) - (2)].entry), (yyvsp[(1) - (2)].node), 0); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 192 "hw7parser.y"
    { SYMTBL entry = symtbl_lookup((yyvsp[(2) - (3)].name));
                if (!entry) entry = symtbl_install((yyvsp[(2) - (3)].name),SYMBOL_NUM,TYPE_INT,0); 
                (yyval.entry) = entry; 
              }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 199 "hw7parser.y"
    { data_type = TYPE_INT; }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 201 "hw7parser.y"
    { data_type = TYPE_FLOAT; }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 205 "hw7parser.y"
    { current_scope++; }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 207 "hw7parser.y"
    {
                 (yyval.node) = ast_create_node(AST_LIST, 0, (yyvsp[(3) - (5)].node), (yyvsp[(4) - (5)].node));
                 symtbl_dump_current();
                 printf("\n\n");
                 symtbl_finalizeScope();
                 current_scope--; 
               }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 215 "hw7parser.y"
    {  (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 217 "hw7parser.y"
    {  (yyval.node) = 0;  }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 221 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 223 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_LIST, 0, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 227 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 229 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_IF_ELSE,   0, (yyvsp[(3) - (7)].node), 
                     ast_create_node(AST_TWO_SIDED, 0, (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node))); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 232 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_IF_THEN,   0, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)) ; }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 234 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_WHILE,     0, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)) ; }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 236 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_BREAK,     0,  0,  0) ; }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 238 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_CONTINUE,  0,  0,  0) ; }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 240 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_RETURN,    0,  0,  0) ; }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 242 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_RETURN,    0, (yyvsp[(2) - (3)].node),  0) ; }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 244 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 246 "hw7parser.y"
    { (yyval.node) = 0; }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 250 "hw7parser.y"
    { 
                if ((yyvsp[(3) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("a function call that returns void cannot be on the right hand side of an assignment statement\n"); 
                SYMTBL entry = symtbl_lookup((yyvsp[(1) - (3)].name));
                if (!entry) yyerror("identifier undefined\n");
                if (entry->sym_type==SYMBOL_FUNC) yyerror("identifier name is a function name\n"); 
                if (!entry->ast_link && (yyvsp[(3) - (3)].node)->type == AST_ID && (yyvsp[(3) - (3)].node)->entry->ast_link) yyerror("assignment of an array to a non-array  variable"); 
                if (entry->ast_link) yyerror("assignment of a value to an array\n"); 
                if (entry->data_type==TYPE_INT && (yyvsp[(3) - (3)].node)->entry->data_type==TYPE_FLOAT) yyerror("cannot assign a float value to an integer variable\n"); 
                (yyval.node) = ast_create_node(AST_ASSIGN, entry->data_type?Float:Int, 
                     ast_create_node(AST_ID, entry, 0, 0), (yyvsp[(3) - (3)].node)); 
              }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 262 "hw7parser.y"
    { 
                if ((yyvsp[(4) - (4)].node)->entry->data_type == TYPE_VOID) yyerror("a function call that returns void cannot be on the right hand side of an assignment statement\n"); 
                SYMTBL entry = symtbl_lookup((yyvsp[(1) - (4)].name));
                if (!entry) yyerror("identifier undefined\n");
                if (entry->sym_type==SYMBOL_FUNC) yyerror("identifier name is a function name\n");
                if (!entry->ast_link) yyerror("identifier name is not an array\n"); 
                if (!entry->ast_link && (yyvsp[(4) - (4)].node)->type == AST_ID && (yyvsp[(4) - (4)].node)->entry->ast_link) yyerror("assignment of an array to a non-array  variable"); 
                if (entry->data_type==TYPE_INT && (yyvsp[(4) - (4)].node)->entry->data_type==TYPE_FLOAT) yyerror("cannot assign a float value to an integer variable\n"); 
                matchArrayRefs((yyvsp[(2) - (4)].node),entry->ast_link);
                (yyval.node) = ast_create_node(AST_ASSIGN, entry->data_type?Float:Int,
                     ast_create_node(AST_ARRAY_REF, entry, (yyvsp[(2) - (4)].node), 0), (yyvsp[(4) - (4)].node)); 
              }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 275 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 279 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 281 "hw7parser.y"
    { 
                if ((yyvsp[(1) - (5)].node)->entry->data_type == TYPE_VOID) yyerror("conditional exp cannot apply to a function that returns void\n"); 
                if ((yyvsp[(3) - (5)].node)->entry->data_type == TYPE_VOID) yyerror("conditional exp cannot apply to a function that returns void\n"); 
                if ((yyvsp[(5) - (5)].node)->entry->data_type == TYPE_VOID) yyerror("conditional exp cannot apply to a function that returns void\n"); 
                (yyval.node) = ast_create_node(AST_COND_EXP, (yyvsp[(3) - (5)].node)->entry->data_type||(yyvsp[(5) - (5)].node)->entry->data_type?Float:Int, (yyvsp[(1) - (5)].node), 
                     ast_create_node(AST_ALT,      (yyvsp[(3) - (5)].node)->entry->data_type||(yyvsp[(5) - (5)].node)->entry->data_type?Float:Int, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node))); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 290 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 292 "hw7parser.y"
    { 
                if ((yyvsp[(1) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("|| cannot apply to a function that returns void\n"); 
                if ((yyvsp[(3) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("|| cannot apply to a function that returns void\n"); 
                if ((yyvsp[(1) - (3)].node)->entry->data_type != TYPE_INT) yyerror("|| can only apply to integer type\n"); 
                if ((yyvsp[(3) - (3)].node)->entry->data_type != TYPE_INT) yyerror("|| can only apply to integer type\n"); 
                (yyval.node) = ast_create_node(AST_OR, Int, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) ; 
              }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 302 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 304 "hw7parser.y"
    { 
                if ((yyvsp[(1) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("&& cannot apply to a function that returns void\n"); 
                if ((yyvsp[(3) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("&& cannot apply to a function that returns void\n"); 
                if ((yyvsp[(1) - (3)].node)->entry->data_type != TYPE_INT) yyerror("&& can only apply to integer type\n"); 
                if ((yyvsp[(3) - (3)].node)->entry->data_type != TYPE_INT) yyerror("&& can only apply to integer type\n"); 
                (yyval.node) = ast_create_node(AST_AND, Int, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) ; 
              }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 314 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 316 "hw7parser.y"
    { 
                if ((yyvsp[(1) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("relational operator cannot apply to a function that returns void\n"); 
                if ((yyvsp[(3) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("relational operator cannot apply to a function that returns void\n"); 
                (yyval.node) = ast_create_node(AST_EQ, Int, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) ; }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 323 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 325 "hw7parser.y"
    { 
                if ((yyvsp[(1) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("< cannot apply to a function that returns void\n"); 
                if ((yyvsp[(3) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("< cannot apply to a function that returns void\n"); 
                (yyval.node) = ast_create_node(AST_LT, Int, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) ; }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 330 "hw7parser.y"
    { 
                if ((yyvsp[(1) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("> cannot apply to a function that returns void\n"); 
                if ((yyvsp[(3) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("> cannot apply to a function that returns void\n"); 
                (yyval.node) = ast_create_node(AST_GT, Int, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) ; }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 337 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 339 "hw7parser.y"
    { 
                if ((yyvsp[(1) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("+ cannot apply to a function that returns void\n"); 
                if ((yyvsp[(3) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("+ cannot apply to a function that returns void\n"); 
                (yyval.node) = ast_create_node(AST_ADD, (yyvsp[(1) - (3)].node)->entry->data_type||(yyvsp[(3) - (3)].node)->entry->data_type?Float:Int, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 344 "hw7parser.y"
    { 
                if ((yyvsp[(1) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("- cannot apply to a function that returns void\n"); 
                if ((yyvsp[(3) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("- cannot apply to a function that returns void\n"); 
                (yyval.node) = ast_create_node(AST_SUB, (yyvsp[(1) - (3)].node)->entry->data_type||(yyvsp[(3) - (3)].node)->entry->data_type?Float:Int, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 351 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 353 "hw7parser.y"
    { 
                if ((yyvsp[(1) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("* cannot apply to a function that returns void\n"); 
                if ((yyvsp[(3) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("* cannot apply to a function that returns void\n"); 
                (yyval.node) = ast_create_node(AST_MUL, (yyvsp[(1) - (3)].node)->entry->data_type||(yyvsp[(3) - (3)].node)->entry->data_type?Float:Int, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 358 "hw7parser.y"
    { 
                if ((yyvsp[(1) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("/ cannot apply to a function that returns void\n"); 
                if ((yyvsp[(3) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("/ cannot apply to a function that returns void\n"); 
                (yyval.node) = ast_create_node(AST_DIV, (yyvsp[(1) - (3)].node)->entry->data_type||(yyvsp[(3) - (3)].node)->entry->data_type?Float:Int, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 363 "hw7parser.y"
    { 
                if ((yyvsp[(1) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("% cannot apply to a function that returns void\n"); 
                if ((yyvsp[(3) - (3)].node)->entry->data_type == TYPE_VOID) yyerror("% cannot apply to a function that returns void\n"); 
                if ((yyvsp[(1) - (3)].node)->entry->data_type != TYPE_INT) yyerror("% can only apply to integer type\n"); 
                if ((yyvsp[(3) - (3)].node)->entry->data_type != TYPE_INT) yyerror("% can only apply to integer type\n"); 
                (yyval.node) = ast_create_node(AST_MOD, Int, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)) ; }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 372 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 374 "hw7parser.y"
    { 
                if ((yyvsp[(2) - (2)].node)->entry->data_type == TYPE_VOID) yyerror("! cannot apply to a function that returns void\n"); 
                if ((yyvsp[(2) - (2)].node)->entry->data_type != TYPE_INT) yyerror("! can only apply to integer type\n"); 
                (yyval.node) = ast_create_node(AST_NOT, Int, (yyvsp[(2) - (2)].node),  0) ; }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 379 "hw7parser.y"
    { 
                if ((yyvsp[(2) - (2)].node)->entry->data_type == TYPE_VOID) yyerror("- cannot apply to a function that returns void\n"); 
                (yyval.node) = ast_create_node(AST_UMINUS, (yyvsp[(2) - (2)].node)->entry->data_type?Float:Int, (yyvsp[(2) - (2)].node),  0) ; }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 385 "hw7parser.y"
    { SYMTBL entry = symtbl_lookup((yyvsp[(1) - (1)].name));
                if (!entry) entry = symtbl_install((yyvsp[(1) - (1)].name),SYMBOL_NUM,TYPE_INT,0); 
                (yyval.node) = ast_create_node(AST_INT,   entry,  0,  0); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 390 "hw7parser.y"
    { SYMTBL entry = symtbl_lookup((yyvsp[(1) - (1)].name));
                if (!entry) entry= symtbl_install((yyvsp[(1) - (1)].name),SYMBOL_NUM,TYPE_FLOAT,0); 
                (yyval.node) = ast_create_node(AST_FLOAT, entry, 0,  0); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 395 "hw7parser.y"
    { SYMTBL entry = symtbl_lookup((yyvsp[(1) - (1)].name));
                if (!entry) yyerror("identifier undefined\n"); 
                if (entry->sym_type==SYMBOL_FUNC) yyerror("function ref without parameters\n"); 
                (yyval.node) = ast_create_node(AST_ID, entry, 0,  0); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 401 "hw7parser.y"
    { SYMTBL entry = symtbl_lookup((yyvsp[(1) - (4)].name));
                if (!entry) yyerror("function undefined\n"); 
                if (entry->sym_type!=SYMBOL_FUNC) yyerror("function ref expected\n"); 
                matchFuncRefs((yyvsp[(3) - (4)].node),entry->ast_link);
                (yyval.node) = ast_create_node(AST_FUNC_CALL,  entry, (yyvsp[(3) - (4)].node),  0); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 408 "hw7parser.y"
    { SYMTBL entry = symtbl_lookup((yyvsp[(1) - (2)].name));
                if (!entry) yyerror("array identifier undefined\n"); 
                if (entry->sym_type==SYMBOL_FUNC) yyerror("identifier is a function name, not an array name\n");
                if (!entry->ast_link) yyerror("identifier name is not an array\n"); 
                matchArrayRefs((yyvsp[(2) - (2)].node),entry->ast_link);
                (yyval.node) = ast_create_node(AST_ARRAY_REF,  entry, (yyvsp[(2) - (2)].node),  0); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 416 "hw7parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 420 "hw7parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 422 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_ARG_LIST, 0, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 426 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_ARG, (yyvsp[(1) - (1)].node)->entry->data_type?Float:Int, (yyvsp[(1) - (1)].node), 0); }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 430 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_ARRAY_INDEX, 0, 0, (yyvsp[(1) - (1)].node)); }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 432 "hw7parser.y"
    { (yyval.node) = ast_create_node(AST_ARRAY_INDEX, 0, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 436 "hw7parser.y"
    { if ((yyvsp[(2) - (3)].node)->entry->data_type != TYPE_INT) yyerror("array index not of integer type\n");
                (yyval.node) = (yyvsp[(2) - (3)].node);
              }
    break;


/* Line 1792 of yacc.c  */
#line 2204 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 441 "hw7parser.y"


#include "lex.yy.c"

