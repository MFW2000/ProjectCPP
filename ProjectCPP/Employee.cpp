#include "Employee.h"

#include <iostream>
#include <utility>

Employee::Employee(std::string username, std::string password, std::string department) :
    username(std::move(username)), password(std::move(password)),
    department(std::move(department)) {
}
Employee::~Employee() {
    std::cout << "Employee " << username << " deleted!" << std::endl;
}

// Getters
const std::string& Employee::getUsername() const {
    return username;
}
const std::string& Employee::getDepartment() const {
    return department;
}

void Employee::output(bool newLine) const {
    std::cout << " " << username << " (" << department << ")";

    if (newLine) {
        std::cout << std::endl;
    }
}
