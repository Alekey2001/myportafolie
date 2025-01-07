#include <iostream>
#include <string>
#include "create.h"

class UserAuthentication {
public:
    UserAuthentication(UserDatabase& db) : database(db) {}

    bool registerUser(const std::string& email, const std::string& password) {
        if (database.userExists(email)) {
            std::cout << "User already exists." << std::endl;
            return false;
        }
        database.addUser(email, password);
        std::cout << "User registered successfully." << std::endl;
        return true;
    }

    bool verifyCredentials(const std::string& email, const std::string& password) {
        return database.verifyUser(email, password);
    }

private:
    UserDatabase& database;
};

int main() {
    UserDatabase db;
    UserAuthentication auth(db);
    std::string email, password;
    int choice;

    std::cout << "1. Register\n2. Login\nEnter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter email: ";
        std::cin >> email;
        std::cout << "Enter password: ";
        std::cin >> password;
        auth.registerUser(email, password);
    } else if (choice == 2) {
        std::cout << "Enter email: ";
        std::cin >> email;
        std::cout << "Enter password: ";
        std::cin >> password;

        if (auth.verifyCredentials(email, password)) {
            std::cout << "Access granted." << std::endl;
        } else {
            std::cout << "Access denied." << std::endl;
        }
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}