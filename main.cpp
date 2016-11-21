#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"
#include "Sort.h"
#include "Heap.h"
#include "binarySearch.h"
#include <queue>
using namespace std;
using namespace binaryMethod;




int main() {
//    BST<int, string> bst = BST<int, string>();
//    bst.insert(3,"a");
//    bst.insert(5,"b");
//    bst.insert(2,"c");
//    bst.insert(4,"d");
//    bst.insert(2,"e");
//    cout<<bst.contain(10)<<endl;
//    cout<<*bst.search(2)<<endl;

    /**
     * 利用字符串作为key，该字符出现的次数作为value，将这样的KV对存储在二叉搜索树中
     * 然后来对字符串做动态维护操作，例如插入后查询某一个字符串出现的次数，时间复杂度为logn级别
     */
    int n = 10;
//    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
//    SortTestHelper::printArray(arr1,n);
//    BST<int , int> bst_rate = BST<int , int>();
//    for(int i = 0 ; i < n ; i ++){
//        int* o = bst_rate.search(arr1[i]);
//        if(o == NULL){
//            bst_rate.insert(arr1[i],1);
//        }
//        else //二叉树中已有相应key节点
//            (*o) ++;
//    }
//    cout<<"1出现的次数:"<<*bst_rate.search(1)<<endl;


    int* arr2 = SortTestHelper::generateNearlyOrderedArray(n,5);
    cout<<"原数组:";
    SortTestHelper::printArray(arr2,n);
    BST<int, string> bst_Order = BST<int, string>();
    for(int i = 0 ; i < n ; i ++){
        bst_Order.insert(arr2[i],"none");
    }
    cout<<"前序遍历:";
    bst_Order.perOrder();
    cout<<"中序遍历:";
    bst_Order.inOrder();
    cout<<"后序遍历:";
    bst_Order.postOrder();
    cout<<"层序遍历:";
    bst_Order.levelOrder();
}