//
// Created by pool_little on 29/10/2016.
//

#ifndef PRO_HANSU_SORTTESTHELPER_H
#define PRO_HANSU_SORTTESTHELPER_H

#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;
namespace SortTestHelper{
    //n个元素的随机整形数组，每个元素的范围有L和R规范，返回数组指针
    int* generateRandomArray(int n, int rangeL, int rangeR){
        assert(rangeL < rangeR);
        int *arr = new int[n];
        srand(time(NULL));                                              //为rand函数设置一个随机种子，这里用时间作为随机种子数。
        for(int i = 0 ; i < n ; i ++){
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    template <typename T>
    void printArray(T arr[], int n){
        for(int i = 0 ; i < n ; i ++ ){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }

    //判断排序的正确性
    template <typename T>
    bool isSorted(T arr[], int n){
        for(int i = 0 ; i < n - 1 ; i ++){
            if(arr[i] > arr[i+1]){
                return false;
            }
        }
        return true;
    }

    template <typename T>
    void testSort(string sortName, void(*sort)(T[],int),T arr[], int n ){
        //时钟周期，1个时钟周期很短<1s
        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();
        assert(isSorted(arr,n));
        cout<<sortName<<":"<<double (endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
        return;
    }
}



#endif //PRO_HANSU_SORTTESTHELPER_H
