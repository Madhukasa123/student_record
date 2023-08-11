// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
public:
    Student(const std::string& name, int rollNumber);
    void addGrade(double grade);
    double calculateAverageGrade() const;
    std::string getName() const;
    int getRollNumber() const;
    const std::vector<double>& getGrades() const;

private:
    std::string name;
    int rollNumber;
    std::vector<double> grades;
};

#endif
