/* 
 * File:   Progression.cpp
 * Author: ideapad
 * 
 * Created on December 12, 2014, 3:44 PM
 */
//#define xx 0
//#if xx

#include "Progression.h"

//incomplete!!!
list<PropTerm> term_prog(PropTerm prop_term, const OnticAction &ontic_act) 
{
    list<PropTerm> progression;
    for (int eff_i = 0; eff_i < ontic_act.con_eff.size(); eff_i++) {
        ConEffect cur_con_eff = ontic_act.con_eff[eff_i];
        for (int con_i = 0; con_i < cur_con_eff.condition.size(); con_i++) {
            if (!(prop_term.literals[cur_con_eff.condition[con_i] * 2] || prop_term.literals[cur_con_eff.condition[con_i] * 2 + 1]))
                ;/////////////!!!!!!!!!!!!!!!!!!!!!
        
        }
    }
}

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
    result.minimal();

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
    result.minimal();
    //result.show();
    return result;
}


vector<EpisDNF> epistemic_prog(EpisDNF episDNF, const EpisAction &epis_action)
{	
    /*EpisDNF p_episDNF;
    EpisDNF n_episDNF;
    //for each S5-TE, do epistemic progression
    for (list<EpisTerm>::iterator epis_term_it = episDNF.epis_terms.begin(); epis_term_it != episDNF.epis_terms.end(); epis_term_it++) {
	EpisTerm p_epis_term;
	EpisTerm n_epis_term;
	EpisTerm cur_epis_term = *epis_term_it;
	
        //For the K part of an EpisTerm
        p_epis_term.pos_propDNF = p_epis_term.pos_propDNF.group(epis_action.res1);
        n_epis_term.pos_propDNF = n_epis_term.pos_propDNF.group(epis_action.res2.negation());
        
        //For the K^ part of an EpisTerm
        for (list<PropDNF>::iterator propDNF_it = epis_term_it->neg_propDNFs.begin(); propDNF_it != epis_term_it->neg_propDNFs.end(); propDNF_it++) {
            if (propDNF_it->entails(epis_action.res2))
                p_epis_term.neg_propDNFs.push_back(*propDNF_it);
            if (propDNF_it->entails(epis_action.res2.negation()))
                n_epis_term.neg_propDNFs.push_back(*propDNF_it);
        }
	p_episDNF.epis_terms.push_back(p_epis_term);
	n_episDNF.epis_terms.push_back(n_epis_term);
    }
    
    vector<EpisDNF> result;
    result.push_back(p_episDNF);
    result.push_back(n_episDNF);
    //result[0].show();
    result[0].minimal();
    //result[0].show();
    //result[1].show();
    result[1].minimal();
    //result[1].show();
    return result;*/
}

//#endif