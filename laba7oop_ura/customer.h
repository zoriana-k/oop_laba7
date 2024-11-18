#pragma once
#include "project.h"
#include "manager.h"
using namespace std;

class customer : public person {
private:
    int projectsOrdered;
    double totalPayment;

public:
    // Конструктор
    customer(const char* name, int age, const char* ID, const std::string& address, const std::string& position, int projectsOrdered, double totalPayment)
        : person(name, age, ID, address, position), projectsOrdered(projectsOrdered), totalPayment(totalPayment) {}
    // Для класу customer
    friend ostream& operator<<(ostream& os, const customer& cust) {
        os << "Name: " << cust.name << ", Age: " << cust.age << ", Nickname: " << cust.ID
            << ", Address: " << cust.address << ", Position: " << cust.position << ", Projects Ordered: " << cust.projectsOrdered
            << ", Total Payment: " << cust.totalPayment;
        return os;
    }

    // Префіксна форма оператора ++: збільшує кількість замовлених проєктів
    customer& operator++() {
        ++projectsOrdered;
        cout << "Prefix ++: Projects ordered increased to " << projectsOrdered << endl;
        return *this;
    }

    // Постфіксна форма оператора ++: збільшує загальний платіж
    customer operator++(int) {
        customer temp = *this;
        totalPayment += 500;  // додаємо до платежу
        cout << "Postfix ++: Total payment increased to $" << totalPayment << endl;
        return temp;
    }

    // Префіксна форма оператора --: зменшує кількість замовлених проєктів
    customer& operator--() {
        if (projectsOrdered > 0) --projectsOrdered;
        cout << "Prefix --: Projects ordered decreased to " << projectsOrdered << endl;
        return *this;
    }

    // Постфіксна форма оператора --: зменшує загальний платіж
    customer operator--(int) {
        customer temp = *this;
        if (totalPayment >= 500) totalPayment -= 500;
        cout << "Postfix --: Total payment decreased to $" << totalPayment << endl;
        return temp;
    }
    customer operator+(double amount) const {
        return customer(name.c_str(), age, ID.c_str(), address, position, projectsOrdered, totalPayment + amount);
    }

    customer operator-(double amount) const {
        double newTotalPayment = totalPayment - amount > 0 ? totalPayment - amount : 0;
        return customer(name.c_str(), age, ID.c_str(), address, position, projectsOrdered, newTotalPayment);
    }
    customer& operator=(const customer& other) {
        if (this == &other) return *this;
        name = other.name;
        age = other.age;
        ID = other.ID;
        address = other.address;
        position = other.position;
        projectsOrdered = other.projectsOrdered;
        totalPayment = other.totalPayment;
        return *this;
    }

    customer& operator+=(int projects) {
        projectsOrdered += projects;
        return *this;
    }

    customer& operator-=(int projects) {
        projectsOrdered = projectsOrdered > projects ? projectsOrdered - projects : 0;
        return *this;
    }

    customer& operator*=(double multiplier) {
        totalPayment *= multiplier;
        return *this;
    }

    double operator*(double multiplier) const {
        return totalPayment * multiplier;
    }

    int operator[](int index) const {
        if (index == 0) return projectsOrdered;
        throw std::out_of_range("Invalid index for customer!");
    }

    // Метод для виведення інформації про об'єкт
    void printInfo() const override {
        person::printInfo();
        cout << "Projects ordered: " << projectsOrdered << "\nTotal payment: $" << totalPayment << endl;
    }

    void xxx() const override {
        cout << "omg" << endl;
    }
};
