#pragma once

#include "Employee.h"
#include "Ticket.h"

#include <vector>
#include <memory>
#include <string>

class Helpdesk {
    std::vector<std::shared_ptr<Employee>> employees;
    std::vector<std::shared_ptr<Ticket>> tickets;
    unsigned int nextTicketId = 1; // Start ID from 1

public:
    Helpdesk();
    ~Helpdesk();

    std::shared_ptr<Employee> getEmployeeByName(std::string const& username) const;

    std::shared_ptr<Ticket> getTicketById(unsigned int id);

    void addEmployee(const std::shared_ptr<Employee>& employee);

    void addTicket(const std::shared_ptr<Ticket>& ticket);

    void readEmployeeFromFile(const std::string& fileName);

    static void solveTicket(std::shared_ptr<Employee> employee, const std::shared_ptr<Ticket>& ticket,
        const std::string& fixDescription);

    void printEmployees();

    void printTickets();

    // Generate and increment ID automaticly
    unsigned int getNextTicketId() {
        return nextTicketId++;
    };
};
