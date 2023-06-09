#ifndef STUDENTS_DATA_APPLICATION_MINHEAP_H
#define STUDENTS_DATA_APPLICATION_MINHEAP_H
#include <bits/stdc++.h>
#include "../Student/Student.h"
using namespace std;

class MinHeap{
    vector<Student> heap;
public:
    int getParentPosition(int i);
    int getLeftChildPosition(int i);
    int getRightChildPosition(int i);
    void heapify(int i);
    void insert(Student element);
    Student getMin();
    void displayHeap();
    int getHeapSize();
    Student deleteMin();
    void heapSort();
};


#endif //STUDENTS_DATA_APPLICATION_MINHEAP_H
