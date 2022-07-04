#pragma once

#include "Ticket.h"

class HardwareTicket : public Ticket {
    unsigned int hardwareCode;

public:
    HardwareTicket(unsigned int id, const std::string& date, const std::shared_ptr<Employee>& ticketCreator,
        const std::string& issueDescription, unsigned int hardwareCode);

    void output() const override;
};
