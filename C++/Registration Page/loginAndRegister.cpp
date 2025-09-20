#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string fileName = "file.txt";

void saveUser(string &username, string &pass) {
    ofstream out(fileName, ios::app);
    out << username << "," << pass << endl;
}

void splitUserAndPass(string l, string &u, string &pass) {
    bool commaFound = false;
    u = "";
    pass = "";

    for (int i = 0; i < l.length(); i++) {
        if (l[i] == ',') {   
            commaFound = true;
            continue;
        }

        if (!commaFound)
            u += l[i];
        else
            pass += l[i];
    }
}

bool usernameCheck(const string &username) {
    ifstream in(fileName);
    string storedUser, storedPassword, line;

    while (getline(in, line)) {
        splitUserAndPass(line, storedUser, storedPassword);
        if (storedUser == username) {
            return false; 
        }
    }
    return true; 
}

void registerUser() {
    string username, pass;

    cout << "\n\t\t--User Registration--\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> pass;

    if (!usernameCheck(username)) {
        cout << "Error! Username already exists...";
        return;
    }

    saveUser(username, pass);
    cout << "Registration successful...";
}

void loginUser() {
    string username, pass;
    cout << "\n\t\t--- User Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> pass;

    ifstream infile(fileName);
    string storedUser, storedPass, line;
    bool success = false;

    while (getline(infile, line)) {
        splitUserAndPass(line, storedUser, storedPass);
        if (storedUser == username && storedPass == pass) {
            success = true;
            break;
        }
    }

    if (success) {
        cout << "Login successful! Welcome, " << username << "!\n";
    } else {
        cout << "Error: Invalid username or password.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n\t\t--- Login & Registration System ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
