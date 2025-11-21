#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    int id;
    string name;
    string email;
};

int main() {
    int opt = 1;
    int num = 0;

    while (opt != 2) {
        cout << "Enter number of students: ";
        cin >> num;

        vector<Student> students(num);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < num; i++) {
            cout << "\n--- Student " << i + 1 << " Details ---\n";

            cout << "Enter name: ";
            cin >> students[i].name;
            cout << "Enter id: ";
            cin >> students[i].id;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter email: ";
            cin >> students[i].email;
        }

        cout << "\n\n--- Displaying All Student Records ---\n";
        for (int i = 0; i < num; i++) {
            cout << "\nStudent " << i + 1 << " Details:\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "ID: " << students[i].id << "\n";
            cout << "Email: " << students[i].email << "\n";
        }
        cout << "\n----------------------------------------\n";

        cout << "Continue? (1 FOR YES, 2 FOR NO): ";
        if (!(cin >> opt)) {
            cout << "Invalid option. \n";
            opt = 2;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return 0;
}