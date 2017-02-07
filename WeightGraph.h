//
// Created by pool_little on 07/02/2017.
//

#ifndef ALGORITHM_CPP_WEIGHTGRAPH_H
#define ALGORITHM_CPP_WEIGHTGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename Weight>
class Edge{
private:
    /**
     * 两节点；权重；
     */
    int x,y;
    int weight;

public:
    /**
     * 1.构造函数
     * 赋值两节点，权重
     */
    Edge(int x, int y, Weight weight){
        this->x = x;
        this->y = y;
        this->weight = weight;
    }

    /**
     * 2.析构函数
     */
    ~Edge(){
    }

    /**
     * 3.Gets函数
     * 提供两节点及权重的查询
     */
    int GetX(){return this->x;}
    int GetY(){return this->y;}

    /**
     * 4.getOther函数
     * 已知一个节点，求另一个节点
     */
    int GetOther(int i){
        assert(i == x || i == y);
        return i == x ? y : x ;
    }

    /**
     * 5.运算符重载
     * "<< > < >= <= =="
     * 用于比较边的优劣，目前只比较权重
     */
    friend ostream& operator << (ostream &os, const Edge &e){
        os<<e.x<<"-"<<e.y<<":"<<e.weight;
        return os;
    }
    bool operator > (Edge<Weight>& e){
        return weight > e.weight;
    }
    bool operator >= (Edge<Weight>& e){
        return weight >= e.weight;
    }
    bool operator < (Edge<Weight>& e){
        return weight < e.weight;
    }
    bool operator <= (Edge<Weight>& e){
        return weight <= e.weight;
    }
};

template <typename Weight>
class DenseGraph_wt{
private:
    /**
     * 节点个数；边个数；是否有向；图的向量存储；
     */
    int nodes;
    int edges;
    bool directed;
    vector<vector<Edge<Weight> *>> graph;
public:
    /**
     * 1.构造函数
     * 初始化所有属性，向量中所有元素置NULL
     */
    DenseGraph_wt(int nodes, bool directed){
        this->nodes = nodes;
        this->directed = directed;
        for(int i = 0 ; i < nodes ; i ++){
            graph.push_back(vector<Edge<Weight> *>(nodes, NULL));
        }
    }

    /**
     * 2.析构函数
     */

    /**
     * 3.Gets函数
     * 提供节点数与边数的查询
     */
    int GetNodes(){return nodes;}
    int GetEdges(){return edges;}

    /**
     * 4.查询函数，查询边是否存在
     */
    bool hasEdge(int x, int y){
        assert(x >= 0 && x <= nodes);
        assert(y >= 0 && y <= nodes);
        //这是有向图的写法，无向图只需判断一侧即可
        if(graph[x][y] || graph[y][x])
            return true;
        return false;
    }

    /**
     * 5.addEdge函数
     * 注意添加的元素为Edge对象
     */
    void addEdge(int x, int y, Weight weight){
        assert(x >= 0 && x <= nodes);
        assert(y >= 0 && y <= nodes);
        if(hasEdge(x, y)){
            delete(graph[x][y]);
            edges --;
        }
        graph[x][y] = new Edge<Weight>(x, y, weight);
        if(!directed)
            graph[y][x] = new Edge<Weight>(y, x, weight);
        edges ++;
    }

    /**
     * 6.show函数
     * 打印图的邻接矩阵
     */


    /**
     * 7.adjIterator
     * 定点临边迭代器
     */
    class adjIterator{
    private:
        DenseGraph_wt &dg_wt;
        int tar_node;
        int index;
    public:
        adjIterator(DenseGraph_wt &graph, int tar_node):dg_wt(graph){
            this->tar_node = tar_node;
            this->index = -1;
        }
        Edge<Weight>* begin(){
            index = -1;
            return next();
        }
        Edge<Weight>* next(){
            for(index += 1 ; index < dg_wt.GetNodes() ; index++){
                if(dg_wt.graph[tar_node][index])
                    return dg_wt.graph[tar_node][index];
            }
            return NULL;
        }
        bool end(){
            return index >= dg_wt.GetNodes();
        }
    };
};

template <typename Weight>
class ReadGraph{
private:
public:
    /**
     * 构造函数
     * 传入图的引用，文件对象名，为该图添加所有的边
     */
};
#endif //ALGORITHM_CPP_WEIGHTGRAPH_H
