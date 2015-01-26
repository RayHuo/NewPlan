/* 
 * File:   EpisDNF.cpp
 * Author: ideapad
 * 
 * Created on December 11, 2014, 6:43 PM
 */
//#define xx 0
//#if xx
#include "EpisDNF.h"
#include "atoms.h"
#include "Progression.h"
#include <boost/dynamic_bitset.hpp>
#include <vector>

bool PropTerm::consistent() const
{
    for(int i = 0; i < Atoms::instance().atoms_length(); i++){
        if(literals[i * 2] && literals[i * 2 + 1] )
            return false;
    }
    return true;
}

bool PropTerm::entails(const PropTerm& prop_term) const
{
    if (!literals.any()) //first PropTerm is false
        return true;
    return prop_term.literals.is_subset_of(literals);
}

bool PropTerm::equals(const PropTerm& prop_term)
{
    if (prop_term.literals == literals)
	return true;
    return false;
}

//This reasoning rule is Proposition 3.4 PropTerm |= PropClause
bool PropTerm::entails(const PropClause& prop_clause) const
{
    //I understood Proposition 3.4 means if the PropTerm and PropClause has only one same literal, 
    //then return true, otherwise return false
    for (int i = 0; i < Atoms::instance().atoms_length(); i++) {
        if (literals[2 * i] && prop_clause.literals[2 * i] || literals[2 * i + 1] && prop_clause.literals[2 * i + 1])
            return true;
    }
    return false;
}

PropTerm PropTerm::group(const PropTerm& prop_term) const
{
    PropTerm result(Atoms::instance().atoms_length() * 2);
    for (int i = 0; i < Atoms::instance().atoms_length() * 2; i += 2) {
        if (literals[i] && prop_term.literals[i + 1] || literals[i + 1] && prop_term.literals[i]) {
            result.literals.set();
            return result;
        }
        if (literals[i] || prop_term.literals[i])
            result.literals[i] = 1;
        if (literals[i + 1] || prop_term.literals[i + 1])
            result.literals[i + 1] = 1;
    }
    return result;
}

PropTerm& PropTerm::minimal()
{
    if (consistent())
        return *this;
    literals.set(); //inconsistent means this PropTerm is false, we can use a dynamic_bitset whose bits are 1.
    return *this;
}

list<PropTerm> PropTerm::ontic_prog(const OnticAction& ontic_action)
{
    list<PropTerm> progression; //Maybe need to make current PropTerm split into some PropTerms
    boost::dynamic_bitset<> cur_prop_term = literals; //Do not change the PropTerm itself, so need a copy
    
    for (int eff_i = 0; eff_i < ontic_action.con_eff.size(); eff_i++) {
        ConEffect cur_con_eff = ontic_action.con_eff[eff_i];
        for (int i = 0; i < cur_con_eff.condition.size(); i++) {
            if (cur_con_eff.condition[i] > 0) {
                if (!(cur_prop_term[cur_con_eff.condition[i] * 2 - 1] || cur_prop_term[cur_con_eff.condition[i] * 2]))
                    i++;
            }
        
        }
    
    }
}

/*PropTerm PropTerm::compose(const PropTerm& prop_term)
{
    //cout<<"propterm compose"<<endl;
    //cout<<literals<<endl;
    //cout<<prop_term.literals<<endl;
    this->literals.operator |=(prop_term.literals);
    //cout<<"and answer"<<endl;
    //cout<<literals<<endl;
    min();
    //cout<<"min answer"<<endl;
    //cout<<literals<<endl;
    return (*this);
}*/

bool PropDNF::consistent() const
{
    for (list<PropTerm>::const_iterator it = prop_terms.begin(); it != prop_terms.end(); it++) {
        if (it->consistent())
            return true;
    }   
    return false;
}

bool PropDNF::entails(const PropDNF& propDNF) const
{
    /*for (list<PropTerm>::const_iterator pre_it = prop_terms.begin(); pre_it != prop_terms.end(); pre_it++) {
        bool flag = true;
        for (list<PropTerm>::const_iterator post_it = propDNF.prop_terms.begin(); post_it != propDNF.prop_terms.end(); post_it++) 
            if (pre_it->entails(*post_it)){
                flag = false;
                break;
            }
        if (flag)
            return false;      
    }
	return true;*/
    
    //This reasoning rule is Proposition 3.6 DNF |= DNF
    for (list<PropTerm>::const_iterator pre_it = prop_terms.begin(); pre_it != prop_terms.end(); pre_it++) {
        for (list<PropTerm>::const_iterator post_it = propDNF.prop_terms.begin(); post_it != propDNF.prop_terms.end(); post_it++) {
            if (!pre_it->entails(*post_it))
                return false; 
            else //if only one pre term can entail post term, we need to jump the inside loop and see next pre term 
                break;
        }
    }
    return true;
}

bool PropDNF::equals(const PropDNF& propDNF)
{
    /*if (prop_terms.size() != propDNF.prop_terms.size())
        return false;
    else {
        for (list<PropTerm>::const_iterator pre_it = prop_terms.begin(); pre_it != prop_terms.end(); pre_it++) {
            bool flag = true;
            for (list<PropTerm>::const_iterator post_it = propDNF.prop_terms.begin(); post_it != propDNF.prop_terms.end(); post_it++) 
		if (pre_it->equals(*post_it)) {
                    flag = false;
                    break;
                }
            
            if (flag)
                return false;
        }
        return true;
    }*/
    return this->entails(propDNF) && propDNF.entails(*this);
}

//This reasoning rule is Proposition 3.3 DNF |= CNF
bool PropDNF::entails(const PropCNF& propCNF) const
{
    for (list<PropTerm>::const_iterator pre_it = prop_terms.begin(); pre_it != prop_terms.end(); pre_it++) {
        for (list<PropClause>::const_iterator post_it = propCNF.prop_clauses.begin(); post_it != propCNF.prop_clauses.end(); post_it++) {
            if (!pre_it->entails(*post_it))
                return false;
        }
    }
    return true;
}

PropDNF PropDNF::group(const PropDNF& propDNF) const
{
    PropDNF result;
    for (list<PropTerm>::const_iterator it_i = prop_terms.begin(); it_i != prop_terms.end(); it_i++) {
        for (list<PropTerm>::const_iterator it_j = propDNF.prop_terms.begin(); it_j != propDNF.prop_terms.end(); it_j++) 
            result.prop_terms.push_back(it_i->group(*it_j));
    }
    //need to add min and PI method
    return result;
}

PropDNF& PropDNF::minimal()
{
    //show();
    /*for(list<PropTerm>::iterator pre_it = prop_terms.begin(); pre_it != prop_terms.end(); ){
        //pre_it->min();
        if(!pre_it->literals.any()){
            list<PropTerm>::iterator post_it = pre_it;
            pre_it++;
            prop_terms.erase(post_it);
        }
        else
            pre_it++;
    }
    for (list<PropTerm>::iterator pre_it = prop_terms.begin(); pre_it != prop_terms.end(); pre_it++) {
        for (list<PropTerm>::iterator post_it = prop_terms.begin(); post_it != prop_terms.end(); post_it++) {
            if (post_it != pre_it && post_it->entails(*pre_it)) {
                list<PropTerm>::iterator post_it1 = post_it;
                post_it++;
                prop_terms.erase(post_it1);
                continue;
            }
        }
    }
    //show();
    return (*this);*/
    PropDNF result;
    for (list<PropTerm>::iterator pre_it = prop_terms.begin(); pre_it != prop_terms.end(); pre_it++) {
        bool can_entail = false;
        for (list<PropTerm>::iterator post_it = prop_terms.begin(); post_it != prop_terms.end(); post_it++) {
            if (post_it != pre_it && pre_it->entails(*post_it)) {
                can_entail = true;
                break;
            }       
        }
       
        if(!can_entail)
            result.prop_terms.push_back(*pre_it);
    }
    
    this->prop_terms = result.prop_terms;
    
    return *this;
}

PropDNF PropDNF::ontic_prog(const OnticAction& ontic_action)
{
    PropDNF result;
    for (list<PropTerm>::iterator it = prop_terms.begin(); it != prop_terms.end(); it++) {
        list<PropTerm> res = it->ontic_prog(ontic_action);
        for (list<PropTerm>::iterator prog_res_it = res.begin(); prog_res_it != res.end(); prog_res_it++)
            result.prop_terms.push_back(*prog_res_it);
        //result.prop_terms.push_back((*it).ontic_prog(ontic_action));
    }
    return result;
}

/*PropDNF PropDNF::compose(const PropDNF& propDNF)
{
    //cout<<"compose"<<endl;
    //cout<<"self"<<endl;
    //show();
    //cout<<"add"<<endl;
    //propDNF.show();
    PropDNF result;
    for (list<PropTerm>::iterator it_i = prop_terms.begin(); it_i != prop_terms.end(); it_i++) {
        for (list<PropTerm>::const_iterator it_j = propDNF.prop_terms.begin(); it_j != propDNF.prop_terms.end(); it_j++) {
            PropTerm p;
            p.literals = it_i->literals;
            result.prop_terms.push_back(p.compose(*it_j));
        }
    }
    //cout<<"and answer"<<endl;
    //result.show();
    result.min();
    //cout<<"min answer"<<endl;
    //result.show();
    return result;
}*/


void PropDNF::convert_IPIA() {
    assert(! prop_terms.empty());
    list<PropTerm>::const_iterator it = prop_terms.begin();
    list<PropTerm> pi;
    pi.push_back(*it);
    for (++ it; it != prop_terms.end(); ++ it) {
        // Algorithm 1: Incremental prime implicant algorithm
        PropTerm t = *it;
        list<PropTerm> segma;
        segma.push_back(t);
        // delete operation
        bool is_t_delete = delete_operation_in_IPIA(t, pi, segma);
        if (! is_t_delete) {
            list<PropTerm> new_to_segma;
            for (size_t l = 0; l < t.literals.size(); ++ l) {
                if (! t.literals.test(l)) {
                    continue;
                }
                // 存在 t'属于pi，t''属于segma，
                // 且 (l属于t') && (~l属于t'') || (~l属于t') && (l属于t'')
                size_t _l = (l % 2 == 0) ? l + 1 : l - 1;
                for (list<PropTerm>::iterator it_pi = pi.begin();
                        it_pi != pi.end(); ++ it_pi) {
                    for (list<PropTerm>::iterator it_segma = segma.begin();
                            it_segma != segma.end(); ++ it_segma) {
                        if (it_pi->literals.test(l) && it_segma->literals.test(_l) ||
                                it_pi->literals.test(_l) && it_segma->literals.test(l)) {
                            // t* = term(t', t'', l);
                            PropTerm tx = *it_pi;
                            tx.literals |= it_segma->literals;
                            tx.literals.reset(l);
                            tx.literals.reset(_l);
                            // segma = segma \cup {t*}
                            if (tx.consistent()) 
                                new_to_segma.push_back(tx);
                        }
                    }
                }
            }
            segma.insert(segma.end(), new_to_segma.begin(), new_to_segma.end());
            // delete operation，需要保证没有重复的元素
            delete_operation_in_IPIA(t, pi, segma);
        }
        // pi = pi \cup segma, update it for the next iteration
        pi.insert(pi.end(), segma.begin(), segma.end());
    }
    prop_terms = pi;
}
// 
bool PropDNF::delete_operation_in_IPIA(const PropTerm &t, list<PropTerm> &pi, 
        list<PropTerm> &segma) {
    // 化简pi和segma，删除重复元素
    PropDNF pi_helper;  pi_helper.prop_terms = pi;      
    pi_helper.minimal();    pi = pi_helper.prop_terms;
    PropDNF segma_helper;       segma_helper.prop_terms = segma;
    segma_helper.minimal();         segma = segma_helper.prop_terms;
    // pi \cup segma
    list<PropTerm> both;
    both.insert(both.end(), pi.begin(), pi.end());
    both.insert(both.end(), segma.begin(), segma.end());
    //处理pi
    for (list<PropTerm>::iterator it = pi.begin(); it != pi.end(); ) {
        int count = 0;
        for (list<PropTerm>::const_iterator it_both = both.begin();
                it_both != both.end(); ++ it_both) {
            if (it_both->entails(*it))
                ++ count;
        }
        if (count > 1)
            it = pi.erase(it);
        else
            ++ it;
    }
    // 处理segma
    bool is_t_delete = false;
    for (list<PropTerm>::iterator it = segma.begin(); it != segma.end(); ) {
        int count = 0;
        for (list<PropTerm>::const_iterator it_both = both.begin();
                it_both != both.end(); ++ it_both) {
            if (it_both->entails(*it))
                ++ count;
        }
        if (count > 1) {
            if (it->equals(t))
                is_t_delete = true;
            it = segma.erase(it);
        }
        else
            ++ it;
    }
    return is_t_delete;
}

bool EpisTerm::consistent() const
{
    if (!pos_propDNF.consistent())
        return false;
    else {
        for (list<PropDNF>::const_iterator it = neg_propDNFs.begin(); it != neg_propDNFs.end(); it++) {
            if (!it->consistent())
                return false;
        }
        return true;
    }
}

//This reasoning rule is Proposition 3.5
bool EpisTerm::entails(const EpisTerm& epis_term) const
{
    if (!pos_propDNF.entails(epis_term.pos_propDNF))
        return false;
    else {
        //The following is the first case of rule 2 in Proposition 3.5
        int count = 0; //The pos_propDNF of first EpisTerm can entail how many DNF in neg_propDNFs of second EpisTerm
        for (list<PropDNF>::const_iterator post_it = epis_term.neg_propDNFs.begin(); post_it != epis_term.neg_propDNFs.end(); post_it++) {
            if (pos_propDNF.entails(*post_it))
                count++;
            else 
                break;
        }
        if (count == epis_term.neg_propDNFs.size())
            return true;
        
        //The following is the second case of rule 2 in Proposition 3.5
	for (list<PropDNF>::const_iterator post_it = epis_term.neg_propDNFs.begin(); post_it != epis_term.neg_propDNFs.end(); post_it++) {
            bool can_entail = false;
            for (list<PropDNF>::const_iterator pre_it = neg_propDNFs.begin(); pre_it != neg_propDNFs.end(); pre_it++) {
                if (pre_it->entails(*post_it)) {
                    can_entail = true;
                    break;
                }
	    }		
            if (!can_entail)
                return false;           
        }		
        return true;
    }
}

bool EpisTerm::equals(const EpisTerm& epis_term)
{
    /*if (neg_propDNFs.size() != epis_term.neg_propDNFs.size())
		return false;
    else {
        if (!pos_propDNF.equals(epis_term.pos_propDNF))
            return false;
        else {
            for (list<PropDNF>::const_iterator pre_it = neg_propDNFs.begin(); pre_it != neg_propDNFs.end(); pre_it++) {
                bool flag = true;
                for (list<PropDNF>::const_iterator post_it = epis_term.neg_propDNFs.begin(); post_it != epis_term.neg_propDNFs.end(); post_it++) 
                    if (pre_it->equals(*post_it)){
                        flag = false;
                        break;
                    }				
                if (flag)
                    return false;           
            }		
            return true;
        }
    }*/
    return this->entails(epis_term) && epis_term.entails(*this);
}

//This reasoning is Proposition 3.2 EpisTerm |= EpisClause
bool EpisTerm::entails(const EpisClause& epis_clause) const
{
    //case 1 of Proposition 3.2
    PropDNF ec_neg_tmp = epis_clause.neg_propCNF.negation();
    if (!pos_propDNF.group(ec_neg_tmp).consistent())
        return true;
    
    //case 2 of Proposition 3.2
    for (list<PropDNF>::const_iterator it = neg_propDNFs.begin(); it != neg_propDNFs.end(); it++) {
        if (!it->group(ec_neg_tmp).consistent())
            return true;
    }
    
    //case 3 of Proposition 3.2
    for (list<PropCNF>::const_iterator it = epis_clause.pos_propCNFs.begin(); it != epis_clause.pos_propCNFs.end(); it++) {
        if (!pos_propDNF.group(it->negation()).consistent())
            return true;
    }
    
    return false;
}

EpisTerm& EpisTerm::minimal()
{
    /*//show();
    pos_propDNF.minimal();
    for (list<PropDNF>::iterator it = neg_propDNFs.begin(); it != neg_propDNFs.end(); it++){
        it->minimal();
        if(it->prop_terms.size() == 0){
            list<PropDNF>::iterator it1 = it;
            it++;
            neg_propDNFs.erase(it1);
        }
            
    }
    for (list<PropDNF>::iterator pre_it = neg_propDNFs.begin(); pre_it != neg_propDNFs.end(); pre_it++) {
        for (list<PropDNF>::iterator post_it = neg_propDNFs.begin(); post_it != neg_propDNFs.end(); ) {
            if (pre_it != post_it && post_it->entails(*pre_it)) {
                list<PropDNF>::iterator post_it1 = post_it;
                post_it++;
                neg_propDNFs.erase(post_it1);
                continue;
            }
            else
                post_it++;
        }
    }
    
    return (*this);*/
    
    //For an EpisTerm, we need each \eta_i can entail \psi;
    separable();
    
    //For an EpisTerm, possible parts can't entail each other
    for (list<PropDNF>::iterator pre_it = neg_propDNFs.begin(); pre_it != neg_propDNFs.end(); pre_it++) {
        for (list<PropDNF>::iterator post_it = neg_propDNFs.begin(); post_it != neg_propDNFs.end(); ) {
            if (pre_it != post_it && pre_it->entails(*post_it)) {
                list<PropDNF>::iterator delete_it = post_it;
                post_it++;
                neg_propDNFs.erase(delete_it);
            }
            else
                post_it++;
        }
    }  
    
    //For an EpisTerm, we need that \psi and each \eta_i are minimal 
    pos_propDNF.minimal();
    for (list<PropDNF>::iterator it = neg_propDNFs.begin(); it != neg_propDNFs.end(); it++)
        it->minimal();
          
    return *this;
}

EpisTerm& EpisTerm::separable()
{
    for (list<PropDNF>::iterator it = neg_propDNFs.begin(); it != neg_propDNFs.end(); it++) {
        if (!it->entails(pos_propDNF)) 
            *it = it->group(pos_propDNF);
    }
    return *this;
}

/*PropDNF EpisTerm::group_pel(const list<PropDNF>& propDNFs)
{
    list<PropDNF>::const_iterator it = propDNFs.begin();
    PropDNF tmp = *it;
    it++;
    for (; it != propDNFs.end(); it++) 
        tmp = tmp.compose(*it);
    tmp.min();
    return tmp;    
}*/

/*EpisTerm EpisTerm::group_pel(const EpisTerm & epis_term)
{
    EpisTerm result = *this; //need copy constructor, = operator, destructor are written explicitly???
    result.pos_propDNF = result.pos_propDNF.group(epis_term.pos_propDNF);
    
    for (list<PropDNF>::const_iterator it = epis_term.neg_propDNFs.begin(); it != epis_term.neg_propDNFs.end(); it++) 
        result.neg_propDNFs.push_back(*it);
    //cout<<"\n\n\n\nshow before min"<<endl;
    //show();
    result.minimal();
    return result;
}*/

/*void EpisTerm::show(){
    cout<<"  show_EpisTerm"<<endl;
    cout<<"   pos_part"<<endl;
    pos_propDNF.show();
    cout<<"   neg_part"<<endl;
    //cout<<neg_propDNFs.size()<<endl;
    for(list<PropDNF>::iterator it = neg_propDNFs.begin(); it != neg_propDNFs.end(); it++)
        it->show();
    cout<<"  end_show_EpisTerm"<<endl;
    
}*/

/*bool EpisTerm::is_empty(){
    if(pos_propDNF.prop_terms.size() == 0 && neg_propDNFs.size() == 0)
        return true;
    return false;
}*/

void EpisTerm::convert_IPIA() {
    pos_propDNF.convert_IPIA();
    for (list<PropDNF>::iterator it = neg_propDNFs.begin();
            it != neg_propDNFs.end(); ++ it) {
        it->convert_IPIA();
    }
}

EpisTerm EpisTerm::ontic_prog(const OnticAction& ontic_action)
{
    EpisTerm result;
    result.pos_propDNF = pos_propDNF.ontic_prog(ontic_action);
    for (list<PropDNF>::iterator it = neg_propDNFs.begin(); it != neg_propDNFs.end(); it++)
        result.neg_propDNFs.push_back(it->ontic_prog(ontic_action));
    return result;
}

//This method is based on Proposition 3.7, and it is a basis of method equals
bool EpisDNF::entails(const EpisDNF& episDNF) const
{	
    for (list<EpisTerm>::const_iterator pre_it  = epis_terms.begin(); pre_it != epis_terms.end(); pre_it++) {
        bool can_entail = false;
        for (list<EpisTerm>::const_iterator post_it = episDNF.epis_terms.begin(); post_it != episDNF.epis_terms.end(); post_it++) {
            if (pre_it->entails(*post_it)) {
                can_entail = true;
                break;
            }
        }
        if (!can_entail)
            return false;
    }
    return true;
    /*for (list<EpisTerm>::const_iterator post_it = episDNF.epis_terms.begin(); post_it != episDNF.epis_terms.end(); post_it++) {
        bool flag = true;
        for (list<EpisTerm>::const_iterator pre_it = epis_terms.begin(); pre_it != epis_terms.end(); pre_it++) 
            if (pre_it->entails(*post_it)){
                flag = false;
                break;
            }
        if(flag)
             return false;
    }
    return true;*/
}


//This reasoning rule is Proposition 3.7 EDNF |= ENDF
bool EpisDNF::equals(const EpisDNF& episDNF)
{
    return this->entails(episDNF) && episDNF.entails(*this);
}

/*bool EpisDNF::entails(EpisClause epis_clause)
{
    //epis_clause.show();
    EpisTerm epis_term = negation_Clause(epis_clause);
    //epis_term.show();
    for (list<EpisTerm>::iterator it = epis_terms.begin(); it != epis_terms.end(); it++) {
        //cout<<"self:"<<endl;
        //show();
        //cout<<"group:"<<endl;
        //epis_term.show();
        EpisTerm judge_epis_term = (*it).group_pel(epis_term);
        //cout<<"answer:"<<endl;
        //judge_epis_term.show();
        if (!judge_epis_term.consistent())
            return false;
    }
    return true;
}*/

//This method is Propposition 3.1 EpisDNF |= EpisCNF
bool EpisDNF::entails(const EpisCNF& episCNF) const {
    /*//cout<<"cnf size: "<<episCNF.epis_clauses.size()<<endl;
    if(episCNF.epis_clauses.size() != 0)
        for(list<EpisClause>::iterator it = episCNF.epis_clauses.begin(); it != episCNF.epis_clauses.end(); it++){
            //show();
            //cout<<"\\\\"<<endl;
            //it->show();
            //cout<<"\\\\\\\\\\"<<endl;
            if(!this->entails(*it))
                return false;
        }
    return true;*/
    for (list<EpisTerm>::const_iterator pre_it = epis_terms.begin(); pre_it != epis_terms.end(); pre_it++) {
        for (list<EpisClause>::const_iterator post_it = episCNF.epis_clauses.begin(); post_it != episCNF.epis_clauses.end(); post_it++) {
            if (!pre_it->entails(*post_it))
                return false;
        }
    }
    return true;
}

EpisDNF& EpisDNF::minimal()
{
    //show();
    /*for (list<EpisTerm>::iterator it = epis_terms.begin(); it != epis_terms.end(); it++){
        it->minimal();
        if(it->isempty()){
            list<EpisTerm>::iterator it1 = it;
            it++;
            epis_terms.erase(it1);
        }
    }
    
    for (list<EpisTerm>::iterator pre_it = epis_terms.begin(); pre_it != epis_terms.end(); pre_it++) {
        for (list<EpisTerm>::iterator post_it = epis_terms.begin(); post_it != epis_terms.end(); post_it++) {
            if (pre_it != post_it && post_it->entails(*pre_it)) {
                list<EpisTerm>::iterator post_it1 = post_it;
                post_it++;
                epis_terms.erase(post_it1);
                continue;
            }
        }
    }
    
    return (*this);*/
    for (list<EpisTerm>::iterator it = epis_terms.begin(); it != epis_terms.end(); it++)
        it-> minimal();
}

EpisDNF EpisDNF::ontic_prog(const OnticAction& ontic_action)
{
    EpisDNF result;
    for (list<EpisTerm>::iterator it = epis_terms.begin(); it != epis_terms.end(); it++) {
        result.epis_terms.push_back(it->ontic_prog(ontic_action));
    }
    result.minimal();
    return result;
}

/*void EpisDNF::show(){
    cout<<"show-EpisDNF"<<endl;
    for(list<EpisTerm>::iterator it = epis_terms.begin(); it != epis_terms.end(); it++)
        it->show();
    
    cout<<"end_show-EpisDNF"<<endl;
            
}*/

void EpisDNF::convert_IPIA() {
    for (list<EpisTerm>::iterator it = epis_terms.begin();
            it != epis_terms.end(); ++ it) {
        it->convert_IPIA();
    }
}




/*EpisTerm EpisClause::negation()
{
    EpisTerm result;
    
    //for positive knowledge
    list<PropDNF> pos_propDNFs;
    for (list<PropCNF>::iterator it = neg_propCNFs.begin(); it != neg_propCNFs.end(); it++) 
	pos_propDNFs.push_back(it->negation());
    result.pos_propDNF = result.group_pel(pos_propDNFs);
    
    //for negative knowledge
    for (list<PropCNF>::iterator it = pos_propCNFs.begin(); it != pos_propCNFs.end(); it++)
	result.neg_propDNFs.push_back(it->negation());
    
    return result;
}
*/
/*EpisTerm negation_Clause(EpisClause episclause){
    EpisTerm result;
    
    //for positive knowledge
    list<PropDNF> pos_propDNFs;
    for (list<PropCNF>::iterator it = episclause.neg_propCNFs.begin(); it != episclause.neg_propCNFs.end(); it++) {
        //it->show();
        //cout<<"//////"<<endl;
        //(it->negation()).show();
	pos_propDNFs.push_back(it->negation());
    }
    result.pos_propDNF = result.group_pel(pos_propDNFs);
    
    //for negative knowledge
    for (list<PropCNF>::iterator it = episclause.pos_propCNFs.begin(); it != episclause.pos_propCNFs.end(); it++)
        result.neg_propDNFs.push_back(it->negation());
    
    return result; 
}*/
//#endif