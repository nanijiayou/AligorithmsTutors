//
//  BFSPaths.cpp
//  Graph
//
//  Created by kalai on 2021/3/6.
//

#include "BFSPaths.hpp"

BFSPaths::BFSPaths(Graph *graph, int s):_s(s)
{
    _marked.resize(graph->V());
    _edgeTo.resize(graph->V());
    
    bfs(graph, s);
}

void BFSPaths::bfs(Graph *graph, int s)
{
    queue<int> queue;
    queue.push(s);
    _marked[s] = true;
    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();
        for(auto i : graph->adj(v))
        {
            if(!marked(i))
            {
                _marked[i] = true;
                _edgeTo[i] = v;
                queue.push(i);
            }
        }
    }
}

bool BFSPaths::hasPathTo(int v)
{
    return marked(v);
}

deque<int> BFSPaths::pathTo(int v)
{
    deque<int> path;
    if(!marked(v)) return path;
    for(int x = v; x != _s; x = _edgeTo[v])
        path.push_front(x);
    path.push_front(_s);
    return path;
}
