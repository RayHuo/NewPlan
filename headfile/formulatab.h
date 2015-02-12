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
    vector<_formula*> get_formula_list() const;
};




#endif	/* FORMULATAB_H */

