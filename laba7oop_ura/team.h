#pragma once
#include <string>
#include <vector>
#include "Resource.h"

class Team {
private:
    string teamName;
    vector<string> members;
    double budget;
    vector<Resource> allocatedResources;

public:
    Team(const string& name = "Default Team", double budget = 0.0)
        : teamName(name), budget(budget) {}

    void addMember(const string& memberName) {
        members.push_back(memberName);
    }

    void allocateResource(const Resource& resource) {
        allocatedResources.push_back(resource);
    }

    void displayInfo() const {
        cout << "Team: " << teamName << endl;
        cout << "Budget: $" << budget << endl;
        cout << "Members: ";
        for (const auto& member : members)
            cout << member << " ";
        cout << endl;
        cout << "Resources:" << endl;
        for (const auto& resource : allocatedResources)
            cout << resource << endl;
    }

    bool operator==(const Team& other) const {
        return teamName == other.teamName && budget == other.budget;
    }

    friend ostream& operator<<(ostream& os, const Team& team) {
        os << "Team [Name: " << team.teamName << ", Budget: $" << team.budget << "]";
        return os;
    }
};