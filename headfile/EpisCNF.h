/* 
 * File:   EpisCNF.h
 * Author: ideapad
 *
 * Created on December 11, 2014, 7:01 PM
 */

#ifndef EPISCNF_H
#define	EPISCNF_H
#include <boost/dynamic_bitset.hpp>
#include <list>
#include<iostream>
//#include "EpisDNF.h"
using namespace std;
//using namespace std; 


class PropTerm {
public:
    PropTerm(int l){literals.resize(l);};
    PropTerm(){};
    
    //PropTerm(const PropTerm &);
    ~PropTerm(){};
    boost::dynamic_bitset<> literals;
    inline bool consistent() const;
    inline bool entails(const PropTerm &) const;
    inline bool equals(const PropTerm &) const; 
    inline PropTerm& min();
    PropTerm compose(const PropTerm &);
};


class PropDNF {
public:
    list<PropTerm> prop_terms;
    inline bool consistent() const;
    inline bool entails(const PropDNF &) const;
    inline bool equals(const PropDNF &) const;
    PropDNF& min();
    PropDNF compose(const PropDNF &);
    void show() const;
};


class PropClause
{
public:
    PropTerm negation();
    PropClause(int i){literals.resize(i);}
    PropClause(){};
    ~PropClause(){};
    boost::dynamic_bitset<> literals;
};
  

class PropCNF
{
public:
    PropDNF negation();
    list<PropClause> prop_clauses;
    void show();
};


class EpisClause
{
public:
    //EpisTerm negation();
    list<PropCNF> pos_propCNFs;
    list<PropCNF> neg_propCNFs;
    void show();
};


class EpisCNF {
public:
    list<EpisClause> epis_clauses;
    void show();
};

#endif	/* EPISCNF_H */

