#include "atoms.h"
#include <stdlib.h>
Atoms::Atoms(){
    atoms_str.clear();
    length = 0;
}

Atoms::~Atoms(){
    atoms_str.clear();
}

Atoms& Atoms::instance(){
    static Atoms atom;
    return atom;
}




int Atoms::query_atoms(string s){
    for(int i = 0; i < atoms_str.size(); i++)
        if(s == atoms_str[i])
            return i+1;
    return -1;
}

int Atoms::add_atoms(string s){
    atoms_str.push_back(s);
    length++;
    return length;
    
}

string Atoms::get_atom_string(int i){
    return atoms_str[i-1];
}

int Atoms::atoms_length(){
    return length;
}

void Atoms::show(){
    for(int i = 0; i < length; i++)
        cout<<"i: "<<i+1<<" str: "<<atoms_str[i]<<endl;
    for(map<int,int>::iterator it = vac_to_atom.begin(); it != vac_to_atom.end(); it++){
        cout<<it->first<<it->second<<endl;
    }
}

void Atoms::gen_vac_to_atom(){
    for(int i = 0; i < length; i++){
      char *c;
      int len = atoms_str[i].length();
      c = (char *)malloc((len+1)*sizeof(char));
      atoms_str[i].copy(c,len,0);
      c[len]='\0';
      int cnum = Vocabulary::instance().queryAtom(c);
      vac_to_atom[cnum] = i+1;
    }
}


int Atoms::get_true_num(int id){
    return vac_to_atom[id];
}