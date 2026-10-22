#include <iostream>
#include "BST.h"
#include "generalTree.h"

int main(){
    // Root node
    GeneralTree<char> tree('A');

    // PARENT NODE A
    tree.insert('B');
    tree.insert('C');
    GeneralTree<char>* nodeD = tree.insert('D');
    GeneralTree<char>* nodeE = tree.insert('E');
    GeneralTree<char>* nodeF = tree.insert('F');
    GeneralTree<char>* nodeG = tree.insert('G');

    // PARENT NODE D
    nodeD->insert('H');

    // PARENT NODE E
    nodeE->insert('I');
    GeneralTree<char>* nodeJ = nodeE->insert('J');

    // PARENT NODE F
    nodeF->insert('K');
    nodeF->insert('L');
    nodeF->insert('M');

    // PARENT NODE G
    nodeG->insert('N');

    // PARENT NODE J
    nodeJ->insert('P');
    nodeJ->insert('Q');

    // Task 9-2
    std::cout<<"Pre-Order:\n";
    tree.preOrder();
    std::cout<<"\n\n";
    
    std::cout<<"Post-Order:\n";
    tree.postOrder();
    std::cout<<"\n\n";
    
    std::cout<<"In-Order:\n";
    tree.inOrder();
    
    // Task 9-3
    std::cout<<"\n";
    std::cout << "\nFinding I using pre-order:\n";
    tree.findData(1, 'I');
    std::cout << "Finding I using in-order:\n";
    tree.findData(2, 'I');
    std::cout << "Finding I using post-order:\n";
    tree.findData(3, 'I');

    // Not finding anything (display nothing)
    std::cout << "\nFinding O using pre-order:\n";
    tree.findData(1, 'O');
    std::cout << "Finding O using in-order:\n";
    tree.findData(2, 'O');
    std::cout << "Finding O using post-order:\n";
    tree.findData(3, 'O');

    // INSERT
    std::cout<<"\n";
    std::cout<<"Inserting 'O'\n";
    nodeG->insert('O');
    std::cout << "Pre-order search: ";
    tree.findData(1, 'O');
    std::cout << "In-order search: ";
    tree.findData(2, 'O');
    std::cout << "Post-order search: ";
    tree.findData(3, 'O');
    std::cout<<"\n\n\n";

    // SUPPLEMENTARY
    int values1[] = {3, 9, 18, 0, 1, 4, 5};
    int size = sizeof(values1)/sizeof(values1[0]);
    BinarySearchTree<int> tree2(2);
    
    for (int i = 0; i < size; ++i){
    tree2.insert(values1[i]);
    }
    
    
    std::cout<<"Binary Search Tree (2, 3, 9, 18, 0, 1, 4, 5):\n\n";

    std::cout<<"Pre-Order:\n";
    tree2.preOrder();
    std::cout<<"\n\n";
    
    std::cout<<"In-Order:\n";
    tree2.inOrder();
    std::cout<<"\n\n";

    std::cout<<"Post-Order:\n";
    tree2.postOrder();
    return 0;
}
