#include <iostream>
#include <cmath>

// Function Prototype
float dist(float x1, float x2, float y1, float y2);

// Main Function
int main() {
// Variable Declare
float x1, x2, y1, y2;

    std::cout << "Distance Between Two Points Calculator\n";
    std::cout << "Input x1: ";
    std::cin >> x1;
    std::cout << "Input y1: ";
    std::cin >> y1;
    std::cout << "Input x2: ";
    std::cin >> x2;
    std::cout << "Input y2: ";
    std::cin >> y2;

    // Function Call
    std::cout << "\nThe distance between the two points is: " << dist(x1, x2, y1, y2);
    
    return 0;
}

// Function Definition
float dist(float x1, float x2, float y1, float y2) {
    float xx = pow((x2-x1), 2);
    float yy = pow((y2-y1), 2);
    return sqrt(xx + yy);
}





