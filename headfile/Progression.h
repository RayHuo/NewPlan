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
#include "EpisCNF.h"

using namespace std;


enum STATE_TYPE {
    TOBEEXPLORED = 0,
    EXPLORED,
    DEAD,
    GOAL
};

//物理动作中的effect（效果三元组）
struct ConEffect
{
    vector<int> condition; //效果中的条件
    vector<int> add; //add集合存储的变量代表做完该动作之后，这些变量需要变为True
    vector<int> del; //del集合存储的变量代表做完该动作之后，这些变量需要变为False
    PropTerm con; //use it to replace vector<int> condition
};

//物理动作的描述
struct OnticAction
{
    string name; //动作的名称
    int act_num; //动作的编号
    EpisCNF pre_con; //动作执行的前置条件
    pre pre_f; //将前置条件转换为EpisCNF的承接存储
    vector<ConEffect> con_eff; //效果三元组

    vector<string> para_match;
};

//观察动作的描述
struct EpisAction
{
    string name; //动作的名称
    int act_num; //动作的编号
    EpisCNF pre_con; //动作执行的前置条件
    pre pre_f; //将前置条件转换为EpisCNF的承接存储
    vector<int> observe; //需要观察的“公式”
    vector<string> para_match;
    //vector<int> result; 

    // new added
    PropDNF pos_res; //将所需要观察的“公式”化为DNF形式， 为了好做演进 positive result
    PropDNF neg_res; //将所需要观察的“公式”化为DNF形式， 为了好做演进 negative result  
};



//搜索算法中的结点
struct Node
{
    int num; //搜索图中的结点编号
    EpisDNF kb; //结点的知识库
    //下面两个变量分别是在搜索过程中所需要的两中标记
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
    int front_bdd_state; //前一个结点
    int next_bdd_state;  //后一个结点
    bool is_observe_action; //是否为观察动作
    bool is_true; //?不明
    //bool is_new_node;
    int action_number;  //动作的编号
};


#endif	/* PROGRESSION_H */

