#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "Student.h"
#include "Employee.h"

using namespace std;

vector<Person*> people;

void printAll() {
    if (people.empty()) {
        cout << "Spysok porozhniy!\n";
        return;
    }
    cout << "\n--- VSI ZAPYSI V SYSTEMI ---\n";
    for (size_t i = 0; i < people.size(); ++i) {
        cout << i + 1 << ". ";
        people[i]->print();
    }
}

void addStudent() {
    string fullName, gender, phoneNumber, specialty, groupName;
    int day = 0, month = 0, year = 0;
    int course = 1;
    double height = 0;
    double weight = 0;

    cout << "\n-- Vvedit dani studenta --\n";
    cout << "PIB: "; cin.ignore(); getline(cin, fullName);

    cout << "Rik narodzhennya (1950-2026): "; cin >> year;
    while (year < 1950 || year > 2026) {
        cout << "[POMYLKA!] Vvedit realniy rik: "; cin >> year;
    }

    cout << "Misyac narodzhennya (1-12): "; cin >> month;
    while (month < 1 || month > 12) {
        cout << "[POMYLKA!] Misyaciv buvae tilky 12: "; cin >> month;
    }

    cout << "Den narodzhennya: "; cin >> day;
    int maxDays = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) maxDays = 30;
    else if (month == 2) maxDays = 29;

    while (day < 1 || day > maxDays) {
        cout << "[POMYLKA!] U tsomu misyaci dniv mozhe buty vid 1 do " << maxDays << ": "; cin >> day;
    }

    cout << "Zrist (vid 50 do 250 cm): "; cin >> height;
    while (height < 50 || height > 250) {
        cout << "[POMYLKA!] Vvedit realniy zrist: "; cin >> height;
    }

    cout << "Vaga (vid 2 do 300 kg): "; cin >> weight;
    while (weight < 2 || weight > 300) {
        cout << "[POMYLKA!] Vvedit realnu vagu: "; cin >> weight;
    }

    cout << "Stat: "; cin >> gender;
    cout << "Telefon (10 cyfr, napryklad 0671234567): "; cin >> phoneNumber;

    cout << "Specialnist: "; cin.ignore(); getline(cin, specialty);
    cout << "Kurs: "; cin >> course;
    cout << "Grupa: "; cin >> groupName;

    people.push_back(new Student(fullName, day, month, year, height, weight, gender, phoneNumber, specialty, course, groupName));
    cout << "Studenta uspihno dodano!\n";
}

void addEmployee() {
    string fullName, gender, phoneNumber, company, position;
    int day = 0, month = 0, year = 0;
    double height = 0;
    double weight = 0;
    double salary = 0;

    cout << "\n-- Vvedit dani robitnyka --\n";
    cout << "PIB: "; cin.ignore(); getline(cin, fullName);

    cout << "Rik narodzhennya (1950-2026): "; cin >> year;
    while (year < 1950 || year > 2026) {
        cout << "[POMYLKA!] Vvedit realniy rik: "; cin >> year;
    }

    cout << "Misyac narodzhennya (1-12): "; cin >> month;
    while (month < 1 || month > 12) {
        cout << "[POMYLKA!] Misyaciv buvae tilky 12: "; cin >> month;
    }

    cout << "Den narodzhennya: "; cin >> day;
    int maxDays = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) maxDays = 30;
    else if (month == 2) maxDays = 29;

    while (day < 1 || day > maxDays) {
        cout << "[POMYLKA!] U tsomu misyaci dniv mozhe buty vid 1 do " << maxDays << ": "; cin >> day;
    }

    cout << "Zrist (vid 50 do 250 cm): "; cin >> height;
    while (height < 50 || height > 250) {
        cout << "[POMYLKA!] Vvedit realniy zrist: "; cin >> height;
    }

    cout << "Vaga (vid 2 do 300 kg): "; cin >> weight;
    while (weight < 2 || weight > 300) {
        cout << "[POMYLKA!] Vvedit realnu vagu: "; cin >> weight;
    }

    cout << "Stat: "; cin >> gender;
    cout << "Telefon (10 cyfr, napryklad 0671234567): "; cin >> phoneNumber;

    cout << "Companiya: "; cin.ignore(); getline(cin, company);
    cout << "Posada: "; getline(cin, position);
    cout << "Zarplata: "; cin >> salary;

    people.push_back(new Employee(fullName, day, month, year, height, weight, gender, phoneNumber, company, position, salary));
    cout << "Robitnyka uspihno dodano!\n";
}

void searchPerson() {
    if (people.empty()) {
        cout << "Nemae kogo shukaty, spysok porozhniy.\n";
        return;
    }
    cout << "Vvedit PIB dlya poshuku: ";
    cin.ignore();
    string searchName;
    getline(cin, searchName);

    bool found = false;
    for (size_t i = 0; i < people.size(); ++i) {
        if (people[i]->getName().find(searchName) != string::npos) {
            people[i]->print();
            found = true;
        }
    }
    if (!found) {
        cout << "Lyudynu z takym im'yam ne znaydeno.\n";
    }
}

void deletePerson() {
    if (people.empty()) {
        cout << "Spysok porozhniy.\n";
        return;
    }
    printAll();
    cout << "Vvedit nomer elementa, yakiy hochete vydalyty: ";
    int index;
    cin >> index;

    if (index > 0 && index <= (int)people.size()) {
        int vectorIndex = index - 1;

        delete people[vectorIndex];
        people.erase(people.begin() + vectorIndex);

        cout << "Element uspihno vydaleno.\n";
    }
    else {
        cout << "Nekorektniy nomer!\n";
    }
}

void cleanup() {
    for (size_t i = 0; i < people.size(); ++i) {
        delete people[i];
    }
    people.clear();
}

int main() {
    people.push_back(new Student("Kovalenko Oleksiy Petrovych", 12, 5, 2004, 185, 78, "cholovicha", "0671234567", "Kompyuterna inzheneriya", 1, "KI-11"));
    people.push_back(new Employee("Marchenko Iryna Vasylivna", 3, 9, 1990, 165, 58, "zhinocha", "+380501112233", "TOV Tehnologii", "Rozrobnyk", 45000));
    people.push_back(new Student("Veleten Maksym Olehovych", 20, 11, 2003, 205, 100, "cholovicha", "0991234567", "Kompyuterna inzheneriya", 1, "KI-12"));

    int choice = -1;

    while (choice != 0) {
        cout << "\n===== GOLOVNE MENU =====\n";
        cout << "1. Vyvesty vsih ludey\n";
        cout << "2. Dodaty studenta\n";
        cout << "3. Dodaty robitnyka\n";
        cout << "4. Poshuk za PIB\n";
        cout << "5. Vydalyty za nomerom\n";
        cout << "0. Vyhid\n";
        cout << "Vash vybir: ";
        cin >> choice;

        if (choice == 1) {
            printAll();
        }
        else if (choice == 2) {
            addStudent();
        }
        else if (choice == 3) {
            addEmployee();
        }
        else if (choice == 4) {
            searchPerson();
        }
        else if (choice == 5) {
            deletePerson();
        }
        else if (choice == 0) {
            cout << "Programa zavershena. Do pobachennya!\n";
        }
        else {
            cout << "Nepravylyniy vybir, sprobuyte sche raz.\n";
        }
    }

    cleanup();
    return 0;
}