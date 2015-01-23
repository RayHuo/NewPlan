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
#include <boost/dynamic_bitset.hpp>
#include <vector>

bool PropTerm::consistent() const
{
    for(int i = 0; i < Atoms::instance().atoms_length(); i++){
        if(literals[i*2] && literals[i*2+1] )
            return false;
    }
    return true;
}

bool PropTerm::entails(const PropTerm& prop_term) const
{
    return prop_term.literals.is_subset_of(literals);
}

bool PropTerm::equals(const PropTerm& prop_term) const
{
    if (prop_term.literals == literals)
		return true;
	return false;
}

PropTerm& PropTerm::min()
{
    if (consistent())
        return *this;
    literals.reset();
    return (*this);
}

PropTerm PropTerm::compose(const PropTerm& prop_term)
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
}

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
    for (list<PropTerm>::const_iterator pre_it = prop_terms.begin(); pre_it != prop_terms.end(); pre_it++) {
        bool flag = true;
        for (list<PropTerm>::const_iterator post_it = propDNF.prop_terms.begin(); post_it != propDNF.prop_terms.end(); post_it++) 
            if (pre_it->entails(*post_it)){
                flag = false;
                break;
            }
        if (flag)
            return false;      
    }
	return true;
}

bool PropDNF::equals(const PropDNF& propDNF) const
{
    if (prop_terms.size() != propDNF.prop_terms.size())
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
    }
}

PropDNF& PropDNF::min()
{
    //show();
    for(list<PropTerm>::iterator pre_it = prop_terms.begin(); pre_it != prop_terms.end(); ){
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
    return (*this);
}

PropDNF PropDNF::compose(const PropDNF& propDNF)
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
}


void PropDNF::convect_IPIA() {
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
                            tx.literals.reset(~l);
                            // segma = segma \cup {t*}
                            if (tx.consistent())
                                segma.push_back(tx);
                        }
                    }
                }
                // delete operation，需要保证没有重复的元素
                delete_operation_in_IPIA(t, pi, segma);
            }
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
    pi_helper.min();    pi = pi_helper.prop_terms;
    PropDNF segma_helper;       segma_helper.prop_terms = segma;
    segma_helper.min();         segma = segma_helper.prop_terms;
    // 处理pi
    for (list<PropTerm>::iterator it = pi.begin(); it != pi.end(); /*手动处理迭代器*/) {
        bool is_delete = false;
        for (list<PropTerm>::iterator it_pi = pi.begin();
                (! is_delete) && (it_pi != pi.end()); ++ it_pi) {
            if (it == it_pi)
                continue;
            if (it_pi->entails(*it)) {
                is_delete = true;
                it = pi.erase(it);
            }
        }
        for (list<PropTerm>::iterator it_segma = segma.begin();
                (! is_delete) && (it_segma != segma.end()); ++ it_segma) {
            if (it_segma->entails(*it)) {
                is_delete = true;
                it = pi.erase(it);
            }
        }
        if (! is_delete)
            ++ it;
    }
    // 处理segma
    for (list<PropTerm>::iterator it = segma.begin(); it != segma.end(); /*手动处理迭代器*/) {
        bool is_delete = false;
        for (list<PropTerm>::iterator it_pi = pi.begin();
                (! is_delete) && (it_pi != pi.end()); ++ it_pi) {
            if (it_pi->entails(*it)) {
                is_delete = true;
                it = segma.erase(it);
            }
        }
        for (list<PropTerm>::iterator it_segma = segma.begin();
                (! is_delete) && (it_segma != segma.end()); ++ it_segma) {
            if (it == it_segma)
                continue;
            if (it_segma->entails(*it)) {
                is_delete = true;
                it = segma.erase(it);
            }
        }
        if (! is_delete)
            ++ it;
    }
    bool is_t_delete = true;
    for (list<PropTerm>::const_iterator it = segma.begin(); it != segma.end(); ++ it) {
        if (it->equals(t)) {
            is_t_delete = false;
            break;
        }
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

bool EpisTerm::entails(const EpisTerm& epis_term) const
{
    if (!pos_propDNF.entails(epis_term.pos_propDNF))
        return false;
    else {
	for (list<PropDNF>::const_iterator post_it = epis_term.neg_propDNFs.begin(); post_it != epis_term.neg_propDNFs.end(); post_it++) {
            bool flag = true;
            for (list<PropDNF>::const_iterator pre_it = neg_propDNFs.begin(); pre_it != neg_propDNFs.end(); pre_it++) 
                if (pre_it->entails(*post_it)){
                    flag = false;
                    break;
                }
			
            if (flag)
                return false;           
        }		
        return true;
    }
}

bool EpisTerm::equals(const EpisTerm& epis_term) const
{
    if (neg_propDNFs.size() != epis_term.neg_propDNFs.size())
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
    }
}

EpisTerm& EpisTerm::min()
{
    //show();
    pos_propDNF.min();
    for (list<PropDNF>::iterator it = neg_propDNFs.begin(); it != neg_propDNFs.end(); it++){
        it->min();
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
    
    return (*this);
}

PropDNF EpisTerm::group_pel(const list<PropDNF>& propDNFs)
{
    list<PropDNF>::const_iterator it = propDNFs.begin();
    PropDNF tmp = *it;
    it++;
    for (; it != propDNFs.end(); it++) 
        tmp = tmp.compose(*it);
    tmp.min();
    return tmp;    
}

EpisTerm EpisTerm::group_pel(const EpisTerm & epis_term)
{
    EpisTerm ep;
    ep.pos_propDNF = pos_propDNF.compose(epis_term.pos_propDNF);
    for (list<PropDNF>::const_iterator it = epis_term.neg_propDNFs.begin(); it != epis_term.neg_propDNFs.end(); it++) 
        ep.neg_propDNFs.push_back(*it);
    //cout<<"\n\n\n\nshow before min"<<endl;
    //show();
    ep.min();
    return ep;
}

void EpisTerm::show(){
    cout<<"  show_EpisTerm"<<endl;
    cout<<"   pos_part"<<endl;
    pos_propDNF.show();
    cout<<"   neg_part"<<endl;
    //cout<<neg_propDNFs.size()<<endl;
    for(list<PropDNF>::iterator it = neg_propDNFs.begin(); it != neg_propDNFs.end(); it++)
        it->show();
    cout<<"  end_show_EpisTerm"<<endl;
    
}

bool EpisTerm::isempty(){
    if(pos_propDNF.prop_terms.size() == 0 && neg_propDNFs.size() == 0)
        return true;
    return false;
}

void EpisTerm::convert_IPIA() {
    pos_propDNF.convert_IPIA();
    for (list<PropDNF>::iterator it = neg_propDNFs.begin();
            it != neg_propDNFs.end(); ++ it) {
        it->convert_IPIA();
    }
}

//??EpisDNF |= EpisDNF ==> EpisDNF | !EpisDNF sat??
bool EpisDNF::entails(const EpisDNF& episDNF) const
{	
    
    for (list<EpisTerm>::const_iterator post_it = episDNF.epis_terms.begin(); post_it != episDNF.epis_terms.end(); post_it++) {
        bool flag = true;
        for (list<EpisTerm>::const_iterator pre_it = epis_terms.begin(); pre_it != epis_terms.end(); pre_it++) 
            if (pre_it->entails(*post_it)){
                flag = false;
                break;
            }
        if(flag)
             return false;
    }
    return true;
}




bool EpisDNF::equals(const EpisDNF& episDNF) const
{
    if (epis_terms.size() != episDNF.epis_terms.size())
        return false;
    else {
	for (list<EpisTerm>::const_iterator pre_it = epis_terms.begin(); pre_it != epis_terms.end(); pre_it++) {
            bool flag = true;
            for (list<EpisTerm>::const_iterator post_it = episDNF.epis_terms.begin(); post_it != episDNF.epis_terms.end(); post_it++) 
                if (pre_it->equals(*post_it)){
                    flag = false;
                    break;
                }
            
            if (flag)
		return false;           
        }		
        return true;	
    }
}





bool EpisDNF::entails(EpisClause epis_clause)
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
}

//?? EpisDNF |= EpisCNF => EpisDNF | !EpisCNF?? 
bool EpisDNF::entails(EpisCNF episCNF){
    //cout<<"cnf size: "<<episCNF.epis_clauses.size()<<endl;
    if(episCNF.epis_clauses.size() != 0)
        for(list<EpisClause>::iterator it = episCNF.epis_clauses.begin(); it != episCNF.epis_clauses.end(); it++){
            //show();
            //cout<<"\\\\"<<endl;
            //it->show();
            //cout<<"\\\\\\\\\\"<<endl;
            if(!this->entails(*it))
                return false;
        }
    return true;
}

EpisDNF& EpisDNF::min()
{
    //show();
    for (list<EpisTerm>::iterator it = epis_terms.begin(); it != epis_terms.end(); it++){
        it->min();
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
    
    return (*this);
}

void EpisDNF::show(){
    cout<<"show-EpisDNF"<<endl;
    for(list<EpisTerm>::iterator it = epis_terms.begin(); it != epis_terms.end(); it++)
        it->show();
    
    cout<<"end_show-EpisDNF"<<endl;
        
    
}

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
EpisTerm negation_Clause(EpisClause episclause){
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
}
//#endif