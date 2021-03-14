//
//  DirectedCycle.hpp
//  Graph
//
//  Created by kalai on 2021/3/7.
//
//  在有向图G中寻找有向环
//

#ifndef DirectedCycle_hpp
#define DirectedCycle_hpp

#include <stdio.h>
#include "digraph.hpp"

class DirectedCycle
{
public:
    DirectedCycle() {};
    DirectedCycle(Digraph *G);                          // 寻找有向环构造函数
    
    bool marked(int v) { return _marked[v];};           // 是否已访问
    bool onStack(int v) { return _onStack[v];};         // v是否在调用栈上
    bool hasCycle() { return !_cycle.empty();};         // G是否包含有向环
    deque<int> cycle() { return _cycle;};               // 有向环中的所有顶点

private:
    deque<bool> _marked;                                // 是否被访问过
    deque<int> _edgeTo;                                 //
    deque<int> _cycle;                                  // 有向环中的所有顶点
    deque<bool> _onStack;                               // 递归调用的栈上的所有顶点
    void dfs(Digraph *G, int v);
};

#endif /* DirectedCycle_hpp */
