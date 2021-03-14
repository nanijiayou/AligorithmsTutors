//
//  digraph.cpp
//  Graph
//
//  Created by kalai on 2021/3/7.
//

#include "digraph.hpp"

Digraph::Digraph(int V): _V(V)
{
    _adj.resize(_V);
}

Digraph::Digraph(istream &in)
{
    _V = readInt(in);
    _adj.resize(_V);
    int E = readInt(in);
    for(int i = 0; i < E; i++)
    {
        int v = readInt(in);
        int w = readInt(in);
        addEdge(v, w);
    }
}

Digraph* Digraph::reverse()
{
    Digraph *R = new Digraph(V());
    for (int v = 0; v < V(); v++) {
        for(auto w : adj(v))
            R->addEdge(w, v);
    }
    return R;
}

int Digraph::readInt(istream &in)
{
    int temp;
    in >> temp;
    return temp;
}

void Digraph::addEdge(int v, int w)
{
    _adj[v].push_front(w);
    _E++;
}

