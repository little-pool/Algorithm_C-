//
// Created by pool_little on 03/01/2017.
//

#ifndef ALGORITHM_CPP_PATH_H
#define ALGORITHM_CPP_PATH_H

#include <vector>
#include <stack>
using namespace std;
template <typename Graph>
class Path{
private:
    Graph &g;   //待遍历图的引用
    int source_node;      //待检索路径的初始节点
    bool* visited;   //存储节点是否遍历过，后会指向bool数组。
    int* from;  //存储遍历节点的初始节点，后会指向int数组。
    /**
     * 遍历
     */
    void DeepFirstSearch(int node_id){
        visited[node_id] = true;
        typename Graph::adjIterator adj(g, node_id);
        for(int i = adj.begin() ; !adj.end() ; i = adj.next()){
            if(!visited[i]){
                from[i] = node_id;
                DeepFirstSearch(i);
            }
        }
    }
public:
    //test print from
    int* GetFrom(){
        return this->from;
    }

    //深度优先遍历时将visited与from赋好值，visited初始值置为false，from的初始值全部置为-1。
    Path(Graph &G, int source_node):g(G){
        //初始赋值
        this->source_node = source_node;
        visited = new bool[this->g.GetNodeNum()];
        from = new int[this->g.GetNodeNum()];
        for(int i = 0 ; i < this->g.GetNodeNum() ; i ++){
            visited[i] = false;
            from[i] = -1;
        }
        //深度优先遍历源节点
        DeepFirstSearch(source_node);
    }


    /**
     * 寻路
     */
    //指定末节节点，然后根据from回溯前置节点，一一入栈后出栈得到最终路径返回vector
    vector<int> GetPath(int des_node){
        int i = des_node;
        stack<int> stk;
        while(i != -1){
            stk.push(i);
            i = from[i];
        }
        vector<int> v_path;
        while(!stk.empty()){
            v_path.push_back(stk.top());
            stk.pop();
        }
        return v_path;
    }


    /**
     * 输出
     */
    //判断是否有路径
    bool IfPath(int i){
        return visited[i];
    }
    //输出路径
    void PathPrint(int w){
        if(!IfPath(w))
            cout<<"No path from "<<source_node<<" to "<<w<<endl;
            return;
        //else
        vector<int> tmp = GetPath(w);
        for(int i = 0 ; i < tmp.size() ; i ++){
            if(tmp[i] != w)
                cout<<tmp[i]<<" -> ";
            else
                cout<<tmp[i]<<endl;
        }
        cout<<endl;
    }
};
#endif //ALGORITHM_CPP_PATH_H
