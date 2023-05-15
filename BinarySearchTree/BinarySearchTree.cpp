#include "BinarySearchTree.h"
#include<bits/stdc++.h>
using namespace std;


Node::Node(Student data) {
    ///Time Complexity O(1)
    this->data = data;
    left = nullptr;
    right = nullptr;
}

BinarySearchTree::BinarySearchTree() {
    ///Time Complexity O(1)
    root = nullptr;
}


Node *BinarySearchTree::getRoot() {
    ///Time Complexity O(1)
    return root;
}

Node* BinarySearchTree::insert(Node* node, Student el) {
    ///Time Complexity O(h), h stands for height of the tree
    if(node == nullptr){
        Node * newnode = new Node(el);
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

void BinarySearchTree::insert(const Student &el) {
    ///Time Complexity O(h), h stands for height of the tree
    root = insert(root, el);
}

Node *BinarySearchTree::searchNode(Node *node, int  id) {
    ///Time Complexity O(h), h stands for height of the tree
    if (node == nullptr) {
        return nullptr;
    }
    else if (id == node->data.getId()) {
        return node;
    }
    else if (id < node->data.getId()) {
        return searchNode(node->left, id);
    }
    else {
        return searchNode(node->right, id);
    }
}
bool BinarySearchTree::search(int id) {
    ///Time Complexity O(h), h stands for height of the tree
    Node* node = searchNode(root, id);
    Student std =  Student();
    if (node == nullptr) {
       cout << "Student not found." << endl;
    }
    else {
        cout << "Student is found." << endl;
        cout << node->data;
    }
}
Node* BinarySearchTree:: findMin(Node* node) {
    ///Time Complexity O(h), h stands for height of the tree
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
Node* BinarySearchTree::deleteNode(Node *node, int  id) {
    ///Time Complexity O(N)
    if (node == nullptr){
        return nullptr;
    }
    else if (id < node->data.getId()) {
        node->left = deleteNode(node->left, id);
    }
    else if (id > node->data.getId()) {
        node->right = deleteNode(node->right, id);
    }
    else {
        //Node has no children
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        //Node has one child on the right
        else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        //Node has one child on the left
        else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        // Node has two children
        else {
            Node* minRight = findMin(node->right);
            node->data = minRight->data;
            //uses the function again to search for the position of the minright and delete it
            node->right = deleteNode(node->right, minRight->data.getId());
        }
    }
    return node;
}


void BinarySearchTree::remove(int id) {
    ///Time Complexity O(N)
    root = deleteNode(root, id);
}


void BinarySearchTree::inorder(Node *r) {
    ///Time Complexity O(N)
    if(r != nullptr){
        inorder(r->left);
        cout<<r->data<<"\n";
        inorder(r->right);
    }
}

void BinarySearchTree::preorder(Node* r){
    ///Time Complexity O(N)
    if(r==nullptr){
        return;
    }
    cout<<r->data<<endl;
    preorder(r->left);
    preorder(r->right);
}

void BinarySearchTree::postorder(Node *r) {
    ///Time Complexity O(N)
    if( r != nullptr){
        postorder(r->left);
        postorder(r->right);
        cout<<r->data<<" ";
    }
}
////void BinarySearchTree<T>:: inOrderTraversal(Node* root, vector<T>& sorted) {
//    if (root == nullptr) {
//        return;
//    }
//
//    inOrderTraversal(root->left, sorted);
//    sorted.push_back(root->data);
//    inOrderTraversal(root->right, sorted);
//}
////vector<T>  BinarySearchTree<T>::sortBinarySearchTree(Node* root) {
//    vector<T> sorted;
//    inOrderTraversal(root, sorted);
//    return sorted;
//}
