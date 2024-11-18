#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "person.h"
#include "project.h"
#include "team.h"
#include "employeer.h"

class manager : public person {
private:
    int projectsCount;
    double budget;

public:
    // Конструктор
    manager(const char* name, int age, const char* ID, const std::string& address, const std::string& position, int projectsCount, double budget)
        : person(name, age, ID, address, position), projectsCount(projectsCount), budget(budget) {}

    // Префіксна форма оператора ++: збільшує кількість проєктів
    manager& operator++() {
        ++projectsCount;
        cout << "Prefix ++: Projects count increased to " << projectsCount << endl;
        return *this;
    }

    // Постфіксна форма оператора ++: збільшує бюджет
    manager operator++(int) {
        manager temp = *this;
        budget += 1000;  // додаємо до бюджету
        cout << "Postfix ++: Budget increased to $" << budget << endl;
        return temp;
    }

    // Префіксна форма оператора --: зменшує кількість проєктів
    manager& operator--() {
        if (projectsCount > 0) --projectsCount;
        cout << "Prefix --: Projects count decreased to " << projectsCount << endl;
        return *this;
    }

    // Постфіксна форма оператора --: зменшує бюджет
    manager operator--(int) {
        manager temp = *this;
        if (budget >= 1000) budget -= 1000;
        cout << "Postfix --: Budget decreased to $" << budget << endl;
        return temp;
    }
    manager operator+(double budgetIncrease) const {
        return manager(name.c_str(), age, ID.c_str(), address, position, projectsCount, budget + budgetIncrease);
    }

    manager operator-(double budgetDecrease) const {
        double newBudget = budget - budgetDecrease > 0 ? budget - budgetDecrease : 0;
        return manager(name.c_str(), age, ID.c_str(), address, position, projectsCount, newBudget);
    }
    manager& operator=(const manager& other) {
        if (this == &other) return *this;
        name = other.name;
        age = other.age;
        ID = other.ID;
        address = other.address;
        position = other.position;
        projectsCount = other.projectsCount;
        budget = other.budget;
        return *this;
    }

    manager& operator+=(int projects) {
        projectsCount += projects;
        return *this;
    }

    manager& operator-=(int projects) {
        projectsCount = projectsCount > projects ? projectsCount - projects : 0;
        return *this;
    }

    manager& operator*=(double multiplier) {
        budget *= multiplier;
        return *this;
    }

    double operator*(double multiplier) const {
        return budget * multiplier;
    }

    int operator[](int index) const {
        if (index == 0) return projectsCount;
        throw std::out_of_range("Invalid index for manager!");
    }

    template <typename T>
    T calculateRemainingBudget(T costPerProject, int projectCount) const {
        T totalCost = costPerProject * projectCount;
        return budget > totalCost ? static_cast<T>(budget - totalCost) : 0;
    }

    // Метод для виведення інформації про об'єкт
    void printInfo() const override {
        person::printInfo();
        cout << "Projects count: " << projectsCount << "\nBudget: $" << budget << endl;
    }

    void xxx() const override {
        cout << "i'm tired" << endl;
    }
};
