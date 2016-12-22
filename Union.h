//
// Created by pool_little on 22/12/2016.
//

#ifndef ALGORITHM_CPP_UNION_H
#define ALGORITHM_CPP_UNION_H

#include <cassert>

namespace UnionFind_01{
    /**
     * 利用数组的值代表连接标示符，体现元素的连接关系，纯线性结构，在合并时效率为On1，效率比较低。
     */
    class UnionFind{
    private:
        int* id;
        int count;
    public:

        UnionFind(int n){
            this->count = n;
            id = new int[count];
            for(int i = 0 ; i < count ; i ++){
                id[i] = i;
            }
        }

        int find(int n){
            assert(0 <= n < count);
            return id[n];
        }

        bool isConnected(int p, int q){
            return find(p) == find(q);
        }

        void unionElements(int p, int q){
            int pID = find(p);
            int qID = find(q);
            if(pID == qID)
                return;
            for(int i = 0 ; i < count ; i ++){
                if(id[i] == pID)
                    id[i] = qID;
            }
        }
    };

}

namespace UnionFind_02{
    /**
     * 利用数组的值代表父节点的指针，将原有的线性结构转变为树形结构，在合并时只需修改指针的指向即可，效率<On1。
     */
    class UnionFind{
    private:
        int* parent;
        int count;
    public:
        UnionFind(int n){
            this->count = n;
            parent = new int[count];
            for(int i = 0 ; i < count ; i ++){
                parent[i] = i;
            }
        }

        int findRoot(int n){
            if(parent[n] != n)
                return findRoot(parent[n]);
            return parent[n];
        }

        bool isConnected(int p, int q){
            return findRoot(p) == findRoot(q);
        }

        void unionElements(int p, int q){
            if(isConnected(p,q))
                return;
            int pRoot = findRoot(p);
            int qRoot = findRoot(q);
            parent[pRoot] = qRoot;
        }

    };
}

namespace UnionFind_03{
    /**
     * 基于rank的Union优化，即在Union时先判断哪一颗树的rank(层数)少，然后将小数Union到大树上。
     */
    class UnionFind{
    private:
        int* parent;
        int* rank;
        int count;
    public:
        UnionFind(int n){
            this->count = n;
            this->parent = new int[count];
            this->rank = new int[count];
            for(int i = 0 ; i < count ; i ++){
                parent[i] = i;
                rank[i] = 1;
            }
        }
        ~UnionFind(){
            delete[] parent;
            delete[] rank;
        }
        int findRoot(int n){
            if(parent[n] != n)
                return findRoot(parent[n]);
            return parent[n];
        }

        int findSize(int n){
            return rank[n];
        }
        bool isConnected(int p, int q){
            return findRoot(p) == findRoot(q);
        }
        void unionElements(int p, int q){
            if(isConnected(p, q))
                return;
            int pRoot = findRoot(p);
            int qRoot = findRoot(q);
            if(rank[pRoot] < rank[qRoot])
                parent[pRoot] = qRoot;
            else if(rank[pRoot] > rank[qRoot])
                parent[qRoot] = pRoot;
            else//rank is equal between pRoot and qRoot
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;
        }
    };
}
#endif //ALGORITHM_CPP_UNION_H
