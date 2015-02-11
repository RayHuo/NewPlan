#include "formulatab.h"
Formulatab& Formulatab::instance() {
    static Formulatab vocabulary;
    return vocabulary;
}

Formulatab::Formulatab() {
    formula_list.clear();
}

Formulatab::~Formulatab() {
    formula_list.clear();
}

int Formulatab::addAtom(_formula* f){
    formula_list.push_back(f);
    return formula_list.size();
}
_formula* Formulatab::getAtom(int id){
    return formula_list[id-1];
}

vector<_formula*> Formulatab::get_formula_list() const {
    return formula_list;
}
