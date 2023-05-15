#include "AVL.h"
#include <bits/stdc++.h>
using namespace std;

AVL::AVL(){
    AVLNode* newNode = new AVLNode();
    newNode->parent = nullptr;
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;
    newNode->height = 1;
}

int AVL::max(int a, int b) {
    return (a > b) ? a : b;
}

AVLNode *AVL::getRoot() {
    return root;
}

void AVL::insert(const Student& student) {
    AVLNode* newNode = new AVLNode();
    newNode->data = student;

    /// first item to be inserted
    if(root == nullptr){
        root = newNode;
        return;
    } else {
        /// other items to be inserted
        AVLNode* current = root;
        while (current != nullptr){
            if(current->data < student){
                if(current->rightChild != nullptr && current->rightChild->data != student){
                    current = current->rightChild;
                } else {
                    current->rightChild = newNode;
                    newNode->parent = current;
                    break;
                }
            } else if(current->data > student){
                if(current->leftChild != nullptr && current->leftChild->data != student){
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
        AVLNode* temp = newNode;
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
            return solveViolation(temp);
        }
    }
}


void AVL::deleteNode(int id) {
    AVLNode *temp2;
    if(root == nullptr){
        return;
    } else {
        AVLNode *current = root;

        while (current != nullptr && current->data.getId() != id) {
            if (id < current->data.getId()) {
                current = current->leftChild;
            }
            else {
                current = current->rightChild;
            }
        }

        if (current == nullptr) {
            cout << "Id: " << id << " not found in the provided AVL.\n";
            return;
        }
        /// it has no child or one child
        if (current->leftChild == nullptr || current->rightChild == nullptr) {
            AVLNode *temp;
            if (current->leftChild == nullptr) {
                temp2 = current;
                temp = current->rightChild;
            } else {
                temp2 = current;
                temp = current->leftChild;
            }

            /// there is no child
            if (temp == nullptr) {
                temp = current;
                if(current->data > current->parent->data) {
                    current->parent->rightChild = nullptr;
                }
                else {
                    current->parent->leftChild = nullptr;
                }
            } else {
                temp->parent = current->parent;
                *current = *temp;
            }
            delete temp;
        }
        /// it has two children
        else {
            AVLNode *temp;
            temp = minValueNode(current->rightChild);
            temp2 = temp->parent;
            if(temp->data > temp->parent->data) {
                temp->parent->rightChild = nullptr;
            }
            else {
                temp->parent->leftChild = nullptr;
            }
            current->data = temp->data;
            delete temp;
        }
        updateHeight(temp2);

        AVLNode* temp3 = temp2;
        while (temp3 != nullptr){
            int balance = getBalance(temp3);
            if(balance > 1 || balance < -1){
                solveViolation(temp3);
            }
            temp3 = temp3->parent;
        }
    }
}

AVLNode *AVL::minValueNode(AVLNode* node)
{
    AVLNode* current = node;

    /* loop down to find the leftmost leaf */
    while (current->leftChild != nullptr)
        current = current->leftChild;

    return current;
}

void AVL::solveViolation(AVLNode *temp) {
    int balance = getBalance(temp);
    int rightBalance = getBalance(temp->rightChild);
    int leftBalance = getBalance(temp->leftChild);
    if(balance < -1 && rightBalance < 0){
        leftRotation(temp);
    } else if(balance > 1 && leftBalance > 0) {
        rightRotation(temp);
    }else if(balance > 1 && leftBalance < 0){
        AVLNode* rt = temp;
        AVLNode* rtChild = rt->leftChild;
        AVLNode* leaf = rtChild->rightChild;
        AVLNode* leafLeft = leaf->leftChild;
        leaf->parent = rt;
        rt->leftChild = leaf;
        leaf->leftChild = rtChild;
        rtChild->parent = leaf;
        rtChild->rightChild = leafLeft;
        rightRotation(temp);
    } else if(balance < -1 && rightBalance > 0){
        AVLNode* rt = temp;
        AVLNode* rtChild = rt->rightChild;
        AVLNode* leaf = rtChild->leftChild;
        AVLNode* leafRight = leaf->rightChild;
        leaf->parent = rt;
        rt->rightChild = leaf;
        leaf->rightChild = rtChild;
        rtChild->parent = leaf;
        rtChild->leftChild = leafRight;
        leftRotation(temp);
    }
}

bool AVL::searchNode(int id){
    AVLNode *current = root;

    while (current != nullptr && current->data.getId() != id) {
        if (id < current->data.getId()) {
            current = current->leftChild;
        }
        else {
            current = current->rightChild;
        }
    }
    if (current == nullptr) {
        cout << "Student is not found.\n";
        return false;
    } else {
        cout << "Student is found.\n";
        cout << current->data;
        return true;
    }
}

int AVL::getHeight(AVLNode *node) {
    int leftHeight = 0, rightHeight = 0;
    if(node == nullptr){
        return 0;
    }
    if(node->leftChild != nullptr){
        leftHeight = node->leftChild->height;
    }
    if(node->rightChild != nullptr){
        rightHeight = node->rightChild->height;
    }
    return 1 + max(leftHeight, rightHeight);
}

void AVL::updateHeight(AVLNode* node){
    AVLNode* temp = node->parent;
    while (temp != nullptr){
        temp->height = getHeight(temp);
        temp = temp->parent;
    }
}

int AVL::getBalance(AVLNode *node) {
    int leftHeight = 0, rightHeight = 0;
    if(node == nullptr){
        return 0;
    }
    if(node->leftChild != nullptr){
        leftHeight = node->leftChild->height;
    }
    if(node->rightChild != nullptr){
        rightHeight = node->rightChild->height;
    }
    return leftHeight - rightHeight;
}

void AVL::rightRotation(AVLNode *root) {
    AVLNode* temp = root->leftChild;
    AVLNode* tempRight = temp->rightChild;

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
    AVLNode* newTemp = temp->parent;
    while(newTemp != nullptr){
        newTemp->height = getHeight(newTemp);
        newTemp = newTemp->parent;
    }
}

void AVL::leftRotation(AVLNode *root) {
    AVLNode* temp = root->rightChild;
    AVLNode* tempLeft = temp->leftChild;

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
    AVLNode* newTemp = temp->parent;
    while(newTemp != nullptr){
        newTemp->height = getHeight(newTemp);
        newTemp = newTemp->parent;
    }
}

void AVL::pre_Order(AVLNode *node) {
    if(node != nullptr){
        cout << node->data << "\n";
        pre_Order(node->leftChild);
        pre_Order(node->rightChild);
    }
}

void AVL::post_Order(AVLNode *node) {
    if(node != nullptr){
        post_Order(node->leftChild);
        post_Order(node->rightChild);
        cout << node->data << "\n";
    }
}

void AVL::in_Order(AVLNode *node) {
    if(node != nullptr) {
        in_Order(node->leftChild);
        cout << node->data << "\n";
        in_Order(node->rightChild);
    }
}