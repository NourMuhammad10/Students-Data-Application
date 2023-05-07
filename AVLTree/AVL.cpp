#include "AVL.h"

template <class T>
AVL<T>::AVL(T data){
    AVLNode<T>* newNode = new AVLNode<T>();
    newNode->parent = nullptr;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    newNode->height = 1;
    newNode->data = data;
}

template <class T>
int AVL<T>::max(int a, int b) {
    return (a > b) ? a : b;
}

template <class T>
AVLNode<T> *AVL<T>::getRoot() {
    return root;
}

template <class T>
void AVL<T>::insert(T val) {

}

template <class T>
int AVL<T>::getHeight(AVLNode<T> *node) {
    int leftHeight = 0, rightHeight = 0;
    if(node->leftChild != nullptr){
        leftHeight = node->leftChild->height;
    }
    if(node->rightChild != nullptr){
        rightHeight = node->rightChild->height;
    }
    return 1 + max(leftHeight, rightHeight);
}

template <class T>
int AVL<T>::getBalance(AVLNode<T> *node) {
    int leftHeight = 0, rightHeight = 0;
    if(node->leftChild != nullptr){
        leftHeight = node->leftChild->height;
    }
    if(node->rightChild != nullptr){
        rightHeight = node->rightChild->height;
    }
    return leftHeight - rightHeight;
}

template <class T>
AVLNode<T> *AVL<T>::leftRotation(AVLNode<T> *v) {
    AVLNode<T>* vParent = v->parent;
    AVLNode<T>* u = v->leftChild;
    AVLNode<T>* leftU = u->leftChild;
    u->parent = vParent;
    u->leftChild = v;
    v->parent = u;
    v->rightChild = leftU;
    v->height = 1 + max(v->leftChild->height, v->rightChild->height);
    u->height = 1 + max(u->leftChild->height, u->rightChild->height);
    return u;
}