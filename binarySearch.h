//
// Created by pool_little on 16/11/2016.
//

#ifndef ALGORITHM_CPP_BINARYSEARCH_H
#define ALGORITHM_CPP_BINARYSEARCH_H
#include <queue>
namespace binaryMethod{
    /**
     * 二分查找返回索引值，若不存在返回-1
     * @param arr
     * @param n
     * @param target
     * @return
     */
    template <typename T>
    int binarySearch(T arr[], int n, T target){
        //在[l...r]区间内对target进行二分查找
        int l = 0;
        int r = n-1;
        while(l <= r){
            /**
             * 这种写法会出现越界问题。
             * int mid = (l + r)/2;
             */
            int mid = l + (r-l)/2;
            if(target == arr[mid])
                return mid;
            else if(target > arr[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

    /**
     * 二分搜索树类
     */
    template <typename Key, typename Value>
    class BST{
    private:
        //用结构体链表来做存储
        struct Node{
            Key key;
            Value value;
            Node* left;
            Node* right;
            //构造函数
            Node(Key key, Value value){
                this->key = key;
                this->value = value;
                this->left = this->right = NULL;
            }
        };

        Node* root;
        int count;
        /**
         * 想以node为根的二叉搜索树中插入节点(key,value)
         * 返回插入新节点后的二叉搜索树的根
         * @param node
         * @param key
         * @param value
         * @return
         */
        Node* insert(Node* node, Key key, Value value){
            //如果递归到空节点上，那么就新创建一个Node来进行插入操作
            if(node == NULL){
                count ++;
                return new Node(key, value);
            }
            //如果遍历得到Node的key与插入的key相等，那么value覆盖
            if(key == node->key)
                node->value = value;
            else if (key < node->key)
                node->left = insert(node->left, key, value);
            else
                node->right = insert(node->right, key, value);
            return node;
        }
        /**
         * 判断指定key是否存在
         * @param node
         * @param key
         * @return
         */
        bool contain(Node* node, Key key){
            //递归到底的情况
            if(node == NULL)
                return false;
            //递归部分的三种情况
            if(key == node->key)
                return true;
            else if(key > node->key)
                return contain(node->right,key);
            else //key < node->key
                return contain(node->left,key);
        }
        /**
         * 查找key对应的value,返回value的指针，因为如果直接返回数值的话，万一该key不存在，那么C++会报错
         * @param node
         * @param key
         * @return
         */
        Value* search(Node* node, Key key){
            //递归到底的情况
            if(node == NULL)
                return NULL;
            //递归过程
            if(key == node->key)
                return &(node->value);
            else if(key > node->key)
                return search(node->right, key);
            else  //key < node->key
                return search(node->left, key);
        }
        void perOrder(Node* node){
            if(node != NULL){
                cout<<node->key<<" ";
                perOrder(node->left);
                perOrder(node->right);
            }
        }
        void inOrder(Node* node){
            if(node != NULL){
                inOrder(node->left);
                cout << node->key << " ";
                inOrder(node->right);
            }
        }
        void postOrder(Node* node){
            if(node != NULL){
                postOrder(node->left);
                postOrder(node->right);
                cout << node->key << " ";
            }
        }
        void destroy(Node* node){
            if(node != NULL){
                destroy(node->left);
                destroy(node->right);
                delete node;
            }
        }
        Node* minimum(Node* node){
            if(node->left == NULL)
                return node;
            return minimum(node->left);
        }
        Node* maximum(Node* node){
            if(node->right == NULL)
                return node;
            return maximum(node->right);
        }
    public:
        BST(){
            root = NULL;
            count = 0;
        }
        ~BST(){
            //TODO:~bst()
            destroy(root);
        }

        int size(){
            return count;
        }
        bool isEmpty(){
            return count == 0;
        }
        /**
         * 插入函数
         * @param key
         * @param value
         */
        void insert(Key key, Value value){
            //调用递归函数
            root = insert(root, key, value);
        }
        /**
         * 简直索隐函数
         * @param key
         * @return
         */
        bool contain(Key key){
            //调用递归函数
            return contain(root, key);
        }
        /**
         * 取值函数，返回value的指针
         * @param key
         * @return
         */
        Value* search(Key key){
            //调用递归函数
            return search(root, key);
        }
        void perOrder(){
            perOrder(root);
            cout<<endl;
        }
        void inOrder(){
            inOrder(root);
            cout<<endl;
        }
        void postOrder(){
            postOrder(root);
            cout<<endl;
        }
        //广度优先遍历
        void levelOrder(){
            //queue不能指定指针类型，很奇怪！
            queue<Node> q;
            q.push(*root);
            while(!q.empty()){
                Node point = q.front();
                cout<<point.key<<" ";
                q.pop();
                if(point.left != NULL)
                    q.push(*(point.left));
                if(point.right != NULL)
                    q.push(*(point.right));
            }
            cout<<endl;
        }
        //寻找最小值
        Key minimum(){
            assert(count != 0);
            Node* minNode = minimum(root);
            return minNode->key;
        }
        Key maximum(){
            assert(count != 0);
            Node* maxNode = maximum(rort);
            return maxNode->key;
        }
    };
}
#endif //ALGORITHM_CPP_BINARYSEARCH_H
