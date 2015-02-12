%{
#include "parse.h"
extern "C" {
	int yywrap(void);
	int yylex(void);
}
extern int context_flag;/* 0 - not in any atom, 1  - in an atom*/

%}


a [Aa]
b [Bb]
c [Cc]
d [Dd]
e [Ee]
f [Ff]
g [Gg]
h [Hh]
i [Ii]
j [Jj]
k [k]
l [Ll]
m [Mm]
n [Nn]
o [Oo]
p [Pp]
q [Qq]
r [Rr]
s [Ss]
t [Tt]
u [Uu]
v [Vv]
w [Ww]
x [Xx]
y [Yy]
z [Zz]
blank	  			[ \n\t\r]*
word                            [a-zA-Z0-9\-_.]+
var                             \?[a-zA-Z][a-zA-Z0-9\-_]* 


%%
"("                                     {  return('('); }

")"                                     {  return(')'); }

"-"                                     {  return('-'); }

","                                     {  return(','); }

"~"                                     {  return(S_NEG); }

"->"                                    {return (S_IMPL);}
"&"					{return (S_CONJ);}
"|"                                     {return (S_DISJ);}
"."                                     {return (End);}
{var}                                   {  yylval.s=strdup(yytext);  return(VAR_TOK); }

{d}{e}{f}{i}{n}{e}                      {  return(DEFINE_TOK); }

{d}{o}{m}{a}{i}{n}                      {  return(DOMAIN_TOK); }

":"{d}{o}{m}{a}{i}{n}                   {  return(DOMAIN_TOK_P);}

":"{o}{b}{j}{e}{c}{t}{s}                {  return(OBJECT_TOK_P);}

":"{i}{n}{i}{t}                         {  return(INIT_TOK_P);}

":"{g}{o}{a}{l}                         {  return(GOAL_TOK_P);}

{o}{n}{e}{o}{f}                         {  return(ONEOF_TOK_P);}

":"{r}{e}{q}{u}{i}{r}{e}{m}{e}{n}{t}{s} {  return(REQUIREMENTS_TOK); }

":"{t}{y}{p}{e}{s}                      {  return(TYPES_TOK) ; }

":"{p}{r}{e}{d}{i}{c}{a}{t}{e}{s}       {  return(PREDICATES_TOK); }

":"{a}{c}{t}{i}{o}{n}                   {  return(ACTION_TOK); }

":"{p}{a}{r}{a}{m}{e}{t}{e}{r}{s}       {  return(PARAMETERS_TOK); }

":"{o}{b}{s}{e}{r}{v}{e}                {  return(OBSERVE_TOK); }

":"{p}{r}{e}{c}{o}{n}{d}{i}{t}{i}{o}{n} {  return(PRECONDITION_TOK); }

":"{e}{f}{f}{e}{c}{t}                   {  return(EFFECT_TOK); }

":"                                     {  return ':';}

{a}{n}{d}                               {  return(AND_TOK); }

{n}{o}{t}                               {  return(NOT_TOK); }

{o}{r}                                  {  return(OR_TOK); }

{i}{m}{p}{l}{y}                         {  return(IMPLY_TOK);}

{t}{r}{u}{e}                            {  return(TRUE_TOK);}

"K"                                     {  return(K_TOK);}

"D""K"                                    {  return(DK_TOK);}

{word}                                  {
                                            yylval.s=strdup(yytext); 
                                            return WORD_TOK;
                                        }
{blank}		    	                {/* skip blankspace */	}
%%

int yywrap()
{
  return 1;
}
