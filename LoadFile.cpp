#include<bits/stdc++.h>
#include "Student/Student.h"
using namespace std;

class LoadFile {
public:
    vector<Student> loadFile() {
        ifstream file("InputFile.txt");
        vector<Student> students;
        string line;
        getline(file, line);
        if (file.is_open()) {
            while (getline(file, line)) {
                Student student;
                student.setId(stoi(line));
                getline(file, line);
                student.setName(line);
                getline(file, line);
                student.setGpa(stof(line));
                getline(file, line);
                student.setDepartment(line);
                students.push_back(student);
            }
            file.close();
        }
        return students;
    }
};