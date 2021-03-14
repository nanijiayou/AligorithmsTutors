//
//  graph.hpp
//  Graph
//
//  Created by kalai on 2021/3/6.
//


#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>

using namespace::std;

class Graph {
    
public:
    Graph(int V);                               // 创建一个包含V个结点但不含边的图
    Graph(istream &in);                         // 从标准输入流in中渡人一幅图
    ~Graph();
    
    int V() { return _V;};                      // 顶点数
    int E() { return _E;};                      // 边数
    void AddEdge(int v, int w);                 // 向图中添加一条边v-w
    deque<int> adj(int v) {return _adj[v];};    // 和v相邻的所有顶点
    
private:
    int readInt(istream &in);                   // 读入数据
    int _V;
    int _E = 0;
    vector<deque<int>> _adj;                    // 邻接表结构存储图
};
#endif /* graph_hpp */
