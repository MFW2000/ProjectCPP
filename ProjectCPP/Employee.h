#pragma once

#include <string>

class Employee {
    std::string username;
    std::string password;
    std::string department;

public:
    Employee(std::string username, std::string password, std::string department);
    virtual ~Employee();

    // Getters
    const std::string& getUsername() const;
    const std::string& getDepartment() const;

    virtual void output(bool newLine) const;
};
