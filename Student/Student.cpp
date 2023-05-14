#include "Student.h"

Student::Student(int id, string name, float gpa, string department) {
    this->id = id;
    this->name = name;
    this->gpa = gpa;
    this->department = department;
}
void Student::setId(int id) {
    this->id = id;
}
string Student::getName() const {
    return name;
}

void Student::setName(string name) {
    this->name = name;
}
void Student::setGpa(float gpa) {
    this->gpa = gpa;
}

void Student::setDepartment(string department) {
    this->department = department;
}

int Student::getId() const {
    return id;
}

float Student::getGpa() const {
    return gpa;
}
string Student::getDepartment() const {
    return department;
}

void Student::displayStudentData() {
    cout<<"["<<id<<", "<<name<<", "<<gpa<<", "<<department<<"]";
}

bool Student::operator<(const Student &other) const {
    return id < other.getId();
}

bool Student::operator>(const Student &other) const {
    return id > other.getId();
}

bool Student::operator==(const Student &other) const {
    return id == other.getId();
}
//ostream &operator<<(ostream &os, Student student) {
//    os<<"["<<student.getId()<<", "<<student.getName()<<", "<<student.getGpa()<<", "<<student.getDepartment()<<"]";
//    return os;
//}







