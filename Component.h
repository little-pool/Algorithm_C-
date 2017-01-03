//
// Created by pool_little on 30/12/2016.
//

#ifndef ALGORITHM_CPP_COMPONENT_H
#define ALGORITHM_CPP_COMPONENT_H

#include <iostream>
#include <cassert>
#include "Graph.h"
using namespace std;
template <typename Graph>
class Component{
private:
    Graph &g;
    bool* visited;
    int component_num;
public:
    Component(Graph &graph):g(graph){
        //初始化数据
        visited = new bool[g.GetNodeNum()];
        for(int i = 0 ; i < g.GetNodeNum() ; i ++){
            visited[i] = false;
        }
        component_num = 0;
        //深度优先遍历
        for(int i = 0 ; i < g.GetNodeNum() ; i ++){
            if(!visited[i]){
                DeepFirstSearch(i);
                component_num ++;
            }

        }
    }
    void DeepFirstSearch(int node_id){
        //先将该节点的标志位置为true
        visited[node_id] = true;
        //利用图的迭代器进行相连接点的遍历
        typename Graph::adjIterator adj(g, node_id);
        for(int i = adj.begin() ; !adj.end() ; i = adj.next()){
            if(!visited[i])
                DeepFirstSearch(i);
        }
    }
    int GetComponentNum(){
        return component_num;
    }
    ~Component(){
        delete[] visited;
     }
};
#endif //ALGORITHM_CPP_COMPONENT_H
