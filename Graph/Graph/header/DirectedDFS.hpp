//
//  DirectedDFS.hpp
//  Graph
//
//  Created by kalai on 2021/3/7.
//
//  有向图可达性
//

#ifndef DirectedDFS_hpp
#define DirectedDFS_hpp
#include <stdio.h>
#include "digraph.hpp"

class DirectedDFS {
    
public:
    DirectedDFS() {};
    DirectedDFS(Digraph *G, int s);                         // 在G中找到从s可到达的所有顶点
    DirectedDFS(Digraph *G, deque<int> sources);            // 在G中找到从sources中的所有顶点可达到的所有顶点
    bool marked(int v) {return _marked[v];};                // v是可到达的吗

private:
    deque<bool> _marked;
    void dfs(Digraph *G, int v);                            // 深度优先递归
};

#endif /* DirectedDFS_hpp */
