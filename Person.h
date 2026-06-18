#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string fullName;
    int day, month, year;
    double height;
    double weight;
    std::string gender;
    std::string phoneNumber;

    void formatPhone();

public:
    Person();
    Person(const std::string& fullName, int day, int month, int year,
        double height, double weight, const std::string& gender, const std::string& phoneNumber);

    void changePhone(const std::string& newPhone);
    bool isTall() const;

    std::string getName() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    double getHeight() const;
    double getWeight() const;
    std::string getGender() const;
    std::string getPhone() const;

    virtual void print() const;
    virtual ~Person();
};

#endif // PERSON_H