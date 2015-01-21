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

using namespace std; 

struct OnticAction;
struct EpisAction;

//认知项的形式为：一个K和若干个K^的合取，需要注意若干个K的合取可以合成变为一个K
class EpisTerm {
public:
    //EpisClause negEpisTerm();
    PropDNF pos_propDNF;    //认知项的K部分，注意只有一个
    list<PropDNF> neg_propDNFs; //认知项的K^部分，注意有若干个，当然也可以为空
    inline bool consistent() const; //判断该认知项是否一致
    inline bool entails(const EpisTerm &) const;    //判断该认知项能否够推出另外一个认知项
    inline bool equals(const EpisTerm &) const; //判断两个认知项是否等价
    inline EpisTerm& min(); //化简认知项，即若K^1 |= K^2, 则删除K^2
 
    EpisTerm group_pel(const EpisTerm &);   //将两个认知项合并成一个认知项，即只用将两个认知项的K部分合取起来
    void show();
    bool isempty();

    // new added
    EpisTerm ontic_prog(const OnticAction &ontic_action); //在当前EpisTerm上做物理动作的演进，并且返回演进结果
    vector<EpisTerm> epistemic_prog(const EpisAction &epis_action); //在当前EpisTerm上做观察动作的演进，并且返回结果

    PropDNF group_pel(const list<PropDNF> &);    // new version delete this
};

//其实就是认知项的析取，这个数据结构是用来存储知识库的
class EpisDNF {
public:
    //EpisCNF negEpisDNF();
    list<EpisTerm> epis_terms;  //存储若干个认知项
    bool consistent() const; //判断认知项的析取是否一致 
    bool entails(const EpisDNF &) const; //判断一个知识库能够推出另一个知识库
    bool equals(const EpisDNF &) const; //判断两个知识库是否等价
    bool entails(EpisClause); //EpisDNF |= EpisClause是EpisDNF |= EpisCNF的辅助函数
    bool entails(EpisCNF); //判断该知识库能够推出某个动作的前置条件
    EpisDNF& min(); //对EpisDNF的化简，剔除冗余知识
    void show();

    // new added
    EpisDNF ontic_prog(const OnticAction &ontic_action); //在当前知识库上做物理动作的演进，并且返回演进结果
    vector<EpisDNF> epistemic_prog(const EpisAction &epis_action); //在当前知识库上做观察动作的演进，并且返回结果
};



EpisTerm negation_Clause(EpisClause);
#endif	/* EPISDNF_H */

