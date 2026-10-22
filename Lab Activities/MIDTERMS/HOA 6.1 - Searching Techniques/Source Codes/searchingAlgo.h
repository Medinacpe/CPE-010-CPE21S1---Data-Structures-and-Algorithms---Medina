#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearchArr(T data[], int arrSize, T dataFind){
    int j = 0; // comps
    int i = 0; // counts

    while(i < arrSize){
        if(dataFind==data[i]){
            std::cout<<"Element found! Number of comparisons: "<<i+1<<"\n";
            j++;
        }
        i++;
    }
    std::cout<<"The element '"<<dataFind<< "' is found "<<j<<" time/s.\n";

    return;
}

template <typename T>
void linearSearchLL(Node<T>*node, T dataFind){
    int i = 0; // number of comparisons
    int j = 0; // count
    while(node!=nullptr){
        i++;
        if(dataFind == node->data){
            std::cout<<"Element found! Number of comparisons: "<<i<<"\n";
            j++;
        }
        node = node->next;
    }
    std::cout<<"The element '"<<dataFind<< "' is found "<<j<<" time/s.\n";
    return;
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    Node<T>* slow = start;
    Node<T>* fast = start;

    while(fast != last && fast->next != last){
        // Slow (one step)
        slow = slow->next;
        // Fast (two steps)
        fast = fast->next->next;
    }
    // When fast reaches end, slow points to middle
    return slow;
}

// Create a binary search using array : getmiddle and / binarySearchArr

template <typename T>
void binarySearchArr(T arr[], int low, int high, T no) {

    if (low > high) {
        std::cout<<"The search was unsuccessful!\n";
    }

    int mid = (low + high) / 2;

    if (arr[mid] == no){
        std::cout<<"The search was a success.\n";
        return;
    } else if (no < arr[mid]){
        binarySearchArr(arr, low, mid-1, no);
    } else {
        binarySearchArr(arr, mid+1, high, no);
    }
}

template <typename T>
void binarySearchLL(Node<T> *start, T findData){
    Node<T>* last = nullptr;

    while(start!=last){
        Node<T>* middle = getMiddle(start, last);
        if(middle == nullptr){
            return;
        }

        if(middle->data == findData){
            std::cout<<"The search was a success.\n";
            return;
        }

        if(middle->data < findData){
            start = middle->next;
        } else {
            last = middle;
        }
    }
    std::cout<<"The search was unsuccessful!\n";
}


#endif