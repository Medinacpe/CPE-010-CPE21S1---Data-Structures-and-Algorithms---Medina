#include <iostream>
#include "singly_ll.h"

int main(){
    // This line creates an empty linked list
    SingleList<char> *head = new SingleList<char>;
    SingleList<char> *second = new SingleList<char>;
    SingleList<char> *third = new SingleList<char>;
    SingleList<char> *fourth = new SingleList<char>;
    SingleList<char> *fifth = new SingleList<char>;
    SingleList<char> *sixth = new SingleList<char>;

    head -> data = 'C';
    head -> next = second;

    second -> data = 'P';
    second -> next = third;

    third -> data = 'E';
    third -> next = fourth;

    fourth -> data = '1';
    fourth -> next = fifth;

    fifth -> data = '0';
    fifth -> next = sixth;

    sixth -> data = '1';
    sixth -> next = nullptr;

    std::cout << "Linked list traversal:\n";
    listTraversal(head);

    std::cout << "Insertion at head:\n";
    sllinsertHead('G', &head);
    listTraversal(head);

    std::cout << "General Insertion:\n";
    sllGeneralinsertion('E',head->next->next);
    listTraversal(head);

    std::cout << "Deleting a node:\n";
    sllDelete('C', &head);
    listTraversal(head);

    std::cout << "Deleting a node:\n";
    sllDelete('P', &head);
    listTraversal(head);

    sllDeleteList(&head);
    return 0;
}