#pragma once
#include "employeer.h"
#include "team.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class project {
public:
    static int totalBudget;
    char name[256];
    char customer[256];
    int budget;
    vector<employeer> teamMembers;  // ������ ����������
    vector<Team> teams;  // ������ ������

    project() : budget(0) {
        strcpy_s(name, "");
        strcpy_s(customer, "");
    }

    project(const char* name, const char* customer, int budget) : budget(budget) {
        strcpy_s(this->name, name);
        strcpy_s(this->customer, customer);
    }

    project(const project& other) : budget(other.budget) {
        strcpy_s(this->name, other.name);
        strcpy_s(this->customer, other.customer);
        this->teamMembers = other.teamMembers;
        this->teams = other.teams;
    }

    ~project() {
        cout << "Project destroyed\n";
    }

    static void increaseTotalBudget(int amount) {
        totalBudget += amount;
    }

    static void printTotalBudget() {
        cout << "Total Project Budget: " << totalBudget << endl;
    }

    void addEmployeer(const employeer& e) {
        teamMembers.push_back(e);
    }

    // ����� ��� ��������� ������� �� �������
    void addTeam(const Team& t) {
        teams.push_back(t);
    }

    void printEmployeer() const {
        cout << "Employeers in project \"" << name << "\":\n";
        for (const auto& employeer : teamMembers) {
            employeer.printInfo();
        }
        cout << "-------------------\n";
    }//��������� ���������� ��� ����������, �� �� �������� �� ������
};
