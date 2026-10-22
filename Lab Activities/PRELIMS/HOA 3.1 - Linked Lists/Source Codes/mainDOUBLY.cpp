#include <iostream>
#include "double_LL.h"

int main() {

    //'C' 'P' 'E'
    // Creation of head node:
    doubleList<char>* head = newNode('C');
    // Creation of other nodes:
    doubleList<char>* second = newNode('P');
    doubleList<char>* third = newNode('E');

    // Link the nodes
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout<<"Initial Traversal"<<std::endl;
    dllTraverse(head);

    std::cout<<"Inserting at the head"<<std::endl;
    dllInsertHead('G',&head);
    dllTraverse(head);

    std::cout<<"Inserting at the end"<<std::endl;
    dllInsertEnd('1',head);
    dllTraverse(head);

    std::cout << "Delete G\n";
    dllDelete('G', &head);
    dllTraverse(head);

    std::cout << "Delete P\n";
    dllDelete('P', &head);
    dllTraverse(head);

    std::cout << "Delete 1\n";
    dllDelete('1', &head);
    dllTraverse(head);

    
    doubleList<char>* current = head;

    while(current != nullptr && current->data != 'C'){
        current = current->next;
    }

    std::cout << "General Insertion\n";
    dllGeneralInsertion('P', current);
    dllTraverse(head);

    return 0;
}