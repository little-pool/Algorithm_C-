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
        void show(){
            cout<<"\t";
            for(int i = 0 ; i < this->node_num ; i ++)
                printf("[%d]\t",i);
            cout<<endl;

            for(int i = 0 ; i < this->node_num ; i ++){
                printf("[%d]\t ",i);
                for(int j = 0 ; j < this->node_num ; j ++){
                    cout<<graph[i][j]<<"\t ";
                }
                cout<<endl;
            }
        }
        class adjIterator{
        private:
            //待传入的图对象的引用
            DenseGraph &dg;
            //待迭代节点
            int node;
            //每个节点相对其他节点的指针索引
            int index;
        public:
            //构造函数
            adjIterator(DenseGraph &SG, int node): dg(SG){
                this->node = node;
                this->index = -1;
            }
            int begin(){
                index = -1;
                return next();
            }

            int next(){
                for(index += 1 ; index < dg.node_num ; index ++){
                    if(dg.graph[node][index])
                        return index;
                }
                return -1;
            }

            bool end(){
                return index >= dg.node_num;
            }
        };
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
            if(m != n && directed == false)
                graph[n].push_back(m);
            m++;
        }
        void show(){
            for(int i = 0 ; i < this->node_num ; i ++){
                printf("[%d]\t ",i);
                for(int j = 0 ; j < graph[i].size() ; j ++){
                    printf("%d\t ",graph[i][j]);
                }
                printf("\n");
            }
        }
        class adjIterator{
        private:
            SparseGraph &sg;
            int node;
            int index;
        public:
            adjIterator(SparseGraph &SG, int node):sg(SG){
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
