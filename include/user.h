#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string _name;
    std::string _surname;
    int _age;
    std::string _username;
    std::string _password;
    std::string _email;

public:
    // Constructor
    User(const std::string& name, const std::string& surname, int age, const std::string& username, const std::string& password, const std::string& email);

    // Getters
    std::string getName() const;
    std::string getSurname() const;
    int getAge() const;
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getEmail() const;

    // Setters
    void setName(const std::string& name);
    void setSurname(const std::string& surname);
    void setAge(int age);
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setEmail(const std::string& email);
};

// Declare `currentUser` as an external variable
extern User currentUser;

#endif // USER_H
