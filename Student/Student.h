#ifndef STUDENTS_DATA_APPLICATION_STUDENT_H
#define STUDENTS_DATA_APPLICATION_STUDENT_H

#include<bits/stdc++.h>
using namespace std;

class Student {
    int id;
    string name;
    float gpa;
    string department;
public:
    Student(){
        id = -1;
    }
    Student(int id, string name, float gpa, string department);
    void setId(int id);
    void setName(string name);
    void setGpa(float gpa);
    void setDepartment(string department);
    int getId() const;
    string getName()const;
    float getGpa() const;
    string getDepartment()const;
    void displayStudentData();
    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;
    bool operator==(const Student& other) const;
    bool operator!=(const Student& other) const;
    friend ostream& operator<<(std::ostream& os, const Student& student);
};


#endif //STUDENTS_DATA_APPLICATION_STUDENT_H
