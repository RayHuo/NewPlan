/* 
 * File:   EpisDNF.h
 * Author: ideapad
 *
 * Created on December 11, 2014, 6:43 PM
 */

#ifndef EPISDNF_H
#define	EPISDNF_H

//#include <boost/dynamic_bitset.hpp>
//#include <list>
#include "EpisCNF.h"

class PropTerm {
public:
    PropTerm(int n){ literals.resize(n); }
    PropTerm(){};
    ~PropTerm(){};
    inline bool consistent() const; //判断该命题项是否一致
    inline bool entails(const PropTerm &) const; //判断该命题项能够推出另外一个命题项
    inline bool equals(const PropTerm &) const;  //判断两个命题项是否等价
    PropTerm& min(); //化简命题项，在这里其实就是若该命题项中同时出现一个原子的正负文字两个方面，那么该命题项就是False
	PropTerm ontic_prog(const OnticAction &ontic_action); //在当前PropTerm上做物理动作的演进，并且返回演进结果
	vector<PropTerm> epistemic_prog(const EpisAction &epis_action); //在当前PropTerm上做观察动作的演进，并且返回结果
	boost::dynamic_bitset<> literals;  //一个原子对应两位，那两位分别表示该原子构成的正文字和负文字
};


class PropDNF {
public:
    inline bool consistent() const; //判断该命题DNF是否一致
    inline bool entails(const PropDNF &) const; //判断该命题DNF是否可以推出另外一个命题DNF
    inline bool equals(const PropDNF &) const; //判断两个命题DNF是否等价
    PropDNF& min(); //化简命题DNF，即若PropTerm1能够推出PropTerm2， 则从prop_terms中把PropTerm1删除
    PropDNF compose(const PropDNF &); //将两个命题DNF合并成一个命题DNF
	PropDNF ontic_prog(const OnticAction &ontic_action); //在当前PropDNF上做物理动作的演进，并且返回演进结果
	vector<PropDNF> epistemic_prog(const EpisAction &epis_action); //在当前PropDNF上做观察动作的演进，并且返回结果
	PropDNF convect_IPIA(); //将DNF转为质蕴含形式
    void show() const;
	list<PropTerm> prop_terms; //存储了多个命题项，这就构成了命题层面的DNF
};


//认知项的形式为：一个K和若干个K^的合取，需要注意若干个K的合取可以合成变为一个K
class EpisTerm {
public:
    //EpisClause negEpisTerm();
    
    inline bool consistent() const; //判断该认知项是否一致
    inline bool entails(const EpisTerm &) const; //判断该认知项能否够推出另外一个认知项
    inline bool equals(const EpisTerm &) const; //判断两个认知项是否等价
    EpisTerm& min(); //化简认知项，即若K^1 |= K^2, 则删除K^2
    //PropDNF group_pel(const list<PropDNF> &);
    EpisTerm group_pel(const EpisTerm &); //将两个认知项合并成一个认知项，即只用将两个认知项的K部分合取起来
	
	EpisTerm ontic_prog(const OnticAction &ontic_action); //在当前EpisTerm上做物理动作的演进，并且返回演进结果
	vector<EpisTerm> epistemic_prog(const EpisAction &epis_action); //在当前EpisTerm上做观察动作的演进，并且返回结果
    void show();
    //bool isempty();
	PropDNF pos_propDNF; //认知项的K部分，注意只有一个
    list<PropDNF> neg_propDNFs; //认知项的K^部分，注意有若干个，当然也可以为空
};

//其实就是认知项的析取，这个数据结构是用来存储知识库的
class EpisDNF {
public:
    //EpisCNF negEpisDNF(); 
    bool consistent() const; //判断认知项的析取是否一致	
    bool entails(const EpisDNF &) const; //判断一个知识库能够推出另一个知识库
    bool equals(const EpisDNF &) const; //判断两个知识库是否等价
    bool entails(EpisClause); //EpisDNF |= EpisClause是EpisDNF |= EpisCNF的辅助函数
    bool entails(EpisCNF); //判断该知识库能够推出某个动作的前置条件
    EpisDNF& min(); //对EpisDNF的化简，剔除冗余知识
	EpisDNF ontic_prog(const OnticAction &ontic_action); //在当前知识库上做物理动作的演进，并且返回演进结果
	vector<EpisDNF> epistemic_prog(const EpisAction &epis_action); //在当前知识库上做观察动作的演进，并且返回结果
    void show();
	list<EpisTerm> epis_terms; //存储若干个认知项
};



EpisTerm negation_Clause(EpisClause);
#endif	/* EPISDNF_H */

