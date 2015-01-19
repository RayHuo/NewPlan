/* 
 * File:   Progression.cpp
 * Author: ideapad
 * 
 * Created on December 12, 2014, 3:44 PM
 */
//#define xx 0
//#if xx

#include "Progression.h"

PropDNF DNF_prog(PropDNF propDNF, const OnticAction & ontic_act) 
{
    PropDNF result;
    for (list<PropTerm>::iterator it = propDNF.prop_terms.begin(); it != propDNF.prop_terms.end(); it++) {
	PropTerm cur_prop_term = *it;

	for (int eff_i = 0; eff_i < ontic_act.con_eff.size(); eff_i++) {
            ConEffect cur_con_eff = ontic_act.con_eff[eff_i];		
			
            bool can_do = true;
            for (int con_i = 0; con_i < cur_con_eff.condition.size(); con_i++) {
                if (!cur_prop_term.literals[cur_con_eff.condition[con_i]]) {
                    can_do = false;
                    break;
		}
            }

            if (can_do) {
		for (int add_i = 0; add_i < cur_con_eff.add.size(); add_i++) {
                    if (cur_prop_term.literals[cur_con_eff.add[add_i]*2 - 1])
			cur_prop_term.literals[cur_con_eff.add[add_i]*2 - 1] = false;
                    cur_prop_term.literals[cur_con_eff.add[add_i]*2 - 2] = true;
                    //if(!cur_prop_term.consistent()){
                        
                    //}
		}

		for (int del_i = 0; del_i < cur_con_eff.del.size(); del_i++) {
                    cur_prop_term.literals[cur_con_eff.del[del_i]*2-2] = false;
		}
            }
        }
	result.prop_terms.push_back(cur_prop_term);
    }
    result.min();

    return result;
}

EpisDNF ontic_prog(EpisDNF episDNF, const OnticAction &ontic_action)
{
    EpisDNF result;
    for (list<EpisTerm>::iterator it = episDNF.epis_terms.begin(); it != episDNF.epis_terms.end(); it++) {
	EpisTerm cur_epis_term = *it;
	EpisTerm res_epis_term;
        
        res_epis_term.pos_propDNF = DNF_prog(it->pos_propDNF, ontic_action);
	for (list<PropDNF>::iterator propDNF_it = it->neg_propDNFs.begin(); propDNF_it != it->neg_propDNFs.end(); propDNF_it++) 
            res_epis_term.neg_propDNFs.push_back(DNF_prog(*propDNF_it, ontic_action));
    }
    result.min();
    result.show();
    return result;
}


vector<EpisDNF> epistemic_prog(EpisDNF episDNF, const EpisAction &epis_action)
{	
    EpisDNF p_episDNF;
    EpisDNF n_episDNF;
    //for each S5-TE, do epsitemic progression
    for (list<EpisTerm>::iterator epis_term_it = episDNF.epis_terms.begin(); epis_term_it != episDNF.epis_terms.end(); epis_term_it++) {
	EpisTerm p_epis_term;
	EpisTerm n_epis_term;
	EpisTerm cur_epis_term = *epis_term_it;
	for (int i = 0; i < epis_action.observe.size(); i++) {
            //int p_literal_num = epis_action.observe[i];
            //int n_literal_num = p_literal_num + 1;
  
            for (list<PropTerm>::iterator prop_term_it = epis_term_it->pos_propDNF.prop_terms.begin(); prop_term_it != epis_term_it->pos_propDNF.prop_terms.end(); prop_term_it++) {
                PropTerm cur_prop_term = *prop_term_it;
                PropTerm cur_prop_term_copy = cur_prop_term;
                cur_prop_term.literals[epis_action.observe[i]*2-2] = true;
                p_epis_term.pos_propDNF.prop_terms.push_back(cur_prop_term);
                cur_prop_term_copy.literals[epis_action.observe[i]*2 - 1] = false;
                n_epis_term.pos_propDNF.prop_terms.push_back(cur_prop_term);
            }
            
            for (list<PropDNF>::iterator propDNF_it = epis_term_it->neg_propDNFs.begin(); propDNF_it != epis_term_it->neg_propDNFs.end(); propDNF_it++) {
		PropDNF p_propDNF;
		PropDNF n_propDNF;
		//PropDNF cur_propDNF = cur_epis_term.propDNFs[propDNF_i];
		for (list<PropTerm>::iterator prop_term_it = propDNF_it->prop_terms.begin(); prop_term_it != propDNF_it->prop_terms.end(); prop_term_it++) {
                    PropTerm cur_prop_term = *prop_term_it;
                    PropTerm cur_prop_term_copy = cur_prop_term;
                    cur_prop_term.literals[epis_action.observe[i]*2-2] = true;
                    p_propDNF.prop_terms.push_back(cur_prop_term);
                    cur_prop_term_copy.literals[epis_action.observe[i]*2 - 1] = false;
                    n_propDNF.prop_terms.push_back(cur_prop_term_copy);
		}
		p_epis_term.neg_propDNFs.push_back(p_propDNF);
		n_epis_term.neg_propDNFs.push_back(n_propDNF);
            }
	}
	p_episDNF.epis_terms.push_back(p_epis_term);
	n_episDNF.epis_terms.push_back(n_epis_term);
    }
    vector<EpisDNF> result;
    result.push_back(p_episDNF);
    result.push_back(n_episDNF);
    //result[0].show();
    result[0].min();
    //result[0].show();
    //result[1].show();
    result[1].min();
    //result[1].show();
    return result;
}

//#endif