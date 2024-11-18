#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <type_traits> // для std::is_same та інших перевірок типів

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
    // Конструктор
    MultiTypeContainer(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5)
        : element1(e1), element2(e2), element3(e3), element4(e4), element5(e5) {}

    // Метод для виведення всіх елементів
    void displayElements() const {
        cout << "Element 1: " << element1 << endl;
        cout << "Element 2: " << element2 << endl;
        cout << "Element 3: " << element3 << endl;
        cout << "Element 4: " << element4 << endl;
        cout << "Element 5: " << element5 << endl;
    }

    // Метод для зміни всіх елементів
    void updateElements(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
        element1 = e1;
        element2 = e2;
        element3 = e3;
        element4 = e4;
        element5 = e5;
    }

    // Метод для отримання суми числових елементів
    auto sumNumericElements() const {
        if constexpr (std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2> && std::is_arithmetic_v<T3>) {
            return static_cast<double>(element1) + static_cast<double>(element2) + static_cast<double>(element3);
        }
        else {
            throw logic_error("One or more elements are not numeric.");
        }
    }

    // Метод для конкатенації всіх строкових елементів
    string concatenateStrings() const {
        if constexpr (std::is_same_v<T4, string> && std::is_same_v<T5, string>) {
            return element4 + " " + element5;
        }
        else {
            throw logic_error("One or more elements are not strings.");
        }
    }

    // Метод для перевірки на рівність
    bool areElementsEqual() const {
        if constexpr (std::is_same_v<T4, T5>) {
            return element4 == element5;
        }
        else {
            return false; // Порівняння неможливе для інших типів
        }
    }
};