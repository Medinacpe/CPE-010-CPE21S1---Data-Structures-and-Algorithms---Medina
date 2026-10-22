#include <iostream>
#include "node.h"
#include "searchingAlgo.h"

int list[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
int max_size = sizeof(list)/sizeof(list[0]);
int toFind = 18;

int list2[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
int max_size2 = sizeof(list2)/sizeof(list2[0]);
int toFind2 = 8;

int main() {

    // Linked-List Creation
    Node<int>* name1 = new_node(15);
    Node<int>* name2 = new_node(18);
    Node<int>* name3 = new_node(2);
    Node<int>* name4 = new_node(19);
    Node<int>* name5 = new_node(18);
    Node<int>* name6 = new_node(0);
    Node<int>* name7 = new_node(8);
    Node<int>* name8 = new_node(14);
    Node<int>* name9 = new_node(19);
    Node<int>* name10 = new_node(14);


    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;
    name7->next = name8;
    name8->next = name9;
    name9->next = name10;
    name10->next = NULL;

    // SEARCHES:

    // Array Based Sequential/Linear Search:
    std::cout<<"Array-Based Linear Search:\n";
    linearSearchArr(list, max_size, toFind);

    std::cout<<"\n"; // Spacing

    // Linked-List Based Sequential/Linear Search:
    std::cout<<"Linked List-Based Linear Search:\n";
    linearSearchLL(name1, 18);

    std::cout<<"\n"; // Spacing

    // Array Based Binary Search
    //binarySearchArr(list2, max_size2, toFind2);
    
    std::cout<<"Recursive Binary Search: ";
    binarySearchArr(list2, 0, max_size-1, toFind2);


    return 0;
}