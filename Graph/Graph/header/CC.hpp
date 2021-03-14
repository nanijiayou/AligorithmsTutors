//
//  CC.hpp
//  Graph
//
//  Created by kalai on 2021/3/7.
//
//  深度优先搜索解决联通分量问题
//

#ifndef CC_hpp
#define CC_hpp

#include <stdio.h>
#include "graph.hpp"

class CC {
public:
    CC() {};
    CC(Graph *graph);
    
    bool connected(int v, int w);                   // v和w是否联通
    int count() { return _count;};                  // 联通分量数
    int id(int v) { return _id[v];};                // 结点v所在的联通分量
    bool marked(int v) {return _marked[v];};        // 是否被标记

private:
    deque<bool> _marked;                            // 记录是否被标记
    
    int _count = 0;
    deque<int> _id;                                 // 联通分量id集合
    
    void dfs(Graph *graph, int v);                  // 深度优先搜索
};

#endif /* CC_hpp */
