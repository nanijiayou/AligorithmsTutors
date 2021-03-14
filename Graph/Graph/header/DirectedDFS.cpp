//
//  DirectedDFS.cpp
//  Graph
//
//  Created by kalai on 2021/3/7.
//

#include "DirectedDFS.hpp"

DirectedDFS::DirectedDFS(Digraph *G, int s)
{
    _marked.resize(G->V());
    dfs(G, s);
}

DirectedDFS::DirectedDFS(Digraph *G,  deque<int> sources)
{
    for(auto s : sources)
        if(!marked(s)) dfs(G, s);
}

void DirectedDFS::dfs(Digraph *G, int v)
{
    _marked[v] = true;
    for(auto w : G->adj(v))
        if(!marked(w)) dfs(G, w);
}
