#include<bits/stdc++.h>
#include "BinarySearchTree/BinarySearchTree.cpp"
using namespace std;

int main(){
        BinarySearchTree<int> tree;
        tree.insert(5);
        tree.insert(2);
        tree.insert(12);
        tree.insert(-4);
        tree.insert(3);
        tree.insert(9);
        tree.insert(21);
        tree.insert(19);
        tree.insert(25);
        tree.insert(18);
        tree.insert(20);
        tree.preorder(tree.getRoot());
        cout<<endl;
        cout<<tree.search(25)<<endl;
        cout<<tree.search(7)<<endl;
        tree.Delete(21);
        tree.preorder(tree.getRoot());
}
