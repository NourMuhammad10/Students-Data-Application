#include "MinHeap.h"
#include <bits/stdc++.h>
using namespace std;

int MinHeap::getParentPosition(int i) {
    ///Time Complexity O(log1)
    return (i-1)/2;
}
int MinHeap::getLeftChildPosition(int i) {
    ///Time Complexity O(log1)
    return (2*i) + 1; //plus one because it's zero based
}
int MinHeap::getRightChildPosition(int i) {
    ///Time Complexity O(log1)
    return (2 * i) + 2; //plus one because it's zero based
}
void MinHeap::heapify(int i) {
    ///Time Complexity O(logN)
    // heapify process takes place from the desired index
    // till the last node in its height
    int left = getLeftChildPosition(i);
    int right = getRightChildPosition(i);
    int smallest = i;
    if(left < heap.size() && heap[left].getGpa() < heap[smallest].getGpa()){
        smallest = left;
    }
    if(left < heap.size() && heap[right].getGpa() < heap[smallest].getGpa()){
        smallest = right;
    }
    if(smallest != i){
        swap(heap[smallest], heap[i]);
        heapify(smallest);
    }
}

Student MinHeap::getMin() {
    ///Time Complexity O(log1)
    return heap[0];
}

void MinHeap::insert(Student element) {
    ///Time Complexity O(logN)
    heap.push_back(element);
    int i = heap.size()-1;
    while( i != 0 && heap[getParentPosition(i)].getGpa() > heap[i].getGpa()){
        //heapify(heap[getParentPosition(i)]);
        swap(heap[getParentPosition(i)], heap[i]);
        i = getParentPosition(i);
    }
}

void MinHeap::displayHeap() {
    ///Time Complexity O(logN)
    for(int i = 0; i < heap.size(); i++){
        cout << heap[i] << "\n";
    }
}

int MinHeap::getHeapSize() {
    ///Time Complexity O(log1)
    return heap.size();
}

Student MinHeap::deleteMin() {
    ///Time Complexity O(logN)
    Student min = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(0);
    return min;
}

void MinHeap::heapSort() {
    ///Time Complexity O(NlogN)
    vector<Student> tempHeap = heap;
    int sortedHeapSize = heap.size();
    vector<Student> sortedHeap;
    for(int i = 0; i < sortedHeapSize; i++){
        sortedHeap.push_back(this->deleteMin());
    }
    heap = tempHeap;
    for (int i = 0; i < sortedHeap.size(); ++i) {
        cout << sortedHeap[i] << "\n";
    }
}
