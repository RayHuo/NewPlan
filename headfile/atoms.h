#ifndef ATOMS_H
#define	ATOMS_H


#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "structs.h"
#include "Vocabulary.h"
using namespace std;

class Atoms{
private:
    Atoms();
    ~Atoms();
    vector<string> atoms_str;
    int length;
    map<int,int> vac_to_atom;
public:
    
    static Atoms& instance();
    int query_atoms(string);
    int add_atoms(string);
    string get_atom_string(int);
    int atoms_length();
    void show();
    void gen_vac_to_atom();
    int get_true_num(int);
};

#endif
