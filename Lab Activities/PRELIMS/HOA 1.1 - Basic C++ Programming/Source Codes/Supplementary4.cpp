#include <iostream>
#include <cmath>

// class name should follow PascalCase
class Triangle{
    private:
        double totalAngle, angleA, angleB, angleC;
        float sideA, sideB, sideC; //for the peremeter

    public:
        //constructor
        Triangle(double A, double B, double C);

        //methods
        void setAngles(double A, double B, double C);

        //validation
        const bool validateTriangle();

        // Supple 4 prototypes
        void setSides(double a, double b, double c);
        float area();
        double perimeter();
        void triType();
};

int main(){
    // Variable Declaration
    int x, y, z;

    //driver code
    std::cout << "Triangle Verifier\n\nInput the first angle: ";
    std::cin >> x;
    std::cout << "Input the second angle: ";
    std::cin >> y;
    std::cout << "Input the third angle: ";
    std::cin >> z;
    Triangle set1(x,y,z);

    if(set1.validateTriangle()){
        std::cout<<"\nThe shape is a valid Triangle\n\n";

        // the perimieter thing
        double a, b, c;
        std::cout << "\nEnter side A: ";
        std::cin >> a;
        std::cout << "Enter side B: ";
        std::cin >> b;
        std::cout << "Enter side C: ";
        std::cin >> c;

        
        set1.setSides(a,b,c);

        std::cout << "\nPerimeter: " << set1.perimeter() << std::endl;
        std::cout << "Area: " << set1.area() << std::endl;

        std::cout << "Triangle Type: ";
        set1.triType();
    } else{
        std::cout<<"\nThe shape is NOT a valid triangle. \n";
    }

    return 0;
}

Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB= B;
    angleC = C;
    totalAngle = A+B+C;
    sideA = sideB = sideC = 0; // reset
}

void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB= B;
    angleC = C;
    totalAngle = A+B+C;
}

const bool Triangle::validateTriangle(){
    // makes sure angles are positive and sum up to exactly 180 degrees
    if (angleA > 0 && angleB > 0 && angleC > 0 && totalAngle == 180) {
        return true;
    }
    return false;
}

// Supple 4 func definitions
void Triangle::setSides(double a, double b, double c){
    sideA = a;
    sideB = b;
    sideC = c;
}

double Triangle::perimeter(){
    return sideA + sideB + sideC;
}

float Triangle::area(){
    float s = perimeter() / 2;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

void Triangle::triType(){
    if(angleA < 90 && angleB < 90 && angleC < 90){
        std::cout << "Acute-angled" << std::endl;
    }
    else if(angleA > 90 || angleB > 90 || angleC > 90){
        std::cout << "Obtuse-angled" << std::endl;
    }
    else{
        std::cout << "Others" << std::endl;
    }
}



