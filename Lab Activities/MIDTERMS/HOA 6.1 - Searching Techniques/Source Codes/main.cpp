#include <iostream>
#include <cstdlib>
#include <time.h>
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 50;


int main() {
    // Generate random values
    int dataset[max_size];
    srand(time(0));
    for(int i=0; i<max_size; i++){
        dataset[i] = rand();
    }

    // BUBBLE SORT (sorting so that binary search works)
    for (int i = 0; i < max_size - 1; i++) {
        for (int j = 0; j < max_size - i - 1; j++) {
            if (dataset[j] > dataset[j + 1]) {
                // Swap elements
                int temp = dataset[j];
                dataset[j] = dataset[j + 1];
                dataset[j + 1] = temp;
            }
        }
    }

    // Printing
    for(int i=0; i < max_size; i++){
        std::cout<<dataset[i]<<" ";
    }



    // Create a user input to ask what value to find:
    int toFind;
    std::cout<<"\n\nWhat value do you want to search? ";
    std::cin>>toFind;

    // Linear Search:
    linearSearchArr(dataset, max_size, toFind);

    std::cout<<"\n";

    // Binary Search:
    binarySearchArr(dataset, max_size, toFind);

    // Linked List:
    Node<char>* name1 = new_node('J');
    Node<char>* name2 = new_node('O');
    Node<char>* name3 = new_node('M');
    Node<char>* name4 = new_node('Z');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = NULL;

    std::cout<<std::endl;

    std::cout<<"Linear Search for Linked List Result:\n";
    linearSearchLL(name1, 'J');
    linearSearchLL(name1, 'A');

    std::cout<<std::endl; // Spacing

    // Implement it here:
    std::cout<<"Binary Search for Linked List Result:\n";
    binarySearchLL(name1, 'M');
    binarySearchLL(name1, 'A');
    return 0;
}