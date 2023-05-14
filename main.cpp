#include<bits/stdc++.h>
#include "BinarySearchTree/BinarySearchTree.cpp"
#include "AVLTree/AVL.cpp"
#include "MinHeap/MinHeap.cpp"
#include "Student/Student.h"
#include"LoadFile.cpp"
using namespace std;

void displayMainMenu();
void BSTMenu();

int main(){
//        BinarySearchTree<int> tree;
//        tree.insert(5);
//        tree.insert(2);
//        tree.insert(12);
//        tree.insert(-4);
//        tree.insert(3);
//        tree.insert(9);
//        tree.insert(21);
//        tree.insert(19);
//        tree.insert(25);
//        tree.insert(18);
//        tree.insert(20);
//        tree.preorder(tree.getRoot());
//        cout<<endl;
//        cout<<tree.search(25)<<endl;
//        cout<<tree.search(7)<<endl;
//        tree.Delete(21);
//        tree.preorder(tree.getRoot());



    AVL<int> tree;
//    tree.insert(10);
//    tree.insert(20);
//    tree.insert(5);
//    tree.insert(2);
//    tree.insert(9);
//    tree.insert(6);
//    tree.deleteNode(5);

    tree.insert(40);
    tree.insert(30);
    tree.insert(50);
    tree.insert(25);
    tree.insert(35);
    tree.insert(15);
    tree.insert(28);
    tree.insert(45);
    tree.insert(60);
    tree.insert(55);
    tree.insert(70);
    tree.deleteNode(35);
    tree.deleteNode(40);
    tree.deleteNode(28);
    tree.deleteNode(25);
    tree.pre_Order(tree.getRoot());
    tree.deleteNode(50);
}

void displayMainMenu(){
    LoadFile studentData;
    vector<Student> students = studentData.loadFile();
    for(auto student: students){
        student.displayStudentData();
        cout<<endl;
    }
    int choice;
    cout<<"Choose Data Structure"<<endl;
    cout<<"1. BST \n2. AVL\n3. Min Heap\n4. Max Heap\n5. Exit Program\n";
    cout<<"Your choice: ";
    cin>>choice;
    switch (choice) {
        case 1:
        {
//            BinarySearchTree<Student> studentsBST;
//            for( Student student : students){
//                studentsBST.insert(student);
//            }
            break;
        }
//        case 2:
//        {
//            break;
//        }
//        case 3:
//        {
//            break;
//        }
//        case 4:
//        {
//            break;
//        }
        case 5:
        {
            cout<<"Thank you for using our Student data application!"<<endl;
            break;
        }
        default:
        {
            cout<<"Invalid choice, please make sure you enter one of the available choices!"<<endl;
            displayMainMenu();
        }
    }
}

//void BSTMenu(){
//    int choice;
//    cout<<"Choose one of the following options:"<<endl;
//    cout<<"1. Add Student\n2. Remove Student\n3. Search Student\n4. Print All (sorted by id)\n5. Return to main menu\n";
//    cout<<"Your choice: ";
//    cin>>choice;
//    switch(choice){
//        case 1:
//        {
//            break;
//        }
//        case 2:
//        {
//            break;
//        }
//        case 3:
//        {
//            break;
//        }
//        case 4:
//        {
//            break;
//        }
//        case 5:
//        {
//            break;
//        }
//        default:
//        {
//            cout<<"Invalid choice, please make sure you enter one of the available choices!"<<endl;
//            BSTMenu();
//        }
//    }
//}
