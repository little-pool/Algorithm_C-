#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"
#include "Sort.h"
#include "Heap.h"
using namespace std;




int main() {
//    MaxHeap<int> maxheap = MaxHeap<int>(100);
//    cout<<maxheap.size()<<endl;
//    srand(time(NULL));
//    for(int i = 0 ; i < 15 ; i ++){
//        maxheap.insert(rand()%100);
//    }
//    maxheap.print_arr();
//    while(!maxheap.isEmpty()){
//        cout<<maxheap.extractMax()<<" ";
//    }
//    cout<<endl;
    int m = 1000000;
    int* arr1 = SortTestHelper::generateRandomArray(m,0,m);
    int* arr2 = SortTestHelper::copyIntArray(arr1,m);
    int* arr3 = SortTestHelper::copyIntArray(arr1,m);
    SortTestHelper::testSort("mergeSort",mergeSort,arr1,m);
    SortTestHelper::testSort("quickSort",quickSort,arr2,m);
    SortTestHelper::testSort("heapSort",heapSort,arr3,m);

    cout<<endl;

}