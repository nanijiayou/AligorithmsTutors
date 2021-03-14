//
//  DepthFirstOrder.hpp
//  Graph
//
//  Created by kalai on 2021/3/7.
//
//  顶点的深度优先次序
//

#ifndef DepthFirstOrder_hpp
#define DepthFirstOrder_hpp

#include <stdio.h>
#include "digraph.hpp"

class DepthFirstOrder {
public:
    DepthFirstOrder() {};
    DepthFirstOrder(Digraph *G);                            // 构造函数
    
    bool marked(int v) { return _marked[v];};
    
    deque<int> pre() { return _pre;};                       // 返回前序排列结果
    deque<int> post() { return _post;};                     // 返回后序排序结果
    deque<int> reversePost() { return _reversePost;};       // 返回逆后序排序结果

private:
    deque<int> _pre;                                        // 前序：递归调用之前将顶点加入队列
    deque<int> _post;                                       // 后序：递归调用之后将顶点加入队列
    deque<int> _reversePost;                                // 逆后序：在递归调用之后将顶点压入栈
    deque<bool> _marked;                                    // 是否已经被访问
    
    void dfs(Digraph *G, int v);                            // 递归调用
};

#endif /* DepthFirstOrder_hpp */
