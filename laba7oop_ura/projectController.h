#pragma once
#include "manager.h"
#include <iostream>
using namespace std;

class projectController : virtual private manager {//��������� �����������
private:
    int projectProgress; // ³������ �������� �������

public:
    // ����������� � �����������
    projectController(const char* name, int age, const char* ID, const std::string& address, const std::string& position, int projectsCount, double budget, int progress)
        : manager(name, age, ID, address, position, projectsCount, budget), projectProgress(progress) {
        cout << "ProjectController created\n";
    }

    // ������������ ������ �������� ����� ����� �������� using
    using manager::printInfo;

    // ����� ��� ��������� ���������� ��� ������� �������
    void printProjectProgress() const {
        cout << "Project Progress: " << projectProgress << "%" << endl;
    }

    //����������
    ~projectController() {
        cout << "ProjectController destroyed\n";
    }
};
