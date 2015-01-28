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

#endif

