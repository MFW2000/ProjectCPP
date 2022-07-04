#include "Helpdesk.h"
#include "ServiceDeskEmployee.h"
#include "Ticket.h"
#include "HardwareTicket.h"
#include "SoftwareTicket.h"

#include <iostream>

int main()
{
    try {
        // Create helpdesk
        Helpdesk helpdesk;

        // Add employees
        helpdesk.readEmployeeFromFile("data.txt");
        helpdesk.addEmployee(std::make_shared<ServiceDeskEmployee>(
            "gerralt", "catsarecool", "Helpdesk Department", "Mice"));

        // Print all employees
        std::cout << "Employees:" << std::endl;
        helpdesk.printEmployees();
        std::cout << std::endl;

        // Add tickets
        helpdesk.addTicket(std::make_shared<SoftwareTicket>(
            helpdesk.getNextTicketId(), "15-01-2018",
            helpdesk.getEmployeeByName("ruud"),
            "Excel can't calculate the number of days in a year", "Office 365"));
        helpdesk.addTicket(std::make_shared<HardwareTicket>(
            helpdesk.getNextTicketId(), "16-01-2018",
            helpdesk.getEmployeeByName("jeroen"),
            "My mouse doesn't work!", 5));
        helpdesk.addTicket(std::make_shared<SoftwareTicket>(
            helpdesk.getNextTicketId(), "17-01-2018",
            helpdesk.getEmployeeByName("ruud"),
            "MacOS won't boot on my system", "MacOS X"));

        // Solve tickets
        Helpdesk::solveTicket(helpdesk.getEmployeeByName("gerralt"),
            helpdesk.getTicketById(2),
            "Try putting it into the USB port instead of the HDMI port.");
        Helpdesk::solveTicket(helpdesk.getEmployeeByName("gerralt"),
            helpdesk.getTicketById(3),
            "Please replace your Dell laptop with a real system.");

        // Print tickets
        std::cout << "Tickets:" << std::endl;
        helpdesk.printTickets();
        std::cout << std::endl;

        // Cleaning up allocated memory
        std::cout << "Cleaning up..." << std::endl;
    }
    catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }

    return 0;
}
