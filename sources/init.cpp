#include <set>

#include "init.h"

#include "atoms.h"
#include<bitset>
#include<fstream>

Init::Init() {
    ontic_actions.clear();
    epis_acitons.clear();
    match_data.clear();
}

Init::~Init() {
    ontic_actions.clear();
    epis_acitons.clear();
    match_data.clear();
}

void Init::exec() {
    yyin = fopen("test/demo/demo_domain.pddl", "r");
    yyparse();
    fclose(yyin);
    yyin = fopen("test/demo/demo_p.pddl", "r");
    yyparse();
    fclose(yyin);
    // 根据parse时的数据结构生成物理动作和感知动作
    make_actions();
    // 生成初始状态和目标状态
    getEpisiDNFInitAndGoal();
    genActionPreCnd();
    convertConToPropTerm();
    genObaDnfAndNeg();
}

void Init::make_actions() {
    for (int i = 0; i < actions_f.size(); i++) {
        if (actions_f[i]->subformula_r->subformula_r->formula_type == CONOBSERVE_F)
            gen_observe_actions(actions_f[i]);
        else
            gen_ontic_actions(actions_f[i]);
    }
}

void Init::gen_ontic_actions(_formula* f) {
    //cout<<"one ontic"<<endl;
    OnticAction eba;
    string eff_name = Vocabulary::instance().getAtom(f->pid);
    if (f->subformula_r->subformula_l->subformula_l->formula_type == EMPTY_F) {
        eba.pre_f = gen_pre(f->subformula_r->subformula_r->subformula_l->subformula_l);
        eba.con_eff = gen_con_eff(f->subformula_r->subformula_r->subformula_r->subformula_l);
        eba.name = eff_name;
        eba.act_num = ontic_actions.size();
        ontic_actions.push_back(eba);
    } else {
        vector<string> para_str;
        _formula* f_para = f->subformula_r->subformula_l->subformula_l;
        switch (f_para->formula_type) {
            case VAR_F:
            {
                string s = Vocabulary::instance().getAtom(f_para->pid);
                para_str.push_back(s);
                break;
            }
            case VARS_F:
            {
                for (int i = 0; i < f_para->count; i++) {
                    string s = Vocabulary::instance().getAtom(f_para->pidlist[i]);
                    para_str.push_back(s);
                }
                break;
            }
            default:
                break;
        }
        vector<string> match_str;
        match_data.clear();
        get_str(0, match_str, para_str);
        for (int i = 0; i < match_data.size(); i++) {
            eba.pre_f = gen_pre_by_match(f->subformula_r->subformula_r->subformula_l->subformula_l, para_str, match_data[i]);
            eba.con_eff = gen_con_eff_by_match(f->subformula_r->subformula_r->subformula_r->subformula_l, para_str, match_data[i]);
            eba.name = eff_name;
            eba.act_num = ontic_actions.size();
            eba.para_match = match_data[i];
            ontic_actions.push_back(eba);
        }
    }
}

void Init::gen_observe_actions(_formula* f) {
    //cout<<"one oba"<<endl;
    EpisAction oba;
    if (f->subformula_r->subformula_l->subformula_l->formula_type == EMPTY_F) {
        oba.pre_f = gen_pre(f->subformula_r->subformula_r->subformula_l->subformula_l);
        oba.name = Vocabulary::instance().getAtom(f->pid);
        //oba.observe = gen_oba_eff(f->subformula_r->subformula_r->subformula_r->subformula_l);
        oba.observe = getDnfFromFormula(f->subformula_r->subformula_r->subformula_r->subformula_l);
        oba.act_num = epis_acitons.size();
        epis_acitons.push_back(oba);
    } else {
        vector<string> para_str;
        _formula* f_para = f->subformula_r->subformula_l->subformula_l;
        switch (f_para->formula_type) {
            case VAR_F:
            {
                string s = Vocabulary::instance().getAtom(f_para->pid);
                para_str.push_back(s);
                break;
            }
            case VARS_F:
            {
                for (int i = 0; i < f_para->count; i++) {
                    string s = Vocabulary::instance().getAtom(f_para->pidlist[i]);
                    para_str.push_back(s);
                }
                break;
            }
            default:
                break;
        }
        vector<string> match_str;

        match_data.clear();
        get_str(0, match_str, para_str);

        for (int i = 0; i < match_data.size(); i++) {

            oba.pre_f = gen_pre_by_match(f->subformula_r->subformula_r->subformula_l->subformula_l, para_str, match_data[i]);
            //oba.observe = gen_bdd_var_nums_by_state(f->subformula_r->subformula_r->subformula_r->subformula_l, para_str,match_data[i]);
            oba.observe = getDnfFromFormulaByVar(f->subformula_r->subformula_r->subformula_r->subformula_l, para_str, match_data[i]);
            oba.name = Vocabulary::instance().getAtom(f->pid);
            oba.act_num = epis_acitons.size();
            oba.para_match = match_data[i];
            epis_acitons.push_back(oba);
        }
    }
}

pre Init::gen_pre(_formula* f) {
    pre p;
    while (f->formula_type == AND_F) {
        //print_f(out, f->subformula_r->subformula_l);
        //int k = f->subformula_r->pid;
        ///_formula* ff = Formulatab::instance().getAtom(k);
        vector<int> xx = gen_and_nums(Formulatab::instance().getAtom(f->subformula_r->pid)->subformula_l);
        p.dk.push_back(xx);

        f = f->subformula_l;
    }
    if (Formulatab::instance().getAtom(f->pid)->formula_type == K_F)
        p.k = gen_and_nums(Formulatab::instance().getAtom(f->pid)->subformula_l);
    else
        p.dk.push_back(gen_and_nums(Formulatab::instance().getAtom(f->pid)->subformula_l));
    //p;
    //show(p);
    return p;
}

void Init::show(FILE *out, pre p) const {
    fprintf(out, "K\n");
    for (int i = 0; i < p.k.size(); i++)
        fprintf(out, "%d ", p.k[i]);
    fprintf(out, "\n");
    fprintf(out, "DK\n");
    for (int i = 0; i < p.dk.size(); i++) {
        for (int j = 0; j < p.dk[i].size(); j++)
            fprintf(out, "%d ", p.dk[i][j]);
        fprintf(out, "\n");
    }
}

pre Init::gen_pre_by_match(_formula* f, vector<string> para_str, vector<string> match_str) {
    pre p;
    while (f->formula_type == AND_F) {
        p.dk.push_back(gen_bdd_var_nums_by_state(Formulatab::instance().getAtom(f->subformula_r->pid)->subformula_l, para_str, match_str));
        f = f->subformula_l;
    }
    if (Formulatab::instance().getAtom(f->pid)->formula_type == K_F)
        p.k = gen_bdd_var_nums_by_state(Formulatab::instance().getAtom(f->pid)->subformula_l, para_str, match_str);
    else
        p.dk.push_back(gen_bdd_var_nums_by_state(Formulatab::instance().getAtom(f->pid)->subformula_l, para_str, match_str));
    return p;
}

vector<int> Init::gen_oba_eff(_formula* f) {

    vector<int> vs;
    vs = gen_and_nums(f);

    return vs;
}

vector<int> Init::gen_oba_eff_by_match(_formula* f, vector<string> para_str, vector<string> match_str) {

    vector<int> vs;
    vs = gen_bdd_var_nums_by_state(f, para_str, match_str);
    return vs;
}

vector<ConEffect> Init::gen_con_eff(_formula* f_eff) {
    vector<ConEffect> ceall;
    ConEffect ce;
    while (f_eff->formula_type == THREE_ATOMS_F) {
        if (f_eff->subformula_r->formula_type == THREE_ATOM_F) {
            ce.condition = gen_oba_eff(f_eff->subformula_r->subformula_l);
            ce.add = gen_oba_eff(f_eff->subformula_r->subformula_r->subformula_l);
            ce.del = gen_oba_eff(f_eff->subformula_r->subformula_r->subformula_r);
            ceall.push_back(ce);
            ce.add.clear();
            ce.del.clear();
        }
        f_eff = f_eff->subformula_l;
    }
    if (f_eff->formula_type == THREE_ATOM_F) {
        ce.condition = gen_oba_eff(f_eff->subformula_l);
        ce.add = gen_oba_eff(f_eff->subformula_r->subformula_l);
        ce.del = gen_oba_eff(f_eff->subformula_r->subformula_r);
        ceall.push_back(ce);
    }


    return ceall;


}

vector<ConEffect> Init::gen_con_eff_by_match(_formula* f_eff, vector<string> para_str, vector<string> match_str) {
    vector<ConEffect> ceall;
    ConEffect ce;


    while (f_eff->formula_type == THREE_ATOMS_F) {
        if (f_eff->subformula_r->formula_type == THREE_ATOM_F) {
            ce.condition = gen_bdd_var_nums_by_state(f_eff->subformula_r->subformula_l, para_str, match_str);
            ce.add = gen_bdd_var_nums_by_state(f_eff->subformula_r->subformula_r->subformula_l, para_str, match_str);
            ce.del = gen_bdd_var_nums_by_state(f_eff->subformula_r->subformula_r->subformula_r, para_str, match_str);
            ceall.push_back(ce);
            ce.add.clear();
            ce.del.clear();
        }
        f_eff = f_eff->subformula_l;
    }
    if (f_eff->formula_type == THREE_ATOM_F) {
        ce.condition = gen_bdd_var_nums_by_state(f_eff->subformula_l, para_str, match_str);
        ce.add = gen_bdd_var_nums_by_state(f_eff->subformula_r->subformula_l, para_str, match_str);
        ce.del = gen_bdd_var_nums_by_state(f_eff->subformula_r->subformula_r, para_str, match_str);
        ceall.push_back(ce);
    }


    return ceall;
}

vector<int> Init::gen_and_nums(_formula* f) {
    vector<int> v;
    switch (f->formula_type) {
        case ONE_ATOM_STATE_F:
        case STATE_F:
            v.push_back(gen_bddnum_by_state(f));
            return v;
            break;

        case AND_F:
            v = gen_and_nums(f->subformula_r);
            v.push_back(gen_bddnum_by_state(f->subformula_l));
            return v;
            break;
        case NEGA_F:
            v.push_back((-1) * gen_bddnum_by_state(f->subformula_l));
            return v;
            break;
        case MULTI_THREE_ATOMS:
        {
            vector<int> fl = gen_and_nums(f->subformula_l);
            vector<int> fr = gen_and_nums(f->subformula_r);
            for (int i = 0; i < fl.size(); i++)
                v.push_back(fl[i]);
            for (int i = 0; i < fr.size(); i++)
                v.push_back(fr[i]);
            return v;
        }
    }
}

int Init::gen_bddnum_by_state(_formula* f) {
    switch (f->formula_type) {
        case ONE_ATOM_STATE_F:
        {
            string s = Vocabulary::instance().getAtom(f->pid);
            int ie = Atoms::instance().query_atoms(s);
            if (ie == -1)
                ie = Atoms::instance().add_atoms(s);
            return ie;
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

            int ie = Atoms::instance().query_atoms(s);

            if (ie == -1)
                ie = Atoms::instance().add_atoms(s);


            //else
            return ie;
            break;
        }
    }
}

_formula* Init::getMatchFormula(_formula* f, vector<string> para_str, vector<string> match_str) {
    _formula* f2 = (_formula*) malloc(sizeof (_formula));
    switch (f->formula_type) {
        case EMPTY_F:
        case ONE_ATOM_STATE_F:
        {
            return f;
            break;
        }
        case STATE_F:
        {

            string s = Vocabulary::instance().getAtom(f->pid);
            string temp;
            if (f->subformula_r->formula_type == VAR_F) {
                char* c = Vocabulary::instance().getAtom(f->subformula_r->pid);
                for (int i = 0; i < para_str.size(); i++) {
                    if (match_string(c, para_str[i])) {
                        temp = match_str[i];
                        break;
                    }
                }
                s = s + "." + temp;
            } else {

                for (int i = 0; i < f->subformula_r->count; i++) {
                    char* c = Vocabulary::instance().getAtom(f->subformula_r->pidlist[i]);

                    for (int i = 0; i < para_str.size(); i++)
                        if (match_string(c, para_str[i])) {
                            temp = match_str[i];
                            s = s + "." + temp;
                            break;
                        }
                }
            }
            char *c;
            int len = s.length();
            c = (char *) malloc((len + 1) * sizeof (char));
            s.copy(c, len, 0);
            c[len] = '\0';
            int id = Vocabulary::instance().queryAtom(c);
            if (id < 0)
                id = Vocabulary::instance().addAtom(c);


            //else
            f2->formula_type = ONE_ATOM_STATE_F;
            f2->pid = id;
            return f2;
            break;
        }
        case MULTI_THREE_ATOMS:
        case AND_F:
        case OR_F:
        {
            //nums.push_back()
            f2->formula_type = f->formula_type;
            _formula* f3 = getMatchFormula(f->subformula_l, para_str, match_str);
            _formula* f4 = getMatchFormula(f->subformula_r, para_str, match_str);
            f2->subformula_l = f3;
            f2->subformula_r = f4;
            return f2;
            break;
        }
        case NEGA_F:
        {
            f2->formula_type = f->formula_type;
            f2->subformula_l = getMatchFormula(f->subformula_l, para_str, match_str);
            return f2;
            break;
        }
    }
}

vector<int> Init::gen_bdd_var_nums_by_state(_formula* f, vector<string> para_str, vector<string> match_str) {
    vector<int> nums;
    switch (f->formula_type) {
        case EMPTY_F:
        {
            return nums;
            break;
        }

        case ONE_ATOM_STATE_F:
        {
            string s = Vocabulary::instance().getAtom(f->pid);
            int ie = Atoms::instance().query_atoms(s);
            if (ie == -1)
                ie = Atoms::instance().add_atoms(s);
            nums.push_back(ie);
            return nums;
            break;
        }
        case STATE_F:
        {

            string s = Vocabulary::instance().getAtom(f->pid);
            string temp;
            if (f->subformula_r->formula_type == VAR_F) {
                char* c = Vocabulary::instance().getAtom(f->subformula_r->pid);
                for (int i = 0; i < para_str.size(); i++) {
                    if (match_string(c, para_str[i])) {
                        temp = match_str[i];
                        break;
                    }
                }
                s = s + "." + temp;
            } else {

                for (int i = 0; i < f->subformula_r->count; i++) {
                    char* c = Vocabulary::instance().getAtom(f->subformula_r->pidlist[i]);

                    for (int i = 0; i < para_str.size(); i++)
                        if (match_string(c, para_str[i])) {
                            temp = match_str[i];
                            s = s + "." + temp;
                            break;
                        }
                }
            }

            int ie = Atoms::instance().query_atoms(s);

            if (ie == -1)
                ie = Atoms::instance().add_atoms(s);

            //else
            nums.push_back(ie);
            return nums;
            break;
        }
        case MULTI_THREE_ATOMS:
        case AND_F:
        {
            //nums.push_back()
            nums = gen_bdd_var_nums_by_state(f->subformula_l, para_str, match_str);
            vector<int> r = gen_bdd_var_nums_by_state(f->subformula_r, para_str, match_str);
            int i_s = r.size();
            for (int i = 0; i < i_s; i++)
                nums.push_back(r[i]);
            return nums;
            break;
        }
        case NEGA_F:
        {
            nums.push_back((-1) * gen_bdd_var_nums_by_state(f->subformula_l, para_str, match_str)[0]);
            return nums;
            break;
        }

    }
}

void Init::get_str(int pos, vector<string> match_str, vector<string> para_str) {
    if (pos == para_str.size()) {
        match_data.push_back(match_str);
        return;
    }
    string s = get_str_type(para_str[pos]);
    for (int i = 0; i < grounding_map[s].size(); i++) {
        string s1 = Vocabulary::instance().getAtom(grounding_map[s][i]);
        if (!is_used_str(s1, match_str) && pos < para_str.size()) {
            if (match_str.size() <= pos)
                match_str.push_back(s1);
            else
                match_str[pos] = s1;
            get_str(pos + 1, match_str, para_str);
        }
    }
}

bool Init::is_used_str(string s, vector<string> v) {
    for (int i = 0; i < v.size(); i++)
        if (s == v[i])
            return true;
    return false;
}

string Init::get_str_type(string s) {
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '.') {
            s = s.substr(i + 1, s.size() - i - 1);
            return s;
        }
}

bool Init::match_string(char* a, string b) {
    string a1 = a;
    for (int i = 0; i < a1.length(); i++)
        if (a1[i] != b[i])
            return false;

    return true;
}

bool Init::check_if_add_to_vector(int i, vector<int> v) {
    if (i == -1)
        return false;
    else {
        for (int j = 0; j < v.size(); j++)
            if (i == v[j])
                return false;
    }
    return true;
}

void Init::showground(FILE *out) const {
    fprintf(out, "grounding_map\n");
    for (map<string, vector<int> >::const_iterator it = grounding_map.begin(); it != grounding_map.end(); it++) {
        fprintf(out, "%s:", it->first.c_str());
        for (int i = 0; i < it->second.size(); i++)
            fprintf(out, "%s ", Vocabulary::instance().getAtom(it->second[i]));
        fprintf(out, "\n");
    }
    Atoms::instance().show(out);
}

void Init::genObaDnfAndNeg() {
    for (int i = 0; i < epis_acitons.size(); i++) {
        epis_acitons[i].pos_res = getPropDNFFromVS(epis_acitons[i].observe);
        epis_acitons[i].neg_res = getPropDNFFromVS(getNegDnf(epis_acitons[i].observe));
    }
}

void Init::showmaps(FILE *out) const {
    //Vocabulary::instance().showVocabulary();
    showground(out);
    fprintf(out, "\nshow ontic actions\n");
    for (int i = 0; i < ontic_actions.size(); i++) {
        fprintf(out, "act_num: %d act_name: %s\n", ontic_actions[i].act_num, ontic_actions[i].name.c_str());
        fprintf(out, "show match:\n");
        for (int j = 0; j < ontic_actions[i].para_match.size(); j++)
            fprintf(out, "%s ", ontic_actions[i].para_match[i].c_str());
        fprintf(out, "\naction_pre_condition:\n");
        ontic_actions[i].pre_con.show(out);
        fprintf(out, "\naction_effect:\n");
        for (int m = 0; m < ontic_actions[i].con_eff.size(); m++) {
            fprintf(out, "con: ");
            for (int j = 0; j < ontic_actions[i].con_eff[m].condition.size(); ++j) {
                fprintf(out, "%d:%s ", ontic_actions[i].con_eff[m].condition[j],
                        Atoms::instance().get_atom_string(ontic_actions[i].con_eff[m].condition[j]).c_str());
            }
            fprintf(out, "\nadd: ");
            for (int j = 0; j < ontic_actions[i].con_eff[m].add.size(); j++)
                fprintf(out, "%d:%s ", ontic_actions[i].con_eff[m].add[j],
                    Atoms::instance().get_atom_string(ontic_actions[i].con_eff[m].add[j]).c_str());
            fprintf(out, "\ndel: ");
            for (int j = 0; j < ontic_actions[i].con_eff[m].del.size(); j++)
                fprintf(out, "%d:%s ", ontic_actions[i].con_eff[m].del[j],
                    Atoms::instance().get_atom_string(ontic_actions[i].con_eff[m].del[j]).c_str());
            fprintf(out, "\n");
        }
    }
    fprintf(out, "\nshow epis actions\n");
    for (int i = 0; i < epis_acitons.size(); i++) {
        fprintf(out, "act_num: %d act_name: %s\n", epis_acitons[i].act_num, epis_acitons[i].name.c_str());
        fprintf(out, "show match: \n");
        for (int j = 0; j < epis_acitons[i].para_match.size(); j++)
            fprintf(out, "%s ", epis_acitons[i].para_match[j].c_str());
        fprintf(out, "\naction_pre_condition:\n");
        epis_acitons[i].pre_con.show(out);
        fprintf(out, "observe:\n");
        fprintf(out, "pos:\n");
        epis_acitons[i].pos_res.show(out);
        fprintf(out, "neg:\n");
        epis_acitons[i].neg_res.show(out);
        fprintf(out, "\n");
    }
    fprintf(out, "\ninit episdnf:\n");
    init.show(out);
    fprintf(out, "\ngoal episcnf:\n");
    goal.show(out);
}

void Init::getEpisiDNFInitAndGoal() {
    while (init_f->formula_type == OR_F) {
        init.epis_terms.push_back(getEpisTerm(init_f->subformula_r));
        init_f = init_f->subformula_l;
    }
    init.epis_terms.push_back(getEpisTerm(init_f));

    checkInit();
 
    goal = getEpisCNFByFormula(goal_f);
    goal = disDKCon(goal);
}

EpisCNF Init::getEpisCNFByFormula(_formula* f) {
    EpisCNF ep;
    if (f->formula_type == AND_F) {
    }
    if (f->formula_type == OR_F) {
        ep.epis_clauses.push_back(getEpisClausebyFormula(f));
    } else
        ep.epis_clauses.push_back(getEpisClausebyFormula(f));
    return ep;
}

EpisClause Init::getEpisClausebyFormula(_formula* f) {
    EpisClause ec;
    while (f->formula_type == OR_F) {
        if (Formulatab::instance().getAtom(f->subformula_r->pid)->formula_type == K_F)
            ec.pos_propCNFs.push_back(getPropCNFFromFormula(Formulatab::instance().getAtom(f->subformula_r->pid)->subformula_l));
        else
            ec.neg_propCNFs.push_back(getPropCNFFromFormula(Formulatab::instance().getAtom(f->subformula_r->pid)->subformula_l));

        f = f->subformula_l;
    }
    if (Formulatab::instance().getAtom(f->pid)->formula_type == K_F)
        ec.pos_propCNFs.push_back(getPropCNFFromFormula(Formulatab::instance().getAtom(f->pid)->subformula_l));
    else
        ec.neg_propCNFs.push_back(getPropCNFFromFormula(Formulatab::instance().getAtom(f->pid)->subformula_l));
    return ec;
}

PropCNF Init::getPropCNFFromFormula(_formula* f) {
    _formula* fm = convertToConjuntiveNormalForm(f);
    vector<_formula*> result;
    divideCNFFormula(fm, result);
    vector< set<int> > vs = convertToSATInput(result);
    absorb(vs);
    PropCNF pc;

    for (int i = 0; i < vs.size(); i++) {
        PropClause pcl(Atoms::instance().atoms_length()*2);
        //for(int i = 0; i < literalsLegnth; i++)
        //p.literals.push_back(false);
        //cout<<"lit length : "<<Atoms::instance().atoms_length()<<endl;
        //cout<<s.size()<<endl;
        int temp = 0;
        for (set<int>::iterator it = vs[i].begin(); it != vs[i].end(); it++) {
            //cout<<"*it: "<<*it<<endl;
            //cout<<Atoms::instance().get_true_num(*it)<<" ";
            //cout<<Atoms::instance().get_true_num(*it*(-1))<<" ";
            if (*it > 0)
                pcl.literals[((*it) - 1)*2] = 1;
            else
                pcl.literals[((*it) * (-1) - 1)*2 + 1] = 1;
        }
        pc.prop_clauses.push_back(pcl);
    }
    return pc;
}

EpisCNF Init::disDKCon(EpisCNF ec) {
    //EpisCNF ec1;
    for (list<EpisClause>::iterator it = ec.epis_clauses.begin(); it != ec.epis_clauses.end(); it++) {
        //it->min();
        //it->neg_propCNF = *(it->neg_propCNFs.begin());
        if (it->neg_propCNFs.size() == 1)
            it->neg_propCNF = *(it->neg_propCNFs.begin());
    }
    return ec;
}

void Init::checkInit() {
    PropDNF pk;
    for (list<EpisTerm>::iterator it = init.epis_terms.begin(); it != init.epis_terms.end(); it++) {
        if (it->pos_propDNF.prop_terms.size() != 0) {
            list<PropDNF> pd;
            for (list<PropDNF>::iterator it1 = it->neg_propDNFs.begin(); it1 != it->neg_propDNFs.end(); it1++) {
                pd.push_back(it1->group(it->pos_propDNF));
            }
            it->neg_propDNFs.clear();
            for (list<PropDNF>::iterator it1 = pd.begin(); it1 != pd.end(); it1++) {
                it->neg_propDNFs.push_back(*it1);
            }
        }
    }    
    init.minimal();
}

EpisTerm Init::getEpisTerm(_formula* f) {
    EpisTerm ep;
    list<PropDNF> neg;
    while (f->formula_type == AND_F) {
        ep.neg_propDNFs.push_back(getPropDNF(f->subformula_r));
        f = f->subformula_l;
    }
    if (Formulatab::instance().getAtom(f->pid)->formula_type == K_F) {
        ep.pos_propDNF = getPropDNF(f);
    } else {
        ep.neg_propDNFs.push_back(getPropDNF(f));
    }
    return ep;
}

vector<set<int> > Init::getNegDnf(vector<set<int> > vs) {
    vector<set<int> > vsNeg;
    set<int> temp;
    for (int i = 0; i < vs.size(); i++) {
        temp.clear();
        for (set<int>::iterator it = vs[i].begin(); it != vs[i].end(); it++)
            temp.insert((*it)*(-1));
        vsNeg.push_back(temp);
    }
    vs = vcnf_to_vdnf(vsNeg);
    absorb(vs);
    return vs;
}

vector<set<int> > Init::getDnfFromFormulaByVar(_formula* f, vector<string> para_str, vector<string> match_str) {
    _formula* matchf;
    matchf = getMatchFormula(f, para_str, match_str);
    return getDnfFromFormula(matchf);
}

vector<set<int> > Init::getDnfFromFormula(_formula* f) {
    if (f->formula_type == K_atom)
        f = Formulatab::instance().getAtom(f->pid)->subformula_l;
    //cout<<"process f : "<<endl;
    //print_f(out, f);
    _formula* fm = convertToConjuntiveNormalForm(f);
    //cout<<"end cnf"<<endl;
    //print_f(out, fm);
    //cout<<"here"<<endl;
    //cout<<"process cnf f : "<<endl;
    //print_f(out, fm);
    //print_f(out, fm);
    //cout<<endl;
    vector<_formula*> result;
    divideCNFFormula(fm, result);
    //cout<<result.size()<<endl;
    //for(int i = 0; i < result.size(); i++){
    //    print_f(result[i]);
    //    cout<<endl;   
    //}
    //cout<<"end result"<<endl;
    vector< set<int> > vs = convertToSATInput(result);

    //cout<<"\n show this vs cnf "<<vs.size()<<endl;
    //cout<<vs.size()<<endl;

    //for(int i = 0; i < vs.size(); i++){
    //    for(set<int>::iterator it = vs[i].begin(); it != vs[i].end(); it++){
    //        cout<<*it<<" ";
    //    }
    //    cout<<endl;
    //}
    absorb(vs);
    vs = vcnf_to_vdnf(vs);
    absorb(vs);
    //cout<<"show this dnf"<<endl;
    //print_f(out, f);
    //cout<<endl;


    //cout<<"\n show this vs dnf"<<vs.size()<<endl;
    //for(int i = 0; i < vs.size(); i++){
    //    for(set<int>::iterator it = vs[i].begin(); it != vs[i].end(); it++){
    //        cout<<*it<<" ";
    //    }
    //    cout<<endl;
    //}

    //cout<<"showvs"<<endl;
    //for(int i = 0; i < vs.size(); i++){
    //    for(set<int>::iterator it = vs[i].begin(); it != vs[i].end(); it++)
    //        cout<<*it<<" ";
    //    cout<<endl;    
    //}
    //cout<<endl;
    return vs;

}

PropDNF Init::getPropDNFFromVS(vector<set<int> > vs) {
    PropDNF p;
    for (int i = 0; i < vs.size(); i++) {
        p.prop_terms.push_back(getPropTerm(vs[i]));
    }
    return p;
}

PropDNF Init::getPropDNF(_formula* f) {
    return getPropDNFFromVS(getDnfFromFormula(f));
}

void Init::convertConToPropTerm() {
    for (int i = 0; i < ontic_actions.size(); i++)
        for (int j = 0; j < ontic_actions[i].con_eff.size(); j++)
            ontic_actions[i].con.push_back(getPropTermFromV(ontic_actions[i].con_eff[j].condition));
}

PropTerm Init::getPropTermFromV(vector<int> s) {
    //grounding_map;id_to_vac
    PropTerm p(Atoms::instance().atoms_length()*2);
    //for(int i = 0; i < literalsLegnth; i++)
    //p.literals.push_back(false);
    //cout<<"lit length : "<<Atoms::instance().atoms_length()<<endl;
    //cout<<s.size()<<endl;
    int temp = 0;
    for (int i = 0; i < s.size(); i++) {
        //cout<<"*it: "<<*it<<endl;
        //cout<<Atoms::instance().get_true_num(*it)<<" ";
        //cout<<Atoms::instance().get_true_num(*it*(-1))<<" ";
        if (s[i] > 0)
            p.literals[(s[i] - 1)*2] = 1;
        else
            p.literals[(s[i] * (-1) - 1)*2 + 1] = 1;
    }
    //cout<<endl;
    //cout<<p.literals<<endl;
    return p;
}

PropTerm Init::getPropTerm(set<int> s) {
    //grounding_map;id_to_vac
    PropTerm p(Atoms::instance().atoms_length()*2);
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        if (*it > 0)
            p.literals[(*it - 1)*2] = 1;
        else
            p.literals[(*it * (-1) - 1)*2 + 1] = 1;
    }
    return p;
}

void Init::genActionPreCnd() {
    for (int i = 0; i < ontic_actions.size(); i++) {
        ontic_actions[i].pre_con = getEpisCNF(ontic_actions[i].pre_f);
    }
    for (int i = 0; i < epis_acitons.size(); i++) {
        epis_acitons[i].pre_con = getEpisCNF(epis_acitons[i].pre_f);
    }
}

EpisCNF Init::getEpisCNF(pre p) {
    EpisCNF ep;
    //EpisClause ec;
    if (p.k.size() != 0)
        ep.epis_clauses.push_back(getEpisClausePre(p.k, true));
    if (p.dk.size() != 0)
        for (int i = 0; i < p.dk.size(); i++)
            ep.epis_clauses.push_back(getEpisClausePre(p.dk[i], false));
    ep = disDKCon(ep);
    //ep.show();
    return ep;
}

/*
struct pre {
    vector<int> k;
    vector<vector<int> > dk; 
};
 */


EpisClause Init::getEpisClausePre(vector<int> s, bool isK) {
    //grounding_map;id_to_vac
    EpisClause ec;
    PropCNF pc;
    if (isK) {
        for (int i = 0; i < s.size(); i++) {
            PropClause pcl(Atoms::instance().atoms_length()*2);
            if (s[i] > 0)
                pcl.literals[(s[i] - 1)*2] = 1;
            else
                pcl.literals[(s[i]*(-1) - 1)*2 + 1] = 1;
            pc.prop_clauses.push_back(pcl);
        }
        ec.pos_propCNFs.push_back(pc);
    } else {
        for (int i = 0; i < s.size(); i++) {
            PropClause pcl(Atoms::instance().atoms_length()*2);
            if (s[i] > 0)
                pcl.literals[(s[i] - 1)*2] = 1;
            else
                pcl.literals[(s[i]*(-1) - 1)*2 + 1] = 1;
            pc.prop_clauses.push_back(pcl);
        }
        ec.neg_propCNFs.push_back(pc);
    }
    return ec;
}

_formula* Init::compositeToAtom(int _atom_id) {
    _formula* fml = (_formula*) malloc(sizeof (_formula));
    assert(fml);

    fml->formula_type = K_atom;
    fml->pid = _atom_id;
    return fml;
}

vector< set<int> > Init::vcnf_to_vdnf(vector< set<int> > l) {
    vector< set<int> > d;
    set<int> s;
    if (l.size() == 0)
        return l;
    else if (l.size() == 1) {
        for (set<int>::iterator it = l[0].begin(); it != l[0].end(); it++) {
            s.clear();
            s.insert(*it);
            d.push_back(s);
        }
        return d;
    }
    twoset(d, l[0], l[1]);
    for (int i = 2; i < l.size(); i++) {
        doubleset(d, l[i]);
    }
    return d;
}

void Init::doubleset(vector< set<int> > &v, set<int> s) {
    vector< set<int> > d;
    for (int i = 0; i < v.size(); i++) {
        for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
            d.push_back(adds(v[i], *it));
        }
    }
    v.clear();
    v.insert(v.end(), d.begin(), d.end());
}

void Init::twoset(vector< set<int> > &v, set<int> s1, set<int> s2) {
    v.clear();
    set<int> s;
    for (set<int>::iterator it1 = s1.begin(); it1 != s1.end(); it1++) {
        for (set<int>::iterator it2 = s2.begin(); it2 != s2.end(); it2++) {
            s.clear();
            s.insert(*it1);
            s.insert(*it2);
            v.push_back(s);
        }
    }
}

set<int> Init::adds(set<int> s, int i) {
    s.insert(i);
    return s;
}

void Init::absorb(vector< set<int> >& l) {
    int i, j, temp;
    for (i = 0; i < l.size();) {
        if (!checkvalue(l[i])) {
            vector< set<int> >::iterator it = l.begin() + i;
            l.erase(it);
        } else
            i++;
    }
    for (i = 0; i < (int) l.size() - 1; i++) {
        for (j = i + 1; j < l.size();) {
            temp = isabsorb(l[i], l[j]);
            if (temp == 1) {
                vector< set<int> >::iterator it = l.begin() + j;
                l.erase(it);
            }
            if (temp == 0) {
                j++;
            }
            if (temp == -1) {
                vector< set<int> >::iterator it = l.begin() + i;
                l.erase(it);
                i--;
            }
        }
    }
}

int Init::isabsorb(set<int> l1, set<int> l2) {
    if (l1.size() <= l2.size()) {
        for (set<int>::iterator it = l1.begin(); it != l1.end(); it++)
            if (l2.find(*it) == l2.end())
                return 0;
        return 1;
    } else {
        for (set<int>::iterator it = l2.begin(); it != l2.end(); it++)
            if (l1.find(*it) == l1.end())
                return 0;
        return -1;
    }
}

bool Init::checkvalue(set<int> l) {
    for (set<int>::iterator it = l.begin(); it != l.end(); it++) {
        if (l.find(-1 * (*it)) != l.end())
            return false; //find the opposite
    }
    return true;
}

vector< set<int> > Init::convertToSATInput(vector<_formula*> cnfDlp) {
    vector< set<int> > res;
    for (int i = 0; i < cnfDlp.size(); i++) {
        set<int> lits;
        convertCNFformulaToLits(cnfDlp[i], lits);
        res.push_back(lits);
    }
    return res;
}

void Init::convertCNFformulaToLits(_formula* rule, set<int>& lits) {

    if (rule->formula_type == K_atom || rule->formula_type == ONE_ATOM_STATE_F) {
        lits.insert(Atoms::instance().get_true_num(rule->pid));
        return;
    }
    if (rule->formula_type == STATE_F) {
        lits.insert(gen_bddnum_by_state(rule));
        return;
    }
    if (rule->formula_type == NEGA_F) {
        //print_f(rule);
        set<int> se;
        convertCNFformulaToLits(rule->subformula_l, se);
        lits.insert((*(se.begin()))*(-1));
        //lits.insert(rule->subformula_l->pid*(-1));
        //convertCNFformulaToLits(rule->subformula_l, lits);
        //set<int> se;
        //se.insert((*lits.begin())*(-1));
        //lits = se;
    } else {
        convertCNFformulaToLits(rule->subformula_l, lits);
        convertCNFformulaToLits(rule->subformula_r, lits);
    }

}

void Init::deleteFormula(_formula* _fml) {
    assert(_fml);

    switch (_fml->formula_type) {
        case K_atom:
        case ONE_ATOM_STATE_F:
        case STATE_F:
            break;
        case AND_F:
        case OR_F:
            assert(_fml->subformula_r);
            deleteFormula(_fml->subformula_r);
    }

    free(_fml);
}

void Init::divideCNFFormula(_formula* fml, vector<_formula*>& division) {
    if (fml->formula_type == AND_F) {
        divideCNFFormula(fml->subformula_l, division);
        divideCNFFormula(fml->subformula_r, division);
    } else {
        division.push_back(fml);
    }
}

_formula* Init::convertToConjuntiveNormalForm(_formula*& fml) {

    if (fml->formula_type == OR_F) {
        convertToConjuntiveNormalForm(fml->subformula_l);
        convertToConjuntiveNormalForm(fml->subformula_r);

        _formula* subfor_l = fml->subformula_l;
        _formula* subfor_r = fml->subformula_r;

        if (subfor_l->formula_type == AND_F || subfor_r->formula_type == AND_F) {
            if (subfor_l->formula_type == AND_F && subfor_r->formula_type == AND_F) {
                _formula* f1 = compositeByConnective(OR_F, subfor_l->subformula_l, subfor_r->subformula_l);
                _formula* f2 = compositeByConnective(OR_F, subfor_l->subformula_r, copyFormula(subfor_r->subformula_l));
                _formula* f3 = compositeByConnective(OR_F, copyFormula(subfor_l->subformula_l), subfor_r->subformula_r);
                _formula* f4 = compositeByConnective(OR_F, copyFormula(subfor_l->subformula_r), copyFormula(subfor_r->subformula_r));

                _formula* f12 = compositeByConnective(AND_F, f1, f2);
                _formula* f34 = compositeByConnective(AND_F, f3, f4);

                fml = compositeByConnective(AND_F, f12, f34);
            } else {
                if (subfor_r->formula_type == AND_F) {
                    fml->subformula_l = subfor_r;
                    fml->subformula_r = subfor_l;
                    subfor_l = fml->subformula_l;
                    subfor_r = fml->subformula_r;
                }
                _formula* f1 = compositeByConnective(OR_F, subfor_l->subformula_l, subfor_r);
                _formula* f2 = compositeByConnective(OR_F, subfor_l->subformula_r, copyFormula(subfor_r));

                fml = compositeByConnective(AND_F, f1, f2);
            }
            convertToConjuntiveNormalForm(fml->subformula_l);
            convertToConjuntiveNormalForm(fml->subformula_r);
        }
    } else if (fml->formula_type == AND_F) {
        convertToConjuntiveNormalForm(fml->subformula_l);
        convertToConjuntiveNormalForm(fml->subformula_r);
    }


    return fml;
}

_formula* Init::compositeByConnective(FORMULA_TYPE _formulaType, _formula* _subformulaL, _formula* _subformulaR) {

    //assert( _formulaType == OR_F || _formulaType == _F);

    _formula* fml = (_formula*) malloc(sizeof (_formula));
    assert(fml);
    fml->formula_type = _formulaType;
    fml->subformula_l = _subformulaL;
    fml->subformula_r = _subformulaR;
    return fml;
}

_formula* Init::copyFormula(const _formula* _fml) {

    if (_fml == NULL) {
        return NULL;
    }

    _formula* newFormula = (_formula*) malloc(sizeof (_formula));
    assert(newFormula);

    memcpy(newFormula, _fml, sizeof (_formula));
    newFormula->formula_type = _fml->formula_type;
    switch (_fml->formula_type) {
        case K_F:
        case DK_F:
            newFormula->subformula_l = _fml->subformula_l;
            break;

        case AND_F:
        case OR_F:
            assert(_fml->subformula_r);
            newFormula->subformula_l = copyFormula(_fml->subformula_l);
            newFormula->subformula_r = copyFormula(_fml->subformula_r);
            break;
    }
    return newFormula;
}

void Init::print_f(FILE *out, _formula* f) const {
    switch (f->formula_type) {
        case K_atom:
            fprintf(out, " K_atom ( ");
            print_f(out, Formulatab::instance().getAtom(f->pid));
            fprintf(out, " ) ");
            break;
        case K_F: //k_f
            fprintf(out, " K ( ");
            print_f(out, f->subformula_l);
            fprintf(out, " ) ");
            break;
        case DK_F: //dk_f
            fprintf(out, " DK ( ");
            print_f(out, f->subformula_l);
            fprintf(out, " ) ");
            break;
        case TRUE_F: //true_f
            fprintf(out, " TRUE_F ");
            break;
        case ONE_ATOM_STATE_F:
            fprintf(out, " ONE_ATOM_STATE_F (");
            fprintf(out, "%s", Vocabulary::instance().getAtom(f->pid));
            fprintf(out, " ) ");
            break;
        case THREE_ATOM_BEHIND_F:
            fprintf(out, " THREE_ATOM_BEHIND_F ( \n");
            print_f(out, f->subformula_l);
            print_f(out, f->subformula_r);
            fprintf(out, " ) ");
            break;
        case THREE_ATOMS_F:
            fprintf(out, " THREE_ATOMS_F ( \n");
            print_f(out, f->subformula_l);
            print_f(out, f->subformula_r);
            fprintf(out, " ) ");
            break;
        case THREE_ATOM_F:
            cout << " THREE_ATOM_F ( " << endl;
            fprintf(out, " THREE_ATOM_F ( \n");
            print_f(out, f->subformula_l);
            print_f(out, f->subformula_r);
            fprintf(out, " ) ");
            break;
        case MULTI_THREE_ATOMS:
            fprintf(out, " MULTI_THREE_ATOMS ( \n");
            print_f(out, f->subformula_l);
            print_f(out, f->subformula_r);
            fprintf(out, " ) ");
            break;
        case STATE_F:
            fprintf(out, " STATE_F ( \n");
            fprintf(out, "%s ", Vocabulary::instance().getAtom(f->pid));
            print_f(out, f->subformula_r);
            fprintf(out, " ) ");
            break;
        case VARS_F:
            fprintf(out, " VARS_F ( \n");
            for (int i = 0; i < f->count; i++)
                fprintf(out, "%s ", Vocabulary::instance().getAtom(f->pidlist[i]));
            fprintf(out, " ) ");
            break;
        case VAR_F:
            fprintf(out, " VAR_F ( \n");
            fprintf(out, "%s ", Vocabulary::instance().getAtom(f->pid));
            fprintf(out, " ) ");
            break;
        case NEGA_F:
            fprintf(out, " ~");
            print_f(out, f->subformula_l);
            break;
        case IMPLY_F:
            fprintf(out, " IMPLY_F ( \n");
            print_f(out, f->subformula_l);
            print_f(out, f->subformula_r);
            fprintf(out, " ) ");
            break;
        case EFFECT_F:
            fprintf(out, " EFFECT_F ( \n");
            print_f(out, f->subformula_l);
            fprintf(out, " ) ");
            break;
        case CONEFFECT_F:
            fprintf(out, " CONEFFECT_F ( \n");
            print_f(out, f->subformula_l);
            print_f(out, f->subformula_r);
            fprintf(out, " ) ");
            break;
        case CONOBSERVE_F:
            fprintf(out, " CONOBSERVE_F ( \n");
            print_f(out, f->subformula_l);
            print_f(out, f->subformula_r);
            fprintf(out, " ) ");
            break;
        case OBSERVE_F:
            fprintf(out, " OBSERVER ( \n");
            print_f(out, f->subformula_l);
            fprintf(out, " ) ");
            break;
        case ACTION_F:
            fprintf(out, " ACTION ( \n");
            fprintf(out, "%s ", Vocabulary::instance().getAtom(f->pid));
            print_f(out, f->subformula_r);
            fprintf(out, " ) ");
            break;
        case ACTION_CONTEXT_F:
            fprintf(out, " ACTION_CONTEXT_F ( \n");
            print_f(out, f->subformula_l);
            print_f(out, f->subformula_r);
            fprintf(out, " ) ");
            break;
        case PARAMETERS_F:
            fprintf(out, " PARAMETERS ( \n");
            print_f(out, f->subformula_l);
            fprintf(out, " ) ");
            break;
        case PRECONDITION_F:
            fprintf(out, " PRECONDITION ( \n");
            print_f(out, f->subformula_l);
            fprintf(out, " ) ");
            break;
        case AND_F:
            fprintf(out, " AND ( \n");
            print_f(out, f->subformula_l);
            print_f(out, f->subformula_r);
            fprintf(out, " )\n");
            break;
        case DISJ_F:
            fprintf(out, " OR ( \n");
            print_f(out, f->subformula_l);
            fprintf(out, "\n");
            print_f(out, f->subformula_r);
            fprintf(out, " )\n");
            break;
        case ONEOF_F:
            fprintf(out, " ONEOF_F ( \n");
            print_f(out, f->subformula_l);
            fprintf(out, "\n");
            print_f(out, f->subformula_r);
            fprintf(out, " ) ");
            break;

        case OR_F:
            fprintf(out, " OR ( ");
            print_f(out, f->subformula_l);
            print_f(out, f->subformula_r);
            fprintf(out, " ) ");
            break;
        case EMPTY_F:
            fprintf(out, " EMPTY \n");
            break;
            //        default:
            //            assert(0);
    }

}