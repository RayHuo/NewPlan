#include <boost/dynamic_bitset.hpp>
#include <list>
#include <iostream>
#include<fstream>
#include "atoms.h"
#include "EpisCNF.h"

bool PropClause::entails(const PropClause& prop_clause) const {
    return true;
}

PropTerm PropClause::negation() const
{
    PropTerm result(Atoms::instance().atoms_length() * 2);
    for (size_t i = 0; i < literals.size(); i++) {
        if(literals[i]) {
            result.literals[i] = 0; //?dynamic_bitset constructor makes all of bis in literals 0, so this clause is useless 
            if (i % 2 == 0) 
                result.literals[i + 1] = 1;
            else                    //this else is useless!!!
                result.literals[i - 1] = 1;
        }
    }
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

PropClause PropClause::group(const PropClause& prop_clause) const
{
    PropClause result(Atoms::instance().atoms_length() * 2);
    for (int i = 0; i < Atoms::instance().atoms_length() * 2; i++) {
        if (literals[i] || prop_clause.literals[i])
            result.literals[i] = 1;
    }
    return result;
}

PropCNF PropCNF::group(const PropCNF& propCNF) const
{
    PropCNF result;
    for (list<PropClause>::const_iterator it_i = prop_clauses.begin(); it_i != prop_clauses.end(); it_i++) {
        for (list<PropClause>::const_iterator it_j = propCNF.prop_clauses.begin(); it_j != propCNF.prop_clauses.end(); it_j++) {
            result.prop_clauses.push_back(it_i->group(*it_j));
        }
    }
    return result;
}

void PropClause::show(FILE *out, bool print_new_line) const
{
    vector<int> id_atoms;
    // 提取原子
    for (size_t i = 0; i < literals.size(); ++ i)
        if (literals[i])
            id_atoms.push_back(i);
    if (id_atoms.empty())
        return ;
    // 注意奇数为非
    fprintf(out, "(%s%s", (id_atoms[0] % 2 ? "~" : ""),
            Atoms::instance().get_atom_string(id_atoms[0] / 2 + 1).c_str());
    for (size_t i = 1; i < id_atoms.size(); ++ i)
        fprintf(out, " | %s%s", (id_atoms[i] % 2 ? "~" : ""),
                Atoms::instance().get_atom_string(id_atoms[i] / 2 + 1).c_str());
    fprintf(out, ")");
    if (print_new_line)
        fprintf(out, "\n");
}

void PropCNF::show(FILE *out, bool print_new_line) const
{    
    if (prop_clauses.empty())
        return ;
    fprintf(out, "( ");
    prop_clauses.begin()->show(out, false);
    for (list<PropClause>::const_iterator it = (++ prop_clauses.begin());
            it != prop_clauses.end(); ++ it) {
        fprintf(out, " & ");
        it->show(out, false);
    }
    fprintf(out, " )");
    if (print_new_line)
        fprintf(out, "\n");
}

void EpisClause::show(FILE *out) const
{
    for (list<PropCNF>::const_iterator it = pos_propCNFs.begin();
            it != pos_propCNFs.end(); ++ it) {
        fprintf(out, "K");
        it->show(out);
    }
    for (list<PropCNF>::const_iterator it = neg_propCNFs.begin();
            it != neg_propCNFs.end(); ++ it) {
        fprintf(out, "*~K~");
        it->show(out);
    }
    if (! neg_propCNF.prop_clauses.empty()) {
        fprintf(out, "~K~");
        neg_propCNF.show(out);
    }
}

PropDNF PropCNF::negation() const
{
    PropDNF result;
    for (list<PropClause>::const_iterator it = prop_clauses.begin(); it != prop_clauses.end(); it++) {
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

void EpisClause::min(){
    if(neg_propCNFs.size()>1){
        PropCNF p = *neg_propCNFs.begin();
        list<PropCNF>::iterator it = neg_propCNFs.begin();
        it++;
        while(it!=neg_propCNFs.end()){
            p = p.group(*it);
        }
        neg_propCNFs.clear();
        neg_propCNFs.push_back(p);
    }
}

EpisClause& EpisClause::separable()
{
    for (list<PropCNF>::iterator it = pos_propCNFs.begin(); it != pos_propCNFs.end(); it++) {
        if (!neg_propCNF.entails(*it))
            *it = it->group(neg_propCNF);
    }
    return *this;
}

EpisClause& EpisClause::minimal()
{
    separable();
    
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
    
    neg_propCNF.minimal();
    for (list<PropCNF>::iterator it = pos_propCNFs.begin(); it != pos_propCNFs.end(); it++) 
        it->minimal();
    
    return *this;
}

EpisCNF::EpisCNF()
{
    for (list<EpisClause>::iterator it = epis_clauses.begin(); it != epis_clauses.end(); it++)
        it->minimal();
}

void EpisCNF::show(FILE *out) const
{
    int i = 0;
    for(list<EpisClause>::const_iterator it = epis_clauses.begin(); it != epis_clauses.end(); it++) {
        fprintf(out, "epis cnf %d:\n", i ++);
        it->show(out);
        fprintf(out, "\n");
    }
}

