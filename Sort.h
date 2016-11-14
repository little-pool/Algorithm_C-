//
// Created by pool_little on 12/11/2016.
//

#ifndef ALGORITHM_CPP_SORT_H
#define ALGORITHM_CPP_SORT_H
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
void InsertionSort(T arr[],int n){
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
 * 归并排序(自顶向下)
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

/*
 * 归并排序(自底向上)
 * 这种方法并不需要递归，只需要迭代。
 */
template <typename T>
void mergeSortBU(T arr[], int n){
    //定义颗粒度，从1开始每次*2到n/2结束。
    for(int size = 1 ; size <= n ; size += size){
        //从头开始，每次对两个颗粒调用__merge函数进行合并
        for(int i = 0 ; i < n - size ; i += size*2){
            __merge(arr,i,i+size-1,min(i+size*2-1,n-1));
            //cout<<"size:"<<size<<" "<<"i:"<<i<<" ";
            //SortTestHelper::printArray(arr,n);
        }
    }

}

/**
 * 快速排序(基本)
 * 这种方法的缺点为当数组的相同元素很多时，分治出的二叉树平衡性就会很差，最坏的情况为单边，导致算法的时间复杂度为O(n^2)
 * @return
 */
template <typename T>
int __partition(T arr[], int l, int r){
    //v初始化为数组的第一个元素
    T v = arr[l];
    //循环将 >v and <v 的数据分别置于两块连续的区域，即：arr[l+1...j] < v and ar[j+1...i) > v；
    int j = l;
    for(int i = l + 1 ; i <= r ; i ++){
        if(arr[i] < v){
            swap(arr[j+1],arr[i]);
            j++;
        }
    }
    //刚忘记写如下两行导致递归回不来！
    swap(arr[l],arr[j]);
    return j;
}

template <typename T>
void __quickSort(T arr[], int l, int r){
    if(l >= r){
        return;
    }
    else{
        int p = __partition(arr, l, r);
        __quickSort(arr, l, p);
        __quickSort(arr, p+1, r);
    }
}

template <typename T>
void quickSort(T arr[], int n){
    __quickSort(arr, 0, n-1);
}
#endif //ALGORITHM_CPP_SORT_H
