#include <iostream>

// Variable Declaration
int choice;
int n1, n2;
bool v1, v2;
bool stay = true;

// Prototype
void sumFunction(int num1, int num2);
void greaterFunction(int num1, int num2);
void logicChecker(bool val1, bool val2);

main() {
    while (stay) {
        std::cout << "Please choose a function from the following:\n\n1. Addition of two numbers\n2. If the first number is greater than the second\n3. Logical Operation Checker\n\n";
        std::cin >> choice;

        std::cout << std::endl;

        switch (choice) {
            case 1: // Addition Case
                std::cout << "Enter first number: ";
                std::cin >> n1;
                std::cout << "Enter second number: ";
                std::cin >> n2;

                sumFunction(n1, n2);
                break;
            
            case 2: // Comparison Case
                std::cout << "Enter first number: ";
                std::cin >> n1;
                std::cout << "Enter second number: ";
                std::cin >> n2;

                greaterFunction(n1, n2);
                break;
            case 3: // Logical Operation
                std::cout << "Enter first boolean value (1 for True / 0 for False): ";
                std::cin >> v1;
                std::cout << "Enter second boolean value (1 for True / 0 for False): ";
                std::cin >> v2;

                logicChecker(v1, v2);
        }
    
    std::cout << "\nContinue? (1 for Yes / 0 for No): ";
    std::cin >> stay;
    }

    std::cout << "\nHave a nice day!";
    return 0;
}

// Function Definitions

void sumFunction(int num1, int num2) {
    int total = num1 + num2;
    std::cout << "\nAnswer: " << total;
}

void greaterFunction(int num1, int num2) {
    if (num1 > num2) {
        std::cout << "\nThe first number is GREATER THAN the second.";
    } else {
        std::cout << "\nThe first number is LESS THAN the second.";
    }
}

void logicChecker(bool val1, bool val2) {
    std::cout << "\nAND operation: " << (val1 && val2) << "\n";
    std::cout << "OR operation: " << (val1 || val2) << "\n";
    std::cout << "NAND operation: " << (!(val1 && val2)) << "\n";
    std::cout << "OR operation: " << (!(val1 || val2)) << "\n";
    std::cout << "NOT (First Value): " << (!val1) << "\n";
    std::cout << "NOT (Second Value): " << (!val2) << "\n";
    std::cout << "XOR operation: " << (val1 != val2) << "\n";
}

/* CODE ANALYSIS:
    In the following code, I was tasked with creating 3 functions with their prototypes and definitions. 
    I thought of the most efficient way to call all three and decided on using a while-loop to be able 
    to choose between all three repeatedly. I also made use of the switch case which was very convenient 
    with the menu system I made. Overall, the code runs as intended and fits exactly what I wanted to achieve.
*/


