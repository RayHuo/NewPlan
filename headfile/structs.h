#ifndef STRUCTS_H
#define	STRUCTS_H

#define MAX_ATOM_LENGTH 512
#define MAX_ATOM_NUMBER 1024

#include <string>
#include <vector>
#include <set>

using namespace std;
// Type definition
////////////////////////////////////////////////////////////////////////////////

enum FORMULA_TYPE {
    STATE_F = 0,	//atom
    ONE_ATOM_STATE_F,
    VARS_F,
    VAR_F,
    NEGA_F,		//negation
    AND_F,
    OR_F,
    CONOBSERVE_F,
    OBSERVE_F,
    ACTION_F,
    PARAMETERS_F,
    PRECONDITION_F ,
    EFFECT_F,
    CONEFFECT_F,
    EMPTY_F,
    TRUE_F,
    FALSE_F,
    ONEOF_F,
    THREE_ATOM_F,
    THREE_ATOMS_F,
    THREE_ATOM_BEHIND_F,
    MULTI_THREE_ATOMS,
    K_F,
    DK_F,
    ACTION_CONTEXT_F,
    IMPLY_F,
    DISJ_F,
    CONJ_F,
    IMPL_F,
    K_atom,
             
};

/*enum STATE_TYPE {
    TOBEEXPLORED = 0,
    EXPLORED, 
    DEAD,
    GOAL 
};*/

typedef struct __formula {
    FORMULA_TYPE formula_type;
    //vector <string>  vars;
    int count;
    union {
        __formula* subformula_l;   //NEGA,CONJ,DISJ,IMPL
        int pid;                 //ATOM
        int pidlist[11];
    };
    __formula* subformula_r;   //CONJ,DISJ,IMPL
}_formula;

struct pre {
    vector<int> k;
    vector<vector<int> > dk; 
};

/*
//Transition
typedef struct tran_bdd_states{
    int front_bdd_state;
    int next_bdd_state;
    bool is_observe_action;
    bool is_true;
    //bool is_new_node;
    int action_number; 
}_transtates; 

//node type 1: definition 1 subjective epistemic term
typedef struct s5_term{
    BDD k;
    vector<BDD> dk; 
}_s5_term;

//node type 2: definition 2 epistemic disjunctive normal form
typedef struct disj_k_state{
    vector<BDD> k;
}_disj_k_state; 

typedef struct con_eff{
    BDD con;
    vector<int> add;
    vector<int> del;
}_con_eff;

//Ontic action: definition 3
typedef struct effect_bdd_action{
    string name;
    int act_num;
    vector<string> para;
    vector<string> para_match;
    _s5_term pre; 
    vector<int> effect_atoms;
    vector<int> effect_new_atoms;
    vector< _con_eff >  effect_tri;
}_effect_bdd_action;

//Epistemic action: definition 4
typedef struct observe_bdd_action{
    string name;
    int act_num;
    vector<string> para;
    vector<string> para_match;
    _s5_term pre;
    BDD observe_eff;
}_observe_bdd_action;
*/
//node: knowledge base


#endif

