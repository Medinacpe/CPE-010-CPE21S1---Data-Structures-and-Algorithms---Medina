


#include <iostream>
#include "stackList.h"

int main(){
    std::string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"
    };

    for (const auto& expr : expressions) {
        std::cout << "Expression: " << expr << "\n";
        bool valid = parser(expr);
        std::cout << "Valid? " << (valid ? "Y" : "N") << "\n\n"; // ternary expression 
    }

    return 0;
}



