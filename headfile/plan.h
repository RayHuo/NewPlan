#ifndef PLAN_H
#define	PLAN_H

#include "init.h"
#include <set>

extern vector<OnticAction> ontic_actions;
extern vector<EpisAction> epis_actions;
extern EpisDNF ontic_prog(EpisDNF episDNF, const OnticAction &ontic_action);

extern vector<EpisDNF> epistemic_prog(EpisDNF episDNF, const EpisAction &epis_action);
class Plan{
public:
    Plan();
    Plan(const char *domain, const char *p, int type = 0);
    void exec_plan();
    
    void explore(int);
    void expand(Transition);
    void PropagateDeadNode(int);
    void isolation_propagation(int);
    void reconnection_propagation(int);
    int get_tobeexplored_node();

    void PropagateGoalNode(int, bool, int);
    bool is_exist_edge_from_node(int);
    bool sat_pre(Node, EpisCNF);
    int checknode(EpisDNF);
    bool check_zero_dead(EpisDNF);
    void BuildPlan();
    void show_build_result(int, vector<Transition> , int , set<int> , int );
private:
    Init in;
    vector<Node> all_nodes;
    int explored_num;
    vector<Transition> all_edges;
    int hert_nodes;
    int searchtype;
    
};
#endif
