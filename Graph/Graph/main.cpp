//
//  main.cpp
//  Graph
//
//  Created by kalai on 2021/3/6.
//

#include <iostream>
#include <fstream>

#include "graph.hpp"
#include "DFSPaths.hpp"
#include "BFSPaths.hpp"
#include "CC.hpp"

#include "digraph.hpp"
#include "DirectedDFS.hpp"
#include "DirectedCycle.hpp"
#include "DepthFirstOrder.hpp"
#include "topological.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
//    std::ifstream is("testfile/tinyCG.txt");
//    cout << "读文件testfile/tinyCG.txt " << is.is_open() << endl;
//    Graph *graph = new Graph(is);
//
//    int s = 0; int v = 5;
//
//    // 深度优先搜索路径
//    DFSPaths *dfsp = new DFSPaths(graph, s);
//    cout << "是否存在0到5的路径 " << dfsp->hasPathTo(v) << endl;
//
//    deque<int> path = dfsp->pathTo(v);
//    cout << s << " to " << v << ": ";
//    for(auto i : path)
//    {
//        i == s ? cout << i  : cout << "-" << i;
//    }
//    cout << endl;
//
//    // 广度优先搜索路径
//    BFSPaths *bfsp = new BFSPaths(graph, s);
//    cout << "是否存在0到5的路径 " << bfsp->hasPathTo(v) << endl;
//    deque<int> path2 = bfsp->pathTo(v);
//
//    cout << s << " to " << v << ": ";
//    for(auto i : path2)
//    {
//        i == s ? cout << i  : cout << "-" << i;
//    }
//    cout << endl;
//
//    // 深度优先遍历，解决联通分量问题
//    std::ifstream ccIs("testfile/tinyG.txt");
//    cout << "读文件testfile/tinyG.txt " << ccIs.is_open() << endl;
//    Graph *ccGraph = new Graph(ccIs);
//    CC *cc = new CC(ccGraph);
//    cout << "联通分量数量 " << cc->count() << endl;
//    cout << "0和6是否联通 " << cc->connected(0, 6) << endl;
//    cout << "0和9是否联通 " << cc->connected(0, 9) << endl;
//    cout << "0所在的联通分量 " << cc->id(0) << endl;
//    cout << "7所在的联通分量 " << cc->id(7) << endl;
//    cout << "9所在的联通分量 " << cc->id(9) << endl;
//
//    cout << "查看所有联通分量：" << endl;
//    vector<vector<int>> vec;
//    vec.resize(cc->count());
//    for(int v = 0; v < ccGraph->V(); v++)
//    {
//        vec[cc->id(v)].push_back(v);
//    }
//
//    for(int i = 0; i < cc->count(); i++)
//    {
//        for(auto k : vec[i])
//            cout << k << " ";
//        cout << endl;
//    }
//
    
    // 有向图
    std::ifstream is("testfile/tinyDG.txt");
    cout << "读文件testfile/tinyDG.txt " << is.is_open() << endl;
    Digraph *digraph = new Digraph(is);

    int s = 0;
    DirectedDFS *reachable = new DirectedDFS(digraph, s);
    cout << "有向图G中s是可以到达4的吗" << reachable->marked(4) << endl;
    
    cout << "有向图G中s可以到达的所有顶点: "<< endl;
    for (int v = 0; v < digraph->V(); v++)
        if(reachable->marked(v))
            cout << v << " ";
    cout << endl;
    
    DirectedCycle *cycleG = new DirectedCycle(digraph);
    cout << "有向图G中是否有环: " << cycleG->hasCycle() << endl;
    
    cout << "有向图G中环为: ";
    for(auto v : cycleG->cycle())
        cout <<  v << " ";
    cout << endl;
    
    // 有向图排序
    std::ifstream is2("testfile/tinyDAG.txt");
    cout << "读文件testfile/tinyDG.txt " << is2.is_open() << endl;
    Digraph *digraph2 = new Digraph(is2);

    DepthFirstOrder *depthFirstOrder = new DepthFirstOrder(digraph2);
    cout << "有向图G顶点排序 前序：";
    for(auto v : depthFirstOrder->pre())
        cout <<  v << " ";
    cout << endl;

    cout << "有向图G顶点排序 后序：";
    for(auto v : depthFirstOrder->post())
        cout <<  v << " ";
    cout << endl;

    cout << "有向图G顶点排序 逆后序: ";
    for(auto v : depthFirstOrder->reversePost())
        cout <<  v << " ";
    cout << endl;

    cout << "有向图G顶点排序 拓扑排序: ";
    Topological *topo = new Topological(digraph2);
    for(auto v : topo->order())
           cout <<  v << " ";
       cout << endl;

    return 0;
}
