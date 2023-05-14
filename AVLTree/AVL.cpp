#include "AVL.h"
#include <bits/stdc++.h>
using namespace std;

template <class T>
AVL<T>::AVL(){
    AVLNode<T>* newNode = new AVLNode<T>();
    newNode->parent = nullptr;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    newNode->height = 1;
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
    AVLNode<T>* newNode = new AVLNode<T>();
    newNode->data = val;

    /// first item to be inserted
    if(root == nullptr){
        root = newNode;
        return;
    } else {
        /// other items to be inserted
        AVLNode<T>* current = root;
        while (current != nullptr){
            if(current->data < val){
                if(current->rightChild != nullptr && current->rightChild->data != val){
                    current = current->rightChild;
                } else {
                    current->rightChild = newNode;
                    newNode->parent = current;
                    break;
                }
            } else if(current->data > val){
                if(current->leftChild != nullptr && current->leftChild->data != val){
                    current = current->leftChild;
                } else {
                    current->leftChild = newNode;
                    newNode->parent = current;
                    break;
                }
            } else {
                cout << "cannot add duplicates\n";
                return;
            }
        }

        /// Updating Height
        updateHeight(newNode);

        /// Check if violation occurs
        bool violation = false;
        AVLNode<T>* temp = newNode;
        while (temp != nullptr){
            int balance = getBalance(temp);
            if(balance > 1 || balance < -1){
                violation = true;
                break;
            }
            temp = temp->parent;
        }

        /// Solve violation
        if(violation){
            return solveViolation(temp, val);
        }
    }
}


template <class T>
void AVL<T>::deleteNode(T val) {
    AVLNode<T> *temp2;
    if(root == nullptr){
        return;
    } else {
        AVLNode<T> *current = root;

        while (current != NULL && current->data != val) {
            if (val < current->data) {
                current = current->leftChild;
            }
            else {
                current = current->rightChild;
            }
        }

        if (current == NULL) {
            cout << "Key " << val << " not found in the provided AVL.\n";
            return;
        }
        /// it has no child or one child
        if (current->leftChild == NULL || current->rightChild == NULL) {
            AVLNode<T> *temp;
            if (current->leftChild == NULL) {
                temp = current->rightChild;
            } else {
                temp = current->leftChild;
            }

            /// there is no child
            if (temp == NULL) {
                temp = current;
                if(current->data > current->parent->data) {
                    current->parent->rightChild = NULL;
                }
                else {
                    current->parent->leftChild = NULL;
                }
                current = NULL;
            } else {
                temp2 = temp->parent;
                temp->parent = current->parent;
                *current = *temp;
            }
            delete temp;
        }
        /// it has two children
        else {
            AVLNode<T> *temp;
            temp = minValueNode(current->rightChild);
            temp2 = temp->parent;
            if(temp->data > temp->parent->data) {
                temp->parent->rightChild = NULL;
            }
            else {
                temp->parent->leftChild = NULL;
            }
            current->data = temp->data;
            delete temp;
        }
        updateHeight(temp2);

        AVLNode<T>* temp3 = temp2;
        while (temp3 != nullptr){
            int balance = getBalance(temp3);
            if(balance > 1 || balance < -1){
                solveViolation(temp3, val);
            }
            temp3 = temp3->parent;
        }
    }
}

template <class T>
AVLNode<T> *AVL<T>::minValueNode(AVLNode<T>* node)
{
    AVLNode<T>* current = node;

    /* loop down to find the leftmost leaf */
    while (current->leftChild != nullptr)
        current = current->leftChild;

    return current;
}

template <class T>
void AVL<T>::solveViolation(AVLNode<T> *temp, T val) {
    int balance = getBalance(temp);
    int rightBalance = getBalance(temp->rightChild);
    int leftBalance = getBalance(temp->leftChild);
    if(balance < -1 && rightBalance < 0){
        leftRotation(temp);
    } else if(balance > 1 && leftBalance > 0) {
        rightRotation(temp);
    }else if(balance > 1 && leftBalance < 0){
        AVLNode<T>* rt = temp;
        AVLNode<T>* rtChild = rt->leftChild;
        AVLNode<T>* leaf = rtChild->rightChild;
        AVLNode<T>* leafLeft = leaf->leftChild;
        leaf->parent = rt;
        rt->leftChild = leaf;
        leaf->leftChild = rtChild;
        rtChild->parent = leaf;
        rtChild->rightChild = leafLeft;
        rightRotation(temp);
    } else if(balance < -1 && rightBalance > 0){
        AVLNode<T>* rt = temp;
        AVLNode<T>* rtChild = rt->rightChild;
        AVLNode<T>* leaf = rtChild->leftChild;
        AVLNode<T>* leafRight = leaf->rightChild;
        leaf->parent = rt;
        rt->rightChild = leaf;
        leaf->rightChild = rtChild;
        rtChild->parent = leaf;
        rtChild->leftChild = leafRight;
        leftRotation(temp);
    }
}

template <class T>
void AVL<T>::searchNode(T val){
    AVLNode<T> *current = root;

    while (current != NULL && current->data != val) {
        if (val < current->data) {
            current = current->leftChild;
        }
        else {
            current = current->rightChild;
        }
    }
    if (current == NULL) {
        cout << "Key " << val << " not found in the provided AVL.\n";
    } else {
        cout << "key is found\n";
    }
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
void AVL<T>::updateHeight(AVLNode<T>* node){
    AVLNode<T>* temp = node->parent;
    while (temp != nullptr){
        temp->height = getHeight(temp);
        temp = temp->parent;
    }
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
void AVL<T>::rightRotation(AVLNode<T> *root) {
    AVLNode<T>* temp = root->leftChild;
    AVLNode<T>* tempRight = temp->rightChild;

    root->leftChild = temp->rightChild;
    if(tempRight != nullptr){
        tempRight->parent = root;
    }
    if(root->parent == nullptr){
        this->root = temp;
    } else if(root == root->parent->rightChild){
        root->parent->rightChild = temp;
    } else {
        root->parent->leftChild = temp;
    }
    temp->parent = root->parent;
    root->parent = temp;
    temp->rightChild = root;

    root->height = getHeight(root);
    temp->height = getHeight(temp);
    AVLNode<T>* newTemp = temp->parent;
    while(newTemp != nullptr){
        newTemp->height = getHeight(newTemp);
        newTemp = newTemp->parent;
    }
}

template <class T>
void AVL<T>::leftRotation(AVLNode<T> *root) {
    AVLNode<T>* temp = root->rightChild;
    AVLNode<T>* tempLeft = temp->leftChild;

    root->rightChild = temp->leftChild;
    if(tempLeft != nullptr){
        tempLeft->parent = root;
    }
    if(root->parent == nullptr){
        this->root = temp;
    } else if(root == root->parent->leftChild){
        root->parent->leftChild = temp;
    } else {
        root->parent->rightChild = temp;
    }
    temp->parent = root->parent;
    root->parent = temp;
    temp->leftChild = root;
    root->height = getHeight(root);
    temp->height = getHeight(temp);
    AVLNode<T>* newTemp = temp->parent;
    while(newTemp != nullptr){
        newTemp->height = getHeight(newTemp);
        newTemp = newTemp->parent;
    }
}

template <class T>
void AVL<T>::pre_Order(AVLNode<T> *node) {
    if(node != nullptr){
        cout << node->data << " ";
        pre_Order(node->leftChild);
        pre_Order(node->rightChild);
    }
}

template <class T>
void AVL<T>::post_Order(AVLNode<T> *node) {
    if(node != nullptr){
        post_Order(node->leftChild);
        post_Order(node->rightChild);
        cout << node->data << " ";
    }
}

template <class T>
void AVL<T>::in_Order(AVLNode<T> *node) {
    if(node != nullptr) {
        in_Order(node->leftChild);
        cout << node->data << " ";
        in_Order(node->rightChild);
    }
}