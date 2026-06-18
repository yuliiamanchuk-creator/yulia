#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>

class Student : public Person {
private:
    std::string specialty;
    int course;
    std::string groupName;

public:
    Student();
    Student(const std::string& fullName, int day, int month, int year, double height, double weight,
        const std::string& gender, const std::string& phoneNumber,
        const std::string& specialty, int course, const std::string& groupName);

    void print() const override;
};

#endif // STUDENT_H