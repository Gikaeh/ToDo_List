#include <iostream>
#include "toDo.h"

using namespace std;

int main() {
    int choice = 0, position;
    string item;
    ToDo<string> homework;

    while (choice != 5) {
        cout << "Please select what to do:\n1. Add a new task\n2. Delete a task\n3. Show all tasks\n4. Clear all tasks\n5. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Where would you like this numbered on the list: ";
                cin >> position;
                cout << "What is this item called: ";
                getline(cin, item);
                getline(cin, item);
                homework.insert(position, item);
                break;
            case 2:
                cout << "Which item would you like to remove(enter number): ";
                cin >> position;
                homework.remove(position);
                break;
            case 3:
                homework.showAll();
                break;
            case 4:
                homework.clear();
                break;
            case 5:
                cout << "Goodbye." << endl;
                homework.~ToDo();
                break;
            default:
                cout << "Invalid input must be between 1 and 5" << endl;
                break;
        }
    }
}