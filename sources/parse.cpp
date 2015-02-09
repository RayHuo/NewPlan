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
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  288

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
     504,   507,   510,   513,   521,   524,   528,   531,   537,   543,
     552,   555,   558,   564,   573,   585,   597,   600,   605,   611,
     614,   622,   625,   628,   631,   634,   639,   645,   648,   654,
     662,   668,   671,   677,   687,   692,   696,   706,   713,   717,
     727,   783,   788,   831,   880,   893,   898,   902,   914,   920,
     930,   940,   954,   959,   969,   988,   999,  1004,  1007,  1013,
    1018,  1021,  1027,  1042,  1057,  1064
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

#define YYPACT_NINF -232

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-232)))

#define YYTABLE_NINF -10

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,     4,     4,    46,   153,    66,    39,  -232,   201,    83,
    -232,  -232,  -232,  -232,  -232,  -232,  -232,  -232,   152,  -232,
    -232,  -232,  -232,  -232,  -232,    46,  -232,  -232,    35,    53,
      92,    81,   101,   129,   131,   131,   188,   118,   133,  -232,
     139,  -232,    46,    46,    46,  -232,   136,   148,   125,   154,
     157,   175,   204,  -232,  -232,    35,  -232,   147,    17,   161,
     176,   207,  -232,    89,    89,    18,   131,   170,  -232,  -232,
    -232,  -232,   210,  -232,  -232,   200,  -232,  -232,    71,  -232,
    -232,   212,  -232,   209,  -232,  -232,  -232,  -232,  -232,  -232,
     200,  -232,  -232,  -232,  -232,  -232,  -232,  -232,   229,   240,
     268,    72,   182,   208,    39,   202,   132,   247,   248,   249,
     251,   252,  -232,  -232,   253,   254,  -232,   211,   256,   213,
     215,   148,   256,   217,   219,  -232,   257,   258,   131,   279,
      20,   221,   280,    39,  -232,   224,    21,   260,   261,   262,
     263,  -232,   264,    95,  -232,   115,   113,   265,   115,   237,
     266,  -232,  -232,    16,  -232,  -232,   269,  -232,  -232,  -232,
    -232,  -232,  -232,  -232,   228,  -232,  -232,    26,   186,  -232,
     179,  -232,   270,  -232,  -232,  -232,  -232,   271,   230,   267,
     272,   232,   273,   274,  -232,   234,   275,   276,   277,   278,
    -232,   288,  -232,  -232,   281,   236,   282,   283,   284,   285,
     287,   289,  -232,  -232,   260,   238,  -232,   237,  -232,  -232,
    -232,   290,  -232,  -232,  -232,  -232,  -232,  -232,  -232,   293,
     237,   291,   114,  -232,   291,   295,   255,  -232,  -232,   270,
     308,   292,   294,   296,   297,   298,   299,   300,   302,  -232,
     241,   303,   304,   305,   306,   307,  -232,  -232,   207,   309,
    -232,    90,   310,   312,   295,   295,   291,  -232,   242,  -232,
     302,   321,   320,   312,   325,   313,   314,   315,   316,  -232,
     207,   317,    13,    28,  -232,   318,  -232,  -232,  -232,  -232,
    -232,  -232,   322,  -232,  -232,  -232,  -232,  -232
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    10,    17,     0,    52,
      53,    11,   101,   105,   106,     5,     7,     8,     0,    74,
      77,    84,    83,    85,    75,     0,    55,    52,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,    16,     0,     0,     0,     6,     0,     0,     0,     0,
       0,     0,     0,   115,   116,   109,   112,   113,     0,     0,
       0,     0,   102,     0,     0,     0,     0,     0,    54,   100,
     103,   108,    56,    57,    58,     0,    87,    95,     0,    91,
      98,     0,    76,     0,    82,    88,    89,    81,    92,    93,
       0,    94,    86,    96,    97,    90,    99,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,     0,     0,     0,
       0,    21,     0,     0,    29,     0,     0,     0,     0,     0,
       0,   104,    79,     0,    80,    78,     0,    12,    27,    15,
      14,    13,    25,    26,     0,     2,    24,     0,     0,    22,
       0,    31,     0,    18,    19,    20,    28,     0,     0,     0,
       0,     0,     0,     0,   124,     0,     0,     0,     0,     0,
     125,     0,     4,    23,     0,     0,     0,     0,     0,     0,
      44,    43,    46,    45,    38,     0,    35,     0,    64,    65,
      66,     0,    70,    71,    67,    68,    69,    72,    73,     0,
       0,     0,     0,    30,     0,     0,     0,    37,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    40,    34,
       0,     0,     0,     0,     0,     0,    48,    51,     0,     0,
      63,     0,     0,     0,     0,     0,     0,    32,     0,    41,
      40,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,     0,     0,     0,   121,     0,   118,    49,    50,    47,
      42,    36,     0,   123,   119,   120,   117,   122
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -232,  -232,  -232,  -232,  -232,   -48,    -4,  -232,   184,  -232,
     227,  -232,  -232,  -232,   199,  -232,   124,  -232,    94,  -232,
    -232,  -232,  -232,    15,   301,  -137,   -75,     0,   -57,   353,
    -232,  -123,  -232,   -14,   -20,   -74,   -41,    49,     1,  -232,
    -232,   -22,     9,  -231,   220,   -52,  -232,  -232,  -232,  -232,
       6,  -170,  -188
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    59,   102,   130,     6,     7,   140,   141,   106,
     104,   131,   142,   143,   144,   205,   206,   226,   249,   258,
     199,   200,   201,    36,   109,   110,   111,    27,    10,    19,
      48,    20,    49,    50,    21,    51,    22,    52,    23,    37,
      12,    13,    14,    38,    55,    56,    57,    15,   252,   273,
     274,    16,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    11,    41,    97,   119,    76,   113,   113,    85,   181,
      92,   103,    66,    67,   169,     8,   272,   259,    26,    28,
      99,    28,   100,   160,    53,     1,     2,    79,    54,    53,
      88,   272,    95,    54,     3,    31,     4,    18,    53,   280,
      62,    34,    54,    35,   115,    35,    70,    77,    80,   282,
      86,    89,    93,    96,   161,   166,   135,    72,    73,    74,
     193,   117,   284,   112,   112,   265,    39,   120,     1,     2,
     178,   253,    40,   185,    28,   275,   124,     3,   128,    25,
      30,   227,   263,    -9,   118,   164,    58,   129,   180,   183,
      31,   187,   189,   240,   195,    60,    34,    88,    35,    41,
      88,    95,   107,   108,    88,   137,   158,   139,   261,   163,
      32,     1,     2,   203,    61,    97,   171,    28,    89,    77,
      93,    89,    96,    80,    96,    89,   107,    46,    47,   177,
     121,    41,   123,    31,    63,     1,     2,     1,     2,    34,
     235,    35,   137,   138,   139,   179,   182,    30,   186,   188,
     183,    61,    69,    76,    92,    28,    28,    29,    81,    82,
      41,    30,    64,   233,    65,    46,    47,    71,   237,    75,
     202,    31,    31,    32,    33,     1,     2,    34,    34,    35,
      35,    78,    28,    98,     3,   105,    25,    83,    84,    28,
      78,    87,   196,   197,   101,    77,    93,   266,   267,   194,
      47,   198,     2,    28,   116,    31,    35,   182,    90,    91,
      28,    34,    28,    35,    47,   132,    42,    43,    44,    31,
     232,   234,    68,   122,   236,    34,    47,    35,    31,    42,
      43,    44,   125,    45,    34,   136,    35,    78,    94,    43,
      44,    40,   134,   126,    78,   152,   153,    91,    78,   154,
     153,    94,    78,   155,    65,   162,   268,    40,   165,     1,
       2,    40,   192,   149,   208,   148,   211,   149,   214,    83,
      91,   127,   228,   229,   148,   250,   269,   270,   283,   285,
     145,   146,   159,   147,   148,   149,   128,   150,   151,   153,
     238,   156,   157,   168,   170,   172,   231,   173,   174,   184,
     190,   209,   191,   204,   207,   219,   210,   212,   213,   215,
     216,   217,   218,     1,    83,   220,   221,   222,     2,   223,
     224,   107,   225,   230,   272,   287,   241,   175,   242,   133,
     243,   244,   245,   246,   247,   248,   251,   254,   255,   256,
      32,   257,   176,   262,   260,   264,    33,   276,   277,   278,
     279,   281,   286,   239,   271,    24,   167,     0,     0,     0,
       0,     0,     0,     0,     0,   114
};

static const yytype_int16 yycheck[] =
{
       0,     0,     6,    55,    78,    46,    63,    64,    49,   146,
      51,    59,    34,    35,   137,     0,     3,   248,     3,     3,
       3,     3,     5,     3,     3,    22,    23,    47,     7,     3,
      50,     3,    52,     7,    31,    19,    33,    33,     3,   270,
      31,    25,     7,    27,    66,    27,    37,    46,    47,    36,
      49,    50,    51,    52,    34,    34,   104,    42,    43,    44,
      34,    75,    34,    63,    64,   253,     0,    81,    22,    23,
     145,   241,    33,   148,     3,   263,    90,    31,     6,    33,
       8,   204,   252,     0,    13,   133,    33,    15,   145,   146,
      19,   148,   149,   230,   168,     3,    25,   117,    27,   103,
     120,   121,    13,    14,   124,    10,   128,    12,    18,   131,
      20,    22,    23,   170,    33,   167,   138,     3,   117,   118,
     119,   120,   121,   122,   123,   124,    13,    13,    14,    14,
      81,   135,    83,    19,    33,    22,    23,    22,    23,    25,
      26,    27,    10,    11,    12,   145,   146,     8,   148,   149,
     207,    33,    34,   194,   195,     3,     3,     4,    33,    34,
     164,     8,    33,   220,    33,    13,    14,    34,   225,    33,
     170,    19,    19,    20,    21,    22,    23,    25,    25,    27,
      27,    33,     3,    36,    31,     9,    33,    33,    34,     3,
      33,    34,    13,    14,    33,   194,   195,   254,   255,    13,
      14,    22,    23,     3,    34,    19,    27,   207,    33,    34,
       3,    25,     3,    27,    14,    33,    28,    29,    30,    19,
     220,   221,    34,    14,   224,    25,    14,    27,    19,    28,
      29,    30,     3,    32,    25,    33,    27,    33,    34,    29,
      30,    33,    34,     3,    33,    34,    33,    34,    33,    34,
      33,    34,    33,    34,    33,    34,   256,    33,    34,    22,
      23,    33,    34,    33,    34,    33,    34,    33,    34,    33,
      34,     3,    34,    35,    33,    34,    34,    35,   272,   273,
      33,    33,     3,    34,    33,    33,     6,    34,    34,    33,
      35,    34,    34,    33,    33,    33,     3,    34,    34,    34,
      34,    34,    33,    33,    33,    17,    34,    34,    34,    34,
      34,    34,    34,    22,    33,    33,    33,    33,    23,    34,
      33,    13,    33,    33,     3,     3,    34,   143,    34,   102,
      34,    34,    34,    34,    34,    33,    33,    33,    33,    33,
      20,    34,   143,    33,    35,    33,    21,    34,    34,    34,
      34,    34,    34,   229,   260,     2,   136,    -1,    -1,    -1,
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
      33,    78,    33,    34,    34,    45,    51,    14,    63,    64,
      65,    62,    64,    65,    34,    63,    64,    65,    64,    65,
      34,    33,    34,    34,    13,    72,    13,    14,    22,    57,
      58,    59,    64,    65,    33,    52,    53,    33,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    17,
      33,    33,    33,    34,    33,    33,    54,    68,    34,    35,
      33,     3,    64,    65,    64,    26,    64,    65,    35,    53,
      62,    34,    34,    34,    34,    34,    34,    34,    33,    55,
      34,    33,    85,    88,    33,    33,    33,    34,    56,    80,
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
      61,    61,    61,    61,    62,    62,    62,    62,    62,    62,
      63,    63,    63,    63,    64,    65,    66,    66,    67,    67,
      67,    68,    68,    68,    68,    68,    69,    69,    69,    69,
      70,    70,    70,    70,    71,    72,    72,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    80,
      80,    81,    81,    82,    82,    82,    83,    84,    84,    85,
      86,    86,    87,    87,    88,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     7,     1,     2,     1,     1,     1,
       1,     1,     4,     3,     2,     2,     2,     1,     6,     6,
       2,     1,     2,     4,     3,     3,     2,     2,     2,     1,
       4,     2,     7,     4,     3,     1,     7,     1,     0,     3,
       0,     1,     3,     1,     1,     1,     1,     7,     4,     7,
       7,     4,     1,     1,     3,     2,     3,     3,     3,     1,
       1,     1,     1,     7,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     2,     2,     3,     1,     4,     4,
       4,     3,     3,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     2,     2,     3,     2,     2,
       3,     1,     2,     2,     5,     1,     1,     4,     3,     2,
       1,     2,     1,     1,     3,     1,     1,    14,    13,     4,
       2,     1,     3,     2,     6,     6
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
#line 1511 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 140 "parse.y" /* yacc.c:1646  */
    {
       //cout<<"result2"<<endl;
    }
#line 1519 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 143 "parse.y" /* yacc.c:1646  */
    {
       //cout<<"result3"<<endl;
    }
#line 1527 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 146 "parse.y" /* yacc.c:1646  */
    {
       //cout<<"pro"<<endl;
    }
#line 1535 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 149 "parse.y" /* yacc.c:1646  */
    {
       init_f = (yyvsp[-1].f);
       //cout<<"newinput"<<endl;
    }
#line 1544 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 153 "parse.y" /* yacc.c:1646  */
    {
       //cout<<"init1"<<endl;
    }
#line 1552 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 156 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"goal1"<<endl;
    }
#line 1560 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 159 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"k_and_or"<<endl;
    }
#line 1568 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 162 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"acts"<<endl;
     }
#line 1576 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 165 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"oneofs"<<endl;
      init_f = (yyvsp[0].f);
    }
#line 1585 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 172 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1593 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 177 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1601 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 182 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1609 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 185 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1617 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 190 "parse.y" /* yacc.c:1646  */
    {
      actions_f.push_back((yyvsp[0].f));
      //cout<<"one acts"<<endl;

    }
#line 1627 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 195 "parse.y" /* yacc.c:1646  */
    {
      actions_f.push_back((yyvsp[0].f));
      //cout<<"one act"<<endl;

    }
#line 1637 "../sources/parse.cpp" /* yacc.c:1646  */
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
#line 1656 "../sources/parse.cpp" /* yacc.c:1646  */
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
#line 1676 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 233 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = CONOBSERVE_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f); 
    }
#line 1687 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 239 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1695 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 244 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OBSERVE_F;
      (yyval.f) -> subformula_l = (yyvsp[0].f);
      //cout<<"observe"<<endl;
    }
#line 1706 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 252 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = PARAMETERS_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      //cout<<"para"<<endl;

    }
#line 1718 "../sources/parse.cpp" /* yacc.c:1646  */
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
#line 1731 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 270 "parse.y" /* yacc.c:1646  */
    {
    }
#line 1738 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 274 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1746 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 277 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1754 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 282 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = CONEFFECT_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);      
    }
#line 1765 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 288 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1773 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 293 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = PRECONDITION_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      //cout<<"precon"<<endl;

    }
#line 1785 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 300 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = PRECONDITION_F;
      (yyval.f) -> subformula_l = (yyvsp[0].f);

    }
#line 1796 "../sources/parse.cpp" /* yacc.c:1646  */
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
#line 1809 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 317 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = EFFECT_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      //cout<<"effect"<<endl;

    }
#line 1821 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 326 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = THREE_ATOMS_F;
      (yyval.f) -> subformula_l = (yyvsp[-2].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);

    }
#line 1833 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 333 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) == (yyvsp[0].f);

    }
#line 1842 "../sources/parse.cpp" /* yacc.c:1646  */
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
#line 1858 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 353 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);

    }
#line 1867 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 357 "parse.y" /* yacc.c:1646  */
    {      
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = EMPTY_F;

      }
#line 1877 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 364 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);

    }
#line 1886 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 368 "parse.y" /* yacc.c:1646  */
    {      
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = EMPTY_F;

      }
#line 1896 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 375 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1904 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 378 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = MULTI_THREE_ATOMS;
      (yyval.f) -> subformula_l = (yyvsp[-2].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);

    }
#line 1916 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 387 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
     }
#line 1924 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 390 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1932 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 393 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1940 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 396 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1948 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 401 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-4].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 1959 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 407 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 1970 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 415 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-4].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 1981 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 421 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-4].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 1992 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 427 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 2003 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 435 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2011 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 438 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2019 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 441 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2027 "../sources/parse.cpp" /* yacc.c:1646  */
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
#line 2050 "../sources/parse.cpp" /* yacc.c:1646  */
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
#line 2076 "../sources/parse.cpp" /* yacc.c:1646  */
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
#line 2088 "../sources/parse.cpp" /* yacc.c:1646  */
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
#line 2100 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 500 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
      //cout<<"imput_k"<<endl;
    }
#line 2109 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 504 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2117 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 507 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2125 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 510 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2133 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 513 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-4].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 2144 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 521 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2152 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 524 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2160 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 528 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2168 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 531 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);     
    }
#line 2179 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 537 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);     
    }
#line 2190 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 543 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);     
    }
#line 2201 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 552 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2209 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 555 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2217 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 558 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 2228 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 564 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 2239 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 573 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = K_F;
      f -> subformula_l = (yyvsp[0].f);
      int id = Formulatab::instance().addAtom(f);
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = K_atom;
      (yyval.f) -> pid = id;
       
    }
#line 2254 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 585 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = DK_F;
      f -> subformula_l = (yyvsp[0].f);
      int id = Formulatab::instance().addAtom(f);
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = K_atom;
      (yyval.f) -> pid = id;
    }
#line 2268 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 597 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2276 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 600 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2284 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 605 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);     
    }
#line 2295 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 611 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2303 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 614 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);    
    }
#line 2314 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 622 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2322 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 625 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2330 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 628 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2338 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 631 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2346 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 634 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2354 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 639 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);     
    }
#line 2365 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 645 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2373 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 648 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2384 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 654 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2395 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 662 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);  
    }
#line 2406 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 668 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2414 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 671 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2425 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 677 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2436 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 687 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2444 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 692 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);

    }
#line 2453 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 696 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2464 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 706 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2472 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 713 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);

    }
#line 2481 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 717 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);

    }
#line 2493 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 727 "parse.y" /* yacc.c:1646  */
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
#line 2554 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 783 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2562 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 788 "parse.y" /* yacc.c:1646  */
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
#line 2610 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 831 "parse.y" /* yacc.c:1646  */
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
#line 2658 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 880 "parse.y" /* yacc.c:1646  */
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
#line 2676 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 893 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2684 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 898 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);

    }
#line 2693 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 902 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      if((yyvsp[-1].f)-> formula_type != NEGA_F){
          (yyval.f) -> formula_type = NEGA_F;
          (yyval.f) -> subformula_l = (yyvsp[-1].f);
      }  
      else
          (yyval.f) = (yyvsp[-1].f) -> subformula_l;

    }
#line 2708 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 914 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);

    }
#line 2717 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 920 "parse.y" /* yacc.c:1646  */
    {
      int id = Vocabulary::instance().queryAtom((yyvsp[-1].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[-1].s));
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = STATE_F;
      (yyval.f) -> pid = id;
      (yyval.f) -> subformula_r = (yyvsp[0].f);

    }
#line 2732 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 930 "parse.y" /* yacc.c:1646  */
    {
      int id = Vocabulary::instance().queryAtom((yyvsp[0].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[0].s));
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = ONE_ATOM_STATE_F;
      (yyval.f) -> pid = id;
    }
#line 2745 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 940 "parse.y" /* yacc.c:1646  */
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
#line 2764 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 954 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2772 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 959 "parse.y" /* yacc.c:1646  */
    {
      int id = Vocabulary::instance().queryAtom((yyvsp[0].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[0].s));
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> pid = id;
      (yyval.f) -> formula_type=VAR_F;


    }
#line 2787 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 969 "parse.y" /* yacc.c:1646  */
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
#line 2811 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 988 "parse.y" /* yacc.c:1646  */
    {
      int id = Vocabulary::instance().queryAtom((yyvsp[0].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[0].s));
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> pid = id;
      (yyval.f) -> formula_type=VAR_F;

     }
#line 2825 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 999 "parse.y" /* yacc.c:1646  */
    {
      (yyval.s) = strdup((yyvsp[0].s));
    }
#line 2833 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1004 "parse.y" /* yacc.c:1646  */
    {
      
    }
#line 2841 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1007 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"right"<<endl;
    }
#line 2849 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1013 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"object"<<endl;
    }
#line 2857 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1018 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"words1"<<endl;
    }
#line 2865 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1021 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"word2"<<endl;

    }
#line 2874 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1027 "parse.y" /* yacc.c:1646  */
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
#line 2894 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1042 "parse.y" /* yacc.c:1646  */
    {

      string s2((yyvsp[0].s));
      int id = Vocabulary::instance().queryAtom((yyvsp[-1].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[-1].s));
      grounding_map[s2].push_back(id);
      (yyval.s) = (yyvsp[0].s);

      //cout<<"word2: "<<s2<<endl;
    }
#line 2910 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1057 "parse.y" /* yacc.c:1646  */
    {
      init_f = (yyvsp[-2].f);

      //cout<<"init"<<endl;
    }
#line 2920 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1064 "parse.y" /* yacc.c:1646  */
    {
      goal_f = (yyvsp[-2].f);
      //cout<<"goal"<<endl;
    }
#line 2929 "../sources/parse.cpp" /* yacc.c:1646  */
    break;


#line 2933 "../sources/parse.cpp" /* yacc.c:1646  */
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
#line 1075 "parse.y" /* yacc.c:1906  */

