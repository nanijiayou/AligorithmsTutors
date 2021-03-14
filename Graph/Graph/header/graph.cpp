//
//  graph.cpp
//  Graph
//
//  Created by kalai on 2021/3/6.
//

#include "graph.hpp"

Graph::Graph(int V):_V(V)
{
    _E = 0;
    _adj.resize(V);
}

Graph::Graph(istream &in)
{
    _V = readInt(in);
    _adj.resize(_V);
    
    int E = readInt(in);
    for(int i = 0; i < E; i++)
    {
        int v = readInt(in);
        int w = readInt(in);
        AddEdge(v, w);
    }
}

int Graph::readInt(istream &in)
{
    int temp;
    in >> temp;
    return temp;
}

void Graph::AddEdge(int v, int w)
{
    _adj[v].push_front(w);
    _adj[w].push_front(v);
    _E++;
}

