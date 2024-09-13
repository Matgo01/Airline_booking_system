#include "user.h"

// Constructor implementation
User::User(const std::string& name, const std::string& surname, int age, const std::string& username, const std::string& password, const std::string& email) 
: _name(name), _surname(surname), _age(age), _username(username), _password(password), _email(email) {
}

User currentUser("DefaultName", "DefaultSurname", 0, "DefaultUsername", "DefaultPassword", "DefaultEmail");

// Getter implementations
std::string User::getName() const {
    return _name;
}

std::string User::getSurname() const {
    return _surname;
}

int User::getAge() const {
    return _age;
}

std::string User::getUsername() const {
    return _username;
}

std::string User::getPassword() const {
    return _password;
}

std::string User::getEmail() const {
    return _email;
}

// Setter implementations
void User::setName(const std::string& name) {
    _name = name;
}

void User::setSurname(const std::string& surname) {
    _surname = surname;
}

void User::setAge(int age) {
    _age = age;
}

void User::setUsername(const std::string& username) {
    _username = username;
}

void User::setPassword(const std::string& password) {
    _password = password;
}

void User::setEmail(const std::string& email) {
    _email = email;
}
