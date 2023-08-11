// Student.cpp
#include "Student.h"

Student::Student(const std::string& name, int rollNumber) : name(name), rollNumber(rollNumber) {}

void Student::addGrade(double grade) {
    grades.push_back(grade);
}

double Student::calculateAverageGrade() const {
    if (grades.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (double grade : grades) {
        sum += grade;
    }
    return sum / grades.size();
}

std::string Student::getName() const {
    return name;
}

int Student::getRollNumber() const {
    return rollNumber;
}

const std::vector<double>& Student::getGrades() const {
    return grades;
}
