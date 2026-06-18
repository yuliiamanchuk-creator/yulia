#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
    : Person(), specialty("KI"), course(1), groupName("KI-26")
{
}

Student::Student(const string& fullName, int day, int month, int year, double height, double weight,
    const string& gender, const string& phoneNumber,
    const string& specialty, int course, const string& groupName)
    : Person(fullName, day, month, year, height, weight, gender, phoneNumber),
    specialty(specialty), course(course), groupName(groupName)
{
}

void Student::print() const {
    cout << "[STUDENT] " << getName() << " (Stat: " << getGender() << ")"
        << " | Data narodzhennya: " << getDay() << "." << getMonth() << "." << getYear()
        << " | Tel: " << getPhone()
        << " | Navchaetsya na: " << specialty << ", Kurs: " << course << " [" << groupName << "]" << endl;
}