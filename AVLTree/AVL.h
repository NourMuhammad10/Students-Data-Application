#ifndef STUDENTS_DATA_APPLICATION_AVL_H
#define STUDENTS_DATA_APPLICATION_AVL_H
template<class T>
struct AVLNode{
    T data;
    int height;
    AVLNode* leftChild;
    AVLNode* rightChild;
    AVLNode* parent;
    AVLNode(T data){
        rightChild = nullptr;
        rightChild = nullptr;
        parent = nullptr;
        height = 1;
        this->data = data;
    }
};

template<class T>
class AVL {
private:
    AVLNode<T>* root;
public:
    AVL(T data);
    void insert(T val);
    AVLNode<T>* getRoot();
    int max(int a, int b);
    int getHeight(AVLNode<T> *node);
    int getBalance(AVLNode<T> *node);
    AVLNode<T>* leftRotation(AVLNode<T> *v);
};

//1. Add a student (write the id “from 0 to 100”, name, GPA, and department)
//2. Remove a student using id
//3. Search for student using id (if found print the student information)
//4. Print all and Department Report (all the information of students are printed sorted by id and
//        count students per department)


#endif //STUDENTS_DATA_APPLICATION_AVL_H
