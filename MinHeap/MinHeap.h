#ifndef STUDENTS_DATA_APPLICATION_MINHEAP_H
#define STUDENTS_DATA_APPLICATION_MINHEAP_H
#include <bits/stdc++.h>
using namespace std;

template<class T>
class MinHeap{
    vector<T> heap;
public:
    int getParentPosition(int i);
    int getLeftChildPosition(int i);
    int getRightChildPosition(int i);
    void heapify(int i);
    void insert(T element);
    T getMin();
    void displayHeap();
    int getHeapSize();
    T deleteMin();
    vector<T> heapSort();
};


#endif //STUDENTS_DATA_APPLICATION_MINHEAP_H
