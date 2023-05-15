#include<bits/stdc++.h>
#include "BinarySearchTree/BinarySearchTree.h"
#include "AVLTree/AVL.h"
#include "MinHeap/MinHeap.h"
#include "MaxHeap/MaxHeap.h"
#include "LoadFile.cpp"
using namespace std;

void displayMainMenu();
void BSTMenu(BinarySearchTree BSTstudents);
void AVLMenu(AVL AVLstudents);
void MaxHeapMenu(MaxHeap maxHeapStudent);
void MinHeapMenu(MinHeap minHeapStudent);

map<string, int> departmentMap;
set<string> departmentSet;
int cnt;

int main(){
    displayMainMenu();
    return 0;
}

void displayMainMenu(){
    LoadFile studentData;
    vector<Student> students = studentData.loadFile();
    while(true){
        cnt = 0;
        departmentMap.clear();
        departmentSet.clear();
        for (const Student& stud: students) {
            departmentMap[stud.getDepartment()]++;
            departmentSet.insert(stud.getDepartment());
            cnt++;
        }
        int choice;
        cout << "\nChoose Data Structure" << endl;
        cout << "1. BST \n2. AVL\n3. Min Heap\n4. Max Heap\n5. Exit Program\n";
        cout << "Your choice: ";
        cin >> choice;
        bool flag = false;
        switch (choice) {
            case 1:
            {
                BinarySearchTree studentsBST;
                for(const Student& student : students){
                    studentsBST.insert(student);
                }
                BSTMenu(studentsBST);
                break;
            }
            case 2:
            {
                AVL studentsAVL;
                for(const Student& student : students){
                    studentsAVL.insert(student);
                }
                AVLMenu(studentsAVL);
                break;
            }
            case 3:
            {
                MinHeap studentsMinHeap;
                for(const Student& student : students){
                    studentsMinHeap.insert(student);
                }
                MinHeapMenu(studentsMinHeap);
                break;
            }
            case 4:
            {
                MaxHeap studentsMaxHeap;
                for(const Student& student : students){
                    studentsMaxHeap.insert(student);
                }
                MaxHeapMenu(studentsMaxHeap);
                break;
            }
            case 5:
            {
                cout<<"Thank you for using our Student data application!"<<endl;
                flag = true;
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
    bool flag = false;
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
                float gpa;
                cout << "id: ";
                cin >> id;
                while(id < 0 || id > 100){
                    cout << "Invalid Id, try again: ";
                    cin >> id;
                }
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "GPA: ";
                cin >> gpa;
                while(gpa < 0 || gpa > 4.0){
                    cout << "Invalid GPA, try again: ";
                    cin >> gpa;
                }
                cout << "Department: ";
                cin >> department;
                cout << "\n";
                Student stud(id, name, gpa, department);
                if(BSTstudents.search(id) == nullptr){
                    BSTstudents.insert(stud);
                    cout << "\nThe student is added.\n";
                    departmentMap[department]++;
                    cnt++;
                } else {
                    cout << "\nThe student already exists, cannot be added.\n";
                }
                break;
            }
            case 2: {
                int id;
                cout << "id: ";
                cin >> id;
                while(id < 0 || id > 100){
                    cout << "Invalid Id, try again: ";
                    cin >> id;
                }
                Node* node = BSTstudents.search(id);
                if (node != nullptr) {
                    cnt--;
                    departmentMap[node->data.getDepartment()]--;
                    BSTstudents.remove(id);
                    cout << "\nStudent is deleted. \n";
                } else {
                    cout << "\nStudent not found." << endl;
                }
                break;
            }
            case 3: {
                int id;
                cout << "id: ";
                cin >> id;
                while(id < 0 || id > 100){
                    cout << "Invalid Id, try again: ";
                    cin >> id;
                }
                BSTstudents.search(id);
                break;
            }
            case 4: {
                BSTstudents.inorder(BSTstudents.getRoot());
                cout << "Total Students Number: " << cnt << "\n";
                cout << "\nStudents per Departments: \n";
                for (const string& set: departmentSet) {
                    cout << set << ": " << departmentMap[set] << "\n";
                }
                break;
            }
            case 5: {
                flag = true;
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
    bool flag = false;
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
                float gpa;
                cout << "id: ";
                cin >> id;
                while(id < 0 || id > 100){
                    cout << "Invalid Id, try again: ";
                    cin >> id;
                }
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "GPA: ";
                cin >> gpa;
                while(gpa < 0 || gpa > 4.0){
                    cout << "Invalid GPA, try again: ";
                    cin >> gpa;
                }
                cout << "Department: ";
                cin >> department;
                cout << "\n";
                Student stud(id, name, gpa, department);
                if(AVLstudents.searchNode(id) == nullptr){
                    AVLstudents.insert(stud);
                    cout << "\nThe student is added.\n";
                    departmentMap[department]++;
                    cnt++;
                } else {
                    cout << "\nThe student already exists, cannot be added.\n";
                }
                break;
            }
            case 2: {
                int id;
                cout << "id: ";
                cin >> id;
                while(id < 0 || id > 100){
                    cout << "Invalid Id, try again: ";
                    cin >> id;
                }
                AVLNode* node = AVLstudents.searchNode(id);
                if (node != nullptr) {
                    cnt--;
                    departmentMap[node->data.getDepartment()]--;
                    AVLstudents.deleteNode(id);
                    cout << "\nStudent is deleted. \n";
                } else {
                    cout << "\nStudent is not found.\n";
                }
                break;
            }
            case 3: {
                int id;
                cout << "id: ";
                cin >> id;
                while(id < 0 || id > 100){
                    cout << "Invalid Id, try again: ";
                    cin >> id;
                }
                AVLstudents.searchNode(id);
                break;
            }
            case 4: {
                AVLstudents.in_Order(AVLstudents.getRoot());
                cout << "Total Students Number: " << cnt << "\n";
                cout << "\nStudents per Departments: \n";
                for (const string& set: departmentSet) {
                    cout << set << ": " << departmentMap[set] << "\n";
                }
                break;
            }
            case 5: {
                flag = true;
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
    bool flag = false;
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
                float gpa;
                cout << "id: ";
                cin >> id;
                while(id < 0 || id > 100){
                    cout << "Invalid Id, try again: ";
                    cin >> id;
                }
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "GPA: ";
                cin >> gpa;
                while(gpa < 0 || gpa > 4.0){
                    cout << "Invalid GPA, try again: ";
                    cin >> gpa;
                }
                cout << "Department: ";
                cin >> department;
                cout << "\n";
                departmentMap[department]++;
                Student stud(id, name, gpa, department);
                minHeapStudent.insert(stud);
                cout << "\n The student is added.\n";
                cnt++;
                break;
            }
            case 2: {
                minHeapStudent.heapSort();
                cout << "Total Students Number: " << cnt << "\n";
                cout << "\nStudents per Departments: \n";
                for (const string& set: departmentSet) {
                    cout << set << ": " << departmentMap[set] << "\n";
                }
                break;
            }
            case 3: {
                flag = true;
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
    bool flag = false;
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
                float gpa;
                cout << "id: ";
                cin >> id;
                while(id < 0 || id > 100){
                    cout << "Invalid Id, try again: ";
                    cin >> id;
                }
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "GPA: ";
                cin >> gpa;
                while(gpa < 0 || gpa > 4.0){
                    cout << "Invalid GPA, try again: ";
                    cin >> gpa;
                }
                cout << "Department: ";
                cin >> department;
                cout << "\n";
                departmentMap[department]++;
                Student stud(id, name, gpa, department);
                maxHeapStudent.insert(stud);
                cout << "\n The student is added.\n";
                cnt++;
                break;
            }
            case 2: {
                maxHeapStudent.heapSort();
                cout << "Total Students Number: " << cnt << "\n";
                cout << "\nStudents per Departments: \n";
                for (const string& set: departmentSet) {
                    cout << set << ": " << departmentMap[set] << "\n";
                }
                break;
            }
            case 3: {
                flag = true;
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