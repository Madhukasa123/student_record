// StudentRecordSystem.cpp
#include "StudentRecordSystem.h"
#include <iostream>
#include <algorithm>

void StudentRecordSystem::addStudent(const std::string& name, int rollNumber) {
    students.push_back(Student(name, rollNumber));
}

void StudentRecordSystem::addGrade(int rollNumber, double grade) {
    for (Student& student : students) {
        if (student.getRollNumber() == rollNumber) {
            student.addGrade(grade);
            return;
        }
    }
    std::cout << "Student with roll number " << rollNumber << " not found." << std::endl;
}

void StudentRecordSystem::displayStudentDetails(int rollNumber) const {
    for (const Student& student : students) {
        if (student.getRollNumber() == rollNumber) {
            std::cout << "Name: " << student.getName() << std::endl;
            std::cout << "Roll Number: " << student.getRollNumber() << std::endl;
            std::cout << "Average Grade: " << student.calculateAverageGrade() << std::endl;
            std::cout << "Grades: ";
            for (double grade : student.getGrades()) {
                std::cout << grade << " ";
            }
            std::cout << std::endl;
            return;
        }
    }
    std::cout << "Student with roll number " << rollNumber << " not found." << std::endl;
}

void StudentRecordSystem::sortStudentsByAverageGrade() {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.calculateAverageGrade() > b.calculateAverageGrade();
    });
}

void StudentRecordSystem::displayAllStudentDetails() const {
    for (const Student& student : students) {
        displayStudentDetails(student.getRollNumber());
    }
}
