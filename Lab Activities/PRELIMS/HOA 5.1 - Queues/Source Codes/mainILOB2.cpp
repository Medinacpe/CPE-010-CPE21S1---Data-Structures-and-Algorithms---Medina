#include <iostream>
#include "queueArr.h"

int main() {

    // INITIALIZATION
    queueArr<int> q(7);

    // CHECK IF EMPTY
    q.Empty();

    // ENQUEUE
    std::cout << "\nEnqueuing 1, 2, 3, 4, 5, 6, and 7..." << std::endl;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);

    std::cout << "Size of queue: " << q.Size() << std::endl;
    std::cout << "Front of the queue: " << q.Front() << std::endl;
    std::cout << "Back of the queue: " << q.Back() << std::endl;

    // DEQUEUE AND DISPLAY
    std::cout << "\n Displaying, dequeueing one element, then displaying again..." << std::endl;
    q.Display();
    q.Dequeue();
    q.Display();

    std::cout << "Displaying, enqueuing one element (67), then displaying again..." << std::endl;
    q.Display();
    q.Enqueue(67);
    q.Display();
    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;

    // COPY CONSTRUCTOR
    std::cout << "\nTesting Copy Constructor..." << std::endl;
    queueArr<int> qAnotherOne = q;
    std::cout << "The Copied Queue: ";
    qAnotherOne.Display();

    // COPY ASSIGNMENT OPERATOR
    std::cout << "\nTesting Copy Assignment Operator..." << std::endl;
    queueArr<int> qAssignment(7);
    qAssignment = q;
    std::cout << "Assigned Queue: ";
    qAssignment.Display();

    // CLEARING
    std::cout << "\nClearing..." << std::endl;
    q.Clear();
    std::cout << "Is queue empty? " << (q.Empty() ? "Yes" : "No") << std::endl; // Ternary operator
    q.Display();

    return 0;
}