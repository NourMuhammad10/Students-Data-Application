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
AVLNode<T>* AVL<T>::insert(T val) {
    AVLNode<T>* newNode = new AVLNode<T>();
    bool isRight = false, isLeft = false;
    newNode->data = val;

    /// first item to be inserted
    if(root == nullptr){
        root = newNode;
        return root;
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
                    isRight = true;
                    break;
                }
            } else if(current->data > val){
                if(current->leftChild != nullptr && current->leftChild->data != val){
                    current = current->leftChild;
                } else {
                    current->leftChild = newNode;
                    newNode->parent = current;
                    isLeft = true;
                    break;
                }
            }
        }

        /// Updating Height
        updateHeight(newNode);

        /// Check if violation occurs
        bool violation = false;
        cout << "\n\nnew insertion:\n";
        AVLNode<T>* temp = newNode;
        while (temp != nullptr){
            int balance = getBalance(temp);
            cout << "Node: " << temp->data << " with balance = " << balance << " and height " << temp->height << "\n";
            if(balance > 1 || balance < -1){
                cout << "Violated at: " << temp->data << " with balance = " << balance << "\n";
                violation = true;
                break;
            }
            temp = temp->parent;
        }

        /// Solve violation
        if(violation){
            int balance = getBalance(temp);
                if(balance < -1 && val > temp->rightChild->data){
                    cout << "RR violation at " << temp->data << "\n";
                    return leftRotation(temp);
                } else if(balance > 1 && val > temp->leftChild->data){
                    cout << "LR violation\n";
                    AVLNode<T>* rt = temp;
                    AVLNode<T>* rtChild = rt->leftChild;
                    AVLNode<T>* leaf = rtChild->rightChild;
                    AVLNode<T>* leafLeft = leaf->leftChild;
                    leaf->parent = rt;
                    rt->leftChild = leaf;
                    leaf->leftChild = rtChild;
                    rtChild->parent = leaf;
                    rtChild->rightChild = leafLeft;
                    return rightRotation(temp);
                } else if(balance > 1 && val < temp->leftChild->data){
                    cout << "LL violation at " << temp->data << "\n";
                    return rightRotation(temp);
                } else if(balance < -1 && val < temp->rightChild->data){
                    cout << "RL violation\n";
                    AVLNode<T>* rt = temp;
                    AVLNode<T>* rtChild = rt->rightChild;
                    AVLNode<T>* leaf = rtChild->leftChild;
                    AVLNode<T>* leafRight = leaf->rightChild;
                    leaf->parent = rt;
                    rt->rightChild = leaf;
                    leaf->rightChild = rtChild;
                    rtChild->parent = leaf;
                    rtChild->leftChild = leafRight;
                    return leftRotation(temp);
                }
            }
        return root;
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
    node->height = 1;
    AVLNode<T>* temp = node;
    while (temp->parent != nullptr){
        temp->parent->height += 1;
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
AVLNode<T> *AVL<T>::rightRotation(AVLNode<T> *root) {
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
    return root;
}

template <class T>
AVLNode<T>* AVL<T>::leftRotation(AVLNode<T> *root) {
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
    return root;

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
    if(node != nullptr){
        in_Order(node->leftChild);
        cout << node->data << " ";
        in_Order(node->rightChild);
    }
}