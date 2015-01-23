/* 
 * File:   EpisCNF.h
 * Author: ideapad
 *
 * Created on December 11, 2014, 7:01 PM
 */

#ifndef EPISCNF_H
#define	EPISCNF_H
#include <boost/dynamic_bitset.hpp>
#include <list>
#include <iostream>
#include "EpisDNF.h"

using namespace std;

struct OnticAction;
struct EpisAction;
class PropTerm;
class PropDNF;

//以下4个数据结构完全和PropTerm、PropDNF、EpisTerm、EpisDNF对应
class PropClause
{
public:
    PropTerm negation(); //求出该命题子句的否定，结果就变成了一个命题项
    inline bool consistent() const;
    inline bool entails(const PropClause &) const;
    PropClause& min(); //对于PropClause的化简，就是如果出现一个原子的正负文字，则为True
    PropClause(int i){literals.resize(i);}
    PropClause(){};
    ~PropClause(){};
    boost::dynamic_bitset<> literals;
};
  

class PropCNF
{
public:
    PropDNF negation();
    list<PropClause> prop_clauses;
    void show();
};

//认知子句的形式为：一个K^和若干个K的析取，需要注意若干个K^的析取可以合成变为一个K^
class EpisClause
{
public:
    EpisClause group_nel(const EpisClause&); //将两个认知子句合并成一个认知子句，即只用将两个认知项的K^部分析取起来
    list<PropCNF> pos_propCNFs; //认知子句的K部分，有若干个，当然可以一个都没有
    list<PropCNF> neg_propCNFs; //认知子句的K^部分，注意只有一个
    void show();
    
    // new added
//    EpisTerm negation(); //将该认知子句取反得到EpisTerm
};

//认知子句的合取，其实就是所有动作(包括物理动作和观察动作)的前置条件
class EpisCNF {
public:
    list<EpisClause> epis_clauses;
    void show();
};

#endif	/* EPISCNF_H */

