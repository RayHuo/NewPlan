
#include "Vocabulary.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <assert.h>

Vocabulary& Vocabulary::instance() {
    static Vocabulary vocabulary;
    return vocabulary;
}

Vocabulary::Vocabulary() : atom_id(1) {
    atom_list.clear();
}

Vocabulary::~Vocabulary() {
    atom_list.clear();
}

int Vocabulary::addAtom(char* atom) {
    atom_list.push_back(atom);
    return atom_id++;
}

int Vocabulary::queryAtom(char* atom) {
    for(int i = 0; i < atom_list.size(); i++) {
        if(strcmp(atom, atom_list.at(i)) == 0) {
            return i + 1;
        }
    }
    
    return -1;
}

void Vocabulary::dumpVocabulary(FILE* _out) {
    for(int i = 0; i < atom_list.size(); i++) {
        fprintf(_out, "%s\n", atom_list.at(i));
    }
}
void Vocabulary::showVocabulary(){
    for(int i = 0; i < atom_list.size(); i++) {
        printf( "%s\n", atom_list.at(i));
    }
}
char* Vocabulary::getAtom(int id) {
    return atom_list.at(id - 1);
}

int Vocabulary::apSize() {
    return atom_list.size();
}

void Vocabulary::getmap(map<int,string> &m1, map<string,int> &m2, int &l,map<string,vector<int> > &ground, map<int,int> &id){
    int count = 0;
    for(map<string,vector<int> >::iterator it = ground.begin(); it != ground.end(); it++){
        for(int i = 0; i < it->second.size(); i++){
            id[count++] = it->second[i];
        }
    }
    //cout<<"count: "<<count<<endl;
    //printf( "%d\n",count);
    l = count*2;
    for(int i = 0; i < l; i+=2){
        m1[i] = atom_list[id[i/2]-1];
        m1[i+1] = "-"+m1[i];
        m2[m1[i]] =  i;
        m2[m1[i+1]] = i+1;
    }
    //printf( "%d\n",m1.size());
}
