#include "MaxHeap.h"
#include <bits/stdc++.h>
using namespace std;

int MaxHeap::getParentPosition(int i) {
    ///Time Complexity O(log1)
    return (i-1)/2;
}
int MaxHeap::getLeftChildPosition(int i) {
    ///Time Complexity O(log1)
    return (2*i) + 1; //plus one because it's zero based
}
int MaxHeap::getRightChildPosition(int i) {
    ///Time Complexity O(log1)
    return (2 * i) + 2; //plus one because it's zero based
}
void MaxHeap::heapify(int i) {
    ///Time Complexity O(logN)
    // heapify process takes place from the desired index
    // till the last node in its height
    int left = getLeftChildPosition(i);
    int right = getRightChildPosition(i);
    int largest = i;
    if(left < heap.size() && heap[left].getGpa() > heap[largest].getGpa()){
        largest = left;
    }
    if(left < heap.size() && heap[right].getGpa() > heap[largest].getGpa()){
        largest = right;
    }
    if(largest != i){
        swap(heap[largest], heap[i]);
        heapify(largest);
    }
}

Student MaxHeap::getMax() {
    ///Time Complexity O(log1)
    return heap[0];
}

void MaxHeap::insert(Student element) {
    ///Time Complexity O(logN)
    heap.push_back(element);
    int i = heap.size()-1;
    while( i != 0 && heap[getParentPosition(i)].getGpa() < heap[i].getGpa()){
        //heapify(heap[getParentPosition(i)]);
        swap(heap[getParentPosition(i)], heap[i]);
        i = getParentPosition(i);
    }
}

void MaxHeap::displayHeap() {
    ///Time Complexity O(logN)
    for(int i = 0; i < heap.size(); i++){
        cout << heap[i] << "\n";
    }
}

int MaxHeap::getHeapSize() {
    ///Time Complexity O(log1)
    return heap.size();
}

Student MaxHeap::deleteMax() {
    ///Time Complexity O(logN)
    Student max = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(0);
    return max;
}
void MaxHeap::heapSort() {
    vector<Student> tempHeap = heap;
    int sortedHeapSize = heap.size();
    vector<Student> sortedHeap;
    for(int i = 0; i < sortedHeapSize; i++){
        sortedHeap.push_back(this->deleteMax());
    }
    heap = tempHeap;
    for (int i = 0; i < sortedHeap.size(); ++i) {
        cout << sortedHeap[i] << "\n";
    }
}
