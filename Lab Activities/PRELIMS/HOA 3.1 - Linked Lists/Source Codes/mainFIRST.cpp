#include <iostream>
#include "singly_ll.h"

class Node{
    public:
        char data;
        Node *next;
};

//Create a simple linked list with your name, in this case "ROMAN"
int main(){
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;

    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;

    //define first node
    head->data = 'J';
    head->next = second;

    //define second node
    second->data = 'O';
    second->next = third;

    //define third node
    third->data = 'M';
    third->next = fourth;

    //define fourth node
    fourth->data = 'Z';
    fourth->next = NULL;

    // deallocation
    delete head;
    delete second;
    delete third;
    delete fourth;
    return 0;
}