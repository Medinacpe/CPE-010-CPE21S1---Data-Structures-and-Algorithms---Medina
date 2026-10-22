#ifndef BST_H
#define BST_H
#include <iostream>

template <typename T>
class BinarySearchTree{

    private:
        // Key Creation
        T key;
        // Left and Right Pointers
        BinarySearchTree<T>* left;
        BinarySearchTree<T>* right;
    public:
        // Constructor
        BinarySearchTree(T value);
        // Insert left and right
        void insert(T value);
        // Traversal
        void preOrder();
        void inOrder();
        void postOrder();
        // Searching
        void findData();
};

// Constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value){
    key = value;
    left = nullptr;
    right = nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(T value){
    
    // Whether to insert left 
    if(value < key){
        if(left == nullptr){
            left = new BinarySearchTree<T>(value);
        } else {
            left->insert(value);
        }
    }

    // Whether to insert right
    else if(value > key){
        if(right == nullptr){
            right = new BinarySearchTree<T>(value);
        } else {
            right->insert(value);
        }
    }

}

// TRAVERSAL
template <typename T>
void BinarySearchTree<T>::preOrder(){
    std::cout << key << " ";
    if(left != nullptr){
        left->preOrder();
    }

    if(right != nullptr){
        right->preOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::inOrder(){
    if(left != nullptr){
        left->inOrder();
    }
    std::cout<<key<<" ";
    if(right != nullptr){
        right->inOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::postOrder(){
    if(left != nullptr){
        left->postOrder();
    }
    if(right != nullptr){
        right->postOrder();
    }
    std::cout<<key<<" ";
}

// SEARCHING
template <typename T>
void BinarySearchTree<T>::findData(){

}

#endif