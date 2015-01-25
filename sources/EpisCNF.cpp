/* 
 * File:   EpisCNF.cpp
 * Author: ideapad
 * 
 * Created on December 11, 2014, 7:01 PM
 */
//#define xx 0
//#if xx
//#ifndef EPISCNF_H
//#define	EPISCNF_H
#include <boost/dynamic_bitset.hpp>
#include <list>
#include <iostream>
#include "atoms.h"
#include "EpisCNF.h"

PropTerm PropClause::negation()
{
    PropTerm result(Atoms::instance().atoms_length() * 2);
    //cout<<"oring: "<<endl;
    //cout<<this->literals<<endl;
    for (int i = 0; i < literals.size(); i++) {
        if(literals[i]) {
            result.literals[i] = 0; //?dynamic_bitset constructor makes all of bis in literals 0, so this clause is useless 
            if (i % 2 == 0) 
                result.literals[i + 1] = 1;
            else                    //this else is useless!!!
                result.literals[i - 1] = 1;
        }
    }
    //cout<<result.literals<<endl;
    return result;
}

bool PropClause::is_true() const
{
    return literals.count() == literals.size(); 
}

PropClause& PropClause::minimal()
{
    PropClause result(Atoms::instance().atoms_length() * 2);
    for (int i = 0; i < Atoms::instance().atoms_length(); i += 2) {
        if (literals[i] && literals[i + 1]) {
            result.literals.set(); //This PropClause is true, we can use a dynamic_bitset whose bits are 1.
            break;
        }          
    }
    *this = result;
    return *this;
}

/*void PropCNF::show()
{
    cout<<"    PropCNF begin"<<endl;
    for(list<PropClause>::iterator it = prop_clauses.begin(); it != prop_clauses.end(); it++)
        cout<<it->literals<<endl;
    cout<<"    PropCNF end"<<endl;
}

void EpisClause::show()
{
    cout<<"  EpisClause pos begin"<<endl;
    for(list<PropCNF>::iterator it = pos_propCNFs.begin(); it != pos_propCNFs.end(); it++)
        it->show();
    cout<<"  EpisClause pos end"<<endl;
    cout<<"  EpisClause neg begin"<<endl;
    for(list<PropClause>::iterator it = neg_propCNFs.prop_clauses.begin(); it != neg_propCNFs.prop_clauses.end(); it++)
        it->show();
    cout<<"  EpisClause neg end"<<endl;

}*/

PropDNF PropCNF::negation()
{
    PropDNF result;
    for (list<PropClause>::iterator it = prop_clauses.begin(); it != prop_clauses.end(); it++) {
        //cout<<"propcnf"<<endl;
        //cout<<it->literals<<endl;
        
        result.prop_terms.push_back(it->negation());
    }
    return result;	
}

//a |= b <=> !b |= !a, but I think this method is not right!
bool PropCNF::entails(PropCNF& propCNF)
{
    return propCNF.negation().entails(this->negation());
}

PropCNF& PropCNF::minimal()
{
    for (list<PropClause>::iterator pre_it = prop_clauses.begin(); pre_it != prop_clauses.end(); pre_it++) {
        for (list<PropClause>::iterator post_it = prop_clauses.begin(); post_it != prop_clauses.end(); ) {
            if (post_it != pre_it && pre_it->entails(*post_it)) {
                list<PropClause>::iterator delete_it = post_it;
                post_it++;
                prop_clauses.erase(delete_it);
            }   
            else
                post_it++;
        }
    }
    
    return *this;
}

EpisClause& EpisClause::separable()
{
    for (list<PropCNF>::iterator pre_it = pos_propCNFs.begin(); pre_it != pos_propCNFs.end(); ) {
        bool can_entail = false;
        PropCNF tmp = *pre_it;
        for (list<PropCNF>::iterator post_it = pos_propCNFs.begin(); post_it != pos_propCNFs.end(); post_it++) {
            if (pre_it != post_it && tmp.entails(*post_it)) {
                can_entail = true;
                list<PropCNF>::iterator delete_it = pre_it;
                pre_it++;
                pos_propCNFs.erase(delete_it);
            }
        }
        if (!can_entail)
            pre_it++;
    }
    
    return *this;
}

EpisClause& EpisClause::minimal()
{
    separable();
    
    neg_propCNF.minimal();
    for (list<PropCNF>::iterator it = pos_propCNFs.begin(); it != pos_propCNFs.end(); it++) 
        it->minimal();
}

EpisCNF:: EpisCNF()
{
    for (list<EpisClause>::iterator it = epis_clauses.begin(); it != epis_clauses.end(); it++)
        it->minimal();
}

/*void EpisCNF::show(){
    cout<<"EpisCNF begin"<<endl;
    for(list<EpisClause>::iterator it = epis_clauses.begin(); it != epis_clauses.end(); it++)
        it->show();
    cout<<"EpisCNF end"<<endl;
}

void PropDNF::show() const{
    cout<<"    show_PropDNF:"<<endl;
    for(list<PropTerm>::const_iterator it = prop_terms.begin(); it != prop_terms.end(); it++){
        cout<<"      "<<it->literals<<endl;
    }
    cout<<"    end_show_PropDNF:"<<endl;
}*/

//#endif