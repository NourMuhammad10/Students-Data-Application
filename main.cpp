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
}

void displayMainMenu(){
    LoadFile studentData;
    vector<Student> students = studentData.loadFile();

    int choice;
    cout << "\n\nChoose Data Structure" << endl;
    cout << "1. BST \n2. AVL\n3. Min Heap\n4. Max Heap\n5. Exit Program\n";
    cout << "Your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
        {
            BinarySearchTree studentsBST;
            for(Student student : students){
                studentsBST.insert(student);
            }
            BSTMenu(studentsBST);
            return;
        }
        case 2:
        {
            AVL studentsAVL;
            for(Student student : students){
                studentsAVL.insert(student);
            }
            AVLMenu(studentsAVL);
            return;
        }
        case 3:
        {
            MinHeap studentsMinHeap;
            for(Student student : students){
                studentsMinHeap.insert(student);
            }
            MinHeapMenu(studentsMinHeap);
            return;
        }
        case 4:
        {
            MaxHeap studentsMaxHeap;
            for(Student student : students){
                studentsMaxHeap.insert(student);
            }
            MaxHeapMenu(studentsMaxHeap);
            return;
        }
        case 5:
        {
            cout<<"Thank you for using our Student data application!"<<endl;
            return;
        }
        default:
        {
            cout<<"Invalid choice, please make sure you enter one of the available choices!"<<endl;
            displayMainMenu();
            return;
        }
    }
}

void BSTMenu(BinarySearchTree BSTstudents){
    LoadFile studentData;
    vector<Student> students = studentData.loadFile();
    int choice;
    cout << "\n\nChoose one of the following options:" << endl;
    cout << "1. Add Student\n2. Remove Student\n3. Search Student\n4. Print All (sorted by id)\n5. Return to main menu\n";
    cout << "Enter number of option: ";
    cin >> choice;
    switch(choice){
        case 1:
        {
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
            BSTMenu(BSTstudents);
            return;
        }
        case 2:
        {
            int id;
            cout << "id: ";
            cin >> id;
            if(BSTstudents.search(id)){
                BSTstudents.remove(id);
                cout << "Student is deleted. \n";
            }
            BSTMenu(BSTstudents);
            return;
        }
        case 3:
        {
            int id;
            cout << "id: ";
            cin >> id;
            BSTstudents.search(id);
            BSTMenu(BSTstudents);
            return;
        }
        case 4:
        {
            BSTstudents.inorder(BSTstudents.getRoot());
            BSTMenu(BSTstudents);
            return;
        }
        case 5:
        {
            displayMainMenu();
            return;
        }
        default:
        {
            cout<<"Invalid choice, please make sure you enter one of the available choices!"<<endl;
            BSTMenu(BSTstudents);
            return;
        }
    }
}


void AVLMenu(AVL AVLstudents){
    LoadFile studentData;
    vector<Student> students = studentData.loadFile();
    int choice;
    cout << "\n\nChoose one of the following options:" << endl;
    cout << "1. Add Student\n2. Remove Student\n3. Search Student\n4. Print All (sorted by id)\n5. Return to main menu\n";
    cout << "Enter number of option: ";
    cin >> choice;
    switch(choice){
        case 1:
        {
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
            AVLMenu(AVLstudents);
            return;
        }
        case 2:
        {
            int id;
            cout << "id: ";
            cin >> id;
            if(AVLstudents.searchNode(id)){
                AVLstudents.deleteNode(id);
                cout << "Student is deleted. \n";
            }
            AVLMenu(AVLstudents);
            return;
        }
        case 3:
        {
            int id;
            cout << "id: ";
            cin >> id;
            AVLstudents.searchNode(id);
            AVLMenu(AVLstudents);
            return;
        }
        case 4:
        {
            AVLstudents.in_Order(AVLstudents.getRoot());
            AVLMenu(AVLstudents);
            return;
        }
        case 5:
        {
            displayMainMenu();
            return;
        }
        default:
        {
            cout<<"Invalid choice, please make sure you enter one of the available choices!"<<endl;
            AVLMenu(AVLstudents);
            return;
        }
    }
}

void MinHeapMenu(MinHeap minHeapStudent){
    LoadFile studentData;
    vector<Student> students = studentData.loadFile();
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
            minHeapStudent.insert(stud);
            cout << "\n The student is added.\n";
            MinHeapMenu(minHeapStudent);
            return;
        }
        case 2: {
            minHeapStudent.heapSort();
            MinHeapMenu(minHeapStudent);
            return;
        }
        case 3: {
            displayMainMenu();
            return;
        }
        default:
        {
            cout<<"Invalid choice, please make sure you enter one of the available choices!"<<endl;
            MinHeapMenu(minHeapStudent);
            return;
        }
    }
}

void MaxHeapMenu(MaxHeap maxHeapStudent){
    LoadFile studentData;
    vector<Student> students = studentData.loadFile();
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
            MaxHeapMenu(maxHeapStudent);
            return;
        }
        case 2: {
            maxHeapStudent.heapSort();
            MaxHeapMenu(maxHeapStudent);
            return;
        }
        case 3: {
            displayMainMenu();
            return;
        }
        default:
        {
            cout<<"Invalid choice, please make sure you enter one of the available choices!"<<endl;
            MaxHeapMenu(maxHeapStudent);
            return;
        }
    }
}