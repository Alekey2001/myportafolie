#include <unordered_map>
#include <string>

class UserDatabase {
public:
    UserDatabase() {
        // Sample user data
        users["admin"] = "password123";
        users["user"] = "mypassword";
    }

    bool userExists(const std::string& email) {
        return users.find(email) != users.end();
    }

    bool verifyUser(const std::string& email, const std::string& password) {
        auto it = users.find(email);
        return it != users.end() && it->second == password;
    }

    void addUser(const std::string& email, const std::string& password) {
        users[email] = password;
    }

private:
    std::unordered_map<std::string, std::string> users;
};