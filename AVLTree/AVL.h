#ifndef STUDENTS_DATA_APPLICATION_AVL_H
#define STUDENTS_DATA_APPLICATION_AVL_H
#include "../Student/Student.h"

struct AVLNode{
    Student data;
    int height;
    AVLNode* leftChild;
    AVLNode* rightChild;
    AVLNode* parent;
    AVLNode(){
        rightChild = nullptr;
        leftChild = nullptr;
        parent = nullptr;
        height = 1;
    }
};

class AVL {
private:
    AVLNode* root = nullptr;
public:
    AVL();
    void insert(const Student& student);
    void deleteNode(int id);
    AVLNode* getRoot();
    void setRoot(AVLNode* rt){
        this->root = rt;
    }
    int max(int a, int b);
    int getHeight(AVLNode *node);
    void updateHeight(AVLNode* node);
    int getBalance(AVLNode *node);
    bool searchNode(int id);
    AVLNode* minValueNode(AVLNode* node);
    void solveViolation(AVLNode* node);
    void leftRotation(AVLNode *v);
    void rightRotation(AVLNode *v);
    void pre_Order(AVLNode* node);
    void post_Order(AVLNode* node);
    void in_Order(AVLNode* node);
};

//1. Add a student (write the id “from 0 to 100”, name, GPA, and department)
//2. Remove a student using id
//3. Search for student using id (if found print the student information)
//4. Print all and Department Report (all the information of students are printed sorted by id and
//        count students per department)


#endif //STUDENTS_DATA_APPLICATION_AVL_H
