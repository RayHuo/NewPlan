/* 
 * File:   Progression.h
 * Author: ideapad
 *
 * Created on December 12, 2014, 3:44 PM
 */


#ifndef PROGRESSION_H
#define	PROGRESSION_H

#include <iostream>
#include <map>
#include <vector>
#include "structs.h"
#include "EpisDNF.h"

using namespace std;


enum STATE_TYPE {
    TOBEEXPLORED = 0,
    EXPLORED,
    DEAD,
    GOAL
};
struct ConEffect
{
    vector<int> condition;
    vector<int> add;
    vector<int> del;
};

struct OnticAction
{
    string name;
    int act_num;
    EpisCNF pre_con;
    pre pre_f;
    vector<ConEffect> con_eff;

    vector<string> para_match;
};

struct EpisAction
{
    string name;
    int act_num;
    EpisCNF pre_con;
    pre pre_f;
    vector<int> observe;
    vector<string> para_match;
	//vector<int> result;
};



struct Node
{
    int num;
    EpisDNF kb;
    STATE_TYPE flag;
    bool isolated;
    Node(){};
    Node(STATE_TYPE s, bool b, EpisDNF ed, int n){flag = s; isolated = b; kb = ed; num = n;};
    ~Node(){};
};

struct Transition
{
    /*int pre;
    int next;
    int act_num;
    bool is_ontic;
    bool pos;*/
    int front_bdd_state;
    int next_bdd_state;
    bool is_observe_action;
    bool is_true;
    //bool is_new_node;
    int action_number; 
};


#endif	/* PROGRESSION_H */

