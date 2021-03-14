//
//  topological.cpp
//  Graph
//
//  Created by kalai on 2021/3/7.
//

#include "topological.hpp"

Topological::Topological(Digraph *G)
{
    DirectedCycle *cycleFinder = new DirectedCycle(G);
    if(!cycleFinder->hasCycle())
    {
        DepthFirstOrder *dfo = new DepthFirstOrder(G);
        _order = dfo->reversePost();
        delete(dfo);
        dfo = nullptr;
    }
    delete(cycleFinder);
    cycleFinder =  nullptr;
};
