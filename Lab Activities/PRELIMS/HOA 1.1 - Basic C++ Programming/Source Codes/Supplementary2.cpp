#include <iostream>

// Global Variable Declaration
float kel, fah;

// Function Prototype
float keltofah(float kelvin);

// Main Function
int main() {
    std::cout << "Kelvin to Fahrenheit Converter\n";
    std::cout << "Input Kelvin: ";
    std::cin >> kel;

    // Function Call
    std::cout << "\nThe converted temperature is: " << keltofah(kel) << " degree/s fahrenheit.";
    return 0;
}

// Function Definition
float keltofah(float kelvin){
    fah = (kel - 273.15) * 1.8 + 32;
    return fah;
}





