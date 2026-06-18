#include "Person.h"
#include <iostream>

using namespace std;

Person::Person()
    : fullName("Nevidomo"), day(1), month(1), year(2000),
    height(0.0), weight(0.0), gender("nevidomo"), phoneNumber("")
{
}

Person::Person(const string& fullName, int day, int month, int year,
    double height, double weight, const string& gender, const string& phoneNumber)
    : fullName(fullName), day(day), month(month), year(year),
    height(height), weight(weight), gender(gender), phoneNumber(phoneNumber)
{
    formatPhone();
}

void Person::formatPhone() {
    if (phoneNumber.length() == 10 && phoneNumber[0] == '0') {
        phoneNumber = "+38" + phoneNumber;
    }
    else if (phoneNumber.length() != 13 || phoneNumber[0] != '+') {
        phoneNumber = "Nekorektniy nomer";
    }
}

void Person::changePhone(const string& newPhone) {
    phoneNumber = newPhone;
    formatPhone();
}

bool Person::isTall() const {
    return height > 200;
}

string Person::getName() const { return fullName; }
int Person::getDay() const { return day; }
int Person::getMonth() const { return month; }
int Person::getYear() const { return year; }
double Person::getHeight() const { return height; }
double Person::getWeight() const { return weight; }
string Person::getGender() const { return gender; }
string Person::getPhone() const { return phoneNumber; }

void Person::print() const {
    cout << fullName << " | " << day << "." << month << "." << year
        << " | Zrist: " << height << " cm | Vaga: " << weight << " kg"
        << " | Stat: " << gender << " | Tel: " << phoneNumber
        << " | Zrist > 200: " << (isTall() ? "Tak" : "Ni");
}

Person::~Person() {}