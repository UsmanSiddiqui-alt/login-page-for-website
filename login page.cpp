#include <iostream>
#include <string>
using namespace std;

// Structure to store user data
struct User {
    string username;
    string password;
};

// Function to display login menu
void displayMenu() {
    cout << "Login Page\n";
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "3. Exit\n";
}

// Function to register new user
void registerUser(User users[], int &size) {
    cout << "Enter username: ";
    cin >> users[size].username;
    cout << "Enter password: ";
    cin >> users[size].password;
    size++;
    cout << "Registration successful!\n";
}

// Function to login existing user
bool loginUser(User users[], int size) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (int i = 0; i < size; i++) {
        if (users[i].username == username && users[i].password == password) {
            cout << "Login successful!\n";
            return true;
        }
    }

    cout << "Invalid credentials!\n";
    return false;
}

int main() {
    User users[100];
    int size = 0;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                if (!loginUser(users, size)) {
                    cout << "Try again!\n";
                } else {
                    return 0;
                }
                break;
            case 2:
                registerUser(users, size);
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}



