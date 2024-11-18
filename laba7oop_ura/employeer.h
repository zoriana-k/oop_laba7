#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "person.h"

class employeer : public person {
private:
    int experience;
    int taskBudget;
    bool isActive;
    vector<string> assignedTasks;

public:
    // Конструктор
    employeer(const char* name, int age, const char* ID, const std::string& address, const std::string& position, int experience, int taskBudget)
        : person(name, age, ID, address, position), experience(experience), taskBudget(taskBudget), isActive(true) {}

    
    employeer operator+(int experienceGain) const {
        return employeer(name.c_str(), age, ID.c_str(), address, position, experience + experienceGain, taskBudget);
    }

    employeer operator-(int experienceLoss) const {
        int newExperience = experience - experienceLoss > 0 ? experience - experienceLoss : 0;
        return employeer(name.c_str(), age, ID.c_str(), address, position, newExperience, taskBudget);
    }
    employeer& operator=(const employeer& other) {
        if (this == &other) return *this;
        name = other.name;
        age = other.age;
        ID = other.ID;
        address = other.address;
        position = other.position;
        experience = other.experience;
        taskBudget = other.taskBudget;
        return *this;
    }

    employeer& operator+=(int experienceGain) {
        experience += experienceGain;
        return *this;
    }

    employeer& operator-=(int experienceLoss) {
        experience = experience > experienceLoss ? experience - experienceLoss : 0;
        return *this;
    }

    employeer& operator*=(double multiplier) {
        taskBudget = static_cast<int>(taskBudget * multiplier);
        return *this;
    }

    int operator[](int index) const {
        if (index == 0) return experience;
        if (index == 1) return taskBudget;
        throw out_of_range("Invalid index for employeer!");
    }
    // Для класу employeer
    friend ostream& operator<<(ostream& os, const employeer& emp) {
        os << "Name: " << emp.name << ", Age: " << emp.age << ", ID: " << emp.ID
            << ", Address: " << emp.address << ", Position: " << emp.position
            << ", Experience: " << emp.experience << ", Task budget: " << emp.taskBudget;
        return os;
    }

    // Метод для виведення інформації про об'єкт
    void printInfo() const override {
        person::printInfo();
        cout << "Experience: " << experience << " years\nTask Budget: $" << taskBudget << endl;
    }

    void xxx() const override {
        cout << "i wanna sleep" << endl;
    }
};
