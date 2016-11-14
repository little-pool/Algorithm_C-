#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"
#include "Sort.h"
#include "Heap.h"
using namespace std;




int main() {
    MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout<<maxheap.size()<<endl;
    srand(time(NULL));
    for(int i = 0 ; i < 15 ; i ++){
        maxheap.insert(rand()%100);
    }
    maxheap.print_arr();
    while(!maxheap.isEmpty()){
        cout<<maxheap.extractMax()<<" ";
    }
    cout<<endl;
}