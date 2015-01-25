/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_PARSE_H_INCLUDED
# define YY_YY_PARSE_H_INCLUDED
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
#line 32 "parse.y" /* yacc.c:1909  */

    char* s;
    struct __formula* f;

#line 123 "../parse.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_H_INCLUDED  */
