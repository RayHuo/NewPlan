/* 
 * File:   formulatab.h
 * Author: xhd
 *
 * Created on November 11, 2014, 3:59 PM
 */
//用来实现初始状态转epis_DNF用
//存k和非K开头的公式，统一类型K_atom

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

