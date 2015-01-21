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
#include "EpisDNF.h"

PropTerm PropClause::negation()
{
    PropTerm result(Atoms::instance().atoms_length()*2);
    //cout<<"oring: "<<endl;
    //cout<<this->literals<<endl;
    for (int i = 0; i < literals.size(); i++) {
        if(literals[i]){
	result.literals[i] = 0;
	if (i % 2 == 0) 
            result.literals[i + 1] = 1;
	else //this else is useless!!!
            result.literals[i - 1] = 1;
        }
    }
    //cout<<result.literals<<endl;
    return result;
}

void PropCNF::show()
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
    for(list<PropCNF>::iterator it = neg_propCNFs.begin(); it != neg_propCNFs.end(); it++)
        it->show();
    cout<<"  EpisClause neg end"<<endl;

}

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

void EpisCNF::show(){
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
}

//#endif