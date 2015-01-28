#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
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
vector<EpisAction> epis_actions;

int main(int argc, char **argv) 
{
    if (argc != 3) {
        printf("Usage:\n%s domain_file p_file\n", argv[0]);
        return 0;
    }
    Plan p = Plan(argv[1], argv[2]);
    p.exec_plan(); 
    p.BuildPlan();
    return 0;
} 

