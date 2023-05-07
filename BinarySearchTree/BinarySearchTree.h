#ifndef STUDENTS_DATA_APPLICATION_BINARYSEARCHTREE_H
#define STUDENTS_DATA_APPLICATION_BINARYSEARCHTREE_H

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
    bool search(const T& el);
    Node<T>* searchNode(const T& el);
    Node<T>* getPreviousNode(const T& el);
    void Delete(const T& el);
    void inorder(Node<T>* r); //needed for testing only
    void preorder(Node<T>* r); //needed for testing only
    void postorder(Node<T>* r); //needed for testing only
};


#endif //STUDENTS_DATA_APPLICATION_BINARYSEARCHTREE_H
