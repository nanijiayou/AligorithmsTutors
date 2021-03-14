//
//  DFSPaths.cpp
//  Graph
//
//  Created by kalai on 2021/3/6.
//

#include "DFSPaths.hpp"

DFSPaths::DFSPaths(Graph *graph, int s):_s(s)
{
    _marked.resize(graph->V());
    _edgeTo.resize(graph->V());
    dfs(graph, s);
}

void DFSPaths::dfs(Graph *graph, int v)
{
    _marked[v] = true;
    for(auto w : graph->adj(v))
    {
        if(!marked(w))
        {
            _edgeTo[w] = v;
            dfs(graph, w);
        }
    }
}

bool DFSPaths::hasPathTo(int v)
{
    return marked(v);
}

deque<int> DFSPaths::pathTo(int v)
{
    deque<int> path;
    if(!marked(v)) return path;
    for(int x = v; x != _s; x = _edgeTo[x])
        path.push_front(x);
    path.push_front(_s);
    return path;
}


