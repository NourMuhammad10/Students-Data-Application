#ifndef STUDENTS_DATA_APPLICATION_BINARYSEARCHTREE_H
#define STUDENTS_DATA_APPLICATION_BINARYSEARCHTREE_H
#include"../Student/Student.h"
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    Student data;
    Node* left;
    Node* right;
    Node(Student data);
};


class BinarySearchTree {
    Node* root;
public:
    BinarySearchTree();
    Node* getRoot();
    Node* insert (Node* node, Student el);
    void insert(const Student& el);
    Node *searchNode(Node *node, int id);
    Node* search(int id);
    Node* findMin(Node* node);
    Node *deleteNode(Node *node, int id);
    void remove(int id);
    void inorder(Node* r);
    void preorder(Node* r);
    void postorder(Node* r);
//    //For sorting the BST
//    void inOrderTraversal(Node* root, vector<T>& sorted);
//    vector<T> sortBinarySearchTree(Node* root);

};



#endif //STUDENTS_DATA_APPLICATION_BINARYSEARCHTREE_H
