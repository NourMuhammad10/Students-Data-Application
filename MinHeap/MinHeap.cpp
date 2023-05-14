#include "MinHeap.h"
#include <bits/stdc++.h>
using namespace std;

template<class T>
int MinHeap<T>::getParentPosition(int i) {
    ///Time Complexity O(log1)
    return (i-1)/2;
}
template<class T>
int MinHeap<T>::getLeftChildPosition(int i) {
    ///Time Complexity O(log1)
    return (2*i) + 1; //plus one because it's zero based
}
template<class T>
int MinHeap<T>::getRightChildPosition(int i) {
    ///Time Complexity O(log1)
    return (2 * i) + 2; //plus one because it's zero based
}
template<class T>
void MinHeap<T>::heapify(int i) {
    ///Time Complexity O(logN)
    // heapify process takes place from the desired index
    // till the last node in its height
    int left = getLeftChildPosition(i);
    int right = getRightChildPosition(i);
    int smallest = i;
    if(left < heap.size() && heap[left] < heap[smallest]){
        smallest = left;
    }
    if(left < heap.size() && heap[right] < heap[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(heap[smallest], heap[i]);
        heapify(smallest);
    }
}

template<class T>
T MinHeap<T>::getMin() {
    ///Time Complexity O(log1)
    return heap[0];
}

template<class T>
void MinHeap<T>::insert(T element) {
    ///Time Complexity O(logN)
    heap.push_back(element);
    int i = heap.size()-1;
    while( i != 0 && heap[getParentPosition(i)] > heap[i]){
        //heapify(heap[getParentPosition(i)]);
        swap(heap[getParentPosition(i)], heap[i]);
        i = getParentPosition(i);
    }
}

template<class T>
void MinHeap<T>::displayHeap() {
    ///Time Complexity O(logN)
    for(int i = 0; i < heap.size(); i++){
        cout<<heap[i]<<" ";
    }
}

template<class T>
int MinHeap<T>::getHeapSize() {
    ///Time Complexity O(log1)
    return heap.size();
}

template<class T>
T MinHeap<T>::deleteMin() {
    ///Time Complexity O(logN)
    T min = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(0);
    return min;
}
template<class T>
vector<T> MinHeap<T>::heapSort() {
    vector<T> tempHeap = heap;
    int sortedHeapSize = heap.size();
    vector<T> sortedHeap;
    for(int i = 0; i< sortedHeapSize; i++){
        sortedHeap.push_back(this->deleteMin());
    }
    heap = tempHeap;
    return sortedHeap;
}
