#include <iostream>

int main() {
    // Variable Declaration
    int i, j, k;

    // Input Phase
    std::cout << "First Number (variable i): ";
    std::cin >> i;
    std::cout << "Second Number (variable j): ";
    std::cin >> j;

    // Variable Number Swap
    k = i;
    i = j;
    j = k;

    // Final Output
    std::cout << "\n\nVariable i and j have been swapped:\n\n";
    std::cout << "Variable i: " << i << std::endl;
    std::cout << "Variable j: " << j;
    return 0;
}
