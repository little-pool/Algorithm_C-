#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"
using namespace std;

/*
 * 选择排序
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

/*
 * 插入排序
 * 1.判断i?<i-1
 * 2.如果i<i-1 then swap(i,i-1)
 */
template <typename T>
void InsertionSort(T arr,int n){
    for(int i = 1 ; i < n ; i ++){
        for(int j = i ; j > 0 ; j --){
            if(arr[j] < arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
}

/*
 * 插入排序的优化
 * 为了减少插入排序中的交换过程的次数，我们用多次赋值来取代交换
 */
template <typename T>
void InsertionSort_new(T arr[],int n){
    for(int i = 1 ; i < n ; i ++){
        T point = arr[i];
        int j;
        for(j = i ; j > 0 && arr[j-1] > point ; j --){
            arr[j] = arr[j-1];
        }
        arr[j] = point;
    }
}

/*
 * 归并排序
 */
//递归使用归并排序，对arr[l...r]的范围进行排序
template <typename T>
void __merge(T arr[],int l,int mid,int r){
    T aux[r-l+1];
    for(int i = l ; i <= r ; i ++){
        aux[i-l] = arr[i];
    }
    int i = l;
    int j = mid + 1;
    for (int k = l ; k <= r ; k ++){
        if(i>mid){
            arr[k] = aux[j-l];
            j++;
        }
        else if(j>r){
            arr[k] = aux[i-l];
            i++;

        }
        else if(aux[i-l] < aux[j-l]){
            arr[k] = aux[i-l];
            i++;
        }
        else{
            arr[k] = aux[j-l];
            j++;
        }
    }
}

template <typename T>
void __mergeSort(T arr[],int l, int r){
    if(l >= r){
        return;
    }
    else{
        int mid = (l+r)/2;
        __mergeSort(arr,l,mid);
        __mergeSort(arr,mid+1,r);
        __merge(arr,l,mid,r);
    }
}

template <typename T>
void mergeSort(T arr[], int n){
    __mergeSort(arr, 0, n-1);
}




//void swap1(int a, int b){
//    int temp = a;
//    a = b;
//    b = temp;
//    cout<<"形参地址"<<&a<<" "<<&b<<endl;
//    cout<<a<<" "<<b<<endl;
//}
//
//void swap2(int *a,int *b){
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//    cout<<"形参地址"<<&a<<" "<<&b<<endl;
//    cout<<*a<<" "<<*b<<endl;
//}


int main() {

//    int a = 1;
//    int b = 2;
//
//    cout<<"调用int交换"<<endl;
//    cout<<"实参地址"<<&a<<" "<<&b<<endl;
//    swap1(a,b);
//    cout<<a<<" "<<b<<endl;
//
//    cout<<"调用int*交换"<<endl;
//    cout<<"实参地址"<<&a<<" "<<&b<<endl;
//    swap2(&a,&b);
//    cout<<a<<" "<<b<<endl;

    //利用helper生成随机测试数组
    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
//    SortTestHelper::printArray(arr,n);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);
//    SortTestHelper::printArray(arr2,n);
    int *arr3 = SortTestHelper::copyIntArray(arr,n);
//    SortTestHelper::printArray(arr3,n);
    int *arr4 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("SelectionSort",SelectionSort,arr,n);
    SortTestHelper::testSort("InsertionSort",InsertionSort,arr2,n);
    SortTestHelper::testSort("InsertionSort_new",InsertionSort_new,arr3,n);
    SortTestHelper::testSort("mergeSort",mergeSort,arr4,n);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

//
//    Student d[3] = {{"A",90},{"B",80},{"C",70}};
//    SelectionSort( d , 3 );
//    for(int i = 0 ; i < 3 ; i ++){
//        cout<<d[i];
//    }
//    cout<<'\n';
    return 0;
}