#include <iostream>
#include <cstdlib>
#include "sortingAlgo.h"
#include <string>

// DECLARATIONS
const int max = 100;

// FUNCTION PROTOTYPE/S
void display(int arr[]);

int main() {
    int A[max];
    srand(67);
    for(int i = 0; i < max; i++) {
        A[i] = rand() % 5 + 1;
    }

    int voteCount[5] = {0, 0, 0, 0, 0};
    std::string candidates[5] = {"Bo Dalton Capistrano", "Cornelius Raymon Agustin", "Deja Jayla Banaga", "Lalla Brielle Yabut", "Franklin Relano Castro"};
    
    std::cout<<"Unsorted Votes: \n";
    display(A);

    std::cout<<"\n\nSorted Votes: \n";
    insertionSort(A, max);
    display(A);

    for(int i = 0; i < max; i++){
        voteCount[A[i]-1]++;
    }

    std::cout<<"\n\nVoting Results:\n";
    int highest = voteCount[0];
    for(int i=0; i < 5; i++){
        std::cout<< candidates[i] << ": " << voteCount[i] << " votes\n";

        if(voteCount[i] > highest) {
            highest = voteCount[i];
        }
    }
    
    std::cout << "\nWinning Candidate: \n";
    for(int i = 0; i < 5; i++){
        if (voteCount[i] == highest){
            std::cout << candidates[i] << " with " << highest << " votes takes the lead!";
        }
    }

    /*
    std::cout<<"Bubble sort: \n";
    bubbleSort(arr, max);
    display(arr);
    */

    /*
    std::cout<<"Insertion sort: \n";
    insertionSort(arr, max);
    display(arr);
    */

    /*
    std::cout<<"Selection sort: \n";
    selectionSort(arr, max);
    display(arr);
    */

    return 0;
}

// FUNCTION DEFINITION/S
void display(int arr[]) {
    for (int i = 0; i < max; i++) {
        std::cout << arr[i] << " ";
    }
}