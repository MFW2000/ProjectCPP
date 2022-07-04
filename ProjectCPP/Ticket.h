#pragma once

#include "Employee.h"
#include "ServiceDeskEmployee.h"

#include <iostream>
#include <string>
#include <memory>

class Ticket {
    unsigned int id;
    std::string date;
    std::shared_ptr<Employee> ticketCreator;
    std::string issueDescription;
    std::shared_ptr<Employee> ticketSolver;
    std::string fixDescription;

protected:
    Ticket(unsigned int id, std::string date, std::shared_ptr<Employee> ticketCreator,
        std::string issueDescription);
    virtual ~Ticket();

public:
    // Getters
    unsigned int getId() const;
    const std::shared_ptr<Employee>& getTicketCreator() const;
    const std::string& getIssueDescription() const;
    const std::shared_ptr<Employee>& getTicketSolver() const;
    const std::string& getFixDescription() const;

    // Setters
    void setTicketSolver(std::shared_ptr<Employee>& ticketSolver);
    void setFixDescription(const std::string& fixDescription);

    virtual void output() const;
};
