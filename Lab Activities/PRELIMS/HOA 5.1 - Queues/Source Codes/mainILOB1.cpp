#include <iostream>
#include "queuell.h"

int main(){
    qNode<char> *front = nullptr;
    qNode<char> *back = nullptr;

    // Enqueue
    std::cout<<"Enqueuing: \n";
    enqueue(&front, &back, 'M');
    std::cout<<front->data<<" "<<back->data<<std::endl;
    enqueue(&front, &back, 'J');
    std::cout<<front->data<<" "<<back->data<<std::endl;
    enqueue(&front, &back, 'O');
    std::cout<<front->data<<" "<<back->data<<std::endl;
    enqueue(&front, &back, 'M');
    std::cout<<front->data<<" "<<back->data<<std::endl;
    enqueue(&front, &back, 'Z');
    std::cout<<front->data<<" "<<back->data<<std::endl;

    std::cout<<std::endl; // Spacing

    // Dequeue
    std::cout<<"Dequeuing: \n";
    dequeue(&front, &back);
    std::cout<<front->data<<" "<<back->data<<std::endl;

    std::cout<<std::endl; // Spacing

    // Display
    std::cout<<"Printing all elements: \n";
    display(front);

    std::cout<<std::endl; // Spacing

    // Front
    std::cout<<"Front Element: ";
    std::cout<<frontFind(front);

    return 0;
}