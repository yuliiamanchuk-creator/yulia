#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee()
    : Person(), company("Nevidomo"), position("Nevidomo"), salary(0.0)
{
}

Employee::Employee(const string& fullName, int day, int month, int year, double height, double weight,
    const string& gender, const string& phoneNumber,
    const string& company, const string& position, double salary)
    : Person(fullName, day, month, year, height, weight, gender, phoneNumber),
    company(company), position(position), salary(salary)
{
}

void Employee::print() const {
    cout << "[ROBITNYK] " << getName() << " (" << getGender() << ")"
        << " | Data narodzhennya: " << getDay() << "." << getMonth() << "." << getYear()
        << " | Zrist: " << getHeight() << " cm | Vaga: " << getWeight() << " kg"
        << " | Tel: " << getPhone()
        << " | Misce roboty: " << company << " | Posada: " << position
        << " | Zarplata: " << salary << " grn" << endl;
}