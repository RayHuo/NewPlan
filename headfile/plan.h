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
    int show_build_result(int, const vector<Transition> &, int , set<int>, int );
    void show_statistic() const;
private:
    Init in;
    vector<Node> all_nodes;
    int explored_num;
    vector<Transition> all_edges;
    int hert_nodes;
    int searchtype;
    // 统计信息，搜索的节点数就是all_nodes.size()
    int plan_tree_depth;//树的深度
    int plan_tree_node_num;//树的节点数
    float preprocess_time;//预处理时间
    float search_time;//搜索时间
};
#endif
