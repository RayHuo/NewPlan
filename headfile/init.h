//实现将公式存的动作和初始目标状态转成epis的表达方式
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
#include <cstdio>
//#include "DataStructure.h"




extern FILE *yyin;

extern _formula* init_f;
extern _formula* goal_f;
extern vector<_formula*> actions_f; 
//例化原子中原子号和类型的对照
extern map< string,vector<int> > grounding_map;
extern vector<OnticAction> ontic_actions;
extern vector<EpisAction> epis_acitons;

extern int yyparse();



class Init{
public:
    Init();
    ~Init();
    
    void exec();//执行生成动作
    
    //void gen_init_and_goal();
    //_s5_term gen_s5_from_f(_formula* f);
    //_disj_k_state gen_dis_from_f(_formula* f);
    //BDD gen_init_goal_b(_formula*);
    
    
    void make_actions();
    void gen_ontic_actions(_formula*);//生成物理动作
    void gen_observe_actions(_formula*);//生成感知动作
    //_s5_term gen_pre(_formula* f, vector<string> para_str, vector<string> match_str);
    //通过前提公式获得pre类型前提，此类型为中间量目标是生成epis_CNF的前提条件
    pre gen_pre(_formula*);
    //功能同上，适应例化中带变量，匹配生成新原子的情况
    pre gen_pre_by_match(_formula*, vector<string> para_str, vector<string> match_str);
    //从公式获取感知动作效果
    vector<int> gen_oba_eff(_formula*);
    vector<int> gen_oba_eff_by_match(_formula* f, vector<string> para_str, vector<string> match_str);
    //从公式获取物理动作效果，三元组形式
    vector<ConEffect> gen_con_eff(_formula* f);
    vector<ConEffect> gen_con_eff_by_match(_formula* f, vector<string> para_str, vector<string> match_str);
    //BDD gen_var_atom_b(_formula* f, vector<string> para_str, vector<string> match_str);
   //获取该原子公式对应的原子，此处生成原子，存在单例atoms类中返回一个原子序号
    int gen_bddnum_by_state(_formula*);
    //此处命名延用上一用bdd的版本，功能是将一个CNF公式转成
    //用atoms中原子序号表示的vector<int>
    int gen_var_num_by_state(_formula* f, vector<string> para_str, vector<string> match_str);
    _formula* getMatchFormula(_formula* f, vector<string> para_str, vector<string> match_str);
    vector<int> gen_bdd_nums_by_state(_formula* f);
    vector<int> gen_bdd_var_nums_by_state(_formula* f, vector<string> para_str, vector<string> match_str);
    void get_str(int pos, vector<string> match_str, vector<string> para_str);
    bool is_used_str(string s, vector<string> v);
    //字符串识别，获取类型
    string get_str_type(string s);
    //匹配，a为b的头部即可匹配上
    bool match_string(char* a, string b);
    //判断是否已存在
    bool check_if_add_to_vector(int i, vector<int> v);
    _formula* get_pre_match(_formula*);
    //建立当前公式里的原子在Atom中的对应关系，并返回其在Atom中的id集合。
    vector<int> gen_and_nums(_formula* f);

    
    //转换到CNF
    _formula* convertToConjuntiveNormalForm(_formula*& fml);
    //组合两个公式
    _formula* compositeByConnective(FORMULA_TYPE _formulaType, _formula* _subformulaL, _formula* _subformulaR);
    //复制，避免调用的时候修改了原公式
    _formula* copyFormula(const _formula* _fml) ;
    //拆分CNF为DNF序列的vector
    void divideCNFFormula(_formula* fml, vector<_formula*>& division);
    //将vector<_formula*> 转换成 vector< set<int> > 来实现转dnf
    vector< set<int> > convertToSATInput(vector<_formula*> cnfDlp);
    //上面函数调用的子函数，每个公式转set<int>形式
    void convertCNFformulaToLits(_formula* rule, set<int>& lits);
    void deleteFormula(_formula* _fml);
    //cnf转dnf生成后化简
    void absorb(vector< set<int> >& l);
    //化简辅助函数，判断是否化简
    int isabsorb(set<int> l1, set<int> l2);
    //检查是否存在自相矛盾，即1和-1并存，可消去
    bool checkvalue(set<int> l);
    //cnf转dnf，拆cnf为一列dnf，做合取生成新dnf
    vector< set<int> > vcnf_to_vdnf(vector< set<int> > l);
    //实现cnf转dnf的辅助函数
    void twoset(vector< set<int> > &v, set<int> s1, set<int> s2);
    void doubleset(vector< set<int> > &v, set<int> s);
    set<int> adds(set<int> s, int i);
    //原子号生成公式
    _formula* compositeToAtom(int _atom_id);
    
    
    /*vector<_formula*> v_convertto_vf(vector< set<int> > l);
    _formula* vf_convertto_formula(vector<_formula*> fl);*/
    
    
    //PropTerm getProTerm(set<int>);
    //公式生成propdnf，这里将一个公式进行上面的转dnf步骤，
    //然后dnf已vector<set<int> >形式保存，调用getpropterm转dnf中每个cnf 
    PropDNF getPropDNF(_formula*);
    EpisTerm getEpisTerm(_formula*);
    //这里将cnf转成propterm，bitset中存储每个原子两个位置，
    //前一个表示正，后一个表示负，同1矛盾消去，同0表示此处该原子未被用
    PropTerm getPropTerm(set<int>);
    PropTerm getPropTermFromV(vector<int>);
    //把中间类型pre生成episcnf的类型的前提
    EpisCNF getEpisCNFByFormula(_formula*);
    EpisClause getEpisClausebyFormula(_formula*);
    PropCNF getPropCNFFromFormula(_formula* f);
    
    EpisCNF getEpisCNF(pre);
    EpisCNF disDKCon(EpisCNF);

    
    EpisClause getEpisClausePre(vector<int>, bool);
    void getEpisiDNFInitAndGoal();
    void genActionPreCnd();
    //此处进行k后部分合取到dk后的操作，逻辑上的问题杨睿让这么写的
    void checkInit();
    
    vector<set<int> > getDnfFromFormula(_formula*);
    vector<set<int> > getDnfFromFormulaByVar(_formula* f, vector<string> para_str, vector<string> match_str);
    vector<set<int> > getNegDnf(vector<set<int> >);
    PropDNF getPropDNFFromVS(vector<set<int> >);
    void convertConToPropTerm();
    void genObaDnfAndNeg();
    void showground(FILE *out) const;
    void showmaps(FILE *out) const;
    void show(FILE *out, pre p) const;
    void print_f(FILE *out, _formula* f) const;
    
    EpisDNF init;
    EpisCNF goal;
    vector<vector<string> > match_data;
    
    
};
#endif