#pragma once
#include "manager.h"
#include <iostream>
using namespace std;

class projectController : virtual private manager {//віртуальне наслідування
private:
    int projectProgress; // Відсоток прогресу проекту

public:
    // Конструктор з параметрами
    projectController(const char* name, int age, const char* ID, const std::string& address, const std::string& position, int projectsCount, double budget, int progress)
        : manager(name, age, ID, address, position, projectsCount, budget), projectProgress(progress) {
        cout << "ProjectController created\n";
    }

    // Використання методу базового класу через оператор using
    using manager::printInfo;

    // Метод для виведення інформації про прогрес проекту
    void printProjectProgress() const {
        cout << "Project Progress: " << projectProgress << "%" << endl;
    }

    //Деструктор
    ~projectController() {
        cout << "ProjectController destroyed\n";
    }
};
