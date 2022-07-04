#pragma once

#include "Ticket.h"

class SoftwareTicket : public Ticket {
    std::string softwareName;

public:
    SoftwareTicket(unsigned int id, const std::string& date, const std::shared_ptr<Employee>& ticketCreator,
        const std::string& issueDescription, std::string softwareName);

    void output() const override;
};
