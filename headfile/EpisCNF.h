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
//#include "EpisDNF.h"


using namespace std;

struct OnticAction;
struct EpisAction;

class PropTerm {
public:
    PropTerm(int l){literals.resize(l);};
    PropTerm(){};
    
    //PropTerm(const PropTerm &);
    ~PropTerm(){};
    inline bool consistent() const; //判断该命题项是否一致
    inline bool entails(const PropTerm &) const; //判断该命题项能够推出另外一个命题项
    inline bool equals(const PropTerm &) const;  //判断两个命题项是否等价
    PropTerm& min(); //化简命题项，在这里其实就是若该命题项中同时出现一个原子的正负文字两个方面，那么该命题项就是False
    boost::dynamic_bitset<> literals;  //一个原子对应两位，那两位分别表示该原子构成的正文字和负文字

    // new added
    PropTerm ontic_prog(const OnticAction &ontic_action); //在当前PropTerm上做物理动作的演进，并且返回演进结果
    vector<PropTerm> epistemic_prog(const EpisAction &epis_action); //在当前PropTerm上做观察动作的演进，并且返回结果
    
    PropTerm compose(const PropTerm &);  // new version delete this
};


class PropDNF {
public:
    inline bool consistent() const; //判断该命题DNF是否一致
    inline bool entails(const PropDNF &) const; //判断该命题DNF是否可以推出另外一个命题DNF
    inline bool equals(const PropDNF &) const; //判断两个命题DNF是否等价
    PropDNF& min(); //化简命题DNF，即若PropTerm1能够推出PropTerm2， 则从prop_terms中把PropTerm1删除
    PropDNF compose(const PropDNF &); //将两个命题DNF合并成一个命题DNF
    void show() const;
    list<PropTerm> prop_terms; //存储了多个命题项，这就构成了命题层面的DNF

    // new added
    PropDNF ontic_prog(const OnticAction &ontic_action); //在当前PropDNF上做物理动作的演进，并且返回演进结果
    vector<PropDNF> epistemic_prog(const EpisAction &epis_action); //在当前PropDNF上做观察动作的演进，并且返回结果
    PropDNF convect_IPIA(); //将DNF转为质蕴含形式
};

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

