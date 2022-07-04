#include "ServiceDeskEmployee.h"

#include <iostream>
#include <utility>

ServiceDeskEmployee::ServiceDeskEmployee(const std::string& username, const std::string& password,
    const std::string& department, std::string expertise) :
    Employee(username, password, department), expertise(std::move(expertise)) {
}

void ServiceDeskEmployee::output(bool newLine) const {
    std::cout << " " << getUsername() << " (" << getDepartment() << ", Expertise: " << expertise << ")";

    if (newLine) {
        std::cout << std::endl;
    }
}
