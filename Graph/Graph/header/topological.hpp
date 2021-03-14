//
//  topological.hpp
//  Graph
//
//  Created by kalai on 2021/3/7.
//

#ifndef topological_hpp
#define topological_hpp

#include <stdio.h>
#include "DepthFirstOrder.hpp"
#include "DirectedCycle.hpp"

class Topological
{
public:
    Topological() {};
    Topological(Digraph *G);                        // 构造函数
    bool isDAG() { return _order.empty();};         // 是否是有向无环图
    deque<int> order() { return _order;};           // 返回排序结果

private:
    deque<int> _order;                              // 顶点拓扑排序结果
};

#endif /* topological_hpp */
