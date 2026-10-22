#include <iostream>
#include "classes.h"

int main() {
    Printer myPrinter(5); // Create printer object with max space of 5 job orders

    std::cout << "ILO C - PRINTER TEST" << std::endl;

    // Multiple requests from multiple users
    std::cout << "-- Submitting Print Requests --" << std::endl;
    myPrinter.addJob(001, "Jomz", 67);
    myPrinter.addJob(002, "Ryle", 6);
    myPrinter.addJob(003, "Medina", 7);
    myPrinter.addJob(004, "CPE21S1", 76);

    std::cout << "\nTotal Pending Jobs: " << myPrinter.getPendingCount() << "\n" << std::endl;

    // Doing the first two jobs
    std::cout << "-- Processing First Two Requests --" << std::endl;
    myPrinter.processNext();
    myPrinter.processNext();

    // Enqueue a print request
    std::cout << "\n-- New Print Request Arrives --" << std::endl;
    myPrinter.addJob(005, "CPE010", 22);

    // Do all the jobs
    myPrinter.processAll();

    // Try printing while the queue is empty (must show that its in idle and that there are no pending jobs to print)
    std::cout << "-- Attempting to print from empty queue --" << std::endl;
    myPrinter.processNext();

    return 0;
}