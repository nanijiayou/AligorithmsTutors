//
//  CC.cpp
//  Graph
//
//  Created by kalai on 2021/3/7.
//

#include "CC.hpp"

CC::CC(Graph *graph)
{
    _marked.resize(graph->V());
    _id.resize(graph->V());
    for(int s = 0; s < graph->V(); s++)
    {
        if(!marked(s))
        {
            dfs(graph, s);
            _count++;
        }
    }
}

bool CC::connected(int v, int w)
{
    return id(v) == id(w);
}

void CC::dfs(Graph *graph, int v)
{
    _marked[v] = true;
    _id[v] = _count;
    for(auto w : graph->adj(v))
        if(!marked(w))
            dfs(graph, w);
}
