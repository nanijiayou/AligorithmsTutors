//
//  DepthFirstOrder.cpp
//  Graph
//
//  Created by kalai on 2021/3/7.
//

#include "DepthFirstOrder.hpp"

DepthFirstOrder::DepthFirstOrder(Digraph *G)
{
    _marked.resize(G->V());
    for(int v = 0; v < G->V(); v++)
        if(!marked(v)) dfs(G, v);
};

void DepthFirstOrder::dfs(Digraph *G, int v)
{
    _pre.push_back(v);
    _marked[v] = true;
    for(auto w : G->adj(v))
        if(!marked(w)) dfs(G, w);
    _post.push_back(v);
    _reversePost.push_front(v);
}
