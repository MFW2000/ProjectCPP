#include "Ticket.h"

#include <utility>

Ticket::Ticket(unsigned int id, std::string date, std::shared_ptr<Employee> ticketCreator,
    std::string issueDescription) :
    id(id), date(std::move(date)), ticketCreator(std::move(ticketCreator)),
    issueDescription(std::move(issueDescription)) {
}
Ticket::~Ticket() {
    std::cout << "Ticket " << id << " deleted!" << std::endl;
}

// Getters
unsigned int Ticket::getId() const {
    return id;
}
const std::shared_ptr<Employee>& Ticket::getTicketCreator() const {
    return ticketCreator;
}
const std::string& Ticket::getIssueDescription() const {
    return issueDescription;
}
const std::shared_ptr<Employee>& Ticket::getTicketSolver() const {
    return ticketSolver;
}
const std::string& Ticket::getFixDescription() const {
    return fixDescription;
}

// Setters
void Ticket::setTicketSolver(std::shared_ptr<Employee>& newTicketSolver) {
    Ticket::ticketSolver = newTicketSolver;
}
void Ticket::setFixDescription(const std::string& newFixDescription) {
    Ticket::fixDescription = newFixDescription;
}

void Ticket::output() const {
    std::cout << "  " << "Status: " << (getFixDescription().empty() ? "Open" : "Closed") << std::endl;
    std::cout << "  ";
    getTicketCreator()->output(false);
    std::cout << ": " << getIssueDescription() << std::endl;

    if (!getFixDescription().empty() && getTicketSolver() != nullptr) {
        std::cout << "  ";
        getTicketSolver()->output(false);
        std::cout << ": " << getFixDescription() << std::endl;
    }
}
