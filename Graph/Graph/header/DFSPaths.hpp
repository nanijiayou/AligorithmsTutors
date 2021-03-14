//
//  DFSPaths.hpp
//  Graph
//
//  Created by kalai on 2021/3/6.
//
//  使用深度优先搜索查找图中的路径
//

#ifndef DFSPaths_hpp
#define DFSPaths_hpp

#include <stdio.h>
#include "graph.hpp"

class DFSPaths{
public:
    DFSPaths(){};
    DFSPaths(Graph *graph, int s);                      // 找出图中所有以s为起点的路径
    ~DFSPaths(){};
    
    bool marked(int v) { return _marked[v];};           // 是否被标记
    bool hasPathTo(int v);                              // 是否存在从s到v的路径
    deque<int> pathTo(int v);                           // s到v的路径
private:
    deque<bool> _marked;                                // 访问标记
    deque<int> _edgeTo;                                 // 经过的每一个顶点
    void dfs(Graph *graph, int v);                      // 递归搜索
    int _s;                                             // 起点
};

#endif /* DFSPaths_hpp */
