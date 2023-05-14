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
    ///Time Complexity O(N)
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
    ///Time Complexity O(h), h stands for height of the tree
    root = insert(root, el);
}

template<class T>
Node<T> *BinarySearchTree<T>::searchNode(Node<T> *node, T data) {
    ///Time Complexity O(h), h stands for height of the tree
    if (node == nullptr) {
        return nullptr;
    }
    else if (data == node->data) {
        return node;
    }
    else if (data < node->data) {
        return searchNode(node->left, data);
    }
    else {
        return searchNode(node->right, data);
    }
}
template<class T>
T BinarySearchTree<T>::search(T data) {
    ///Time Complexity O(h), h stands for height of the tree
    Node<T>* node = searchNode(root, data);
    if (node == nullptr) {
       cout<<"Data not found"<<endl;
    }
    else {
        return node->data;
    }
}
template<class T>
Node<T>* BinarySearchTree<T>:: findMin(Node<T>* node) {
    ///Time Complexity O(h), h stands for height of the tree
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
template<class T>
Node<T>* BinarySearchTree<T>::deleteNode(Node<T> *node, T data) {
    ///Time Complexity O(N)
    if (node == nullptr){
        return nullptr;
    }
    else if (data < node->data) {
        node->left = deleteNode(node->left, data);
    }
    else if (data > node->data) {
        node->right = deleteNode(node->right, data);
    }
    else {
        //Node has no children
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        //Node has one child on the right
        else if (node->left == nullptr) {
            Node<T>* temp = node;
            node = node->right;
            delete temp;
        }
        //Node has one child on the left
        else if (node->right == nullptr) {
            Node<T>* temp = node;
            node = node->left;
            delete temp;
        }
        // Node has two children
        else {
            Node<T>* minRight = findMin(node->right);
            node->data = minRight->data;
            //uses the function again to search for the position of the minright and delete it
            node->right = deleteNode(node->right, minRight->data);
        }
    }
    return node;
}


template<class T>
void BinarySearchTree<T>::remove(T data) {
    ///Time Complexity O(N)
    root = deleteNode(root, data);
}

template<class T>
void BinarySearchTree<T>::inorder(Node<T> *r) {
    ///Time Complexity O(N)
    if(r != nullptr){
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }
}

template<class T>
void BinarySearchTree<T>::preorder(Node<T>* r){
    ///Time Complexity O(N)
    if(r==nullptr){
        return;
    }
    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
}

template<class T>
void BinarySearchTree<T>::postorder(Node<T> *r) {
    ///Time Complexity O(N)
    if( r != nullptr){
        postorder(r->left);
        postorder(r->right);
        cout<<r->data<<" ";
    }
}
//template<class T>
//void BinarySearchTree<T>:: inOrderTraversal(Node<T>* root, vector<T>& sorted) {
//    if (root == nullptr) {
//        return;
//    }
//
//    inOrderTraversal(root->left, sorted);
//    sorted.push_back(root->data);
//    inOrderTraversal(root->right, sorted);
//}
//template<class T>
//vector<T>  BinarySearchTree<T>::sortBinarySearchTree(Node<T>* root) {
//    vector<T> sorted;
//    inOrderTraversal(root, sorted);
//    return sorted;
//}
