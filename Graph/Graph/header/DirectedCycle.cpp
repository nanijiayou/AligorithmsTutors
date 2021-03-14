//
//  DirectedCycle.cpp
//  Graph
//
//  Created by kalai on 2021/3/7.
//

#include "DirectedCycle.hpp"

DirectedCycle::DirectedCycle(Digraph *G)
{
    _marked.resize(G->V());
    _edgeTo.resize(G->V());
    _onStack.resize(G->V());
    
    for(int s = 0; s < G->V(); s++)
        if(!marked(s)) dfs(G, s);
}

void DirectedCycle::dfs(Digraph *G, int v)
{
    _marked[v] = true;
    _onStack[v] = true;
    for(auto w : G->adj(v))
    {
        if(hasCycle()) return;
        else if(!marked(w))
        {
            _edgeTo[w] = v;
            dfs(G, w);
        }
        else if(onStack(w))
        {
            for(int x = v; x != w; x = _edgeTo[x])
            {
                _cycle.push_front(x);
            }
            _cycle.push_front(w);
            _cycle.push_front(v);
        }
    }
    _onStack[v] = false;
}

