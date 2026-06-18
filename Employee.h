#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <string>

class Employee : public Person {
private:
    std::string company;
    std::string position;
    double salary;

public:
    Employee();
    Employee(const std::string& fullName, int day, int month, int year, double height, double weight,
        const std::string& gender, const std::string& phoneNumber,
        const std::string& company, const std::string& position, double salary);

    void print() const override;
};

#endif // EMPLOYEE_H