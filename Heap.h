//
// Created by pool_little on 12/11/2016.
//

#ifndef ALGORITHM_CPP_HEAP_H
#define ALGORITHM_CPP_HEAP_H

#include <bootstrap.h>
#include <cassert>
#include <algorithm>

//定义一个最大堆
template <typename Item>
class MaxHeap{
private:
    //我们用数组来存储堆中的数据
    Item* data;
    //count描述这个堆中一共有多少个元素
    int count;
    int capacity;

    void shiftUp(int k){
        while(data[k/2] < data[k] && k > 1){
            swap(data[k/2],data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k){
        while(2*k <= count){
            //data[k]与其子节点中较大的元素调换位置
            int j = 2*k;    //j代表子节点中较大值的索引
            if(j + 1 <= count && data[j+1] > data[j])
                j ++;
            //判断是否应该进行交换
            if(data[k] >= data[j])
                break;
            swap(data[k],data[j]);
            k = j;
        }
    }
public:
    MaxHeap(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }
    ~MaxHeap(){
        delete [] data;
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count==0;
    }
    //插入元素到堆的最后一个元素上，然后向上调节位置。
    void insert(Item item){
        //将新的元素存储到data中
        assert(count+1 <= capacity);
        data[count+1] = item;
        count ++;
        shiftUp(count);
    }
    //弹出堆的第一个元素，然后将最后一个元素放到其位置，向下调节位置。
    Item extractMax(){
        assert(count > 0);
        Item ret = data[1];
        swap(data[1],data[count]);
        count --;
        shiftDown(1);
        return ret;
    }
    void print_arr(){
        for(int i = 1 ; i <= count ; i ++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};
#endif //ALGORITHM_CPP_HEAP_H
