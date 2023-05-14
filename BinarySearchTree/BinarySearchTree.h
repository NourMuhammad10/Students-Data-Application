#ifndef STUDENTS_DATA_APPLICATION_BINARYSEARCHTREE_H
#define STUDENTS_DATA_APPLICATION_BINARYSEARCHTREE_H

#include<bits/stdc++.h>
using namespace std;
template<class T>
class Node{
public:
    T data;
    Node* left;
    Node* right;
    Node(T data);
};

template<class T>
class BinarySearchTree {
    Node<T>* root;
public:
    BinarySearchTree();
    void destroyRecursive(Node<T>* node);
    ~BinarySearchTree();
    Node<T>* getRoot();
    Node<T>* insert (Node<T>* node, T el);
    void insert(const T& el);
    Node<T>* searchNode(Node<T>* node, T data);
    T search(T data);
    Node<T>* findMin(Node<T>* node);
    Node<T>* deleteNode(Node<T>* node, T data);
    void remove(T data);
    void inorder(Node<T>* r);
    void preorder(Node<T>* r);
    void postorder(Node<T>* r);
//    //For sorting the BST
//    void inOrderTraversal(Node<T>* root, vector<T>& sorted);
//    vector<T> sortBinarySearchTree(Node<T>* root);
};



#endif //STUDENTS_DATA_APPLICATION_BINARYSEARCHTREE_H
