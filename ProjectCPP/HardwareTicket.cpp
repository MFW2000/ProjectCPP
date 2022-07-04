#include "HardwareTicket.h"

HardwareTicket::HardwareTicket(unsigned int id, const std::string& date,
    const std::shared_ptr<Employee>& ticketCreator, const std::string& issueDescription,
    unsigned int hardwareCode) :
    Ticket(id, date, ticketCreator, issueDescription), hardwareCode(hardwareCode) {
}

void HardwareTicket::output() const {
    std::cout << " Ticket " << getId() << " (Hardwareticket, computer ID: " << hardwareCode <<
        ") " << std::endl;
    Ticket::output();
}
