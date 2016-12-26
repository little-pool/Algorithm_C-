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
    /**
     * 用邻接表来表示稀疏图
     */
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
        bool HasSide(int m, int n){
            assert(0 <= m <= node_num);
            assert(0 <= n <= node_num);
            for(int i = 0 ; i < graph[m].size() ; i ++){
                if(graph[m][i] == n)
                    return true;
            }
            return false;
        }

        void AddSide(int m, int n){
            assert(0 <= m <= node_num);
            assert(0 <= n <= node_num);
            if(HasSide(m, n))
                return;
            graph[m].push_back(n);
            m++;
        }

        class adjIterrator{
        private:
            SparseGraph &sg;
            int node;
            int index;
        public:
            adjIterrator(SparseGraph &SG, int node):sg(SG){
                this->node = node;
                this->index = 0;
            }

            int begin(){
                index = 0;
                if(sg.graph[node].size())
                    return sg.graph[node][index];
                return -1;
            }

            int next(){
                index ++;
                return sg.graph[node][index];
            }

            bool end(){
                return index >= sg.graph[node].size();
            }
        };
    };
}
#endif //ALGORITHM_CPP_GRAPH_H
