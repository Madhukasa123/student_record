#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Student {
public:
    Student(const std::string& name, int rollNumber) : name(name), rollNumber(rollNumber) {}

    void addGrade(double grade) {
        grades.push_back(grade);
    }

    double calculateAverageGrade() const {
        if (grades.empty()) {
            return 0.0;
        }

        double sum = 0.0;
        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }

    std::string getName() const {
        return name;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    const std::vector<double>& getGrades() const {
        return grades;
    }

private:
    std::string name;
    int rollNumber;
    std::vector<double> grades;
};

class StudentRecordSystem {
public:
    void addStudent(const std::string& name, int rollNumber) {
        students.push_back(Student(name, rollNumber));
    }

    void addGrade(int rollNumber, double grade) {
        for (Student& student : students) {
            if (student.getRollNumber() == rollNumber) {
                student.addGrade(grade);
                return;
            }
        }
        std::cout << "Student with roll number " << rollNumber << " not found." << std::endl;
    }

    void displayStudentDetails(int rollNumber) const {
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

    void sortStudentsByAverageGrade() {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.calculateAverageGrade() > b.calculateAverageGrade();
        });
    }

    void displayAllStudentDetails() const {
        for (const Student& student : students) {
            displayStudentDetails(student.getRollNumber());
        }
    }

private:
    std::vector<Student> students;
};

int main() {
    StudentRecordSystem recordSystem;

    int choice;
    do {
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Grade\n";
        std::cout << "3. Display Student Details\n";
        std::cout << "4. Sort Students by Average Grade\n";
        std::cout << "5. Display All Student Details\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                int rollNumber;
                std::cout << "Enter student name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter roll number: ";
                std::cin >> rollNumber;
                recordSystem.addStudent(name, rollNumber);
                break;
            }
            case 2: {
                int rollNumber;
                double grade;
                std::cout << "Enter roll number: ";
                std::cin >> rollNumber;
                std::cout << "Enter grade: ";
                std::cin >> grade;
                recordSystem.addGrade(rollNumber, grade);
                break;
            }
            case 3: {
                int rollNumber;
                std::cout << "Enter roll number: ";
                std::cin >> rollNumber;
                recordSystem.displayStudentDetails(rollNumber);
                break;
            }
            case 4: {
                recordSystem.sortStudentsByAverageGrade();
                std::cout << "Students sorted by average grade." << std::endl;
                break;
            }
            case 5: {
                recordSystem.displayAllStudentDetails();
                break;
            }
            case 6:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

        std::cin.ignore();
    } while (choice != 6);

    return 0;
}
