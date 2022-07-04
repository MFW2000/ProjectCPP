#pragma once

#include "Employee.h"

class ServiceDeskEmployee : public Employee {
    std::string expertise;

public:
    ServiceDeskEmployee(const std::string& username, const std::string& password, const std::string& department,
        std::string expertise);

    void output(bool newLine) const override;
};
