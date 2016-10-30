#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"
using namespace std;

/*
     * 1.寻找[i,n)之间最小的数值
     * 2.与第i为数据交换位置
     */

template <typename T>//利用泛型来扩展函数的功能
void SelectionSort(T arr[],int n){
    for(int i = 0 ; i < n ; i ++){
        int MinPiont = i;
        for(int j = i + 1 ; j < n ; j ++){
            if(arr[j] < arr[MinPiont]){
                MinPiont = j;
            }
        }
        swap(arr[i],arr[MinPiont]);
    }
}

int main() {
    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    SortTestHelper::testSort("SelectionSort",SelectionSort,arr,n);
    delete[] arr;

//
//    Student d[3] = {{"A",90},{"B",80},{"C",70}};
//    SelectionSort( d , 3 );
//    for(int i = 0 ; i < 3 ; i ++){
//        cout<<d[i];
//    }
//    cout<<'\n';
    return 0;
}