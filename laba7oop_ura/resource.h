#pragma once
#include <string>
#include <iostream>
using namespace std;

class Resource {
private:
    string name;
    string type;
    double cost; // Вартість ресурсу
    bool allocated; // Чи використовується ресурс

public:
    Resource(const string& name = "Unknown", const string& type = "General", double cost = 0.0)
        : name(name), type(type), cost(cost), allocated(false) {}

    void allocate() {
        allocated = true;
        cout << "Resource \"" << name << "\" allocated." << endl;
    }

    void release() {
        allocated = false;
        cout << "Resource \"" << name << "\" released." << endl;
    }

    bool isAllocated() const {
        return allocated;
    }

    double getCost() const {
        return cost;
    }

    string getInfo() const {
        return "Resource: " + name + ", Type: " + type + ", Cost: " + to_string(cost);
    }

    bool operator==(const Resource& other) const {
        return name == other.name && type == other.type && cost == other.cost;
    }

    friend ostream& operator<<(ostream& os, const Resource& resource) {
        os << "Resource [Name: " << resource.name << ", Type: " << resource.type
            << ", Cost: $" << resource.cost << ", Allocated: "
            << (resource.allocated ? "Yes" : "No") << "]";
        return os;
    }
};