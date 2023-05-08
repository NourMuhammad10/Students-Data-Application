#ifndef STUDENTS_DATA_APPLICATION_AVL_H
#define STUDENTS_DATA_APPLICATION_AVL_H
template<class T>
struct AVLNode{
    T data;
    int height;
    AVLNode* leftChild;
    AVLNode* rightChild;
    AVLNode* parent;
    AVLNode(){
        rightChild = nullptr;
        leftChild = nullptr;
        parent = nullptr;
        height = 1;
//        this->data = data;
    }
};

template<class T>
class AVL {
private:
    AVLNode<T>* root = nullptr;
public:
    AVL();
    AVLNode<T>* insert(T val);
    AVLNode<T>* getRoot();
    void setRoot(AVLNode<T>* rt){
        this->root = rt;
    }
    int max(int a, int b);
    int getHeight(AVLNode<T> *node);
    void updateHeight(AVLNode<T>* node);
//    void checkViolation();
    int getBalance(AVLNode<T> *node);
    AVLNode<T>* leftRotation(AVLNode<T> *v);
    AVLNode<T>* rightRotation(AVLNode<T> *v);
    void pre_Order(AVLNode<T>* node);
    void post_Order(AVLNode<T>* node);
    void in_Order(AVLNode<T>* node);
};

//1. Add a student (write the id “from 0 to 100”, name, GPA, and department)
//2. Remove a student using id
//3. Search for student using id (if found print the student information)
//4. Print all and Department Report (all the information of students are printed sorted by id and
//        count students per department)


#endif //STUDENTS_DATA_APPLICATION_AVL_H
