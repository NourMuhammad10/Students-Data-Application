#include "BinarySearchTree.h"
#include<bits/stdc++.h>
using namespace std;


template<class T>
Node<T>::Node(T data) {
    ///Time Complexity O(1)
    this->data = data;
    left = nullptr;
    right = nullptr;
}

template<class T>
BinarySearchTree<T>::BinarySearchTree() {
    ///Time Complexity O(1)
    root = nullptr;
}

template<class T>
void BinarySearchTree<T>::destroyRecursive(Node<T> *node) {
   ///Time Complexity O(n + m), where n is the number of nodes, and m is the number of edges.
    if (node)
    {
        destroyRecursive(node->left);
        destroyRecursive(node->right);
        delete node;
    }
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
    destroyRecursive(root);
}

template<class T>
Node<T> *BinarySearchTree<T>::getRoot() {
    ///Time Complexity O(1)
    return root;
}

template<class T>
Node<T>* BinarySearchTree<T>::insert(Node<T>* node, T el) {
    ///Time Complexity O(h), h stands for height of the tree
    if(node == nullptr){
        Node<T> * newnode = new Node<T>(el);
        node = newnode; //left or right of the appropriate node to insert at
    }
    else if(el < node->data){
        node->left = insert(node->left, el);
    }
    else{
        node->right = insert(node->right, el);
    }
    return node; //placed here as the returned node is the root (recursion process)
}

template<class T>
void BinarySearchTree<T>::insert(const T &el) {
    root = insert(root, el);
}

template<class T>
bool BinarySearchTree<T>::search(const T &el) {
    ///Time Complexity O(h), h stands for height of the tree
    Node<T>* current = root;
    while(current != nullptr){
        if(el == current->data){
            return true;
        }
        else if(el < current->data){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    return false;
}

template<class T>
Node<T> *BinarySearchTree<T>::searchNode(const T &el) {
    ///Time Complexity O(h), h stands for height of the tree
    Node<T>* current = root;
    while(current != nullptr){
        if(el == current->data){
            return current;
        }
        else if(el < current->data){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
}

template<class T>
Node<T> *BinarySearchTree<T>::getPreviousNode(const T &el) {
    ///Time Complexity O(h), h stands for height of the tree
    Node<T>* current = root;
    while(current != nullptr){
        if(current->right->data == el || current->left->data == el){
            return current;
        }
        else if(el < current->data){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
}

template<class T>
void BinarySearchTree<T>::Delete(const T& el) {
    ///Time Complexity O(h), h stands for height of the tree
    Node<T>* node = searchNode(el);
    Node<T>* temp = node;
    Node<T> * prev = node;
    cout<<node->data<<endl;
    if(node->right == nullptr && node->left == nullptr){
        prev = getPreviousNode(el);
        cout<<prev->data<<endl;
        if(prev->right == node){
            delete node;
            prev->right = nullptr;
        }
        else{
            delete node;
            prev->left = nullptr;
        }
        return;
    }
    if(node->right == nullptr){
        node = node->left;
    }
    else if( node->left == nullptr){
        node = node->right;
    }
    else{
        temp = node->left;
        prev = node;
        while(temp->right != nullptr){
            prev = temp;
            temp = temp->right;
        }
        node->data = temp->data;
        if(prev == node){
            prev->left = temp->left;
        }
        else{
            prev->right = temp->left;
        }
    }
    delete temp;
}

template<class T>
void BinarySearchTree<T>::inorder(Node<T> *r) {
    ///Time Complexity O(n + m), where n is the number of nodes, and m is the number of edges.
    if(r != nullptr){
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }
}

template<class T>
void BinarySearchTree<T>::preorder(Node<T>* r){
    ///Time Complexity O(n + m), where n is the number of nodes, and m is the number of edges.
    if(r==nullptr){
        return;
    }
    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
}

template<class T>
void BinarySearchTree<T>::postorder(Node<T> *r) {
    ///Time Complexity O(n + m), where n is the number of nodes, and m is the number of edges.
    if( r != nullptr){
        postorder(r->left);
        postorder(r->right);
        cout<<r->data<<" ";
    }
}
