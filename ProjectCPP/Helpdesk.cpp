#include "Helpdesk.h"

#include <fstream>

Helpdesk::Helpdesk() = default;
Helpdesk::~Helpdesk() {
    std::cout << "Helpdesk deleted!" << std::endl;
}

std::shared_ptr<Employee> Helpdesk::getEmployeeByName(const std::string& username) const {
    for (auto& employee : employees) {
        if (employee->getUsername() == username) {
            return employee;
        }
    }

    throw std::runtime_error("Employee does not exist!");
}

std::shared_ptr<Ticket> Helpdesk::getTicketById(unsigned int id) {
    for (auto& ticket : tickets) {
        if (ticket->getId() == id) {
            return ticket;
        }
    }

    throw std::runtime_error("Ticket does not exist!");
}

void Helpdesk::addEmployee(const std::shared_ptr<Employee>& employee) {
    for (auto& employeeInList : employees) {
        if (employeeInList->getUsername() == employee->getUsername()) {
            throw std::runtime_error("This username already exists!");
        }
    }

    employees.push_back(employee);
}

void Helpdesk::addTicket(const std::shared_ptr<Ticket>& ticket) {
    tickets.push_back(ticket);
}

void Helpdesk::readEmployeeFromFile(const std::string& fileName) {
    std::ifstream input(fileName);

    while (true) {
        std::string username;
        std::string password;
        std::string department;

        input >> username;
        input >> password;
        input >> department;

        if (input.eof()) {
            break;
        }

        if (input.fail()) {
            throw std::runtime_error("Failed to parse file!");
        }

        addEmployee(std::make_shared<Employee>(username, password, department));
    }
}

void Helpdesk::solveTicket(std::shared_ptr<Employee> employee, const std::shared_ptr<Ticket>& ticket,
    const std::string& fixDescription) {
    if (std::dynamic_pointer_cast<ServiceDeskEmployee>(employee) != nullptr) {
        ticket->setTicketSolver(employee);
        ticket->setFixDescription(fixDescription);
    }
    else {
        throw std::runtime_error("This employee is not allowed to solve tickets!");
    }
}

void Helpdesk::printEmployees() {
    for (auto& employee : employees) {
        employee->output(true);
    }
}

void Helpdesk::printTickets() {
    for (auto& ticket : tickets) {
        ticket->output();
    }
}
