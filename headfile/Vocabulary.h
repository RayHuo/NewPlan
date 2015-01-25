#ifndef VOCABULARY_H
#define VOCABULARY_H

#include "structs.h"
#include <cstdio>
#include <vector>
#include <map>

using namespace std;
/*
 * 字符表类，保存各种信息
 */
class Vocabulary {
private:
    unsigned int atom_id;
    vector<char*> atom_list;
private:
    Vocabulary();
    ~Vocabulary();
    
public:
    static Vocabulary& instance();
    void dumpVocabulary(FILE* _out);
    void showVocabulary();
    int addAtom(char*);
    int apSize();
    char* getAtom(int id);
    int queryAtom(char*);
    void getmap(map<int,string> &m1, map<string,int> &m2, int &l,map<string,vector<int> > &ground, map<int,int> &id);
};

#endif
