// StudentRecordSystem.h
#ifndef STUDENT_RECORD_SYSTEM_H
#define STUDENT_RECORD_SYSTEM_H

#include <vector>
#include "Student.h"

class StudentRecordSystem {
public:
    void addStudent(const std::string& name, int rollNumber);
    void addGrade(int rollNumber, double grade);
    void displayStudentDetails(int rollNumber) const;
    void sortStudentsByAverageGrade();
    void displayAllStudentDetails() const;

private:
    std::vector<Student> students;
};

#endif
