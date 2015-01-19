/* 
 * File:   formulatab.h
 * Author: xhd
 *
 * Created on November 11, 2014, 3:59 PM
 */

#include "structs.h"
#include <vector>

#ifndef FORMULATAB_H
#define	FORMULATAB_H

class Formulatab {
private:
    vector<_formula*> formula_list;
private:
    Formulatab();
    ~Formulatab();
    
public:
    static Formulatab& instance();
    int addAtom(_formula*);
    _formula* getAtom(int id);
};




#endif	/* FORMULATAB_H */

