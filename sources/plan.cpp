/*
struct Node
{
    int num;
    EpisDNF kb;
    STATE_TYPE flag;
    bool isloated;
};
*/

#include"plan.h"
Plan::Plan(){
    all_nodes.clear();
    all_edges.clear();

    //all_nodes.push_back(in.init);
    explored_num = -1;
    searchtype = 0;
}

Plan::Plan(char **argv){
    cout<<"plan argv"<<endl;
    all_nodes.clear();
    all_edges.clear();
    
    explored_num = -1;
    searchtype = 0;
    in.exec();
//    in.showmaps(stdout);
    Node fnd;
    fnd.kb = in.init;
    all_nodes.push_back(fnd);
}

void Plan::exec_plan(){
    cout<<"\nexec plan"<<endl;
    if(in.init.entails(in.goal)){ 
        all_nodes[0].flag = GOAL;
        return;
    }
    cout<<"init!=end"<<endl;
    all_nodes[0].isolated = false;
    all_nodes[0].flag = TOBEEXPLORED;
    hert_nodes = 0; //for deep search
    while(true){
        cout<<"in rcy"<<endl;

        int node_pos = get_tobeexplored_node();//heuristic
        //hert_nodes.clear();
        //cout<<"1"<<endl;

        if(node_pos == -1)break;
        cout<<"node_pos: "<<node_pos<<endl;
        cout<<"num: "<<all_nodes[node_pos].num<<endl;
        explore(node_pos); 

        if(all_nodes[0].flag == DEAD)
            return;
        if(all_nodes[0].flag == GOAL)
            return;
    }  
}

void Plan::explore(int node_pos){
    cout<<"in explore"<<endl;
    bool execed = false;//deep search find new node
    for(int i = 0; i < epis_acitons.size(); i++){
        cout<<"in oba"<<endl;
        if(all_nodes[node_pos].kb.entails(epis_acitons[i].pre_con)){
            cout<<"go in oba"<<endl;
            vector<EpisDNF> res = all_nodes[node_pos].kb.epistemic_prog(epis_acitons[i]);
            if(check_zero_dead(res[0]) || check_zero_dead(res[1]))
                continue;
            int res_pos = checknode(res[0]);// find if old node; if it is old node, then return node number            
            if(res_pos == node_pos) continue;
            if(res_pos == -1){
                Node newNode(TOBEEXPLORED,false,res[0],all_nodes.size());
                all_nodes.push_back(newNode);
                res_pos = all_nodes.size()-1;
            }
            else{
                if(all_nodes[res_pos].flag == DEAD)
                    continue;
                if(all_nodes[res_pos].flag == EXPLORED && all_nodes[res_pos].isolated){
                    reconnection_propagation(res_pos);
                }
            }
            Transition tbs;
            tbs.front_bdd_state = node_pos;
            tbs.next_bdd_state = res_pos;
            tbs.is_observe_action = true;
            tbs.action_number = i;
            tbs.is_true = true;
            expand(tbs);
           
            
            int res_pos1 = checknode(res[1]);
            if(res_pos1 == node_pos) continue;
            if(res_pos1 == -1){
                Node newNode(TOBEEXPLORED,false,res[1],all_nodes.size());
                all_nodes.push_back(newNode);
                res_pos1 = all_nodes.size()-1;
            }
            else{
                if(all_nodes[res_pos1].flag == DEAD)
                    continue;
                if(all_nodes[res_pos1].flag == EXPLORED && all_nodes[res_pos1].isolated){
                    reconnection_propagation(res_pos);
                }
            }
            Transition tbs1;
            tbs1.front_bdd_state = node_pos;
            tbs1.next_bdd_state = res_pos1;
            tbs1.is_observe_action = true;
            tbs1.action_number = i;
            tbs1.is_true = false;
            expand(tbs1);
            

            if(all_nodes[res_pos1].flag == GOAL && all_nodes[res_pos].flag == GOAL){
                PropagateGoalNode(node_pos, true, i);
                return;
            }
            if(searchtype == 1 && !execed){
                hert_nodes = res_pos;
                execed = true;
            }
        }
        else
            cout<<"not sat"<<endl;
    }
    
    for(int i = 0; i < ontic_actions.size(); i++){
        cout<<"in effect"<<endl;
        if(all_nodes[node_pos].kb.entails(ontic_actions[i].pre_con)){
            EpisDNF res = all_nodes[node_pos].kb.ontic_prog(ontic_actions[i]);
            if(check_zero_dead(res)) continue;
            int res_pos = checknode(res);
            if(res_pos == node_pos) continue;
            if(res_pos == -1){
                Node newNode(TOBEEXPLORED,false,res,all_nodes.size());
                all_nodes.push_back(newNode);
                res_pos = all_nodes.size()-1;
            }
            else{
                if(all_nodes[res_pos].flag == DEAD)
                    continue;
                if(all_nodes[res_pos].flag == EXPLORED && all_nodes[res_pos].isolated)
                    reconnection_propagation(res_pos);
            }
            Transition tbs;
            tbs.front_bdd_state = node_pos;
            tbs.next_bdd_state = res_pos;
            tbs.is_observe_action = false;
            tbs.action_number = i;

            expand(tbs);
            
            if(all_nodes[res_pos].flag == GOAL){
                PropagateGoalNode(node_pos, false, i);
                return;
            }
            
            if(searchtype == 1 && !execed){
                hert_nodes = res_pos;
                execed = true;
            }    
        }
    }

    if(is_exist_edge_from_node(node_pos)){
        all_nodes[node_pos].flag = EXPLORED;
    }
    else{
        all_nodes[node_pos].flag = DEAD;
        PropagateDeadNode(node_pos);
    }
}

void Plan::expand(Transition ts){
    cout<<"in expand"<<endl;

    if(all_nodes[ts.next_bdd_state].flag != EXPLORED){
        if(all_nodes[ts.next_bdd_state].kb.entails(in.goal))
            all_nodes[ts.next_bdd_state].flag = GOAL;
        else
            all_nodes[ts.next_bdd_state].flag = TOBEEXPLORED;
    }
    all_edges.push_back(ts);
}

void Plan::PropagateDeadNode(int node_num){
    for(int i = 0; i < all_edges.size();){
        if(all_edges[i].next_bdd_state == node_num){
            int front = all_edges[i].front_bdd_state;
            if(!all_edges[i].is_observe_action)
                all_edges.erase(all_edges.begin()+i);
            else{
                for(int j = 0; j < all_edges.size(); j++){
                    if((all_edges[i].front_bdd_state == all_edges[j].front_bdd_state) && (all_edges[i].action_number == all_edges[j].action_number)){
                        if(j!=i){
                            isolation_propagation(all_edges[j].next_bdd_state);
                            if(i > j){
                                all_edges.erase(all_edges.begin()+i);
                                all_edges.erase(all_edges.begin()+j);
                                i--;
                            }
                            else{
                                all_edges.erase(all_edges.begin()+j);
                                all_edges.erase(all_edges.begin()+i);
                                i--;
                            }
                        }
                    }
                }
            }
            bool is_front_dead = true;
            for(int k = 0; k < all_edges.size(); k++){
                if(front == all_edges[k].front_bdd_state)
                    is_front_dead = false;
            }
            //may change num of all_edges
            if(is_front_dead)
                PropagateDeadNode(front);
        }
        else
            i++;
    }
}

void Plan::isolation_propagation(int node_num){
    if(!all_nodes[node_num].isolated){
        all_nodes[node_num].isolated = true;
        for(int i = 0; i < all_edges.size(); i++)
            if(all_edges[i].front_bdd_state == node_num)
                isolation_propagation(all_edges[i].next_bdd_state);
    }    
}

void Plan::reconnection_propagation(int node_num){
    if(all_nodes[node_num].isolated){
        all_nodes[node_num].isolated = false;
        for(int i = 0; i < all_edges.size(); i++)
            if(all_edges[i].front_bdd_state == node_num){
                reconnection_propagation(all_edges[i].next_bdd_state);
            }
    }    
}

int Plan::get_tobeexplored_node(){
    if(searchtype == 1 && all_nodes[hert_nodes].flag == TOBEEXPLORED && !all_nodes[hert_nodes].isolated)
        return hert_nodes;
    for(int i = explored_num + 1; i < all_nodes.size(); i++)
        if(all_nodes[i].flag == TOBEEXPLORED && !all_nodes[i].isolated)
            return i;
    return -1;    
}
    


void Plan::PropagateGoalNode(int start_node_num, bool is_observe_action, int act_num){
    all_nodes[start_node_num].flag = GOAL;
    for(int i = 0; i < all_edges.size();){
        if(all_edges[i].front_bdd_state == start_node_num){
            if(all_edges[i].action_number != act_num || is_observe_action != all_edges[i].is_observe_action){
                isolation_propagation(all_edges[i].next_bdd_state);
                all_edges.erase(all_edges.begin()+i);
            }
            else
                i++;
        }
        else
            i++;            
    }
    for(int i = 0; i < all_edges.size(); i++)
        if(all_edges[i].next_bdd_state == start_node_num){
            if(!all_edges[i].is_observe_action)
                PropagateGoalNode(all_edges[i].front_bdd_state, false, all_edges[i].action_number);
            else
                for(int j = i+1; j < all_edges.size(); j++)
                    if(all_edges[j].is_observe_action && all_edges[j].front_bdd_state == all_edges[i].front_bdd_state && all_edges[j].action_number == all_edges[i].action_number){
                        if(all_nodes[all_edges[j].next_bdd_state].flag == GOAL)
                            PropagateGoalNode(all_edges[i].front_bdd_state, true, all_edges[i].action_number);
                        break;
                    }
            
        } 
}

bool Plan::is_exist_edge_from_node(int n){
    for(int i = 0; i < all_edges.size(); i++){
        if(all_edges[i].front_bdd_state == n)
            return true;
    }
    return false;    
}


int Plan::checknode(EpisDNF ed){
    for(int i = 0; i < all_nodes.size(); i++)
        if( all_nodes[i].kb.equals(ed))
            return i;
    return -1;   
}

bool Plan::check_zero_dead(EpisDNF ed){
    return ed.epis_terms.size() == 0;
   
}

void Plan::BuildPlan(){
    if(all_nodes[0].flag != GOAL){
        cout<<"no plan"<<endl;
        return;
    }
    vector<Transition> goal_edges;
    for(int i = 0; i < all_edges.size(); i++)
        if(all_nodes[all_edges[i].front_bdd_state].flag == GOAL && all_nodes[all_edges[i].next_bdd_state].flag == GOAL)
            goal_edges.push_back(all_edges[i]);
    set<int> nodes;
    show_build_result(0, goal_edges, -1, nodes, -1);
    cout<<endl;    
}

void Plan::show_build_result(int node_num, vector<Transition> goal_edges, int tab_num, set<int> nodes, int oldnode){
    tab_num++;
    vector<Transition> next_trans;
    if(oldnode != -1)
        nodes.insert(oldnode);
    int num = goal_edges.size();
    for(int i = 0; i < num; i++)
        if(goal_edges[i].front_bdd_state == node_num)
            next_trans.push_back(goal_edges[i]);
    for(int i = 0; i < next_trans.size(); i++)
        if(nodes.find(next_trans[i].next_bdd_state) == nodes.end()){
            for (int k = 0; k < tab_num; k++) 
                cout << " ";
            if (next_trans[i].is_observe_action) {
                if (next_trans[i].is_true){                   
                    cout << epis_acitons[next_trans[i].action_number].name;
                    cout<<" +:";
                    if(epis_acitons[next_trans[i].action_number].para_match.size()!=0){
                        cout<<" (";
                        for(int j = 0; j < epis_acitons[next_trans[i].action_number].para_match.size()-1; j++)
                            cout<<epis_acitons[next_trans[i].action_number].para_match[j]<<",";
                        if(epis_acitons[next_trans[i].action_number].para_match.size() > 0)
                            cout<<epis_acitons[next_trans[i].action_number].para_match[epis_acitons[next_trans[i].action_number].para_match.size()-1];
                        cout<<")";
                    }
                    cout<<endl; 
                    
                    show_build_result(next_trans[i].next_bdd_state, goal_edges, tab_num, nodes, node_num);
                }
                else{
                    cout << epis_acitons[next_trans[i].action_number].name;
                    cout<<" -:";
                    if(epis_acitons[next_trans[i].action_number].para_match.size()!=0){
                        cout<<" (";
                        for(int j = 0; j < epis_acitons[next_trans[i].action_number].para_match.size()-1; j++)
                            cout<<epis_acitons[next_trans[i].action_number].para_match[j]<<",";
                        if(epis_acitons[next_trans[i].action_number].para_match.size() > 0)
                            cout<<epis_acitons[next_trans[i].action_number].para_match[epis_acitons[next_trans[i].action_number].para_match.size()-1];                        
                        cout<<")";
                    }
                    cout<<endl;
                        show_build_result(next_trans[i].next_bdd_state, goal_edges, tab_num, nodes, node_num);
                    
                }
            }
            else{
                cout << ontic_actions[next_trans[i].action_number].name;  
                if(ontic_actions[next_trans[i].action_number].para_match.size() != 0){
                    cout<<" (";
                    for(int j = 0; j < ontic_actions[next_trans[i].action_number].para_match.size()-1; j++)
                        cout<<ontic_actions[next_trans[i].action_number].para_match[j]<<",";
                    if(ontic_actions[next_trans[i].action_number].para_match.size() > 0)
                        cout<<ontic_actions[next_trans[i].action_number].para_match[ontic_actions[next_trans[i].action_number].para_match.size()-1];
                    cout<<")";  
                }
                cout<<endl;
                show_build_result(next_trans[i].next_bdd_state, goal_edges, tab_num, nodes, node_num);
            }
            
        }    
}

