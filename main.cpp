// main.cpp
#include <iostream>
#include "StudentRecordSystem.h"

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
                std::getline(std::cin, name
