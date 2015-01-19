/* 
 * File:   EpisDNF.h
 * Author: ideapad
 *
 * Created on December 11, 2014, 6:43 PM
 */

#ifndef EPISDNF_H
#define	EPISDNF_H

//#include <boost/dynamic_bitset.hpp>
//#include <list>
#include "EpisCNF.h"





class EpisTerm {
public:
    //EpisClause negEpisTerm();
    PropDNF pos_propDNF;
    list<PropDNF> neg_propDNFs;
    inline bool consistent() const;
    inline bool entails(const EpisTerm &) const;
    inline bool equals(const EpisTerm &) const;
    inline EpisTerm& min();
    PropDNF group_pel(const list<PropDNF> &);
    EpisTerm group_pel(const EpisTerm &); 
    void show();
    bool isempty();
};


class EpisDNF {
public:
    //EpisCNF negEpisDNF();
    list<EpisTerm> epis_terms;
    bool entails(const EpisDNF &) const;
    bool equals(const EpisDNF &) const;
    bool entails(EpisClause);
    bool entails(EpisCNF) ;
    EpisDNF& min();
    void show();
};



EpisTerm negation_Clause(EpisClause);
#endif	/* EPISDNF_H */

