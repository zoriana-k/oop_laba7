#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class person {
protected:
    string name;
    int age;
    string ID;
    string address;
    string position;
    bool isAvailable;

public:
    // ����������� � �����������
    person(const char* name, int age, const char* ID, const string& address, const string& position)
        : name(name), age(age), ID(ID), address(address), position(position), isAvailable(true) {

    }

    // ������ ������� �� ���������� ���� (getter & setter)
    bool getAvailability() const {
        return isAvailable;
    }

    void setAvailability(bool availability) {
        isAvailable = availability;
    }

    // ³��������� ����� ��� �������������� � �������� ������
    virtual void xxx() const = 0;

    virtual void printInfo() const {
        cout << "Person: " << name << ", Age: " << age << ", ID: " << ID << ", Address: " << address << ", Position: " << position << endl;
    }

    void Printing() const {
        cout << "It's a person" << endl;
    }

    // �������� ����� ��� ���� ���
    void updateContactInfo(const char* newID) {
        ID = newID;
    }

    // ����������
    virtual ~person() {
        cout << "Person destroyed\n";
    }
};
