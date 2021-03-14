//
//  digraph.hpp
//  Graph
//
//  Created by kalai on 2021/3/7.
//

#ifndef digraph_hpp
#define digraph_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>

using std::istream;
using std::vector;
using std::deque;

class Digraph {
    
public:
    Digraph() {};
    Digraph(int V);                                     // 创建v个结点的有向图
    Digraph(istream &in);                               // 初始化个条边
    ~Digraph();
   
    int V() { return _V; };                             // 点数
    int E() { return _E; };                             // 边数
    void addEdge(int v, int w);                         // 添加一条v->w的边
    deque<int> adj(int v) { return _adj[v];};           // 由v指出的边所链接的所有顶点
    Digraph* reverse();                                 // 反向图
    
private:
    int readInt(istream &in);                           // 读取有向图边数据
    int _V;                                             // 结点数
    int _E = 0;                                         // 边数
    vector<deque<int>> _adj;                            // 邻接表存储图数据
};

#endif /* digraph_hpp */
