
//#include "S5Dnf.h"
#include <string>
#include <unistd.h>
#include <stdlib.h>
 #include<string.h>
#include "Vocabulary.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include "structs.h"
#include "Progression.h"

#include "parse.h"
#include <assert.h>
#include "formulatab.h"
#include "init.h"
#include "plan.h"
#include "EpisDNF.h"
#include "atoms.h"
#include "boost/dynamic_bitset.hpp"

using namespace std;
using namespace boost;
_formula* init_f;
_formula* goal_f;

vector<_formula*> actions_f; 
map< string,vector<int> > grounding_map;
vector<OnticAction> ontic_actions;
vector<EpisAction> epis_acitons;

#define TEST 

int main(int argc, char **argv) 
{
#ifdef TEST
    Atoms::instance().length = 4;
    PropTerm ab(8);
    ab.literals.set(0, true);
    ab.literals.set(2, true);
    PropTerm _bcd(8);
    _bcd.literals.set(3, true);
    _bcd.literals.set(4, true);
    _bcd.literals.set(6, true);
    PropTerm _a_c(8);
    _a_c.literals.set(1, true);
    _a_c.literals.set(5, true);
    PropDNF dnf;
    dnf.prop_terms.push_back(ab);
    dnf.prop_terms.push_back(_bcd);
    dnf.prop_terms.push_back(_a_c);
    cout << "origin:" << endl;
    for (list<PropTerm>::const_iterator it = dnf.prop_terms.begin();
            it != dnf.prop_terms.end(); ++ it) {
        cout << it->literals << endl;
    }
    dnf.convert_IPIA();
    cout << "ipia:" << endl;
    for (list<PropTerm>::const_iterator it = dnf.prop_terms.begin();
            it != dnf.prop_terms.end(); ++ it) {
        cout << it->literals << endl;
    }
#else
    Plan p(argv);
//    p.exec_plan();
//    p.BuildPlan();
   
#endif
    dynamic_bitset db("111111");
    cout << db << endl;
    return 0;
} 

