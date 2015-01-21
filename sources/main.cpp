
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


using namespace std;
_formula* init_f;
_formula* goal_f;

vector<_formula*> actions_f; 
map< string,vector<int> > grounding_map;
vector<OnticAction> ontic_actions;
vector<EpisAction> epis_acitons;


int main(int argc, char **argv){
  
    Plan p(argv);
    p.exec_plan();
    p.BuildPlan();

    
    return 0;
} 

