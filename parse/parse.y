%{

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


%}

%union {
    char* s;
    struct __formula* f;
}


%token <s> WORD_TOK
%token <s> DEFINE_TOK
%token <s> DOMAIN_TOK
%token <s> PREDICATES_TOK
%token <s> VAR_TOK
%token <s> ACTION_TOK
%token <s> PARAMETERS_TOK
%token <s> OBSERVE_TOK
%token <s> PRECONDITION_TOK
%token <s> EFFECT_TOK
%token <s> AND_TOK
%token <s> OR_TOK
%token <s> TYPES_TOK
%token <s> WHEN_TOK
%token <s> DOMAIN_TOK_P
%token <s> OBJECT_TOK_P
%token <s> ONEOF_TOK_P
%token <s> INIT_TOK_P
%token <s> GOAL_TOK_P
%token <s> K_TOK
%token <s> DK_TOK
%token <s> REQUIREMENTS_TOK
%token <s> IMPLY_TOK
%token <s> TRUE_TOK
%token <s> NOT_TOK
%token <s> S_IMPL
%token <s> S_CONJ
%token <s> S_DISJ
%token <s> S_NEG
%token <s> End

%type <s> result
%type <s> predicates
%type <s> predicate
%type <s> types
%type <s> typess
%type <s> object
%type <f> init
%type <f> goal
%type <s> word
%type <s> words


%type <f> imply
%type <f> action
%type <s> actions
%type <f> parameters
%type <f> conobserve
%type <f> observe
%type <f> precondition
%type <f> effect
%type <f> coneffect
%type <f> and
%type <f> or
%type <f> nstate
%type <s> vartok
%type <s> pro
%type <f> state
%type <f> var
%type <f> vars
%type <s> domain
%type <f> threeatom
%type <f> threeatoms
%type <f> threeatom1
%type <f> threeatom23
%type <f> statewithoutp
%type <f> multi_threeatom23
%type <f> ig_k_and_or
%type <f> k_and_or
%type <f> and_or
%type <f> s5_term_k
%type <f> disj_k
%type <f> dk_and_or
%type <f> oneof
%type <f> oneofs
%type <f> ors
%type <f> or_and
%type <f> ands
%type <f> and_ors
%type <f> and_orss
%type <f> and_orsss
%type <f> newinput

%type <f> input_k
%type <f> and_or_k_atom
%type <f> or_k_atoms

%left S_IMPL
%left S_DISJ S_CONJ
%left S_NEG
%left IMPLY_TOK
%left OR_TOK AND_TOK
%left NOT_TOK


%%

result
    : '(' DEFINE_TOK domain predicates  actions ')'{
       //cout<<"result1"<<endl;
    }
    | '(' DEFINE_TOK domain actions ')'{
       //cout<<"result2"<<endl;
    }   
    | '(' DEFINE_TOK domain typess predicates  actions ')'{
       //cout<<"result3"<<endl;
    }
    |  pro{
       //cout<<"pro"<<endl;
    }  
    |  newinput End{
       init_f = $1;
       //cout<<"newinput"<<endl;
    }
    | init {
       //cout<<"init1"<<endl;
    }
    | goal{
      //cout<<"goal1"<<endl;
    }
    | k_and_or{
      //cout<<"k_and_or"<<endl;
    }
    | actions {
      //cout<<"acts"<<endl;
     }
    | oneofs {
      //cout<<"oneofs"<<endl;
      init_f = $1;
    }


domain
    : '(' DOMAIN_TOK WORD_TOK ')'{

    }

typess
    : '(' types ')'{

    }

types
    : types WORD_TOK{

    }
    | TYPES_TOK WORD_TOK{

    }

actions
    : actions action{
      actions_f.push_back($2);
      //cout<<"one acts"<<endl;

    }
    | action{
      actions_f.push_back($1);
      //cout<<"one act"<<endl;

    }

action
    : '(' ACTION_TOK WORD_TOK parameters conobserve ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = ACTION_F;
      int id = Vocabulary::instance().queryAtom($3);
      if(id < 0)
          id = Vocabulary::instance().addAtom($3);
      $$ -> pid = id;

      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = ACTION_CONTEXT_F;
      f -> subformula_l = $4;
      f -> subformula_r = $5;
      $$ -> subformula_r = f;
    }
    | '(' ACTION_TOK WORD_TOK parameters coneffect ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = ACTION_F;
      int id = Vocabulary::instance().queryAtom($3);
      if(id < 0)
          id = Vocabulary::instance().addAtom($3);
      $$ -> pid = id;

      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = ACTION_CONTEXT_F;
      f -> subformula_l = $4;
      f -> subformula_r = $5;
      $$ -> subformula_r = f;

    }

conobserve
    : precondition observe{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = CONOBSERVE_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $2; 
    }
    | observe{
      $$ = $1;
    }

observe
    : OBSERVE_TOK and_ors{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = OBSERVE_F;
      $$ -> subformula_l = $2;
      //cout<<"observe"<<endl;
    }

parameters
    : PARAMETERS_TOK '(' vars ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = PARAMETERS_F;
      $$ -> subformula_l = $3;
      //cout<<"para"<<endl;

    }
    | PARAMETERS_TOK '(' ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = PARAMETERS_F;
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = EMPTY_F;
      $$ -> subformula_l = f;

    }
    

predicates
    : '(' predicate ')'{
    }

predicate
    : predicate  nstate {

    }
    | PREDICATES_TOK  nstate {

    }

coneffect
    : precondition effect {
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = CONEFFECT_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $2;      
    }
    | effect{
      $$ = $1;
    }

precondition
    : PRECONDITION_TOK '(' ig_k_and_or ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = PRECONDITION_F;
      $$ -> subformula_l = $3;
      //cout<<"precon"<<endl;

    }
    | PRECONDITION_TOK  nstate {
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = PRECONDITION_F;
      $$ -> subformula_l = $2;

    }
    | PRECONDITION_TOK '(' TRUE_TOK ')'{
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = TRUE_F;
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = PRECONDITION_F;
      $$ -> subformula_l = f;
      //cout<<"true"<<endl;
    }
   

effect
    : EFFECT_TOK '(' threeatoms ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = EFFECT_F;
      $$ -> subformula_l = $3;
      //cout<<"effect"<<endl;

    }

threeatoms
    : threeatoms ',' threeatom{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = THREE_ATOMS_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $3;

    }
    | threeatom{
      $$ == $1;

    }

threeatom
    : '(' threeatom1 ',' threeatom23 ',' threeatom23 ')'{
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = THREE_ATOM_BEHIND_F;
      f -> subformula_l = $4;
      f -> subformula_r = $6;
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = THREE_ATOM_F;
      $$ -> subformula_l = $2;
      $$ -> subformula_r = f;

    }


threeatom1
    : and_ors{
      $$ = $1;

    }
    | {      
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = EMPTY_F;

      }

threeatom23
    : '(' multi_threeatom23 ')'{
      $$ = $2;

    }
    | {      
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = EMPTY_F;

      }

multi_threeatom23
    : statewithoutp{
      $$ = $1;
    }
    | multi_threeatom23 ',' statewithoutp{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = MULTI_THREE_ATOMS;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $3;

    }

ig_k_and_or
    : s5_term_k{
      $$ = $1;
     }
    | disj_k{
      $$ = $1;
    }
    | dk_and_or{
      $$ = $1;
    }
    | k_and_or{
      $$ = $1;
    }

disj_k
    : OR_TOK '(' k_and_or ')' '(' k_and_or ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = OR_F;
      $$ -> subformula_l = $3;
      $$ -> subformula_r = $6;
    } 
    | disj_k '(' k_and_or ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = OR_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $3;
    }

s5_term_k
    : AND_TOK '(' k_and_or ')' '(' dk_and_or ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = AND_F;
      $$ -> subformula_l = $3;
      $$ -> subformula_r = $6;
    }
    | AND_TOK '(' dk_and_or ')' '(' dk_and_or ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = AND_F;
      $$ -> subformula_l = $3;
      $$ -> subformula_r = $6;
    }
    | s5_term_k '(' dk_and_or ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = AND_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $3;
    }
    
newinput
    : k_and_or{
      $$ = $1;
    }
    | dk_and_or{
      $$ = $1;
    }
    | '(' newinput ')'{
      $$ = $2;
    }
    | S_NEG newinput{
      _formula* f = (__formula*)malloc(sizeof(_formula));
      _formula* f1 = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = NEGA_F;
      f -> subformula_l = Formulatab::instance().getAtom($2 -> pid) -> subformula_l;
      //int id = Formulatab::instance().addAtom(f);
      f1 -> subformula_l = f;

      if(Formulatab::instance().getAtom($2 -> pid) -> formula_type == DK_F)
        f1 -> formula_type = K_F;
      else
        f1 -> formula_type = DK_F;
      int id = Formulatab::instance().addAtom(f1);
      
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> pid = id;
      $$ -> formula_type = K_atom;
    }
    | newinput S_IMPL newinput{
      _formula* f = (__formula*)malloc(sizeof(_formula));
      _formula* f1 = (__formula*)malloc(sizeof(_formula));
      _formula* f11 = (__formula*)malloc(sizeof(_formula));
      _formula* f2 = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = NEGA_F;
      f -> subformula_l = Formulatab::instance().getAtom($1 -> pid) -> subformula_l;
      //int id = Formulatab::instance().addAtom(f);
      f1 -> subformula_l = f;
      if(Formulatab::instance().getAtom($1 -> pid) -> formula_type == DK_F)
        f1 -> formula_type = K_F;
      else
        f1 -> formula_type = DK_F;
      int id = Formulatab::instance().addAtom(f1);
      f11 -> pid = id;
      f11 -> formula_type = K_atom;
      f2 -> formula_type = DISJ_F;
      f2 -> subformula_l = f11;
      f2 -> subformula_r = $3;
      $$ = f2;
    } 
    | newinput S_CONJ newinput{
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = CONJ_F;
      f -> subformula_l = $1;
      f -> subformula_r = $3; 
      $$ = f;
    }
    | newinput S_DISJ newinput{
      _formula* f = (__formula*)malloc(sizeof(_formula));     
      f -> formula_type = DISJ_F;
      f -> subformula_l = $1;
      f -> subformula_r = $3;     
      $$ = f;
    }     


input_k 
    :  and_or_k_atom {
      $$ = $1;
      //cout<<"imput_k"<<endl;
    }
    |  or_k_atoms  {
      $$ = $1;
    }
    |  k_and_or {
      $$ = $1;
    }
    |  dk_and_or  {
      $$ = $1;
    }

and_or_k_atom
    : AND_TOK  '(' or_k_atoms ')' {
      $$ = $3;
    }
    | AND_TOK  '(' k_and_or ')' {
      $$ = $3;
    }
    
    | AND_TOK  '(' dk_and_or ')' {
      $$ = $3;
    }
    | and_or_k_atom '(' or_k_atoms ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = AND_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $3;     
    }
    | and_or_k_atom  '(' k_and_or ')' {
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = AND_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $3;     
    }
    | and_or_k_atom  '(' dk_and_or ')' {
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = AND_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $3;     
    }


or_k_atoms
    : OR_TOK '(' k_and_or ')'{
      $$ = $3;
    }
    | OR_TOK '(' dk_and_or ')'{
      $$ = $3;
    }
    | or_k_atoms  '(' k_and_or ')' {
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = OR_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $3;
    }
    | or_k_atoms  '(' dk_and_or ')' {
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = OR_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $3;
    }


k_and_or
    : K_TOK  and_orsss{
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = K_F;
      f -> subformula_l = $2;
      int id = Formulatab::instance().addAtom(f);
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = K_atom;
      $$ -> pid = id;
       
    }

dk_and_or
    : DK_TOK and_orsss{
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f -> formula_type = DK_F;
      f -> subformula_l = $2;
      int id = Formulatab::instance().addAtom(f);
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = K_atom;
      $$ -> pid = id;
    }


and_orsss
    : '(' and_orss ')'{
      $$ = $2;
    }
    | and_ors{
      $$ = $1;
    }

and_orss 
    : and '(' or_and ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = AND_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $3;     
    }
    | AND_TOK  '(' or_and ')'{
      $$ = $3;
    }
    | and_orss '(' or_and ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = AND_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $3;    
    }

and_ors
    : '(' or_and ')'{
      $$ = $2;
    }
    | '(' and_or ')'{
      $$ = $2;
    }
    | ors{
      $$ = $1;
    }
    | ands{
      $$ = $1;
    }
    | oneofs{
      $$ = $1;
    }

and_or 
    : and ors{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = AND_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $2;     
    }
    | AND_TOK  ors  {
      $$ = $2;
    }
    | and_or ors  {
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = AND_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $2;
    }
    | and_or oneofs{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = AND_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $2;
    }

or_and 
    : or ands{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = OR_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $2;  
    }
    | OR_TOK ands{
      $$ = $2;
    }
    | or_and ands{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = OR_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $2;
    }
    | or_and oneofs{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = OR_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $2;
    }



ands
    : '(' and ')'{
      $$ = $2;
    }

and
    : AND_TOK  oneofs {
      $$ = $2;

    }
    | and oneofs {
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = AND_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $2;
    }



ors 
    : '(' or ')'{
      $$ = $2;
    }
    


or
    : OR_TOK oneofs {
      $$ = $2;

    }
    | or oneofs{
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = OR_F;
      $$ -> subformula_l = $1;
      $$ -> subformula_r = $2;

    }


oneofs
    : '(' oneof ')'{
      vector<_formula*> fm;
      for(int i = 0; i < $2->count; i++){
         _formula* f = (__formula*)malloc(sizeof(_formula));
         f -> formula_type = ONE_ATOM_STATE_F;
         f -> pid = $2->pidlist[i];
         fm.push_back(f);
      }
      vector<_formula*> fm1;
      for(int i = 0; i < $2->count; i++){
         _formula* f = (__formula*)malloc(sizeof(_formula));
         if(i==0)
             f = fm[0];
         if(i!=0){
             f->formula_type = NEGA_F;
             f->subformula_l = fm[0];
          }
          
         for(int j = 1; j < $2->count; j++){
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
      for(int i=2; i < $2->count; i++)
      {
        _formula* f1 = (__formula*)malloc(sizeof(_formula));
        f1->formula_type = OR_F;
        f1->subformula_l = f;
        f1->subformula_r = fm1[i];
        f = f1;
      }
      $$ = f;
      
    }
    | imply{
      $$ = $1;
    }

oneof 
    : ONEOF_TOK_P state{
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f = $2;
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
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = ONEOF_F;
      $$ -> count = 1;
      $$ -> pidlist[0] = ie;
    }
    | oneof state{
      _formula* f = (__formula*)malloc(sizeof(_formula));
      f = $2;
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
      $$ = $1;
      $$->pidlist[$1->count] = ie;
      $$->count = $1->count+1;

    }





imply
    : '(' IMPLY_TOK  nstate  nstate ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      _formula* f = (__formula*)malloc(sizeof(_formula));
      if($3-> formula_type != NEGA_F){
          f -> formula_type = NEGA_F;
          f -> subformula_l = $3;
      }
      else
          f = $3-> subformula_l;
      $$ -> formula_type = OR_F;
      $$ -> subformula_l = f;
      $$ -> subformula_r = $4;
    }
    | nstate{
      $$ = $1;
    }

nstate
    : state{
      $$ = $1;

    }
    | '(' NOT_TOK nstate ')'{
      $$ = (__formula*)malloc(sizeof(_formula));
      if($3-> formula_type != NEGA_F){
          $$ -> formula_type = NEGA_F;
          $$ -> subformula_l = $3;
      }  
      else
          $$ = $3 -> subformula_l;

    }

state
    : '(' statewithoutp ')'{
      $$ = $2;

    }

statewithoutp
    : WORD_TOK vars {
      int id = Vocabulary::instance().queryAtom($1);
      if(id < 0)
          id = Vocabulary::instance().addAtom($1);
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = STATE_F;
      $$ -> pid = id;
      $$ -> subformula_r = $2;

    }
    | WORD_TOK {
      int id = Vocabulary::instance().queryAtom($1);
      if(id < 0)
          id = Vocabulary::instance().addAtom($1);
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = ONE_ATOM_STATE_F;
      $$ -> pid = id;
    }

vars 
    : vars var{
      if($1 -> formula_type == VAR_F){
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> formula_type = VARS_F;
      $$ -> count = 2;
      $$ -> pidlist[0] = $1 -> pid;
      $$ -> pidlist[1] = $2 -> pid;
      }
      else{
      $$ -> count = $$ -> count + 1;
      $$ -> pidlist[$$ -> count-1] = $2 -> pid;
      }

    }
    | var{
      $$ = $1;
    }

var
    : vartok{
      int id = Vocabulary::instance().queryAtom($1);
      if(id < 0)
          id = Vocabulary::instance().addAtom($1);
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> pid = id;
      $$ -> formula_type=VAR_F;


    }
    | vartok '-' WORD_TOK{
      string s0($1);

      string s3($3);
      string s1=s0+"."+s3;      
      char *c;
      int len = s1.length();
      c = (char *)malloc((len+1)*sizeof(char));
      s1.copy(c,len,0);
      c[len]='\0';
      int id = Vocabulary::instance().queryAtom(c);
      if(id < 0)
          id = Vocabulary::instance().addAtom(c);
      $$ = (__formula*)malloc(sizeof(_formula));
      $$->pid = id;
      $$->formula_type=VAR_F;


    }
    | WORD_TOK{
      int id = Vocabulary::instance().queryAtom($1);
      if(id < 0)
          id = Vocabulary::instance().addAtom($1);
      $$ = (__formula*)malloc(sizeof(_formula));
      $$ -> pid = id;
      $$ -> formula_type=VAR_F;

     }

vartok
    : VAR_TOK{
      $$ = strdup($1);
    }

pro
    : '(' DEFINE_TOK '(' WORD_TOK WORD_TOK ')' '(' DOMAIN_TOK_P WORD_TOK ')' object init goal ')'{
      
    }
    |'(' DEFINE_TOK '(' WORD_TOK WORD_TOK ')' '(' DOMAIN_TOK_P WORD_TOK ')' init goal ')'{
      //cout<<"right"<<endl;
    }
    

object
    : '(' OBJECT_TOK_P words ')'{
      //cout<<"object"<<endl;
    }

words
    : words word{
      //cout<<"words1"<<endl;
    }
    | word{
      //cout<<"word2"<<endl;

    }

word
    : WORD_TOK '-' WORD_TOK{

      
      string s3($3);
      vector<int> v;
      int id = Vocabulary::instance().queryAtom($1);
      if(id < 0)
          id = Vocabulary::instance().addAtom($1);
      v.push_back(id);
      grounding_map[s3] = v;
      $$ = $3;
      //cout<<"word1: "<<s3<<endl;

      
    }
    | WORD_TOK word{

      string s2($2);
      int id = Vocabulary::instance().queryAtom($1);
      if(id < 0)
          id = Vocabulary::instance().addAtom($1);
      grounding_map[s2].push_back(id);
      $$ = $2;

      //cout<<"word2: "<<s2<<endl;
    }



init
    : '(' INIT_TOK_P '(' input_k ')' ')'{
      init_f = $4;

      //cout<<"init"<<endl;
    }

goal
    : '(' GOAL_TOK_P '(' input_k ')' ')'{
      goal_f = $4;
      //cout<<"goal"<<endl;
    }

;





%%
