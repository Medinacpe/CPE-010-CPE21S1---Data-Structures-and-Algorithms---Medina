#include <iostream>
#include <cstdlib>
#include <string>
#include "sortingAlgos.h"

// DECLARATIONS
const int max = 100;

// FUNCTION PROTOTYPE/S
void display(int arr[]);
void arrayMaker(int arr[], int seed);

int main(){
    int array1[max], array2[max], array3[max];
    arrayMaker(array1, 67);
    arrayMaker(array2, 67);
    arrayMaker(array3, 67);

    // ================================

    std::cout<<"SHELL SORT:\n";
    std::cout << "Unsorted Array:\n";
    display(array1);

    std::cout<<"\n"; // Spacing

    std::cout << "Sorted Array:\n";
    shellSort(array1, max);
    display(array1);
    std::cout<<"\n\n";

    // ================================

    std::cout<<"MERGE SORT:\n";
    std::cout << "Unsorted Array:\n";
    display(array2);

    std::cout<<"\n"; // Spacing

    std::cout << "Sorted Array:\n";
    mergeSort(array2, 0, max - 1, max);
    display(array2);
    std::cout<<"\n\n";

    // ================================

    std::cout<<"QUICK SORT:\n";
    std::cout << "Unsorted Array:\n";
    display(array3);

    std::cout<<"\n"; // Spacing

    std::cout << "Sorted Array:\n";
    quickSort(array3, 0, max - 1);
    display(array3);

    // ================================

    return 0;
}

// FUNCTION DEFINITION/S
void display(int arr[]){
    for (int i = 0; i < max; i++) {
        std::cout << arr[i] << " ";
    }
}

void arrayMaker(int arr[], int seed){
    srand(seed);
    for (int i = 0; i < max; i++) {
        arr[i] = rand() % 100 + 1;
    }
}