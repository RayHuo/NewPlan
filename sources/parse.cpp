/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parse.y" /* yacc.c:339  */


#include <string.h>
#include <string>
#include <vector>
#include "Vocabulary.h"
#include "formulatab.h"
#include "structs.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;

extern _formula* init_f;
extern _formula* goal_f;
extern vector<_formula*> actions_f; 
extern map<string,vector<int> > grounding_map;


extern "C" {
	void yyerror(const char *s);
	extern int yylex(void);
}

void yyerror(const char* s)
{
	printf("Parser error: %s\n", s);
}



#line 98 "../sources/parse.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parse.h".  */
#ifndef YY_YY_HEADFILE_PARSE_H_INCLUDED
# define YY_YY_HEADFILE_PARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    WORD_TOK = 258,
    DEFINE_TOK = 259,
    DOMAIN_TOK = 260,
    PREDICATES_TOK = 261,
    VAR_TOK = 262,
    ACTION_TOK = 263,
    PARAMETERS_TOK = 264,
    OBSERVE_TOK = 265,
    PRECONDITION_TOK = 266,
    EFFECT_TOK = 267,
    AND_TOK = 268,
    OR_TOK = 269,
    TYPES_TOK = 270,
    WHEN_TOK = 271,
    DOMAIN_TOK_P = 272,
    OBJECT_TOK_P = 273,
    ONEOF_TOK_P = 274,
    INIT_TOK_P = 275,
    GOAL_TOK_P = 276,
    K_TOK = 277,
    DK_TOK = 278,
    REQUIREMENTS_TOK = 279,
    IMPLY_TOK = 280,
    TRUE_TOK = 281,
    NOT_TOK = 282,
    S_IMPL = 283,
    S_CONJ = 284,
    S_DISJ = 285,
    S_NEG = 286,
    End = 287
  };
#endif
/* Tokens.  */
#define WORD_TOK 258
#define DEFINE_TOK 259
#define DOMAIN_TOK 260
#define PREDICATES_TOK 261
#define VAR_TOK 262
#define ACTION_TOK 263
#define PARAMETERS_TOK 264
#define OBSERVE_TOK 265
#define PRECONDITION_TOK 266
#define EFFECT_TOK 267
#define AND_TOK 268
#define OR_TOK 269
#define TYPES_TOK 270
#define WHEN_TOK 271
#define DOMAIN_TOK_P 272
#define OBJECT_TOK_P 273
#define ONEOF_TOK_P 274
#define INIT_TOK_P 275
#define GOAL_TOK_P 276
#define K_TOK 277
#define DK_TOK 278
#define REQUIREMENTS_TOK 279
#define IMPLY_TOK 280
#define TRUE_TOK 281
#define NOT_TOK 282
#define S_IMPL 283
#define S_CONJ 284
#define S_DISJ 285
#define S_NEG 286
#define End 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 33 "parse.y" /* yacc.c:355  */

    char* s;
    struct __formula* f;

#line 207 "../sources/parse.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HEADFILE_PARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 222 "../sources/parse.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  278

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,    34,     2,     2,    35,    36,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   140,   143,   146,   149,   153,   156,   159,
     162,   165,   172,   177,   182,   185,   190,   195,   202,   216,
     233,   239,   244,   252,   259,   270,   274,   277,   282,   288,
     293,   300,   306,   317,   326,   333,   339,   353,   357,   364,
     368,   375,   378,   387,   390,   393,   396,   401,   407,   415,
     421,   427,   435,   438,   441,   444,   462,   483,   490,   500,
     504,   507,   510,   515,   518,   522,   525,   531,   537,   546,
     549,   552,   558,   567,   579,   591,   594,   599,   605,   608,
     616,   619,   622,   625,   628,   633,   639,   642,   648,   656,
     662,   665,   671,   681,   686,   690,   700,   707,   711,   721,
     777,   782,   825,   874,   887,   892,   896,   908,   914,   924,
     934,   948,   953,   963,   982,   993,   998,  1001,  1007,  1012,
    1015,  1021,  1036,  1051,  1058
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WORD_TOK", "DEFINE_TOK", "DOMAIN_TOK",
  "PREDICATES_TOK", "VAR_TOK", "ACTION_TOK", "PARAMETERS_TOK",
  "OBSERVE_TOK", "PRECONDITION_TOK", "EFFECT_TOK", "AND_TOK", "OR_TOK",
  "TYPES_TOK", "WHEN_TOK", "DOMAIN_TOK_P", "OBJECT_TOK_P", "ONEOF_TOK_P",
  "INIT_TOK_P", "GOAL_TOK_P", "K_TOK", "DK_TOK", "REQUIREMENTS_TOK",
  "IMPLY_TOK", "TRUE_TOK", "NOT_TOK", "S_IMPL", "S_CONJ", "S_DISJ",
  "S_NEG", "End", "'('", "')'", "','", "'-'", "$accept", "result",
  "domain", "typess", "types", "actions", "action", "conobserve",
  "observe", "parameters", "predicates", "predicate", "coneffect",
  "precondition", "effect", "threeatoms", "threeatom", "threeatom1",
  "threeatom23", "multi_threeatom23", "ig_k_and_or", "disj_k", "s5_term_k",
  "newinput", "input_k", "and_or_k_atom", "or_k_atoms", "k_and_or",
  "dk_and_or", "and_orsss", "and_orss", "and_ors", "and_or", "or_and",
  "ands", "and", "ors", "or", "oneofs", "oneof", "imply", "nstate",
  "state", "statewithoutp", "vars", "var", "vartok", "pro", "object",
  "words", "word", "init", "goal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    40,    41,    44,    45
};
# endif

#define YYPACT_NINF -227

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-227)))

#define YYTABLE_NINF -10

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      73,    26,    26,   159,   109,    43,    42,  -227,   171,    83,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,   140,  -227,
    -227,  -227,  -227,  -227,  -227,   159,  -227,  -227,    91,    64,
     104,    82,    93,   105,   111,   111,   149,     2,   122,  -227,
     160,  -227,   159,   159,   159,  -227,   143,   154,   172,   174,
     176,   179,   181,  -227,  -227,    91,  -227,   155,   132,   221,
     246,   253,  -227,    18,    18,    27,   111,   177,  -227,  -227,
    -227,  -227,   189,  -227,  -227,   147,  -227,  -227,    89,  -227,
    -227,   243,  -227,   161,  -227,  -227,  -227,  -227,  -227,  -227,
     147,  -227,  -227,  -227,  -227,  -227,  -227,  -227,   255,   256,
     257,    31,   228,   188,    42,   229,    62,   230,   231,   232,
     234,   235,  -227,  -227,   236,   237,  -227,   190,   239,   192,
     194,   154,   239,   196,   198,  -227,   240,   241,   111,   262,
      10,   200,   263,    42,  -227,   202,    15,   244,   245,   247,
     242,  -227,   248,   129,  -227,    57,   215,   249,    57,   215,
     250,  -227,  -227,   170,  -227,  -227,   252,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,   206,  -227,  -227,    21,   144,  -227,
      55,  -227,   254,  -227,  -227,  -227,  -227,   208,   258,   259,
     260,   261,  -227,   210,   264,   265,   266,   267,  -227,   269,
    -227,  -227,   270,   212,   271,   272,   268,   273,   275,   276,
    -227,  -227,   244,   214,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,   278,   215,   251,  -227,  -227,
     251,   274,   277,  -227,  -227,   254,   279,   280,   281,   282,
     283,   284,   286,  -227,   287,   288,   289,   290,  -227,  -227,
     253,   291,   178,   292,   294,   274,   274,   251,   216,  -227,
     286,   285,   304,   294,   307,   295,   296,   297,   298,  -227,
     253,   299,     9,    22,  -227,   300,  -227,  -227,  -227,  -227,
    -227,  -227,   293,  -227,  -227,  -227,  -227,  -227
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    10,    17,     0,    52,
      53,    11,   100,   104,   105,     5,     7,     8,     0,    73,
      76,    83,    82,    84,    74,     0,    55,    52,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,    16,     0,     0,     0,     6,     0,     0,     0,     0,
       0,     0,     0,   114,   115,   108,   111,   112,     0,     0,
       0,     0,   101,     0,     0,     0,     0,     0,    54,    99,
     102,   107,    56,    57,    58,     0,    86,    94,     0,    90,
      97,     0,    75,     0,    81,    87,    88,    80,    91,    92,
       0,    93,    85,    95,    96,    89,    98,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,     0,     0,   106,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,     0,     0,     0,
       0,    21,     0,     0,    29,     0,     0,     0,     0,     0,
       0,   103,    78,     0,    79,    77,     0,    12,    27,    15,
      14,    13,    25,    26,     0,     2,    24,     0,     0,    22,
       0,    31,     0,    18,    19,    20,    28,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,   124,     0,
       4,    23,     0,     0,     0,     0,     0,     0,    44,    43,
      46,    45,    38,     0,    35,    63,    64,    65,    69,    70,
      66,    67,    68,    71,    72,     0,     0,     0,    32,    30,
       0,     0,     0,    37,    33,     0,     0,     0,     0,     0,
       0,     0,    40,    34,     0,     0,     0,     0,    48,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      40,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,     0,     0,     0,   120,     0,   117,    49,    50,    47,
      42,    36,     0,   122,   118,   119,   116,   121
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -227,  -227,  -227,  -227,  -227,   -42,    -2,  -227,   136,  -227,
     187,  -227,  -227,  -227,   148,  -227,    65,  -227,    56,  -227,
    -227,  -227,  -227,    23,   301,  -227,   -88,     0,   -61,   308,
    -227,  -126,  -227,   -48,   -31,   -69,   -41,   121,     1,  -227,
    -227,   -28,    74,  -226,   175,   -40,  -227,  -227,  -227,  -227,
     -10,  -214,  -183
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    59,   102,   130,     6,     7,   140,   141,   106,
     104,   131,   142,   143,   144,   203,   204,   222,   241,   248,
     197,   198,   199,    36,   109,   110,   111,    27,    10,    19,
      48,    20,    49,    50,    21,    51,    22,    52,    23,    37,
      12,    13,    14,    38,    55,    56,    57,    15,   243,   263,
     264,    16,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    11,   113,   113,    41,    76,    66,    67,    85,   119,
      92,   169,   262,   160,   249,    97,    79,   103,    53,    88,
     244,    95,    54,     8,    53,   262,    26,   117,    54,   253,
      28,   107,   108,   120,   270,    61,    69,   128,   115,    30,
       1,     2,   124,    39,   161,   272,   129,    77,    80,   166,
      86,    89,    93,    96,    35,   191,   274,   177,    28,    18,
     183,   255,   135,   112,   112,    72,    73,    74,   194,   195,
     265,   108,   137,   138,   139,    40,   223,     1,     2,     1,
       2,   196,    35,    -9,   179,   181,    88,   185,   187,    88,
      95,   164,    28,    88,    53,     1,     2,    58,    54,   193,
     158,    41,   118,   163,     3,    62,     4,    60,    31,   201,
     171,    70,    28,    29,    34,    61,    35,    30,    89,    77,
      93,    89,    96,    80,    96,    89,    63,    97,    31,    32,
      33,     1,     2,    41,    34,    99,    35,   100,    64,   137,
       3,   139,    25,    28,    65,   178,   180,    28,   184,   186,
      28,    76,    92,    46,    47,   228,    71,   192,    47,    31,
     231,    47,    41,    31,    28,    34,    31,    35,    30,    34,
     200,    35,    34,    28,    35,   122,    75,    42,    43,    44,
      31,     1,     2,    68,   256,   257,    34,    78,    35,    31,
       3,    98,    25,    77,    93,    34,   251,    35,    32,    42,
      43,    44,   121,    45,   123,    81,    82,    83,    84,    78,
      87,   116,    90,    91,    78,    94,   227,   229,    43,    44,
     230,    40,   134,    78,   152,   153,    91,    78,   154,   153,
      94,    78,   155,    65,   162,    40,   165,     1,     2,    40,
     190,   149,   205,   149,   210,    83,    91,   258,   224,   225,
     259,   260,   273,   275,   101,   105,    28,    47,   125,   126,
     127,   132,   136,   145,   146,   159,   147,   148,   149,   128,
     150,   151,   153,     1,   156,   157,   173,   168,   170,   175,
     172,   226,   174,   182,   188,   189,   215,   202,   262,   133,
     233,   176,   206,   207,   208,   209,   277,     2,   211,   212,
     213,   214,   218,    83,   216,   217,   261,   219,   220,   221,
      24,   167,   232,   234,   235,   236,   237,   238,   239,   240,
     242,   245,   246,   247,    32,   252,   250,   254,    33,   266,
     267,   268,   269,   271,   276,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114
};

static const yytype_int16 yycheck[] =
{
       0,     0,    63,    64,     6,    46,    34,    35,    49,    78,
      51,   137,     3,     3,   240,    55,    47,    59,     3,    50,
     234,    52,     7,     0,     3,     3,     3,    75,     7,   243,
       3,    13,    14,    81,   260,    33,    34,     6,    66,     8,
      22,    23,    90,     0,    34,    36,    15,    46,    47,    34,
      49,    50,    51,    52,    27,    34,    34,   145,     3,    33,
     148,   244,   104,    63,    64,    42,    43,    44,    13,    14,
     253,    14,    10,    11,    12,    33,   202,    22,    23,    22,
      23,    26,    27,     0,   145,   146,   117,   148,   149,   120,
     121,   133,     3,   124,     3,    22,    23,    33,     7,   168,
     128,   103,    13,   131,    31,    31,    33,     3,    19,   170,
     138,    37,     3,     4,    25,    33,    27,     8,   117,   118,
     119,   120,   121,   122,   123,   124,    33,   167,    19,    20,
      21,    22,    23,   135,    25,     3,    27,     5,    33,    10,
      31,    12,    33,     3,    33,   145,   146,     3,   148,   149,
       3,   192,   193,    13,    14,   216,    34,    13,    14,    19,
     221,    14,   164,    19,     3,    25,    19,    27,     8,    25,
     170,    27,    25,     3,    27,    14,    33,    28,    29,    30,
      19,    22,    23,    34,   245,   246,    25,    33,    27,    19,
      31,    36,    33,   192,   193,    25,    18,    27,    20,    28,
      29,    30,    81,    32,    83,    33,    34,    33,    34,    33,
      34,    34,    33,    34,    33,    34,   216,   217,    29,    30,
     220,    33,    34,    33,    34,    33,    34,    33,    34,    33,
      34,    33,    34,    33,    34,    33,    34,    22,    23,    33,
      34,    33,    34,    33,    34,    33,    34,   247,    34,    35,
      34,    35,   262,   263,    33,     9,     3,    14,     3,     3,
       3,    33,    33,    33,    33,     3,    34,    33,    33,     6,
      34,    34,    33,    22,    34,    34,    34,    33,    33,   143,
      33,     3,    34,    34,    34,    33,    17,    33,     3,   102,
     225,   143,    34,    34,    34,    34,     3,    23,    34,    34,
      34,    34,    34,    33,    33,    33,   250,    34,    33,    33,
       2,   136,    35,    34,    34,    34,    34,    34,    34,    33,
      33,    33,    33,    33,    20,    33,    35,    33,    21,    34,
      34,    34,    34,    34,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    23,    31,    33,    38,    42,    43,    60,    64,
      65,    75,    77,    78,    79,    84,    88,    89,    33,    66,
      68,    71,    73,    75,    66,    33,    60,    64,     3,     4,
       8,    19,    20,    21,    25,    27,    60,    76,    80,     0,
      33,    43,    28,    29,    30,    32,    13,    14,    67,    69,
      70,    72,    74,     3,     7,    81,    82,    83,    33,    39,
       3,    33,    79,    33,    33,    33,    78,    78,    34,    34,
      79,    34,    60,    60,    60,    33,    73,    75,    33,    71,
      75,    33,    34,    33,    34,    73,    75,    34,    71,    75,
      33,    34,    73,    75,    34,    71,    75,    82,    36,     3,
       5,    33,    40,    42,    47,     9,    46,    13,    14,    61,
      62,    63,    64,    65,    61,    78,    34,    70,    13,    72,
      70,    74,    14,    74,    70,     3,     3,     3,     6,    15,
      41,    48,    33,    47,    34,    42,    33,    10,    11,    12,
      44,    45,    49,    50,    51,    33,    33,    34,    33,    33,
      34,    34,    34,    33,    34,    34,    34,    34,    78,     3,
       3,    34,    34,    78,    42,    34,    34,    81,    33,    68,
      33,    78,    33,    34,    34,    45,    51,    63,    64,    65,
      64,    65,    34,    63,    64,    65,    64,    65,    34,    33,
      34,    34,    13,    72,    13,    14,    26,    57,    58,    59,
      64,    65,    33,    52,    53,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    17,    33,    33,    34,    34,
      33,    33,    54,    68,    34,    35,     3,    64,    65,    64,
      64,    65,    35,    53,    34,    34,    34,    34,    34,    34,
      33,    55,    33,    85,    88,    33,    33,    33,    56,    80,
      35,    18,    33,    88,    33,    89,    65,    65,    64,    34,
      35,    55,     3,    86,    87,    89,    34,    34,    34,    34,
      80,    34,    36,    87,    34,    87,    34,     3
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    39,    40,    41,    41,    42,    42,    43,    43,
      44,    44,    45,    46,    46,    47,    48,    48,    49,    49,
      50,    50,    50,    51,    52,    52,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    57,    57,    58,    58,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    64,    65,    66,    66,    67,    67,    67,
      68,    68,    68,    68,    68,    69,    69,    69,    69,    70,
      70,    70,    70,    71,    72,    72,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    78,    79,    80,    80,
      81,    81,    82,    82,    82,    83,    84,    84,    85,    86,
      86,    87,    87,    88,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     7,     1,     2,     1,     1,     1,
       1,     1,     4,     3,     2,     2,     2,     1,     6,     6,
       2,     1,     2,     4,     3,     3,     2,     2,     2,     1,
       4,     2,     4,     4,     3,     1,     7,     1,     0,     3,
       0,     1,     3,     1,     1,     1,     1,     7,     4,     7,
       7,     4,     1,     1,     3,     2,     3,     3,     3,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     2,     2,     3,     1,     4,     4,     4,
       3,     3,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     2,     2,     3,     2,     2,     3,
       1,     2,     2,     5,     1,     1,     4,     3,     2,     1,
       2,     1,     1,     3,     1,     1,    14,    13,     4,     2,
       1,     3,     2,     6,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 137 "parse.y" /* yacc.c:1646  */
    {
       //cout<<"result1"<<endl;
    }
#line 1508 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 140 "parse.y" /* yacc.c:1646  */
    {
       //cout<<"result2"<<endl;
    }
#line 1516 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 143 "parse.y" /* yacc.c:1646  */
    {
       //cout<<"result3"<<endl;
    }
#line 1524 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 146 "parse.y" /* yacc.c:1646  */
    {
       //cout<<"pro"<<endl;
    }
#line 1532 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 149 "parse.y" /* yacc.c:1646  */
    {
       init_f = (yyvsp[-1].f);
       //cout<<"newinput"<<endl;
    }
#line 1541 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 153 "parse.y" /* yacc.c:1646  */
    {
       //cout<<"init1"<<endl;
    }
#line 1549 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 156 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"goal1"<<endl;
    }
#line 1557 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 159 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"k_and_or"<<endl;
    }
#line 1565 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 162 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"acts"<<endl;
     }
#line 1573 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 165 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"oneofs"<<endl;
      init_f = (yyvsp[0].f);
    }
#line 1582 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 172 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1590 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 177 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1598 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 182 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1606 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 185 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1614 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 190 "parse.y" /* yacc.c:1646  */
    {
      actions_f.push_back((yyvsp[0].f));
      //cout<<"one acts"<<endl;

    }
#line 1624 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 195 "parse.y" /* yacc.c:1646  */
    {
      actions_f.push_back((yyvsp[0].f));
      //cout<<"one act"<<endl;

    }
#line 1634 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 202 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = ACTION_F;
      int id = Vocabulary::instance().queryAtom((yyvsp[-3].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[-3].s));
      (yyval.f) -> pid = id;

      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = ACTION_CONTEXT_F;
      f -> subformula_l = (yyvsp[-2].f);
      f -> subformula_r = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = f;
    }
#line 1653 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 216 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = ACTION_F;
      int id = Vocabulary::instance().queryAtom((yyvsp[-3].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[-3].s));
      (yyval.f) -> pid = id;

      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = ACTION_CONTEXT_F;
      f -> subformula_l = (yyvsp[-2].f);
      f -> subformula_r = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = f;

    }
#line 1673 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 233 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = CONOBSERVE_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f); 
    }
#line 1684 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 239 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1692 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 244 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OBSERVE_F;
      (yyval.f) -> subformula_l = (yyvsp[0].f);
      //cout<<"observe"<<endl;
    }
#line 1703 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 252 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = PARAMETERS_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      //cout<<"para"<<endl;

    }
#line 1715 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 259 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = PARAMETERS_F;
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = EMPTY_F;
      (yyval.f) -> subformula_l = f;

    }
#line 1728 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 270 "parse.y" /* yacc.c:1646  */
    {
    }
#line 1735 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 274 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1743 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 277 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1751 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 282 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = CONEFFECT_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);      
    }
#line 1762 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 288 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1770 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 293 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = PRECONDITION_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      //cout<<"precon"<<endl;

    }
#line 1782 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 300 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = PRECONDITION_F;
      (yyval.f) -> subformula_l = (yyvsp[0].f);

    }
#line 1793 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 306 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = TRUE_F;
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = PRECONDITION_F;
      (yyval.f) -> subformula_l = f;
      //cout<<"true"<<endl;
    }
#line 1806 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 317 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = EFFECT_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      //cout<<"effect"<<endl;

    }
#line 1818 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 326 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = THREE_ATOMS_F;
      (yyval.f) -> subformula_l = (yyvsp[-2].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);

    }
#line 1830 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 333 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) == (yyvsp[0].f);

    }
#line 1839 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 339 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = THREE_ATOM_BEHIND_F;
      f -> subformula_l = (yyvsp[-3].f);
      f -> subformula_r = (yyvsp[-1].f);
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = THREE_ATOM_F;
      (yyval.f) -> subformula_l = (yyvsp[-5].f);
      (yyval.f) -> subformula_r = f;

    }
#line 1855 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 353 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);

    }
#line 1864 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 357 "parse.y" /* yacc.c:1646  */
    {      
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = EMPTY_F;

      }
#line 1874 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 364 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);

    }
#line 1883 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 368 "parse.y" /* yacc.c:1646  */
    {      
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = EMPTY_F;

      }
#line 1893 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 375 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1901 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 378 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = MULTI_THREE_ATOMS;
      (yyval.f) -> subformula_l = (yyvsp[-2].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);

    }
#line 1913 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 387 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
     }
#line 1921 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 390 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1929 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 393 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1937 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 396 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1945 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 401 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-4].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 1956 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 407 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 1967 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 415 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-4].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 1978 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 421 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-4].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 1989 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 427 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 2000 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 435 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2008 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 438 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2016 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 441 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2024 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 444 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      _formula* f1 = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = NEGA_F;
      f -> subformula_l = Formulatab::instance().getAtom((yyvsp[0].f) -> pid) -> subformula_l;
      //int id = Formulatab::instance().addAtom(f);
      f1 -> subformula_l = f;

      if(Formulatab::instance().getAtom((yyvsp[0].f) -> pid) -> formula_type == DK_F)
        f1 -> formula_type = K_F;
      else
        f1 -> formula_type = DK_F;
      int id = Formulatab::instance().addAtom(f1);
      
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> pid = id;
      (yyval.f) -> formula_type = K_atom;
    }
#line 2047 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 462 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      _formula* f1 = (__formula*)malloc(sizeof(_formula));
      _formula* f11 = (__formula*)malloc(sizeof(_formula));
      _formula* f2 = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = NEGA_F;
      f -> subformula_l = Formulatab::instance().getAtom((yyvsp[-2].f) -> pid) -> subformula_l;
      //int id = Formulatab::instance().addAtom(f);
      f1 -> subformula_l = f;
      if(Formulatab::instance().getAtom((yyvsp[-2].f) -> pid) -> formula_type == DK_F)
        f1 -> formula_type = K_F;
      else
        f1 -> formula_type = DK_F;
      int id = Formulatab::instance().addAtom(f1);
      f11 -> pid = id;
      f11 -> formula_type = K_atom;
      f2 -> formula_type = DISJ_F;
      f2 -> subformula_l = f11;
      f2 -> subformula_r = (yyvsp[0].f);
      (yyval.f) = f2;
    }
#line 2073 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 483 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = CONJ_F;
      f -> subformula_l = (yyvsp[-2].f);
      f -> subformula_r = (yyvsp[0].f); 
      (yyval.f) = f;
    }
#line 2085 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 490 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));     
      f -> formula_type = DISJ_F;
      f -> subformula_l = (yyvsp[-2].f);
      f -> subformula_r = (yyvsp[0].f);     
      (yyval.f) = f;
    }
#line 2097 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 500 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
      //cout<<"imput_k"<<endl;
    }
#line 2106 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 504 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2114 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 507 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2122 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 510 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2130 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 515 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2138 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 518 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2146 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 522 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2154 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 525 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);     
    }
#line 2165 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 531 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);     
    }
#line 2176 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 537 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);     
    }
#line 2187 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 546 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2195 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 549 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2203 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 552 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 2214 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 558 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 2225 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 567 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = K_F;
      f -> subformula_l = (yyvsp[0].f);
      int id = Formulatab::instance().addAtom(f);
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = K_atom;
      (yyval.f) -> pid = id;
       
    }
#line 2240 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 579 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = DK_F;
      f -> subformula_l = (yyvsp[0].f);
      int id = Formulatab::instance().addAtom(f);
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = K_atom;
      (yyval.f) -> pid = id;
    }
#line 2254 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 591 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2262 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 594 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2270 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 599 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);     
    }
#line 2281 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 605 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2289 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 608 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);    
    }
#line 2300 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 616 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2308 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 619 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2316 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 622 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2324 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 625 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2332 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 628 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2340 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 633 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);     
    }
#line 2351 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 639 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2359 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 642 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2370 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 648 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2381 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 656 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);  
    }
#line 2392 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 662 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2400 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 665 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2411 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 671 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2422 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 681 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2430 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 686 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);

    }
#line 2439 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 690 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2450 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 700 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2458 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 707 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);

    }
#line 2467 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 711 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);

    }
#line 2479 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 721 "parse.y" /* yacc.c:1646  */
    {
      vector<_formula*> fm;
      for(int i = 0; i < (yyvsp[-1].f)->count; i++){
         _formula* f = (__formula*)malloc(sizeof(_formula));
         f -> formula_type = ONE_ATOM_STATE_F;
         f -> pid = (yyvsp[-1].f)->pidlist[i];
         fm.push_back(f);
      }
      vector<_formula*> fm1;
      for(int i = 0; i < (yyvsp[-1].f)->count; i++){
         _formula* f = (__formula*)malloc(sizeof(_formula));
         if(i==0)
             f = fm[0];
         if(i!=0){
             f->formula_type = NEGA_F;
             f->subformula_l = fm[0];
          }
          
         for(int j = 1; j < (yyvsp[-1].f)->count; j++){
            if(i!=j){
               _formula* f1 = (__formula*)malloc(sizeof(_formula));
               f1->formula_type = NEGA_F;
               f1->subformula_l = fm[j];
               _formula* f2 = (__formula*)malloc(sizeof(_formula));
               f2->formula_type = AND_F;
               f2->subformula_l = f;
               f2->subformula_r = f1;
               f = f2;
            }
            else{
               _formula* f2 = (__formula*)malloc(sizeof(_formula));
               f2->formula_type = AND_F;
               f2->subformula_l = f;
               f2->subformula_r = fm[j];
               f = f2;
            }
            
         }
         fm1.push_back(f);
      }

      _formula* f = (__formula*)malloc(sizeof(_formula));
      f->formula_type = OR_F;
      f->subformula_l = fm1[0];
      f->subformula_r = fm1[1];
      for(int i=2; i < (yyvsp[-1].f)->count; i++)
      {
        _formula* f1 = (__formula*)malloc(sizeof(_formula));
        f1->formula_type = OR_F;
        f1->subformula_l = f;
        f1->subformula_r = fm1[i];
        f = f1;
      }
      (yyval.f) = f;
      
    }
#line 2540 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 777 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2548 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 782 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f = (yyvsp[0].f);
      int ie;
      switch (f->formula_type) {
        case ONE_ATOM_STATE_F:
        {   
            ie = f->pid;
            break;
        }
        case STATE_F:
        {
            string s = Vocabulary::instance().getAtom(f->pid);
            string temp;
            if (f->subformula_r->formula_type == VAR_F) {
                temp = Vocabulary::instance().getAtom(f->subformula_r->pid);
                s = s + "." + temp;
            } else
                for (int i = 0; i < f->subformula_r->count; i++) {
                    temp = Vocabulary::instance().getAtom(f->subformula_r->pidlist[i]);
                    s = s + "." + temp;
                }
            char *c;
            int len = s.length();
            c = (char *)malloc((len+1)*sizeof(char));
            s.copy(c,len,0);
            c[len]='\0';
            ie = Vocabulary::instance().queryAtom(c);

            if (ie == -1)
                ie = Vocabulary::instance().addAtom(c);


            //else
            //return ie;
            break;
        }
      }
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = ONEOF_F;
      (yyval.f) -> count = 1;
      (yyval.f) -> pidlist[0] = ie;
    }
#line 2596 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 825 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f = (yyvsp[0].f);
      int ie;
      switch (f->formula_type) {
        case ONE_ATOM_STATE_F:
        {   
            ie = f->pid;
            break;
        }
        case STATE_F:
        {
            string s = Vocabulary::instance().getAtom(f->pid);
            string temp;
            if (f->subformula_r->formula_type == VAR_F) {
                temp = Vocabulary::instance().getAtom(f->subformula_r->pid);
                s = s + "." + temp;
            } else
                for (int i = 0; i < f->subformula_r->count; i++) {
                    temp = Vocabulary::instance().getAtom(f->subformula_r->pidlist[i]);
                    s = s + "." + temp;
                }
            char *c;
            int len = s.length();
            c = (char *)malloc((len+1)*sizeof(char));
            s.copy(c,len,0);
            c[len]='\0';
            ie = Vocabulary::instance().queryAtom(c);

            if (ie == -1)
                ie = Vocabulary::instance().addAtom(c);


            //else
            //return ie;
            break;
        }
      }
      (yyval.f) = (yyvsp[-1].f);
      (yyval.f)->pidlist[(yyvsp[-1].f)->count] = ie;
      (yyval.f)->count = (yyvsp[-1].f)->count+1;

    }
#line 2644 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 874 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      _formula* f = (__formula*)malloc(sizeof(_formula));
      if((yyvsp[-2].f)-> formula_type != NEGA_F){
          f -> formula_type = NEGA_F;
          f -> subformula_l = (yyvsp[-2].f);
      }
      else
          f = (yyvsp[-2].f)-> subformula_l;
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = f;
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 2662 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 887 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2670 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 892 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);

    }
#line 2679 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 896 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      if((yyvsp[-1].f)-> formula_type != NEGA_F){
          (yyval.f) -> formula_type = NEGA_F;
          (yyval.f) -> subformula_l = (yyvsp[-1].f);
      }  
      else
          (yyval.f) = (yyvsp[-1].f) -> subformula_l;

    }
#line 2694 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 908 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);

    }
#line 2703 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 914 "parse.y" /* yacc.c:1646  */
    {
      int id = Vocabulary::instance().queryAtom((yyvsp[-1].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[-1].s));
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = STATE_F;
      (yyval.f) -> pid = id;
      (yyval.f) -> subformula_r = (yyvsp[0].f);

    }
#line 2718 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 924 "parse.y" /* yacc.c:1646  */
    {
      int id = Vocabulary::instance().queryAtom((yyvsp[0].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[0].s));
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = ONE_ATOM_STATE_F;
      (yyval.f) -> pid = id;
    }
#line 2731 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 934 "parse.y" /* yacc.c:1646  */
    {
      if((yyvsp[-1].f) -> formula_type == VAR_F){
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = VARS_F;
      (yyval.f) -> count = 2;
      (yyval.f) -> pidlist[0] = (yyvsp[-1].f) -> pid;
      (yyval.f) -> pidlist[1] = (yyvsp[0].f) -> pid;
      }
      else{
      (yyval.f) -> count = (yyval.f) -> count + 1;
      (yyval.f) -> pidlist[(yyval.f) -> count-1] = (yyvsp[0].f) -> pid;
      }

    }
#line 2750 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 948 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2758 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 953 "parse.y" /* yacc.c:1646  */
    {
      int id = Vocabulary::instance().queryAtom((yyvsp[0].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[0].s));
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> pid = id;
      (yyval.f) -> formula_type=VAR_F;


    }
#line 2773 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 963 "parse.y" /* yacc.c:1646  */
    {
      string s0((yyvsp[-2].s));

      string s3((yyvsp[0].s));
      string s1=s0+"."+s3;      
      char *c;
      int len = s1.length();
      c = (char *)malloc((len+1)*sizeof(char));
      s1.copy(c,len,0);
      c[len]='\0';
      int id = Vocabulary::instance().queryAtom(c);
      if(id < 0)
          id = Vocabulary::instance().addAtom(c);
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f)->pid = id;
      (yyval.f)->formula_type=VAR_F;


    }
#line 2797 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 982 "parse.y" /* yacc.c:1646  */
    {
      int id = Vocabulary::instance().queryAtom((yyvsp[0].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[0].s));
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> pid = id;
      (yyval.f) -> formula_type=VAR_F;

     }
#line 2811 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 993 "parse.y" /* yacc.c:1646  */
    {
      (yyval.s) = strdup((yyvsp[0].s));
    }
#line 2819 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 998 "parse.y" /* yacc.c:1646  */
    {
      
    }
#line 2827 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1001 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"right"<<endl;
    }
#line 2835 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1007 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"object"<<endl;
    }
#line 2843 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1012 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"words1"<<endl;
    }
#line 2851 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1015 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"word2"<<endl;

    }
#line 2860 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1021 "parse.y" /* yacc.c:1646  */
    {

      
      string s3((yyvsp[0].s));
      vector<int> v;
      int id = Vocabulary::instance().queryAtom((yyvsp[-2].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[-2].s));
      v.push_back(id);
      grounding_map[s3] = v;
      (yyval.s) = (yyvsp[0].s);
      //cout<<"word1: "<<s3<<endl;

      
    }
#line 2880 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1036 "parse.y" /* yacc.c:1646  */
    {

      string s2((yyvsp[0].s));
      int id = Vocabulary::instance().queryAtom((yyvsp[-1].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[-1].s));
      grounding_map[s2].push_back(id);
      (yyval.s) = (yyvsp[0].s);

      //cout<<"word2: "<<s2<<endl;
    }
#line 2896 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1051 "parse.y" /* yacc.c:1646  */
    {
      init_f = (yyvsp[-2].f);

      //cout<<"init"<<endl;
    }
#line 2906 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1058 "parse.y" /* yacc.c:1646  */
    {
      goal_f = (yyvsp[-2].f);
      //cout<<"goal"<<endl;
    }
#line 2915 "../sources/parse.cpp" /* yacc.c:1646  */
    break;


#line 2919 "../sources/parse.cpp" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1069 "parse.y" /* yacc.c:1906  */

