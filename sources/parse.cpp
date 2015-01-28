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



#line 97 "../sources/parse.cpp" /* yacc.c:339  */

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
#line 32 "parse.y" /* yacc.c:355  */

    char* s;
    struct __formula* f;

#line 206 "../sources/parse.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HEADFILE_PARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 221 "../sources/parse.cpp" /* yacc.c:358  */

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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   277

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

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
       0,   126,   126,   129,   132,   135,   138,   148,   153,   158,
     161,   166,   170,   176,   190,   207,   213,   218,   226,   233,
     244,   248,   251,   256,   262,   267,   274,   280,   291,   300,
     307,   313,   327,   331,   338,   342,   349,   352,   361,   364,
     367,   370,   375,   381,   389,   395,   401,   409,   412,   415,
     418,   436,   457,   464,   477,   489,   501,   504,   507,   510,
     513,   518,   524,   527,   533,   541,   547,   550,   556,   566,
     571,   575,   585,   592,   596,   606,   609,   614,   620,   630,
     643,   648,   652,   664,   670,   680,   694,   708,   713,   723,
     742,   753,   758,   761,   767,   772,   775,   781,   796,   811,
     818
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
  "newinput", "k_and_or", "dk_and_or", "and_ors", "and_or", "or_and",
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

#define YYPACT_NINF -164

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-164)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     101,   -23,   -23,   113,     3,    51,   128,  -164,  -164,  -164,
      53,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,   113,
    -164,    32,   121,  -164,   113,   113,   113,  -164,    13,    36,
      56,    60,    68,    68,   107,   109,   129,   131,   133,    70,
      58,    74,  -164,   139,  -164,  -164,  -164,  -164,    13,  -164,
     116,   103,  -164,  -164,   106,  -164,  -164,    59,    60,    47,
      68,    80,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,   123,   134,    79,
     112,   137,  -164,   126,  -164,   151,   156,   140,   156,   142,
    -164,   127,  -164,   138,   158,    68,   190,   191,    10,   144,
     189,   126,   188,  -164,  -164,   146,  -164,   102,  -164,   164,
    -164,  -164,   192,  -164,  -164,  -164,  -164,  -164,   148,  -164,
     181,   166,    12,  -164,   197,     5,    68,   169,   170,   171,
    -164,   172,    78,  -164,   173,  -164,     8,  -164,    89,  -164,
     175,  -164,  -164,  -164,  -164,   176,  -164,   177,   178,   179,
     180,   182,   183,  -164,  -164,   -23,   149,  -164,    90,   184,
     185,   163,   198,  -164,  -164,   198,   196,   186,  -164,  -164,
     175,   201,   193,   202,   185,   203,   194,   195,   199,   200,
     204,   205,   207,  -164,     2,    15,  -164,   125,   208,   210,
    -164,   211,   212,   213,  -164,  -164,   209,   206,   220,  -164,
    -164,  -164,   214,  -164,   125,   196,   196,   198,   153,  -164,
     207,  -164,   215,   216,   217,   218,   219,  -164,   209,   221,
    -164,   222,  -164,  -164,  -164,  -164,  -164,  -164
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    47,    48,     5,
       0,    54,    59,    58,    60,    76,    80,    81,    55,     0,
      50,     0,     0,     1,     0,     0,     0,     6,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,    51,    52,    53,    90,    91,    84,    87,
      88,     0,    62,    70,     0,    66,    73,     0,     0,     0,
       0,     0,    57,    63,    64,    56,    67,    68,    69,    61,
      71,    72,    65,    74,    75,    78,    83,     0,     0,     0,
       0,     0,    12,     0,    86,     0,     0,     0,     0,     0,
      77,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,    11,     0,    89,     0,    79,     0,
       7,    22,     0,    10,     9,     8,    20,    21,     0,     2,
       0,     0,     0,     4,     0,     0,     0,     0,     0,     0,
      16,     0,     0,    24,     0,    19,     0,    17,     0,    26,
       0,    13,    14,    15,    23,     0,    18,     0,     0,     0,
       0,    39,    38,    41,    40,    33,     0,    30,     0,     0,
       0,     0,     0,    27,    25,     0,     0,     0,    32,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    29,     0,     0,    96,     0,     0,     0,
      93,     0,     0,     0,    43,    46,     0,     0,     0,    98,
      94,    95,     0,    92,     0,     0,     0,     0,     0,    36,
      35,    97,     0,     0,     0,     0,     0,    34,     0,     0,
      99,     0,    44,    45,    42,    37,    31,   100
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,  -164,  -164,  -164,   -66,   -75,  -164,    93,  -164,
     147,  -164,  -164,  -164,    98,  -164,    61,  -164,    22,  -164,
    -133,  -164,  -164,    57,  -134,  -129,    -2,  -164,  -164,   -16,
     223,    84,   224,    11,  -164,    21,   -31,  -164,  -163,   110,
     -45,  -164,  -164,  -164,  -164,     6,    77,    63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    41,    80,    98,    81,    82,   129,   130,   122,
      83,    99,   131,   132,   133,   156,   157,   167,   197,   208,
     150,   151,   152,    22,     7,     8,    11,    34,    35,    12,
      36,    13,    37,    14,    38,    15,    16,    17,    39,    48,
      49,    50,     9,   159,   185,   186,   160,   176
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      18,    60,    61,    84,   153,   184,   104,    21,    46,   154,
      10,    46,    47,   114,    55,    47,    46,   105,   184,    66,
      47,    72,   126,   127,   128,     1,     2,   177,   179,    91,
     104,   180,   178,   209,     3,   118,    19,   181,   198,   135,
      53,    56,   146,   104,   115,    64,    67,    70,    73,   200,
      28,    23,    58,   153,   202,   225,    28,     6,   154,    75,
      20,    77,    28,    78,   111,    40,    29,    30,   117,    51,
     153,   213,    31,   216,    33,   154,   214,   215,    32,    90,
      33,    43,    44,    45,    32,    95,    33,    96,   126,    54,
     128,    84,    28,    57,    97,   137,   139,    56,    73,    53,
      70,    59,   147,   148,    76,    28,    28,    79,   171,    28,
     172,     1,     2,    52,    92,   149,    33,    86,    63,    88,
      69,    31,    31,     1,     2,    31,    93,    32,    32,    33,
      33,    32,     3,    33,     4,     1,     2,    94,   147,   148,
      51,    62,    54,    65,     3,   100,    19,     1,     2,    24,
      25,    26,    85,   168,   106,    42,    24,    25,    26,   102,
      27,   108,    51,    68,    54,    71,    57,    74,    25,    26,
     102,   103,   109,   107,    71,   107,    68,    59,   116,   102,
     119,   102,   123,   169,   170,     1,     2,   217,   218,   107,
     199,   201,   110,   112,   113,    95,    96,   120,   124,   125,
     134,   121,   138,   140,   184,   141,   142,   145,   155,   158,
     161,   162,    28,   163,   164,   165,   166,   173,   175,     2,
       1,   182,   172,   211,   189,   143,   187,   101,   190,   191,
     144,   183,   219,   192,   193,   136,   174,   188,   194,   195,
     196,   210,   203,   204,   205,   206,   207,     0,   212,   220,
     221,   222,   223,   224,     0,   226,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,    89
};

static const yytype_int16 yycheck[] =
{
       2,    32,    33,    48,   138,     3,    81,     4,     3,   138,
      33,     3,     7,     3,    30,     7,     3,    83,     3,    35,
       7,    37,    10,    11,    12,    22,    23,   161,   162,    60,
     105,   165,   161,   196,    31,   101,    33,   166,    36,    34,
      29,    30,    34,   118,    34,    34,    35,    36,    37,    34,
       3,     0,    31,   187,   187,   218,     3,     0,   187,    38,
       3,     3,     3,     5,    95,    33,    13,    14,    99,    33,
     204,   204,    19,   207,    27,   204,   205,   206,    25,    58,
      27,    24,    25,    26,    25,     6,    27,     8,    10,    33,
      12,   136,     3,    33,    15,   126,   127,    86,    87,    88,
      89,    33,    13,    14,    34,     3,     3,    33,    18,     3,
      20,    22,    23,    29,    34,    26,    27,    14,    34,    13,
      36,    19,    19,    22,    23,    19,     3,    25,    25,    27,
      27,    25,    31,    27,    33,    22,    23,     3,    13,    14,
      33,    34,    33,    34,    31,    33,    33,    22,    23,    28,
      29,    30,    36,   155,     3,    34,    28,    29,    30,    33,
      32,    34,    33,    34,    33,    34,    33,    34,    29,    30,
      33,    34,    34,    33,    34,    33,    34,    33,    34,    33,
      34,    33,    34,    34,    35,    22,    23,    34,    35,    33,
     184,   185,    34,     3,     3,     6,     8,    33,    17,    33,
       3,     9,    33,    33,     3,    34,    34,    34,    33,    33,
      33,    33,     3,    34,    34,    33,    33,    33,    33,    23,
      22,    35,    20,     3,    21,   132,    33,    80,    34,    34,
     132,   170,   210,    34,    34,   125,   159,   174,    34,    34,
      33,    35,    34,    33,    33,    33,    33,    -1,    34,    34,
      34,    34,    34,    34,    -1,    34,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    23,    31,    33,    38,    60,    61,    62,    79,
      33,    63,    66,    68,    70,    72,    73,    74,    63,    33,
      60,     4,    60,     0,    28,    29,    30,    32,     3,    13,
      14,    19,    25,    27,    64,    65,    67,    69,    71,    75,
      33,    39,    34,    60,    60,    60,     3,     7,    76,    77,
      78,    33,    68,    70,    33,    66,    70,    33,    72,    33,
      73,    73,    34,    68,    70,    34,    66,    70,    34,    68,
      70,    34,    66,    70,    34,    72,    34,     3,     5,    33,
      40,    42,    43,    47,    77,    36,    14,    69,    13,    67,
      72,    73,    34,     3,     3,     6,     8,    15,    41,    48,
      33,    47,    33,    34,    43,    42,     3,    33,    34,    34,
      34,    73,     3,     3,     3,    34,    34,    73,    42,    34,
      33,     9,    46,    34,    17,    33,    10,    11,    12,    44,
      45,    49,    50,    51,     3,    34,    76,    73,    33,    73,
      33,    34,    34,    45,    51,    34,    34,    13,    14,    26,
      57,    58,    59,    61,    62,    33,    52,    53,    33,    80,
      83,    33,    33,    34,    34,    33,    33,    54,    63,    34,
      35,    18,    20,    33,    83,    33,    84,    61,    62,    61,
      61,    62,    35,    53,     3,    81,    82,    33,    84,    21,
      34,    34,    34,    34,    34,    34,    33,    55,    36,    82,
      34,    82,    57,    34,    33,    33,    33,    33,    56,    75,
      35,     3,    34,    57,    62,    62,    61,    34,    35,    55,
      34,    34,    34,    34,    34,    75,    34,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    38,    38,    38,    39,    40,    41,
      41,    42,    42,    43,    43,    44,    44,    45,    46,    46,
      47,    48,    48,    49,    49,    50,    50,    50,    51,    52,
      52,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      57,    57,    58,    58,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    61,    62,    63,    63,    63,    63,
      63,    64,    64,    64,    64,    65,    65,    65,    65,    66,
      67,    67,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    75,    75,    76,    76,    77,    77,
      77,    78,    79,    79,    80,    81,    81,    82,    82,    83,
      84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     7,     1,     2,     4,     3,     2,
       2,     2,     1,     6,     6,     2,     1,     2,     4,     3,
       3,     2,     2,     2,     1,     4,     2,     4,     4,     3,
       1,     7,     1,     0,     3,     0,     1,     3,     1,     1,
       1,     1,     7,     4,     7,     7,     4,     1,     1,     3,
       2,     3,     3,     3,     2,     2,     3,     3,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       2,     2,     3,     2,     2,     3,     1,     3,     2,     5,
       1,     1,     4,     3,     2,     1,     2,     1,     1,     3,
       1,     1,    14,    13,     4,     2,     1,     3,     2,     6,
       6
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
#line 126 "parse.y" /* yacc.c:1646  */
    {
       cout<<"result1"<<endl;
    }
#line 1465 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 129 "parse.y" /* yacc.c:1646  */
    {
       cout<<"result2"<<endl;
    }
#line 1473 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 132 "parse.y" /* yacc.c:1646  */
    {
       cout<<"result3"<<endl;
    }
#line 1481 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 135 "parse.y" /* yacc.c:1646  */
    {
       cout<<"pro"<<endl;
    }
#line 1489 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 138 "parse.y" /* yacc.c:1646  */
    {
       init_f = (yyvsp[-1].f);
       cout<<"newinput"<<endl;
    }
#line 1498 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 148 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1506 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 153 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1514 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 158 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1522 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 161 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1530 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 166 "parse.y" /* yacc.c:1646  */
    {
      actions_f.push_back((yyvsp[0].f));

    }
#line 1539 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 170 "parse.y" /* yacc.c:1646  */
    {
      actions_f.push_back((yyvsp[0].f));

    }
#line 1548 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 176 "parse.y" /* yacc.c:1646  */
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
#line 1567 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 190 "parse.y" /* yacc.c:1646  */
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
#line 1587 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 207 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = CONOBSERVE_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f); 
    }
#line 1598 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 213 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1606 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 218 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OBSERVE_F;
      (yyval.f) -> subformula_l = (yyvsp[0].f);
      //cout<<"observe"<<endl;
    }
#line 1617 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 226 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = PARAMETERS_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      //cout<<"para"<<endl;

    }
#line 1629 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 233 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = PARAMETERS_F;
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = EMPTY_F;
      (yyval.f) -> subformula_l = f;

    }
#line 1642 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 244 "parse.y" /* yacc.c:1646  */
    {
    }
#line 1649 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 248 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1657 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 251 "parse.y" /* yacc.c:1646  */
    {

    }
#line 1665 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 256 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = CONEFFECT_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);      
    }
#line 1676 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 262 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1684 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 267 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = PRECONDITION_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      //cout<<"precon"<<endl;

    }
#line 1696 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 274 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = PRECONDITION_F;
      (yyval.f) -> subformula_l = (yyvsp[0].f);

    }
#line 1707 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 280 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = TRUE_F;
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = PRECONDITION_F;
      (yyval.f) -> subformula_l = f;
      //cout<<"true"<<endl;
    }
#line 1720 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 291 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = EFFECT_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      //cout<<"effect"<<endl;

    }
#line 1732 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 300 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = THREE_ATOMS_F;
      (yyval.f) -> subformula_l = (yyvsp[-2].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);

    }
#line 1744 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 307 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) == (yyvsp[0].f);

    }
#line 1753 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 313 "parse.y" /* yacc.c:1646  */
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
#line 1769 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 327 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);

    }
#line 1778 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 331 "parse.y" /* yacc.c:1646  */
    {      
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = EMPTY_F;

      }
#line 1788 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 338 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);

    }
#line 1797 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 342 "parse.y" /* yacc.c:1646  */
    {      
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = EMPTY_F;

      }
#line 1807 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 349 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1815 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 352 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = MULTI_THREE_ATOMS;
      (yyval.f) -> subformula_l = (yyvsp[-2].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);

    }
#line 1827 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 361 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
     }
#line 1835 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 364 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1843 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 367 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1851 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 370 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1859 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 375 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-4].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 1870 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 381 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 1881 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 389 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-4].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 1892 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 395 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-4].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 1903 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 401 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-3].f);
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 1914 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 409 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1922 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 412 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 1930 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 415 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 1938 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 418 "parse.y" /* yacc.c:1646  */
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
#line 1961 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 436 "parse.y" /* yacc.c:1646  */
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
#line 1987 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 457 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = CONJ_F;
      f -> subformula_l = (yyvsp[-2].f);
      f -> subformula_r = (yyvsp[0].f); 
      (yyval.f) = f;
    }
#line 1999 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 464 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));     
      f -> formula_type = DISJ_F;
      f -> subformula_l = (yyvsp[-2].f);
      f -> subformula_r = (yyvsp[0].f);     
      (yyval.f) = f;
    }
#line 2011 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 477 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = K_F;
      f -> subformula_l = (yyvsp[0].f);
      int id = Formulatab::instance().addAtom(f);
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = K_atom;
      (yyval.f) -> pid = id;
       
    }
#line 2026 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 489 "parse.y" /* yacc.c:1646  */
    {
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = DK_F;
      f -> subformula_l = (yyvsp[0].f);
      int id = Formulatab::instance().addAtom(f);
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = K_atom;
      (yyval.f) -> pid = id;
    }
#line 2040 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 501 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2048 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 504 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2056 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 507 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2064 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 510 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2072 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 513 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2080 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 518 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);     
    }
#line 2091 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 524 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2099 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 527 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2110 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 533 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2121 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 541 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);  
    }
#line 2132 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 547 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2140 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 550 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2151 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 556 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2162 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 566 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2170 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 571 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);

    }
#line 2179 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 575 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = AND_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2190 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 585 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2198 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 592 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);

    }
#line 2207 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 596 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = OR_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);

    }
#line 2219 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 606 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);
    }
#line 2227 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 609 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2235 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 614 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = ONEOF_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2246 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 620 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = ONEOF_F;
      (yyval.f) -> subformula_l = (yyvsp[-1].f);
      (yyval.f) -> subformula_r = (yyvsp[0].f);
    }
#line 2257 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 630 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      _formula* f = (__formula*)malloc(sizeof(_formula));
      if((yyvsp[-2].f)-> formula_type != NEGA_F){
          f -> formula_type = NEGA_F;
          f -> subformula_l = (yyvsp[-2].f);
      }
      else
          f = (yyvsp[-2].f)-> subformula_l;
      (yyval.f) -> formula_type = DISJ_F;
      (yyval.f) -> subformula_l = f;
      (yyval.f) -> subformula_r = (yyvsp[-1].f);
    }
#line 2275 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 643 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2283 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 648 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);

    }
#line 2292 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 652 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      if((yyvsp[-1].f)-> formula_type != NEGA_F){
          (yyval.f) -> formula_type = NEGA_F;
          (yyval.f) -> subformula_l = (yyvsp[-1].f);
      }  
      else
          (yyval.f) = (yyvsp[-1].f) -> subformula_l;

    }
#line 2307 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 664 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[-1].f);

    }
#line 2316 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 670 "parse.y" /* yacc.c:1646  */
    {
      int id = Vocabulary::instance().queryAtom((yyvsp[-1].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[-1].s));
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = STATE_F;
      (yyval.f) -> pid = id;
      (yyval.f) -> subformula_r = (yyvsp[0].f);

    }
#line 2331 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 680 "parse.y" /* yacc.c:1646  */
    {
      int id = Vocabulary::instance().queryAtom((yyvsp[0].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[0].s));
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> formula_type = ONE_ATOM_STATE_F;
      (yyval.f) -> pid = id;
      vector<int> v;
      v.push_back(id); 
      string s1((yyvsp[0].s));     
      grounding_map[s1] = v;
    }
#line 2348 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 694 "parse.y" /* yacc.c:1646  */
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
#line 2367 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 708 "parse.y" /* yacc.c:1646  */
    {
      (yyval.f) = (yyvsp[0].f);
    }
#line 2375 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 713 "parse.y" /* yacc.c:1646  */
    {
      int id = Vocabulary::instance().queryAtom((yyvsp[0].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[0].s));
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> pid = id;
      (yyval.f) -> formula_type=VAR_F;


    }
#line 2390 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 723 "parse.y" /* yacc.c:1646  */
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
#line 2414 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 742 "parse.y" /* yacc.c:1646  */
    {
      int id = Vocabulary::instance().queryAtom((yyvsp[0].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[0].s));
      (yyval.f) = (__formula*)malloc(sizeof(_formula));
      (yyval.f) -> pid = id;
      (yyval.f) -> formula_type=VAR_F;

     }
#line 2428 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 753 "parse.y" /* yacc.c:1646  */
    {
      (yyval.s) = strdup((yyvsp[0].s));
    }
#line 2436 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 758 "parse.y" /* yacc.c:1646  */
    {

    }
#line 2444 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 761 "parse.y" /* yacc.c:1646  */
    {

    }
#line 2452 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 767 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"object"<<endl;
    }
#line 2460 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 772 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"words1"<<endl;
    }
#line 2468 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 775 "parse.y" /* yacc.c:1646  */
    {
      //cout<<"word2"<<endl;

    }
#line 2477 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 781 "parse.y" /* yacc.c:1646  */
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
#line 2497 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 796 "parse.y" /* yacc.c:1646  */
    {

      string s2((yyvsp[0].s));
      int id = Vocabulary::instance().queryAtom((yyvsp[-1].s));
      if(id < 0)
          id = Vocabulary::instance().addAtom((yyvsp[-1].s));
      grounding_map[s2].push_back(id);
      (yyval.s) = (yyvsp[0].s);

      //cout<<"word2: "<<s2<<endl;
    }
#line 2513 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 811 "parse.y" /* yacc.c:1646  */
    {
      init_f = (yyvsp[-2].f);

      //cout<<"init"<<endl;
    }
#line 2523 "../sources/parse.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 818 "parse.y" /* yacc.c:1646  */
    {
      goal_f = (yyvsp[-2].f);
      //cout<<"goal"<<endl;
    }
#line 2532 "../sources/parse.cpp" /* yacc.c:1646  */
    break;


#line 2536 "../sources/parse.cpp" /* yacc.c:1646  */
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
#line 829 "parse.y" /* yacc.c:1906  */

