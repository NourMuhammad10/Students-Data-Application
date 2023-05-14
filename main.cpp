#include<bits/stdc++.h>
#include "BinarySearchTree/BinarySearchTree.cpp"
#include "AVLTree/AVL.cpp"
using namespace std;

int main(){
//        BinarySearchTree<int> tree;
//        tree.insert(5);
//        tree.insert(2);
//        tree.insert(12);
//        tree.insert(-4);
//        tree.insert(3);
//        tree.insert(9);
//        tree.insert(21);
//        tree.insert(19);
//        tree.insert(25);
//        tree.insert(18);
//        tree.insert(20);
//        tree.preorder(tree.getRoot());
//        cout<<endl;
//        cout<<tree.search(25)<<endl;
//        cout<<tree.search(7)<<endl;
//        tree.Delete(21);
//        tree.preorder(tree.getRoot());



    AVL<int> tree;
//    tree.insert(10);
//    tree.insert(20);
//    tree.insert(5);
//    tree.insert(2);
//    tree.insert(9);
//    tree.insert(6);
//    tree.deleteNode(5);

    tree.insert(40);
    tree.insert(30);
    tree.insert(50);
    tree.insert(25);
    tree.insert(35);
    tree.insert(15);
    tree.insert(28);
    tree.insert(45);
    tree.insert(60);
    tree.insert(55);
    tree.insert(70);
    tree.deleteNode(35);
    tree.deleteNode(40);
    tree.deleteNode(28);
    tree.deleteNode(25);
    tree.pre_Order(tree.getRoot());
    tree.deleteNode(50);
}
