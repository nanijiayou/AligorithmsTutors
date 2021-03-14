//
//  BFSPaths.hpp
//  Graph
//
//  Created by kalai on 2021/3/6.
//
//  使用广度优先搜索查找图中的路径
//

#ifndef BFSPaths_hpp
#define BFSPaths_hpp

#include <stdio.h>
#include <queue>
#include "graph.hpp"

class BFSPaths {
public:
    BFSPaths() {};
    BFSPaths(Graph *graph, int s);                  // 在graph中找出所有起点为s的路径
    
    bool hasPathTo(int v);                          // 是否存在s到v的路径
    bool marked(int v) { return _marked[v];};       // 是否被标记
    deque<int> pathTo(int v);                       // s到v的路径
        
private:
    deque<int> _marked;                             // 记录标记
    deque<int> _edgeTo;                             // 记录路径
    
    int _s;                                         // 起点
    void bfs(Graph *graph, int v);                  // 广度优先遍历
};

#endif /* BFSPaths_hpp */
