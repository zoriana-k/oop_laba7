#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <type_traits> // ��� std::is_same �� ����� �������� ����

using namespace std;

template <typename T1, typename T2, typename T3, typename T4, typename T5>
class MultiTypeContainer {
private:
    T1 element1;
    T2 element2;
    T3 element3;
    T4 element4;
    T5 element5;

public:
    // �����������
    MultiTypeContainer(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5)
        : element1(e1), element2(e2), element3(e3), element4(e4), element5(e5) {}

    // ����� ��� ��������� ��� ��������
    void displayElements() const {
        cout << "Element 1: " << element1 << endl;
        cout << "Element 2: " << element2 << endl;
        cout << "Element 3: " << element3 << endl;
        cout << "Element 4: " << element4 << endl;
        cout << "Element 5: " << element5 << endl;
    }

    // ����� ��� ���� ��� ��������
    void updateElements(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
        element1 = e1;
        element2 = e2;
        element3 = e3;
        element4 = e4;
        element5 = e5;
    }

    // ����� ��� ��������� ���� �������� ��������
    auto sumNumericElements() const {
        if constexpr (std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2> && std::is_arithmetic_v<T3>) {
            return static_cast<double>(element1) + static_cast<double>(element2) + static_cast<double>(element3);
        }
        else {
            throw logic_error("One or more elements are not numeric.");
        }
    }

    // ����� ��� ������������ ��� ��������� ��������
    string concatenateStrings() const {
        if constexpr (std::is_same_v<T4, string> && std::is_same_v<T5, string>) {
            return element4 + " " + element5;
        }
        else {
            throw logic_error("One or more elements are not strings.");
        }
    }

    // ����� ��� �������� �� ������
    bool areElementsEqual() const {
        if constexpr (std::is_same_v<T4, T5>) {
            return element4 == element5;
        }
        else {
            return false; // ��������� ��������� ��� ����� ����
        }
    }
};