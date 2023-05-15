#ifndef STUDENTS_DATA_APPLICATION_MAXHEAP_H
#define STUDENTS_DATA_APPLICATION_MAXHEAP_H
#include <bits/stdc++.h>
#include "../Student/Student.h"
using namespace std;

class MaxHeap{
    vector<Student> heap;
public:
    int getParentPosition(int i);
    int getLeftChildPosition(int i);
    int getRightChildPosition(int i);
    void heapify(int i);
    void insert(Student element);
    Student getMax();
    void displayHeap();
    int getHeapSize();
    Student deleteMax();
    void heapSort();
};



#endif //STUDENTS_DATA_APPLICATION_MAXHEAP_H
