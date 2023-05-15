#include<bits/stdc++.h>
#include "BinarySearchTree/BinarySearchTree.h"
#include "AVLTree/AVL.h"
#include "MinHeap/MinHeap.h"
#include "MaxHeap/MaxHeap.h"
#include "LoadFile.cpp"
using namespace std;

void displayMainMenu();
void BSTMenu(BinarySearchTree studentsData);
void BSTMenu(BinarySearchTree Student);
void AVLMenu(AVL Student);
void MaxHeapMenu(MaxHeap maxHeapStudent);
void MinHeapMenu(MinHeap minHeapStudent);

int main(){
    displayMainMenu();
    return 0;
}

void displayMainMenu(){
    LoadFile studentData;
    vector<Student> students = studentData.loadFile();
    while(true){
        int choice;
        cout << "\n\nChoose Data Structure" << endl;
        cout << "1. BST \n2. AVL\n3. Min Heap\n4. Max Heap\n5. Exit Program\n";
        cout << "Your choice: ";
        cin >> choice;
        bool flag = 0;
        switch (choice) {
            case 1:
            {
                BinarySearchTree studentsBST;
                for(Student student : students){
                    studentsBST.insert(student);
                }
                BSTMenu(studentsBST);
                break;
            }
            case 2:
            {
                AVL studentsAVL;
                for(Student student : students){
                    studentsAVL.insert(student);
                }
                AVLMenu(studentsAVL);
                break;
            }
            case 3:
            {
                MinHeap studentsMinHeap;
                for(Student student : students){
                    studentsMinHeap.insert(student);
                }
                MinHeapMenu(studentsMinHeap);
                break;
            }
            case 4:
            {
                MaxHeap studentsMaxHeap;
                for(Student student : students){
                    studentsMaxHeap.insert(student);
                }
                MaxHeapMenu(studentsMaxHeap);
                break;
            }
            case 5:
            {
                cout<<"Thank you for using our Student data application!"<<endl;
                flag =1;
                break;
            }
            default:
            {
                cout << "Invalid choice, please make sure you enter one of the available choices!" << endl;
                break;
            }
        }
        if(flag){
            return;
        }
    }
}

void BSTMenu(BinarySearchTree BSTstudents){
    bool flag = 0;
    while(true) {
        int choice;
        cout << "\n\nChoose one of the following options:" << endl;
        cout << "1. Add Student\n2. Remove Student\n3. Search Student\n4. Print All (sorted by id)\n5. Return to main menu\n";
        cout << "Enter number of option: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int id;
                string name, department;
                double gpa;
                cout << "id: ";
                cin >> id;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "GPA: ";
                cin >> gpa;
                cout << "Department: ";
                cin >> department;
                Student stud(id, name, gpa, department);
                BSTstudents.insert(stud);
                cout << "\n The student is added.\n";
                break;
            }
            case 2: {
                int id;
                cout << "id: ";
                cin >> id;
                if (BSTstudents.search(id)) {
                    BSTstudents.remove(id);
                    cout << "Student is deleted. \n";
                }
                break;
            }
            case 3: {
                int id;
                cout << "id: ";
                cin >> id;
                BSTstudents.search(id);
                break;
            }
            case 4: {
                BSTstudents.inorder(BSTstudents.getRoot());
                break;
            }
            case 5: {
                flag = 1;
                break;
            }
            default: {
                cout << "Invalid choice, please make sure you enter one of the available choices!" << endl;
                break;
            }
        }
        if(flag){
            break;
        }
    }
}


void AVLMenu(AVL AVLstudents){
    bool flag = 0;
    while(true) {
        int choice;
        cout << "\n\nChoose one of the following options:" << endl;
        cout
                << "1. Add Student\n2. Remove Student\n3. Search Student\n4. Print All (sorted by id)\n5. Return to main menu\n";
        cout << "Enter number of option: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int id;
                string name, department;
                double gpa;
                cout << "id: ";
                cin >> id;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "GPA: ";
                cin >> gpa;
                cout << "Department: ";
                cin >> department;
                Student stud(id, name, gpa, department);
                AVLstudents.insert(stud);
                cout << "\n The student is added.\n";
                break;
            }
            case 2: {
                int id;
                cout << "id: ";
                cin >> id;
                if (AVLstudents.searchNode(id)) {
                    AVLstudents.deleteNode(id);
                    cout << "Student is deleted. \n";
                }
                break;
            }
            case 3: {
                int id;
                cout << "id: ";
                cin >> id;
                AVLstudents.searchNode(id);
                break;
            }
            case 4: {
                AVLstudents.in_Order(AVLstudents.getRoot());
                break;
            }
            case 5: {
                flag = 1;
                break;
            }
            default: {
                cout << "Invalid choice, please make sure you enter one of the available choices!" << endl;
                break;
            }
        }
        if(flag){
            break;
        }
    }
}

void MinHeapMenu(MinHeap minHeapStudent){
    bool flag = 0;
    while(true) {
        int choice;
        cout << "\n\nChoose one of the following options:" << endl;
        cout << "1. Add Student\n2. Print All (sorted by gpa)\n3. Return to main menu\n";
        cout << "Enter number of option: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int id;
                string name, department;
                double gpa;
                cout << "id: ";
                cin >> id;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "GPA: ";
                cin >> gpa;
                cout << "Department: ";
                cin >> department;
                Student stud(id, name, gpa, department);
                minHeapStudent.insert(stud);
                cout << "\n The student is added.\n";
                break;
            }
            case 2: {
                minHeapStudent.heapSort();
                break;
            }
            case 3: {
                flag = 1;
                break;
            }
            default: {
                cout << "Invalid choice, please make sure you enter one of the available choices!" << endl;
                break;
            }
        }
        if(flag){
            break;
        }
    }
}

void MaxHeapMenu(MaxHeap maxHeapStudent){
    bool flag = 0;
    while(true){
        int choice;
        cout << "\n\nChoose one of the following options:" << endl;
        cout << "1. Add Student\n2. Print All (sorted by gpa)\n3. Return to main menu\n";
        cout << "Enter number of option: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                int id;
                string name, department;
                double gpa;
                cout << "id: ";
                cin >> id;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "GPA: ";
                cin >> gpa;
                cout << "Department: ";
                cin >> department;
                Student stud(id, name, gpa, department);
                maxHeapStudent.insert(stud);
                cout << "\n The student is added.\n";
                break;
            }
            case 2: {
                maxHeapStudent.heapSort();
                break;
            }
            case 3: {
                flag = 1;
                break;
            }
            default:
            {
                cout<<"Invalid choice, please make sure you enter one of the available choices!"<<endl;
                break;
            }
        }
        if(flag){
            break;
        }
    }
}