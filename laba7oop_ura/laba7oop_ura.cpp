#include <iostream>
#include <fstream>
#include <stdexcept>
#include "manager.h"
#include "project.h"
#include "customer.h"
#include "employeer.h"
#include "team.h"
#include "resourceManager.h"
#include "teamLeader.h"
#include "projectController.h"
#include "MultiTypeContainer.h"
#include "resource.h"
#include <queue>
#include <vector>
#include <iterator> 
#include <algorithm>
#include <numeric> 
using namespace std;

void processProject(const project& p) {
    cout << "Processing project: " << p.name << endl;
    cout << "Customer: " << p.customer << endl;
    cout << "Budget: " << p.budget << endl;
}

void processProject(const project* p) {
    if (p) {
        cout << "Processing project: " << p->name << endl;
        cout << "Customer: " << p->customer << endl;
        cout << "Budget: " << p->budget << endl;
    }
}

void processProjectPointer(const project* p) {
    cout << "Processing project by pointer: " << p->name << endl;
    cout << "Customer: " << p->customer << endl;
    cout << "Budget: " << p->budget << endl;
}
void displayInfo(const person& person) {
    person.printInfo(); // Поліморфний виклик
}

void xxxx(person* p) {
    p->xxx(); // Поліморфний виклик
}

#include <iostream>
#include <vector>
#include <algorithm>

// Функтори
struct EqualTo {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a == b;
    }
};

struct NotEqualTo {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a != b;
    }
};

struct Greater {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a > b;
    }
};

struct Less {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

struct GreaterEqual {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a >= b;
    }
};

struct LessEqual {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a <= b;
    }
};


int main() {
    // Черга для робітників
    queue<employeer> myQueue;
    employeer emp1("Nadia Suska", 28, "Angel", "101 Pine St", "Developer", 3, 5000);
    employeer emp2("Lisovska Viktoria", 35, "Fairy", "202 Maple St", "Marketer", 5, 6000);
    employeer emp3("Borishchuk Sophia", 29, "Borshch", "303 Birch St", "Tester", 2, 4000);
    myQueue.push(emp1);
    myQueue.push(emp2);
    myQueue.push(emp3);
    cout << "The first element in the queue: " << myQueue.front() << endl;
    cout << "Deleting: " << myQueue.front() <<endl;
    myQueue.pop();
    cout << "New first element after deletion: " << myQueue.front() << endl;

    // Вихідний контейнер для клієнтів
    vector<customer> outputContainer;
    customer inputData[] = {
        customer("Zotova Alina", 33, "KvaCommision", "789 Oak St", "Customer", 1, 50000),
        customer("Plutach Iryna", 25, "CatAndShrek", "12 Yugi St", "Customer", 1, 70000),
        customer("Palyanytsia Ivanna", 38, "PalyanytsiaBakery", "18 Uk St", "Customer", 2, 80000)
    };
    copy(begin(inputData), end(inputData), back_inserter(outputContainer));
    cout << "Items in the source container: ";
    for (const auto& elem : outputContainer) {
        cout << elem << endl;
    }

    // Початкові дані для сортування
    vector<int> numbers = { 5, 2, 8, 1, 10, 3 };
    // Сортування
    sort(numbers.begin(), numbers.end());
    cout << "After sorting: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;
    // Пошук елемента
    int valueToFind = 8;
    auto it = find(numbers.begin(), numbers.end(), valueToFind);
    if (it != numbers.end())
        cout << "Element " << valueToFind << " found in position "
        << distance(numbers.begin(), it) << endl;
    else
        cout << "Element " << valueToFind << " not found" << endl;
    // Обхід елементів
    cout << "Squares of elements: ";
    for_each(numbers.begin(), numbers.end(), [](int num) {
        cout << num * num << " ";
        });
    cout << endl;
    // Агрегація
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum of elements: " << sum << endl;
    // Зворотний порядок
    reverse(numbers.begin(), numbers.end());
    cout << "In reverse order: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    // Використання функторів
    int x = 10, y = 20;
    EqualTo equalTo;
    NotEqualTo notEqualTo;
    Greater greater;
    Less less;
    GreaterEqual greaterEqual;
    LessEqual lessEqual;
    cout << "x == y: " << equalTo(x, y) << endl;
    cout << "x != y: " << notEqualTo(x, y) << endl;
    cout << "x > y: " << greater(x, y) << endl;
    cout << "x < y: " << less(x, y) << endl;
    cout << "x >= y: " << greaterEqual(x, y) << endl;
    cout << "x <= y: " << lessEqual(x, y) << endl;
}
