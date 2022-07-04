#include "SoftwareTicket.h"

#include <utility>

SoftwareTicket::SoftwareTicket(unsigned int id, const std::string& date,
    const std::shared_ptr<Employee>& ticketCreator, const std::string& issueDescription,
    std::string softwareName) :
    Ticket(id, date, ticketCreator, issueDescription), softwareName(std::move(softwareName)) {
}

void SoftwareTicket::output() const {
    std::cout << " Ticket " << getId() << " (Softwareticket, application: " << softwareName <<
        ") " << std::endl;
    Ticket::output();
}
