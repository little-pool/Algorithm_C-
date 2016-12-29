//
// Created by pool_little on 28/12/2016.
//

#ifndef ALGORITHM_CPP_READGRAPH_H
#define ALGORITHM_CPP_READGRAPH_H

#include <cassert>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

template <typename Graph>
class ReadGraph{
private:
public:
    ReadGraph(Graph &g, const string &filename){

        //打开文件
        ifstream file(filename);
        //line用于存储取出每一行的信息
        string line;
        //node_num;side_num；用于存储图中的两个成员变量
        int node_num, side_num;
        //得到文本中的一行数据
        assert(file.is_open());
        assert(getline(file,line));
        //为自身成员变量node_num and side_num赋值
        stringstream ss(line);
        ss>>node_num>>side_num;
        assert(node_num == g.GetNodeNum());
        //逐行读取side信息并添加进目标图中
        for(int i = 0 ; i < side_num ; i ++){
            //继续读取一行
            assert(getline(file, line));
            stringstream ss(line);
            //取值赋值给目标图
            int a, b;
            ss>>a>>b;
            assert(0 <= a <= node_num);
            assert(0 <= b <= node_num);
            g.AddSide(a, b);
        }
    }
};
#endif //ALGORITHM_CPP_READGRAPH_H
