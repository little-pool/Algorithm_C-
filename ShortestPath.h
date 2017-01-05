//
// Created by pool_little on 04/01/2017.
//

#ifndef ALGORITHM_CPP_SHORTESTPATH_H
#define ALGORITHM_CPP_SHORTESTPATH_H

#include <queue>
#include <stack>
#include <iostream>
using namespace std;

template <typename Graph>
class ShortestPath{
private:
    Graph &g;
    bool* visited;
    int* from;
    int* distance;
    int source_node;
    queue<int> q;
public:
    /**
     * 构造函数
     * 1.初始化内部变量
     * 2.广度优先遍历图g，在遍历过程中维护visited，from，distance三个数组
     */
    ShortestPath(Graph &G, int source_node):g(G){
        this->source_node = source_node;
        int width = g.GetNodeNum();

        visited = new bool[width];
        from = new int[width];
        distance = new int[width];

        for(int i = 0 ; i < width ; i ++){
            visited[i] = false;
            from[i] = -1;
            distance[i] = -1;
        }
        //在队首节点出队时，将该节点所有的相邻并且没有入过队的节点会随之入队，最终，所有的节点会按层入队后出队直到遍历结束。
        //此过程为层序遍历，因此可以得到两个节点的最短路径以及节点间距离。
        q.push(source_node);
        visited[source_node] = true;
        distance[source_node] = 0;
        while(!q.empty()){
            typename Graph::adjIterator adj(g, q.front());
            for(int i = adj.begin() ; !adj.end() ; i = adj.next()){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    from[i] = q.front();
                    distance[i] = distance[q.front()]+1;
                }
            }
            cout<<q.front()<<endl;
            cout.flush();
            q.pop();
        }

    }

    /**
     * Utility
     * 1.查看是否有路径
     * 2.查看路径
     * 3.查看距离
     */
    bool IfPath(int d){
        return visited[d];
    }

    vector<int> GetPath(int d){
        stack<int> stk;
        stk.push(d);
        int i = from[d];
        while(i != -1){
            stk.push(i);
            i = from[i];
        }
        vector<int> vct;
        while(!stk.empty()){
            vct.push_back(stk.top());
            stk.pop();
        }
        return vct;
    }

    void PathPrint(int d){
        if(!IfPath(d))
            cout<<"No path from "<<source_node<<" to "<<d<<endl;
        //else
        vector<int> tmp = GetPath(d);
        for(int i = 0 ; i < tmp.size() ; i ++){
            if(tmp[i] != d)
                cout<<tmp[i]<<" -> ";
            else
                cout<<tmp[i]<<endl;
        }
        cout<<endl;
    }

};
#endif //ALGORITHM_CPP_SHORTESTPATH_H
