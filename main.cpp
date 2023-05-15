#include<bits/stdc++.h>
#include "BinarySearchTree/BinarySearchTree.cpp"
#include "AVLTree/AVL.h"
#include "MinHeap/MinHeap.cpp"
#include "LoadFile.cpp"
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



    AVL tree;
    Student student1(1, "merna", 3.73, "AI");
    Student student2(2, "merna2", 3.73, "IS");
    Student student3(3, "merna3", 3.73, "CS");
    Student student4(4, "merna4", 3.73, "DS");
    Student student5(5, "merna5", 3.73, "IT");
    Student student6(6, "merna6", 3.73, "AI");
    Student student7(7, "merna7", 3.73, "AI");
    Student student8(8, "merna8", 3.73, "CS");
    Student student9(9, "merna9", 3.73, "CS");
    Student student10(10, "merna10", 3.73, "CS");
    Student student11(11, "merna11", 3.73, "CS");
    Student student12(12, "merna12", 3.73, "CS");
    Student student13(13, "merna13", 3.73, "CS");

    tree.insert(student3);
    tree.insert(student1);
    tree.insert(student8);
    tree.insert(student5);
    tree.insert(student2);
    tree.insert(student4);
    tree.insert(student7);
    tree.insert(student13);
    tree.insert(student10);
    tree.insert(student12);
    tree.insert(student11);
    tree.pre_Order(tree.getRoot());
    tree.deleteNode(12);
    tree.deleteNode(13);
    tree.deleteNode(5);
    tree.deleteNode(8);
    cout << endl;
    tree.pre_Order(tree.getRoot());

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
