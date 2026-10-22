#ifndef GENERALTREE_H
#define GENERALTREE_H
#include <iostream>

template <typename T>
class GeneralTree{

    private:
        // Key Creation
        T key;
        // Left and Right Pointers
        GeneralTree<T>* left;
        GeneralTree<T>* right;
    public:
        // Constructor
        GeneralTree(T value);
        GeneralTree<T>* insert(T value);
        void display();
        void preOrder();
        void inOrder();
        void postOrder();
        void findData(int choice, T searchKey);
};

// CONSTRUCTOR
template <typename T>
GeneralTree<T>::GeneralTree(T value){
    key = value;
    left = nullptr;
    right = nullptr;
}

// ADD CHILD AT END
template <typename T>
GeneralTree<T>* GeneralTree<T>::insert(T value){
    GeneralTree<T>* newNode = new GeneralTree<T>(value);

    if(left == nullptr){
        left = newNode;
    } else {
        GeneralTree<T>* current = left;
        while(current->right != nullptr){
            current = current->right;
        }
        current->right = newNode;
    }

    return newNode;
}

// DISPLAY FUNCTION/S
template <typename T>
void GeneralTree<T>::display(){
    if(left != nullptr){
        std::cout << key << ": ";
        GeneralTree<T>* current = left;

        while(current != nullptr){
            std::cout << current->key << " ";
            current = current->right;
        }
        std::cout << "\n";

        current = left;
        while(current != nullptr){
            current->display();
            current = current->right;
        }
    }
}

template <typename T>
void GeneralTree<T>::preOrder(){
    std::cout << key << " ";
    GeneralTree<T>* current = left;
    while(current != nullptr){
        current->preOrder();
        current = current->right;
    }
}

template <typename T>
void GeneralTree<T>::inOrder(){
    GeneralTree<T>* current = left;
    if(current != nullptr){
        current->inOrder();
        current = current->right;
    }

    std::cout << key << " ";
    while(current != nullptr){
        current->inOrder();
        current = current->right;
    }
}

template <typename T>
void GeneralTree<T>::postOrder(){
    GeneralTree<T>* current = left;
    while(current != nullptr){
        current->postOrder();
        current = current->right;
    }
    std::cout << key << " ";
}

template <typename T>
void GeneralTree<T>::findData(int choice, T searchKey){
    if(choice < 1 || choice > 3){
        return;
    }

    if(choice == 1 && key == searchKey){
        std::cout << key << " was found!\n";
    }

    GeneralTree<T>* current = left;

    if(choice == 2){
        if(current != nullptr){
            current->findData(choice, searchKey);
            current = current->right;
        }
        if(key == searchKey){
            std::cout << key << " was found!\n";
        }
    }

    while(current != nullptr){
        current->findData(choice, searchKey);
        current = current->right;
    }

    if(choice == 3 && key == searchKey){
        std::cout << key << " was found!\n";
    }
}


#endif
