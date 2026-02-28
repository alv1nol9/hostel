#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    string name;
    char gender; 
    int priority; 
};

struct Room {
    int roomNumber;
    char gender; 
    int capacity;
    vector<Student> occupants;
};

vector<Student> students;
vector<Room> rooms;
vector<Student> waitlist;

void registerStudent() {
    Student s;
    cout << "Enter ID: ";
    cin >> s.id;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Gender (M/F): ";
    cin >> s.gender;
    cout << "Enter Priority (1-3): ";
    cin >> s.priority;
    students.push_back(s);
}

void registerRoom() {
    Room r;
    cout << "Enter Room Number: ";
    cin >> r.roomNumber;
    cout << "Enter Gender Block (M/F): ";
    cin >> r.gender;
    cout << "Enter Capacity: ";
    cin >> r.capacity;
    rooms.push_back(r);
}

bool comparePriority(Student a, Student b) {
    return a.priority < b.priority;
}

void allocateRooms() {
    sort(students.begin(), students.end(), comparePriority);

    for (auto &s : students) {
        bool allocated = false;

        for (auto &r : rooms) {
            if (r.gender == s.gender && r.occupants.size() < r.capacity) {
                r.occupants.push_back(s);
                allocated = true;
                break;
            }
        }

        if (!allocated) {
            waitlist.push_back(s);
        }
    }

    cout << "\nAllocation completed.\n";
}

void displayAllocations() {
    cout << "\n--- ROOM ALLOCATIONS ---\n";
    for (auto &r : rooms) {
        cout << "Room " << r.roomNumber << " (" << r.gender << "):\n";
        for (auto &s : r.occupants) {
            cout << "  " << s.name << " (Priority " << s.priority << ")\n";
        }
    }

    cout << "\n--- WAITLIST ---\n";
    for (auto &s : waitlist) {
        cout << s.name << " (" << s.gender << ", Priority " << s.priority << ")\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\nHOSTEL ALLOCATION SYSTEM\n";
        cout << "1. Register Student\n";
        cout << "2. Register Room\n";
        cout << "3. Allocate Rooms\n";
        cout << "4. Display Allocation Lists\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: registerStudent(); break;
            case 2: registerRoom(); break;
            case 3: allocateRooms(); break;
            case 4: displayAllocations(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while(choice != 0);

    return 0;
}
