//
// Created by pool_little on 23/12/2016.
//

#ifndef ALGORITHM_CPP_GRAPH_H
#define ALGORITHM_CPP_GRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
namespace Dense{
    /**
     * 用邻接矩阵来表示稠密图
     */
    class DenseGraph{
    private:
        int node_num;
        int side_num;
        bool directed;
        vector<vector<bool>> graph;
    public:
        DenseGraph(int n,bool d){
            this->node_num = n;
            this->side_num = 0;
            this->directed = d;
            for(int i = 0 ; i < node_num ; i ++){
                graph.push_back(vector<bool>(node_num, false));
            }
        }
        int GetNodeNum(){
            return node_num;
        }
        int GetSideNum(){
            return side_num;
        }
        bool HasSide(int m, int n){
            assert(0 <= m <= node_num);
            assert(0 <= n <= node_num);
            return graph[m][n];
        }
        void AddSide(int m, int n){
            assert(0 <= m <= node_num);
            assert(0 <= n <= node_num);
            if(HasSide(m, n)){
                return;
            }
            graph[m][n] = true;
            if(!directed)
                graph[n][m] = true;
            side_num ++;
        }
    };
}

namespace Sparse{
    class SparseGraph{
    private:
        int node_num;
        int side_num;
        bool directed;
        vector<vector<int>> graph;
    public:
        SparseGraph(int n, bool d){
            this->node_num = n;
            this->side_num = 0;
            this->directed = d;
            for(int i = 0 ; i < node_num ; i ++){
                graph.push_back(vector<int>());
            }
        }
        int GetNodeNum(){
            return node_num;
        }
        int GetSideNum(){
            return side_num;
        }
        HasSide(int m, int n){
            assert(0 <= m <= node_num);
            assert(0 <= n <= node_num);

        }


    };
}
#endif //ALGORITHM_CPP_GRAPH_H
