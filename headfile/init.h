#ifndef INIT_H
#define	INIT_H

//#include "parse.cpp"
//#include "lex.cpp"

#include  <map>
#include <string>
#include "formulatab.h"
#include "structs.h"
#include "Vocabulary.h"
#include "Progression.h"
#include <string.h>
//#include "DataStructure.h"




extern FILE *yyin;

extern _formula* init_f;
extern _formula* goal_f;
extern vector<_formula*> actions_f; 
extern map< string,vector<int> > grounding_map;
extern vector<OnticAction> ontic_actions;
extern vector<EpisAction> epis_acitons;

extern int yyparse();



class Init{
public:
    Init();
    ~Init();
    
    void exec();
    
    //void gen_init_and_goal();
    //_s5_term gen_s5_from_f(_formula* f);
    //_disj_k_state gen_dis_from_f(_formula* f);
    //BDD gen_init_goal_b(_formula*);
    
    
    void make_actions();
    void gen_ontic_actions(_formula*);
    void gen_observe_actions(_formula*);
    //_s5_term gen_pre(_formula* f, vector<string> para_str, vector<string> match_str);
    pre gen_pre(_formula*);
    pre gen_pre_by_match(_formula*, vector<string> para_str, vector<string> match_str);
    vector<int> gen_oba_eff(_formula*);
    vector<int> gen_oba_eff_by_match(_formula* f, vector<string> para_str, vector<string> match_str);
    vector<ConEffect> gen_con_eff(_formula* f);
    vector<ConEffect> gen_con_eff_by_match(_formula* f, vector<string> para_str, vector<string> match_str);
    //BDD gen_var_atom_b(_formula* f, vector<string> para_str, vector<string> match_str);
    int gen_bddnum_by_state(_formula*);
    vector<int> gen_bdd_var_nums_by_state(_formula* f, vector<string> para_str, vector<string> match_str);
    vector<int> gen_bdd_nums_by_state(_formula* f);
    void get_str(int pos, vector<string> match_str, vector<string> para_str);
    bool is_used_str(string s, vector<string> v);
    string get_str_type(string s);
    bool match_string(char* a, string b);
    bool check_if_add_to_vector(int i, vector<int> v);
    _formula* get_pre_match(_formula*);
    vector<int> gen_and_nums(_formula* f);

    
    
    _formula* convertToConjuntiveNormalForm(_formula*& fml);
    _formula* compositeByConnective(FORMULA_TYPE _formulaType, _formula* _subformulaL, _formula* _subformulaR);
    _formula* copyFormula(const _formula* _fml) ;
    void divideCNFFormula(_formula* fml, vector<_formula*>& division);
    vector< set<int> > convertToSATInput(vector<_formula*> cnfDlp);
    void convertCNFformulaToLits(_formula* rule, set<int>& lits);
    void deleteFormula(_formula* _fml);
    void absorb(vector< set<int> >& l);
    int isabsorb(set<int> l1, set<int> l2);
    bool checkvalue(set<int> l);
    vector< set<int> > vcnf_to_vdnf(vector< set<int> > l);
    void twoset(vector< set<int> > &v, set<int> s1, set<int> s2);
    void doubleset(vector< set<int> > &v, set<int> s);
    set<int> adds(set<int> s, int i);
    _formula* compositeToAtom(int _atom_id);
    
    
    /*vector<_formula*> v_convertto_vf(vector< set<int> > l);
    _formula* vf_convertto_formula(vector<_formula*> fl);*/
    
    
    //PropTerm getProTerm(set<int>);
    PropDNF getPropDNF(_formula*);
    EpisTerm getEpisTerm(_formula*);
    PropTerm getPropTerm(set<int>);
    
    EpisCNF getEpisCNF(pre);
    EpisClause getEpisClausePre(vector<int>, bool);
    void getEpisiDNFInitAndGoal();
    void genActionPreCnd();
    void checkInit();

    
    void showmaps();
    void show(pre p);
    void print_f(_formula* f);
    
    EpisDNF init;
    EpisDNF goal;
    vector<vector<string> > match_data;
    
    
};
#endif